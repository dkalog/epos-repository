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
include tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/depend.make

# Include the progress variables for this target.
include tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/progress.make

# Include the compile flags for this target's objects.
include tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/flags.make

tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o: tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/flags.make
tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o: ../tools/llvm-lto2/llvm-lto2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto2/llvm-lto2.cpp

tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto2/llvm-lto2.cpp > CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.i

tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto2/llvm-lto2.cpp -o CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.s

# Object files for target llvm-lto2
llvm__lto2_OBJECTS = \
"CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o"

# External object files for target llvm-lto2
llvm__lto2_EXTERNAL_OBJECTS =

bin/llvm-lto2: tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/llvm-lto2.cpp.o
bin/llvm-lto2: tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/build.make
bin/llvm-lto2: lib/libLLVMX86CodeGen.so.4.0.1
bin/llvm-lto2: lib/libLLVMX86AsmParser.so.4.0.1
bin/llvm-lto2: lib/libLLVMX86Desc.so.4.0.1
bin/llvm-lto2: lib/libLLVMX86Disassembler.so.4.0.1
bin/llvm-lto2: lib/libLLVMLTO.so.4.0.1
bin/llvm-lto2: lib/libLLVMX86AsmPrinter.so.4.0.1
bin/llvm-lto2: lib/libLLVMX86Info.so.4.0.1
bin/llvm-lto2: lib/libLLVMTarget.so.4.0.1
bin/llvm-lto2: lib/libLLVMLinker.so.4.0.1
bin/llvm-lto2: lib/libLLVMObject.so.4.0.1
bin/llvm-lto2: lib/libLLVMMC.so.4.0.1
bin/llvm-lto2: lib/libLLVMCore.so.4.0.1
bin/llvm-lto2: lib/libLLVMSupport.so.4.0.1
bin/llvm-lto2: tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/llvm-lto2"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/llvm-lto2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/build: bin/llvm-lto2

.PHONY : tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/build

tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/clean:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 && $(CMAKE_COMMAND) -P CMakeFiles/llvm-lto2.dir/cmake_clean.cmake
.PHONY : tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/clean

tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/depend:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/llvm-lto2 /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2 /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-lto2/CMakeFiles/llvm-lto2.dir/depend

