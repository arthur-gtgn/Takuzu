# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arthurgatignol/CLionProjects/Takuzu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Takuzu.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Takuzu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Takuzu.dir/flags.make

CMakeFiles/Takuzu.dir/main.c.o: CMakeFiles/Takuzu.dir/flags.make
CMakeFiles/Takuzu.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Takuzu.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Takuzu.dir/main.c.o -c /Users/arthurgatignol/CLionProjects/Takuzu/main.c

CMakeFiles/Takuzu.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Takuzu.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthurgatignol/CLionProjects/Takuzu/main.c > CMakeFiles/Takuzu.dir/main.c.i

CMakeFiles/Takuzu.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Takuzu.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthurgatignol/CLionProjects/Takuzu/main.c -o CMakeFiles/Takuzu.dir/main.c.s

CMakeFiles/Takuzu.dir/takuzu.c.o: CMakeFiles/Takuzu.dir/flags.make
CMakeFiles/Takuzu.dir/takuzu.c.o: ../takuzu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Takuzu.dir/takuzu.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Takuzu.dir/takuzu.c.o -c /Users/arthurgatignol/CLionProjects/Takuzu/takuzu.c

CMakeFiles/Takuzu.dir/takuzu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Takuzu.dir/takuzu.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthurgatignol/CLionProjects/Takuzu/takuzu.c > CMakeFiles/Takuzu.dir/takuzu.c.i

CMakeFiles/Takuzu.dir/takuzu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Takuzu.dir/takuzu.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthurgatignol/CLionProjects/Takuzu/takuzu.c -o CMakeFiles/Takuzu.dir/takuzu.c.s

# Object files for target Takuzu
Takuzu_OBJECTS = \
"CMakeFiles/Takuzu.dir/main.c.o" \
"CMakeFiles/Takuzu.dir/takuzu.c.o"

# External object files for target Takuzu
Takuzu_EXTERNAL_OBJECTS =

Takuzu: CMakeFiles/Takuzu.dir/main.c.o
Takuzu: CMakeFiles/Takuzu.dir/takuzu.c.o
Takuzu: CMakeFiles/Takuzu.dir/build.make
Takuzu: CMakeFiles/Takuzu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Takuzu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Takuzu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Takuzu.dir/build: Takuzu
.PHONY : CMakeFiles/Takuzu.dir/build

CMakeFiles/Takuzu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Takuzu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Takuzu.dir/clean

CMakeFiles/Takuzu.dir/depend:
	cd /Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arthurgatignol/CLionProjects/Takuzu /Users/arthurgatignol/CLionProjects/Takuzu /Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug /Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug /Users/arthurgatignol/CLionProjects/Takuzu/cmake-build-debug/CMakeFiles/Takuzu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Takuzu.dir/depend

