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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jeong-ighyo/Desktop/bst/lab2_sync

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2_sync.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_sync.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_sync.dir/flags.make

CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o: CMakeFiles/lab2_sync.dir/flags.make
CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o: ../include/lab2_timeval.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o   -c /Users/jeong-ighyo/Desktop/bst/lab2_sync/include/lab2_timeval.c

CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jeong-ighyo/Desktop/bst/lab2_sync/include/lab2_timeval.c > CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.i

CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jeong-ighyo/Desktop/bst/lab2_sync/include/lab2_timeval.c -o CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.s

CMakeFiles/lab2_sync.dir/lab2_bst.c.o: CMakeFiles/lab2_sync.dir/flags.make
CMakeFiles/lab2_sync.dir/lab2_bst.c.o: ../lab2_bst.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab2_sync.dir/lab2_bst.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2_sync.dir/lab2_bst.c.o   -c /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst.c

CMakeFiles/lab2_sync.dir/lab2_bst.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_sync.dir/lab2_bst.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst.c > CMakeFiles/lab2_sync.dir/lab2_bst.c.i

CMakeFiles/lab2_sync.dir/lab2_bst.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_sync.dir/lab2_bst.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst.c -o CMakeFiles/lab2_sync.dir/lab2_bst.c.s

CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o: CMakeFiles/lab2_sync.dir/flags.make
CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o: ../lab2_bst_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o   -c /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst_test.c

CMakeFiles/lab2_sync.dir/lab2_bst_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_sync.dir/lab2_bst_test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst_test.c > CMakeFiles/lab2_sync.dir/lab2_bst_test.c.i

CMakeFiles/lab2_sync.dir/lab2_bst_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_sync.dir/lab2_bst_test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jeong-ighyo/Desktop/bst/lab2_sync/lab2_bst_test.c -o CMakeFiles/lab2_sync.dir/lab2_bst_test.c.s

# Object files for target lab2_sync
lab2_sync_OBJECTS = \
"CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o" \
"CMakeFiles/lab2_sync.dir/lab2_bst.c.o" \
"CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o"

# External object files for target lab2_sync
lab2_sync_EXTERNAL_OBJECTS =

lab2_sync: CMakeFiles/lab2_sync.dir/include/lab2_timeval.c.o
lab2_sync: CMakeFiles/lab2_sync.dir/lab2_bst.c.o
lab2_sync: CMakeFiles/lab2_sync.dir/lab2_bst_test.c.o
lab2_sync: CMakeFiles/lab2_sync.dir/build.make
lab2_sync: CMakeFiles/lab2_sync.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab2_sync"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2_sync.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_sync.dir/build: lab2_sync

.PHONY : CMakeFiles/lab2_sync.dir/build

CMakeFiles/lab2_sync.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2_sync.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2_sync.dir/clean

CMakeFiles/lab2_sync.dir/depend:
	cd /Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jeong-ighyo/Desktop/bst/lab2_sync /Users/jeong-ighyo/Desktop/bst/lab2_sync /Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug /Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug /Users/jeong-ighyo/Desktop/bst/lab2_sync/cmake-build-debug/CMakeFiles/lab2_sync.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_sync.dir/depend

