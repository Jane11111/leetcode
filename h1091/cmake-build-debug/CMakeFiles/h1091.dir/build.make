# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/zxl/Software/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zxl/Software/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zxl/CPlusProjects/h1091

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxl/CPlusProjects/h1091/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/h1091.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/h1091.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/h1091.dir/flags.make

CMakeFiles/h1091.dir/main.cpp.o: CMakeFiles/h1091.dir/flags.make
CMakeFiles/h1091.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxl/CPlusProjects/h1091/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/h1091.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/h1091.dir/main.cpp.o -c /home/zxl/CPlusProjects/h1091/main.cpp

CMakeFiles/h1091.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h1091.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxl/CPlusProjects/h1091/main.cpp > CMakeFiles/h1091.dir/main.cpp.i

CMakeFiles/h1091.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h1091.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxl/CPlusProjects/h1091/main.cpp -o CMakeFiles/h1091.dir/main.cpp.s

# Object files for target h1091
h1091_OBJECTS = \
"CMakeFiles/h1091.dir/main.cpp.o"

# External object files for target h1091
h1091_EXTERNAL_OBJECTS =

h1091: CMakeFiles/h1091.dir/main.cpp.o
h1091: CMakeFiles/h1091.dir/build.make
h1091: CMakeFiles/h1091.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxl/CPlusProjects/h1091/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable h1091"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h1091.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/h1091.dir/build: h1091

.PHONY : CMakeFiles/h1091.dir/build

CMakeFiles/h1091.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/h1091.dir/cmake_clean.cmake
.PHONY : CMakeFiles/h1091.dir/clean

CMakeFiles/h1091.dir/depend:
	cd /home/zxl/CPlusProjects/h1091/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxl/CPlusProjects/h1091 /home/zxl/CPlusProjects/h1091 /home/zxl/CPlusProjects/h1091/cmake-build-debug /home/zxl/CPlusProjects/h1091/cmake-build-debug /home/zxl/CPlusProjects/h1091/cmake-build-debug/CMakeFiles/h1091.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/h1091.dir/depend
