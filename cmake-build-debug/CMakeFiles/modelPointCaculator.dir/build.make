# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "/home/giang/Dev by me/clion-2018.1.4/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/home/giang/Dev by me/clion-2018.1.4/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/giang/Desktop/3DX/modelPoint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/giang/Desktop/3DX/modelPoint/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/modelPointCaculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/modelPointCaculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modelPointCaculator.dir/flags.make

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o: CMakeFiles/modelPointCaculator.dir/flags.make
CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o: ../modelPointCaculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giang/Desktop/3DX/modelPoint/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o -c /home/giang/Desktop/3DX/modelPoint/modelPointCaculator.cpp

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giang/Desktop/3DX/modelPoint/modelPointCaculator.cpp > CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.i

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giang/Desktop/3DX/modelPoint/modelPointCaculator.cpp -o CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.s

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.requires:

.PHONY : CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.requires

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.provides: CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.requires
	$(MAKE) -f CMakeFiles/modelPointCaculator.dir/build.make CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.provides.build
.PHONY : CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.provides

CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.provides.build: CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o


# Object files for target modelPointCaculator
modelPointCaculator_OBJECTS = \
"CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o"

# External object files for target modelPointCaculator
modelPointCaculator_EXTERNAL_OBJECTS =

libmodelPointCaculator.a: CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o
libmodelPointCaculator.a: CMakeFiles/modelPointCaculator.dir/build.make
libmodelPointCaculator.a: CMakeFiles/modelPointCaculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/giang/Desktop/3DX/modelPoint/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmodelPointCaculator.a"
	$(CMAKE_COMMAND) -P CMakeFiles/modelPointCaculator.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modelPointCaculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modelPointCaculator.dir/build: libmodelPointCaculator.a

.PHONY : CMakeFiles/modelPointCaculator.dir/build

CMakeFiles/modelPointCaculator.dir/requires: CMakeFiles/modelPointCaculator.dir/modelPointCaculator.cpp.o.requires

.PHONY : CMakeFiles/modelPointCaculator.dir/requires

CMakeFiles/modelPointCaculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modelPointCaculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modelPointCaculator.dir/clean

CMakeFiles/modelPointCaculator.dir/depend:
	cd /home/giang/Desktop/3DX/modelPoint/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/giang/Desktop/3DX/modelPoint /home/giang/Desktop/3DX/modelPoint /home/giang/Desktop/3DX/modelPoint/cmake-build-debug /home/giang/Desktop/3DX/modelPoint/cmake-build-debug /home/giang/Desktop/3DX/modelPoint/cmake-build-debug/CMakeFiles/modelPointCaculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modelPointCaculator.dir/depend

