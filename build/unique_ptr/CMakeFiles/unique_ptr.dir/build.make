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
include unique_ptr/CMakeFiles/unique_ptr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include unique_ptr/CMakeFiles/unique_ptr.dir/compiler_depend.make

# Include the progress variables for this target.
include unique_ptr/CMakeFiles/unique_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include unique_ptr/CMakeFiles/unique_ptr.dir/flags.make

unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o: unique_ptr/CMakeFiles/unique_ptr.dir/flags.make
unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o: /home/sfleur/lib/unique_ptr/unique_ptr.cpp
unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o: unique_ptr/CMakeFiles/unique_ptr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sfleur/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o"
	cd /home/sfleur/lib/build/unique_ptr && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o -MF CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o.d -o CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o -c /home/sfleur/lib/unique_ptr/unique_ptr.cpp

unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/unique_ptr.dir/unique_ptr.cpp.i"
	cd /home/sfleur/lib/build/unique_ptr && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sfleur/lib/unique_ptr/unique_ptr.cpp > CMakeFiles/unique_ptr.dir/unique_ptr.cpp.i

unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/unique_ptr.dir/unique_ptr.cpp.s"
	cd /home/sfleur/lib/build/unique_ptr && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sfleur/lib/unique_ptr/unique_ptr.cpp -o CMakeFiles/unique_ptr.dir/unique_ptr.cpp.s

# Object files for target unique_ptr
unique_ptr_OBJECTS = \
"CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o"

# External object files for target unique_ptr
unique_ptr_EXTERNAL_OBJECTS =

unique_ptr/libunique_ptr.a: unique_ptr/CMakeFiles/unique_ptr.dir/unique_ptr.cpp.o
unique_ptr/libunique_ptr.a: unique_ptr/CMakeFiles/unique_ptr.dir/build.make
unique_ptr/libunique_ptr.a: unique_ptr/CMakeFiles/unique_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sfleur/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libunique_ptr.a"
	cd /home/sfleur/lib/build/unique_ptr && $(CMAKE_COMMAND) -P CMakeFiles/unique_ptr.dir/cmake_clean_target.cmake
	cd /home/sfleur/lib/build/unique_ptr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unique_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unique_ptr/CMakeFiles/unique_ptr.dir/build: unique_ptr/libunique_ptr.a
.PHONY : unique_ptr/CMakeFiles/unique_ptr.dir/build

unique_ptr/CMakeFiles/unique_ptr.dir/clean:
	cd /home/sfleur/lib/build/unique_ptr && $(CMAKE_COMMAND) -P CMakeFiles/unique_ptr.dir/cmake_clean.cmake
.PHONY : unique_ptr/CMakeFiles/unique_ptr.dir/clean

unique_ptr/CMakeFiles/unique_ptr.dir/depend:
	cd /home/sfleur/lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sfleur/lib /home/sfleur/lib/unique_ptr /home/sfleur/lib/build /home/sfleur/lib/build/unique_ptr /home/sfleur/lib/build/unique_ptr/CMakeFiles/unique_ptr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : unique_ptr/CMakeFiles/unique_ptr.dir/depend

