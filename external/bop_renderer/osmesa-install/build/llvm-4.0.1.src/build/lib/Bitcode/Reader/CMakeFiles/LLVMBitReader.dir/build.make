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
include lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/depend.make

# Include the progress variables for this target.
include lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o: ../lib/Bitcode/Reader/BitReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitReader.cpp

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMBitReader.dir/BitReader.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitReader.cpp > CMakeFiles/LLVMBitReader.dir/BitReader.cpp.i

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMBitReader.dir/BitReader.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitReader.cpp -o CMakeFiles/LLVMBitReader.dir/BitReader.cpp.s

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o: ../lib/Bitcode/Reader/BitcodeReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitcodeReader.cpp

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitcodeReader.cpp > CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.i

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitcodeReader.cpp -o CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.s

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o: ../lib/Bitcode/Reader/BitstreamReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitstreamReader.cpp

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitstreamReader.cpp > CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.i

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/BitstreamReader.cpp -o CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.s

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o: ../lib/Bitcode/Reader/MetadataLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/MetadataLoader.cpp

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/MetadataLoader.cpp > CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.i

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/MetadataLoader.cpp -o CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.s

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/flags.make
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o: ../lib/Bitcode/Reader/ValueList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o -c /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/ValueList.cpp

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMBitReader.dir/ValueList.cpp.i"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/ValueList.cpp > CMakeFiles/LLVMBitReader.dir/ValueList.cpp.i

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMBitReader.dir/ValueList.cpp.s"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader/ValueList.cpp -o CMakeFiles/LLVMBitReader.dir/ValueList.cpp.s

# Object files for target LLVMBitReader
LLVMBitReader_OBJECTS = \
"CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o" \
"CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o" \
"CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o" \
"CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o" \
"CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o"

# External object files for target LLVMBitReader
LLVMBitReader_EXTERNAL_OBJECTS =

lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitReader.cpp.o
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitcodeReader.cpp.o
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/BitstreamReader.cpp.o
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/MetadataLoader.cpp.o
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/ValueList.cpp.o
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/build.make
lib/libLLVMBitReader.so.4.0.1: lib/libLLVMCore.so.4.0.1
lib/libLLVMBitReader.so.4.0.1: lib/libLLVMSupport.so.4.0.1
lib/libLLVMBitReader.so.4.0.1: lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../libLLVMBitReader.so"
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMBitReader.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && $(CMAKE_COMMAND) -E cmake_symlink_library ../../libLLVMBitReader.so.4.0.1 ../../libLLVMBitReader.so.4 ../../libLLVMBitReader.so

lib/libLLVMBitReader.so.4: lib/libLLVMBitReader.so.4.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libLLVMBitReader.so.4

lib/libLLVMBitReader.so: lib/libLLVMBitReader.so.4.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libLLVMBitReader.so

# Rule to build all files generated by this target.
lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/build: lib/libLLVMBitReader.so

.PHONY : lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/build

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/clean:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader && $(CMAKE_COMMAND) -P CMakeFiles/LLVMBitReader.dir/cmake_clean.cmake
.PHONY : lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/clean

lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/depend:
	cd /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/lib/Bitcode/Reader /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader /home/lele/Codes/epos/repository/external/bop_renderer/osmesa-install/build/llvm-4.0.1.src/build/lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Bitcode/Reader/CMakeFiles/LLVMBitReader.dir/depend

