# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/myakoven/Documents/RayTracing_Weekend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/myakoven/Documents/RayTracing_Weekend

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raytracer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/main.cc.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/main.cc.o: main.cc
CMakeFiles/raytracer.dir/main.cc.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/myakoven/Documents/RayTracing_Weekend/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/main.cc.o -MF CMakeFiles/raytracer.dir/main.cc.o.d -o CMakeFiles/raytracer.dir/main.cc.o -c /home/myakoven/Documents/RayTracing_Weekend/main.cc

CMakeFiles/raytracer.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myakoven/Documents/RayTracing_Weekend/main.cc > CMakeFiles/raytracer.dir/main.cc.i

CMakeFiles/raytracer.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myakoven/Documents/RayTracing_Weekend/main.cc -o CMakeFiles/raytracer.dir/main.cc.s

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/main.cc.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/main.cc.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/myakoven/Documents/RayTracing_Weekend/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer
.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd /home/myakoven/Documents/RayTracing_Weekend && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myakoven/Documents/RayTracing_Weekend /home/myakoven/Documents/RayTracing_Weekend /home/myakoven/Documents/RayTracing_Weekend /home/myakoven/Documents/RayTracing_Weekend /home/myakoven/Documents/RayTracing_Weekend/CMakeFiles/raytracer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raytracer.dir/depend

