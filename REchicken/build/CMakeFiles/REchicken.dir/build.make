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
CMAKE_SOURCE_DIR = /Users/taojingyu/Repo/SDLProject/REchicken

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/taojingyu/Repo/SDLProject/REchicken/build

# Include any dependencies generated for this target.
include CMakeFiles/REchicken.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/REchicken.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/REchicken.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/REchicken.dir/flags.make

CMakeFiles/REchicken.dir/codegen:
.PHONY : CMakeFiles/REchicken.dir/codegen

CMakeFiles/REchicken.dir/main.cpp.o: CMakeFiles/REchicken.dir/flags.make
CMakeFiles/REchicken.dir/main.cpp.o: /Users/taojingyu/Repo/SDLProject/REchicken/main.cpp
CMakeFiles/REchicken.dir/main.cpp.o: CMakeFiles/REchicken.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/taojingyu/Repo/SDLProject/REchicken/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/REchicken.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/REchicken.dir/main.cpp.o -MF CMakeFiles/REchicken.dir/main.cpp.o.d -o CMakeFiles/REchicken.dir/main.cpp.o -c /Users/taojingyu/Repo/SDLProject/REchicken/main.cpp

CMakeFiles/REchicken.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/REchicken.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taojingyu/Repo/SDLProject/REchicken/main.cpp > CMakeFiles/REchicken.dir/main.cpp.i

CMakeFiles/REchicken.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/REchicken.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taojingyu/Repo/SDLProject/REchicken/main.cpp -o CMakeFiles/REchicken.dir/main.cpp.s

# Object files for target REchicken
REchicken_OBJECTS = \
"CMakeFiles/REchicken.dir/main.cpp.o"

# External object files for target REchicken
REchicken_EXTERNAL_OBJECTS =

REchicken: CMakeFiles/REchicken.dir/main.cpp.o
REchicken: CMakeFiles/REchicken.dir/build.make
REchicken: /opt/homebrew/Cellar/sdl2/2.30.9/lib/libSDL2-2.0.0.dylib
REchicken: /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib/libSDL2_image-2.0.0.dylib
REchicken: /opt/homebrew/Cellar/sdl2_mixer/2.8.0/lib/libSDL2_mixer-2.0.0.dylib
REchicken: /opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib/libSDL2_ttf-2.0.0.dylib
REchicken: CMakeFiles/REchicken.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/taojingyu/Repo/SDLProject/REchicken/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable REchicken"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/REchicken.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/REchicken.dir/build: REchicken
.PHONY : CMakeFiles/REchicken.dir/build

CMakeFiles/REchicken.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/REchicken.dir/cmake_clean.cmake
.PHONY : CMakeFiles/REchicken.dir/clean

CMakeFiles/REchicken.dir/depend:
	cd /Users/taojingyu/Repo/SDLProject/REchicken/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/taojingyu/Repo/SDLProject/REchicken /Users/taojingyu/Repo/SDLProject/REchicken /Users/taojingyu/Repo/SDLProject/REchicken/build /Users/taojingyu/Repo/SDLProject/REchicken/build /Users/taojingyu/Repo/SDLProject/REchicken/build/CMakeFiles/REchicken.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/REchicken.dir/depend

