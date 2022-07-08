// Copyright (C) 2019 Czech Technical University.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of Czech Technical University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Please contact the author of this library if you have any questions.
// Author: Daniel Barath (barath.daniel@sztaki.mta.hu)
#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <cmath>
#include <random>
#include <vector>

#include <unsupported/Eigen/Polynomials>
#include <Eigen/Eigen>

#include "estimator.h"
#include "model.h"

#include "solver_p3p.h"

namespace gcransac
{
	namespace estimator
	{
		// This is the estimator class for estimating a homography matrix between two images. A model estimation method and error calculation method are implemented
		template<class _MinimalSolverEngine,  // The solver used for estimating the model from a minimal sample
			class _NonMinimalSolverEngine> // The solver used for estimating the model from a non-minimal sample
			class PerspectiveNPointEstimator : public Estimator < cv::Mat, Model >
		{
		protected:
			// Minimal solver engine used for estimating a model from a minimal sample
			const std::shared_ptr<const _MinimalSolverEngine> minimal_solver;

			// Non-minimal solver engine used for estimating a model from a bigger than minimal sample
			const std::shared_ptr<const _NonMinimalSolverEngine> non_minimal_solver;

			// The lower bound of the inlier ratio which is required to pass the validity test.
			// The validity test measures what proportion of the inlier (by Sampson distance) is inlier
			// when using symmetric epipolar distance. 
			const double minimum_triangle_area;

		public:
			PerspectiveNPointEstimator(const double minimum_triangle_area_ = 0.0) :
				// Minimal solver engine used for estimating a model from a minimal sample
				minimal_solver(std::make_shared<const _MinimalSolverEngine>()),
				// Non-minimal solver engine used for estimating a model from a bigger than minimal sample
				non_minimal_solver(std::make_shared<const _NonMinimalSolverEngine>()),
				// The lower bound of the inlier ratio which is required to pass the validity test.
				// It is clamped to be in interval [0, 1].
				minimum_triangle_area(minimum_triangle_area_)
			{}

			~PerspectiveNPointEstimator() {}

			// The size of a non-minimal sample required for the estimation
			static constexpr size_t nonMinimalSampleSize() {
				return _NonMinimalSolverEngine::sampleSize();
			}

			// The size of a minimal sample required for the estimation
			static constexpr size_t sampleSize() {
				return _MinimalSolverEngine::sampleSize();
			}

			// The size of a minimal sample_ required for the estimation
			static constexpr size_t maximumMinimalSolutions() {
				return _MinimalSolverEngine::maximumSolutions();
			}

			// A flag deciding if the points can be weighted when the non-minimal fitting is applied 
			static constexpr bool isWeightingApplicable() {
				return false;
			}

			// The size of a sample when doing inner RANSAC on a non-minimal sample
			OLGA_INLINE size_t inlierLimit() const {
				return 7 * sampleSize();
			}

			OLGA_INLINE bool estimateModel(const cv::Mat& data,
				const size_t *sample,
				std::vector<Model>* models_) const
			{
				// Estimate the model parameters by the minimal solver
				std::vector<Model> temp_models;
				minimal_solver->estimateModel(data,
					sample,
					sampleSize(),
					temp_models);

				for (const Model &model : temp_models)
				{
					if (model.descriptor(2, 3) < 0.0 ||
						model.descriptor.block<3, 3>(0, 0).determinant() < -0.95)
						continue;
					models_->emplace_back(model);
				}

				// The estimation was successfull if at least one model is kept
				return models_->size() > 0;
			}
			
