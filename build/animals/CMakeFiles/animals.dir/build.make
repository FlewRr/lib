# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /snap/cmake/1403/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1403/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sfleur/lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sfleur/lib/build

# Include any dependencies generated for this target.
include animals/CMakeFiles/animals.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include animals/CMakeFiles/animals.dir/compiler_depend.make

# Include the progress variables for this target.
include animals/CMakeFiles/animals.dir/progress.make

# Include the compile flags for this target's objects.
include animals/CMakeFiles/animals.dir/flags.make

animals/CMakeFiles/animals.dir/animals.cpp.o: animals/CMakeFiles/animals.dir/flags.make
animals/CMakeFiles/animals.dir/animals.cpp.o: /home/sfleur/lib/animals/animals.cpp
animals/CMakeFiles/animals.dir/animals.cpp.o: animals/CMakeFiles/animals.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sfleur/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object animals/CMakeFiles/animals.dir/animals.cpp.o"
	cd /home/sfleur/lib/build/animals && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT animals/CMakeFiles/animals.dir/animals.cpp.o -MF CMakeFiles/animals.dir/animals.cpp.o.d -o CMakeFiles/animals.dir/animals.cpp.o -c /home/sfleur/lib/animals/animals.cpp

animals/CMakeFiles/animals.dir/animals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/animals.dir/animals.cpp.i"
	cd /home/sfleur/lib/build/animals && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sfleur/lib/animals/animals.cpp > CMakeFiles/animals.dir/animals.cpp.i

animals/CMakeFiles/animals.dir/animals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/animals.dir/animals.cpp.s"
	cd /home/sfleur/lib/build/animals && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sfleur/lib/animals/animals.cpp -o CMakeFiles/animals.dir/animals.cpp.s

# Object files for target animals
animals_OBJECTS = \
"CMakeFiles/animals.dir/animals.cpp.o"

# External object files for target animals
animals_EXTERNAL_OBJECTS =

animals/libanimals.a: animals/CMakeFiles/animals.dir/animals.cpp.o
animals/libanimals.a: animals/CMakeFiles/animals.dir/build.make
animals/libanimals.a: animals/CMakeFiles/animals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sfleur/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libanimals.a"
	cd /home/sfleur/lib/build/animals && $(CMAKE_COMMAND) -P CMakeFiles/animals.dir/cmake_clean_target.cmake
	cd /home/sfleur/lib/build/animals && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/animals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
animals/CMakeFiles/animals.dir/build: animals/libanimals.a
.PHONY : animals/CMakeFiles/animals.dir/build

animals/CMakeFiles/animals.dir/clean:
	cd /home/sfleur/lib/build/animals && $(CMAKE_COMMAND) -P CMakeFiles/animals.dir/cmake_clean.cmake
.PHONY : animals/CMakeFiles/animals.dir/clean

animals/CMakeFiles/animals.dir/depend:
	cd /home/sfleur/lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sfleur/lib /home/sfleur/lib/animals /home/sfleur/lib/build /home/sfleur/lib/build/animals /home/sfleur/lib/build/animals/CMakeFiles/animals.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : animals/CMakeFiles/animals.dir/depend

