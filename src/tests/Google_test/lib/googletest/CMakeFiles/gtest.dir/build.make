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
CMAKE_SOURCE_DIR = /home/vinchik/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vinchik/src/tests

# Include any dependencies generated for this target.
include Google_test/lib/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include Google_test/lib/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include Google_test/lib/googletest/CMakeFiles/gtest.dir/flags.make

Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: Google_test/lib/googletest/CMakeFiles/gtest.dir/flags.make
Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../Google_test/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinchik/src/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/vinchik/src/tests/Google_test/lib/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/vinchik/src/Google_test/lib/googletest/src/gtest-all.cc

Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/vinchik/src/tests/Google_test/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinchik/src/Google_test/lib/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/vinchik/src/tests/Google_test/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinchik/src/Google_test/lib/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: Google_test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: Google_test/lib/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: Google_test/lib/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vinchik/src/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest.a"
	cd /home/vinchik/src/tests/Google_test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/vinchik/src/tests/Google_test/lib/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_test/lib/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : Google_test/lib/googletest/CMakeFiles/gtest.dir/build

Google_test/lib/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/vinchik/src/tests/Google_test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : Google_test/lib/googletest/CMakeFiles/gtest.dir/clean

Google_test/lib/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/vinchik/src/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vinchik/src /home/vinchik/src/Google_test/lib/googletest /home/vinchik/src/tests /home/vinchik/src/tests/Google_test/lib/googletest /home/vinchik/src/tests/Google_test/lib/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Google_test/lib/googletest/CMakeFiles/gtest.dir/depend

