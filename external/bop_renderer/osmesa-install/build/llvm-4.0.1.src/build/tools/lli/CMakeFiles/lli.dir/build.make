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
include tools/lli/CMakeFiles/lli.dir/depend.make

# Include the progress variables for this target.
include tools/lli/CMakeFiles/lli.dir/progress.make

# Include the compile flags for this target's objects.
include tools/lli/CMakeFiles/lli.dir/flags.make

tools/lli/CMakeFiles/lli.dir/lli.cpp.o: tools/lli/CMakeFiles/lli.dir/flags.make
tools/lli/CMakeFiles/lli.dir/lli.cpp.o: ../tools/lli/lli.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/lli/CMakeFiles/lli.dir/lli.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lli.dir/lli.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/lli.cpp

tools/lli/CMakeFiles/lli.dir/lli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lli.dir/lli.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/lli.cpp > CMakeFiles/lli.dir/lli.cpp.i

tools/lli/CMakeFiles/lli.dir/lli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lli.dir/lli.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/lli.cpp -o CMakeFiles/lli.dir/lli.cpp.s

tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.o: tools/lli/CMakeFiles/lli.dir/flags.make
tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.o: ../tools/lli/OrcLazyJIT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lli.dir/OrcLazyJIT.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/OrcLazyJIT.cpp

tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lli.dir/OrcLazyJIT.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/OrcLazyJIT.cpp > CMakeFiles/lli.dir/OrcLazyJIT.cpp.i

tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lli.dir/OrcLazyJIT.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli/OrcLazyJIT.cpp -o CMakeFiles/lli.dir/OrcLazyJIT.cpp.s

# Object files for target lli
lli_OBJECTS = \
"CMakeFiles/lli.dir/lli.cpp.o" \
"CMakeFiles/lli.dir/OrcLazyJIT.cpp.o"

# External object files for target lli
lli_EXTERNAL_OBJECTS =

bin/lli: tools/lli/CMakeFiles/lli.dir/lli.cpp.o
bin/lli: tools/lli/CMakeFiles/lli.dir/OrcLazyJIT.cpp.o
bin/lli: tools/lli/CMakeFiles/lli.dir/build.make
bin/lli: lib/libLLVMIRReader.so.4.0.1
bin/lli: lib/libLLVMInterpreter.so.4.0.1
bin/lli: lib/libLLVMMCJIT.so.4.0.1
bin/lli: lib/libLLVMOrcJIT.so.4.0.1
bin/lli: lib/libLLVMX86CodeGen.so.4.0.1
bin/lli: lib/libLLVMX86AsmParser.so.4.0.1
bin/lli: lib/libLLVMX86Desc.so.4.0.1
bin/lli: lib/libLLVMX86Disassembler.so.4.0.1
bin/lli: lib/libLLVMExecutionEngine.so.4.0.1
bin/lli: lib/libLLVMRuntimeDyld.so.4.0.1
bin/lli: lib/libLLVMSelectionDAG.so.4.0.1
bin/lli: lib/libLLVMCodeGen.so.4.0.1
bin/lli: lib/libLLVMTarget.so.4.0.1
bin/lli: lib/libLLVMTransformUtils.so.4.0.1
bin/lli: lib/libLLVMObject.so.4.0.1
bin/lli: lib/libLLVMX86AsmPrinter.so.4.0.1
bin/lli: lib/libLLVMCore.so.4.0.1
bin/lli: lib/libLLVMX86Info.so.4.0.1
bin/lli: lib/libLLVMMC.so.4.0.1
bin/lli: lib/libLLVMSupport.so.4.0.1
bin/lli: tools/lli/CMakeFiles/lli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/lli"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/lli/CMakeFiles/lli.dir/build: bin/lli

.PHONY : tools/lli/CMakeFiles/lli.dir/build

tools/lli/CMakeFiles/lli.dir/clean:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli && $(CMAKE_COMMAND) -P CMakeFiles/lli.dir/cmake_clean.cmake
.PHONY : tools/lli/CMakeFiles/lli.dir/clean

tools/lli/CMakeFiles/lli.dir/depend:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/tools/lli /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/tools/lli/CMakeFiles/lli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/lli/CMakeFiles/lli.dir/depend