			OLGA_INLINE double squaredReprojectionError(const cv::Mat& point_,
				const Eigen::Matrix<double, 3, 4>& descriptor_) const
			{
				const double* s = reinterpret_cast<double *>(point_.data);
				const double 
					&u = *s,
					&v = *(s + 1),
					&x = *(s + 2),
					&y = *(s + 3),
					&z = *(s + 4);

				const double 
					&r11 = descriptor_(0, 0),
					&r12 = descriptor_(0, 1),
					&r13 = descriptor_(0, 2),
					&r21 = descriptor_(1, 0),
					&r22 = descriptor_(1, 1),
					&r23 = descriptor_(1, 2),
					&r31 = descriptor_(2, 0),
					&r32 = descriptor_(2, 1),
					&r33 = descriptor_(2, 2),
					&tx = descriptor_(0, 3),
					&ty = descriptor_(1, 3),
					&tz = descriptor_(2, 3);
				
				const double px = r11 * x + r12 * y + r13 * z + tx,
					py = r21 * x + r22 * y + r23 * z + ty,
					pz = r31 * x + r32 * y + r33 * z + tz;

				const double pu = px / pz,
					pv = py / pz;	

				const double du = pu - u,
					dv = pv - v;
				
				return du * du + dv * dv;
			}

			OLGA_INLINE bool isValidSample(
				const cv::Mat& data, // All data points
				const size_t *sample_) const
			{
				// Triangle area
				const size_t &columns = data.cols;
				const double *data_ptr = reinterpret_cast<double *>(data.data);
				const size_t &idx1 = sample_[0] * columns,
					idx2 = sample_[1] * columns,
					idx3 = sample_[2] * columns;

				const double &u1 = data_ptr[idx1 + 5],
					&v1 = data_ptr[idx1 + 6],
					&u2 = data_ptr[idx2 + 5],
					&v2 = data_ptr[idx2 + 6],
					&u3 = data_ptr[idx3 + 5],
					&v3 = data_ptr[idx3 + 6];

				const double du21 = u2 - u1,
					dv21 = v2 - v1,
					du31 = u3 - u1,
					dv31 = v3 - v1;

				const double area =
					0.5 * abs(du21 * dv31 - du31 * dv21);

				return area > minimum_triangle_area;
			}
			
			OLGA_INLINE double squaredResidual(const cv::Mat& point_,
				const Model& model_) const
			{
				return squaredResidual(point_, model_.descriptor);
			}

			OLGA_INLINE double squaredResidual(const cv::Mat& point_,
				const Eigen::MatrixXd& descriptor_) const
			{
				if (descriptor_.cols() != 4 || descriptor_.rows() != 3)
				{
					fprintf(stderr, "Error while calculating the residuals. "
						"The size of the matrix should be 3*4 instead of %d*%d.\n", 
						descriptor_.rows(), descriptor_.cols());
					return 0.0;
				}
				return squaredReprojectionError(point_, descriptor_);
			}

			OLGA_INLINE double residual(const cv::Mat& point_,
				const Model& model_) const
			{
				return residual(point_, model_.descriptor);
			}

			OLGA_INLINE double residual(const cv::Mat& point_,
				const Eigen::MatrixXd& descriptor_) const
			{
				return sqrt(squaredReprojectionError(point_, descriptor_));
			}

			OLGA_INLINE bool isValidModel(Model& model_,
				const cv::Mat& data_,
				const std::vector<size_t> &inliers_,
				const size_t *minimal_sample_,
				const double threshold_,
				bool &model_updated_) const
			{
				return true;
			}

			OLGA_INLINE bool estimateModelNonminimal(
				const cv::Mat& data_,
				const size_t *sample_,
				const size_t &sample_number_,
				std::vector<Model>* models_,
				const double *weights_ = nullptr) const
			{
				if (sample_number_ < nonMinimalSampleSize())
					return false;

				// The eight point fundamental matrix fitting algorithm
				std::vector<Model> temp_models;
				non_minimal_solver->estimateModel(data_,
					sample_,
					sample_number_,
					temp_models,
					weights_);

				for (const Model &model : temp_models)
				{
					if (model.descriptor(2, 3) < 0.0 ||
						model.descriptor.block<3, 3>(0, 0).determinant() < -0.95)
						continue;
					models_->emplace_back(model);
				}

				return models_->size() > 0;

				return true;
			}
		};
	}
}