# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build

# Include any dependencies generated for this target.
include tools/llvm-lto/CMakeFiles/llvm-lto.dir/depend.make

# Include the progress variables for this target.
include tools/llvm-lto/CMakeFiles/llvm-lto.dir/progress.make

# Include the compile flags for this target's objects.
include tools/llvm-lto/CMakeFiles/llvm-lto.dir/flags.make

tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o: tools/llvm-lto/CMakeFiles/llvm-lto.dir/flags.make
tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o: ../tools/llvm-lto/llvm-lto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto/llvm-lto.cpp

tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llvm-lto.dir/llvm-lto.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto/llvm-lto.cpp > CMakeFiles/llvm-lto.dir/llvm-lto.cpp.i

tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llvm-lto.dir/llvm-lto.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto/llvm-lto.cpp -o CMakeFiles/llvm-lto.dir/llvm-lto.cpp.s

# Object files for target llvm-lto
llvm__lto_OBJECTS = \
"CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o"

# External object files for target llvm-lto
llvm__lto_EXTERNAL_OBJECTS =

bin/llvm-lto: tools/llvm-lto/CMakeFiles/llvm-lto.dir/llvm-lto.cpp.o
bin/llvm-lto: tools/llvm-lto/CMakeFiles/llvm-lto.dir/build.make
bin/llvm-lto: lib/libLLVMX86CodeGen.so.4.0.1
bin/llvm-lto: lib/libLLVMX86AsmParser.so.4.0.1
bin/llvm-lto: lib/libLLVMX86Desc.so.4.0.1
bin/llvm-lto: lib/libLLVMX86Disassembler.so.4.0.1
bin/llvm-lto: lib/libLLVMLTO.so.4.0.1
bin/llvm-lto: lib/libLLVMX86AsmPrinter.so.4.0.1
bin/llvm-lto: lib/libLLVMX86Info.so.4.0.1
bin/llvm-lto: lib/libLLVMTarget.so.4.0.1
bin/llvm-lto: lib/libLLVMBitWriter.so.4.0.1
bin/llvm-lto: lib/libLLVMIRReader.so.4.0.1
bin/llvm-lto: lib/libLLVMObject.so.4.0.1
bin/llvm-lto: lib/libLLVMBitReader.so.4.0.1
bin/llvm-lto: lib/libLLVMMC.so.4.0.1
bin/llvm-lto: lib/libLLVMCore.so.4.0.1
bin/llvm-lto: lib/libLLVMSupport.so.4.0.1
bin/llvm-lto: tools/llvm-lto/CMakeFiles/llvm-lto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/llvm-lto"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/llvm-lto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/llvm-lto/CMakeFiles/llvm-lto.dir/build: bin/llvm-lto

.PHONY : tools/llvm-lto/CMakeFiles/llvm-lto.dir/build

tools/llvm-lto/CMakeFiles/llvm-lto.dir/clean:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto && $(CMAKE_COMMAND) -P CMakeFiles/llvm-lto.dir/cmake_clean.cmake
.PHONY : tools/llvm-lto/CMakeFiles/llvm-lto.dir/clean

tools/llvm-lto/CMakeFiles/llvm-lto.dir/depend:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto/CMakeFiles/llvm-lto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-lto/CMakeFiles/llvm-lto.dir/depend

