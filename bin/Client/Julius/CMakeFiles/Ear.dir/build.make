# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/inspiration/samson/puspa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/inspiration/samson/puspa/bin

# Include any dependencies generated for this target.
include Client/Julius/CMakeFiles/Ear.dir/depend.make

# Include the progress variables for this target.
include Client/Julius/CMakeFiles/Ear.dir/progress.make

# Include the compile flags for this target's objects.
include Client/Julius/CMakeFiles/Ear.dir/flags.make

Client/Julius/CMakeFiles/Ear.dir/Ear.c.o: Client/Julius/CMakeFiles/Ear.dir/flags.make
Client/Julius/CMakeFiles/Ear.dir/Ear.c.o: ../Client/Julius/Ear.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/inspiration/samson/puspa/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object Client/Julius/CMakeFiles/Ear.dir/Ear.c.o"
	cd /home/inspiration/samson/puspa/bin/Client/Julius && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Ear.dir/Ear.c.o   -c /home/inspiration/samson/puspa/Client/Julius/Ear.c

Client/Julius/CMakeFiles/Ear.dir/Ear.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ear.dir/Ear.c.i"
	cd /home/inspiration/samson/puspa/bin/Client/Julius && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/inspiration/samson/puspa/Client/Julius/Ear.c > CMakeFiles/Ear.dir/Ear.c.i

Client/Julius/CMakeFiles/Ear.dir/Ear.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ear.dir/Ear.c.s"
	cd /home/inspiration/samson/puspa/bin/Client/Julius && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/inspiration/samson/puspa/Client/Julius/Ear.c -o CMakeFiles/Ear.dir/Ear.c.s

Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.requires:
.PHONY : Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.requires

Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.provides: Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.requires
	$(MAKE) -f Client/Julius/CMakeFiles/Ear.dir/build.make Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.provides.build
.PHONY : Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.provides

Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.provides.build: Client/Julius/CMakeFiles/Ear.dir/Ear.c.o
.PHONY : Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.provides.build

# Object files for target Ear
Ear_OBJECTS = \
"CMakeFiles/Ear.dir/Ear.c.o"

# External object files for target Ear
Ear_EXTERNAL_OBJECTS =

Client/Julius/libEar.a: Client/Julius/CMakeFiles/Ear.dir/Ear.c.o
Client/Julius/libEar.a: Client/Julius/CMakeFiles/Ear.dir/build.make
Client/Julius/libEar.a: Client/Julius/CMakeFiles/Ear.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libEar.a"
	cd /home/inspiration/samson/puspa/bin/Client/Julius && $(CMAKE_COMMAND) -P CMakeFiles/Ear.dir/cmake_clean_target.cmake
	cd /home/inspiration/samson/puspa/bin/Client/Julius && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ear.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/Julius/CMakeFiles/Ear.dir/build: Client/Julius/libEar.a
.PHONY : Client/Julius/CMakeFiles/Ear.dir/build

Client/Julius/CMakeFiles/Ear.dir/requires: Client/Julius/CMakeFiles/Ear.dir/Ear.c.o.requires
.PHONY : Client/Julius/CMakeFiles/Ear.dir/requires

Client/Julius/CMakeFiles/Ear.dir/clean:
	cd /home/inspiration/samson/puspa/bin/Client/Julius && $(CMAKE_COMMAND) -P CMakeFiles/Ear.dir/cmake_clean.cmake
.PHONY : Client/Julius/CMakeFiles/Ear.dir/clean

Client/Julius/CMakeFiles/Ear.dir/depend:
	cd /home/inspiration/samson/puspa/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inspiration/samson/puspa /home/inspiration/samson/puspa/Client/Julius /home/inspiration/samson/puspa/bin /home/inspiration/samson/puspa/bin/Client/Julius /home/inspiration/samson/puspa/bin/Client/Julius/CMakeFiles/Ear.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/Julius/CMakeFiles/Ear.dir/depend
