# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/taojingyu/Repo/SDLProject/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/taojingyu/Repo/SDLProject/demo/build

# Include any dependencies generated for this target.
include CMakeFiles/DEMO.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DEMO.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DEMO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DEMO.dir/flags.make

CMakeFiles/DEMO.dir/codegen:
.PHONY : CMakeFiles/DEMO.dir/codegen

CMakeFiles/DEMO.dir/main.cpp.o: CMakeFiles/DEMO.dir/flags.make
CMakeFiles/DEMO.dir/main.cpp.o: /Users/taojingyu/Repo/SDLProject/demo/main.cpp
CMakeFiles/DEMO.dir/main.cpp.o: CMakeFiles/DEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/taojingyu/Repo/SDLProject/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DEMO.dir/main.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DEMO.dir/main.cpp.o -MF CMakeFiles/DEMO.dir/main.cpp.o.d -o CMakeFiles/DEMO.dir/main.cpp.o -c /Users/taojingyu/Repo/SDLProject/demo/main.cpp

CMakeFiles/DEMO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DEMO.dir/main.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taojingyu/Repo/SDLProject/demo/main.cpp > CMakeFiles/DEMO.dir/main.cpp.i

CMakeFiles/DEMO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DEMO.dir/main.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taojingyu/Repo/SDLProject/demo/main.cpp -o CMakeFiles/DEMO.dir/main.cpp.s

# Object files for target DEMO
DEMO_OBJECTS = \
"CMakeFiles/DEMO.dir/main.cpp.o"

# External object files for target DEMO
DEMO_EXTERNAL_OBJECTS =

DEMO: CMakeFiles/DEMO.dir/main.cpp.o
DEMO: CMakeFiles/DEMO.dir/build.make
DEMO: /opt/homebrew/Cellar/sdl2/2.30.9/lib/libSDL2-2.0.0.dylib
DEMO: CMakeFiles/DEMO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/taojingyu/Repo/SDLProject/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DEMO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DEMO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DEMO.dir/build: DEMO
.PHONY : CMakeFiles/DEMO.dir/build

CMakeFiles/DEMO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DEMO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DEMO.dir/clean

CMakeFiles/DEMO.dir/depend:
	cd /Users/taojingyu/Repo/SDLProject/demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/taojingyu/Repo/SDLProject/demo /Users/taojingyu/Repo/SDLProject/demo /Users/taojingyu/Repo/SDLProject/demo/build /Users/taojingyu/Repo/SDLProject/demo/build /Users/taojingyu/Repo/SDLProject/demo/build/CMakeFiles/DEMO.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DEMO.dir/depend

