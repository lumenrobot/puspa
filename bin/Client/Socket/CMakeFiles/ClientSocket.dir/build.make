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
include Client/Socket/CMakeFiles/ClientSocket.dir/depend.make

# Include the progress variables for this target.
include Client/Socket/CMakeFiles/ClientSocket.dir/progress.make

# Include the compile flags for this target's objects.
include Client/Socket/CMakeFiles/ClientSocket.dir/flags.make

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o: Client/Socket/CMakeFiles/ClientSocket.dir/flags.make
Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o: ../Client/Socket/ClientSocket.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/inspiration/samson/puspa/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o"
	cd /home/inspiration/samson/puspa/bin/Client/Socket && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ClientSocket.dir/ClientSocket.cc.o -c /home/inspiration/samson/puspa/Client/Socket/ClientSocket.cc

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClientSocket.dir/ClientSocket.cc.i"
	cd /home/inspiration/samson/puspa/bin/Client/Socket && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/inspiration/samson/puspa/Client/Socket/ClientSocket.cc > CMakeFiles/ClientSocket.dir/ClientSocket.cc.i

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClientSocket.dir/ClientSocket.cc.s"
	cd /home/inspiration/samson/puspa/bin/Client/Socket && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/inspiration/samson/puspa/Client/Socket/ClientSocket.cc -o CMakeFiles/ClientSocket.dir/ClientSocket.cc.s

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.requires:
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.requires

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.provides: Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.requires
	$(MAKE) -f Client/Socket/CMakeFiles/ClientSocket.dir/build.make Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.provides.build
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.provides

Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.provides.build: Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.provides.build

# Object files for target ClientSocket
ClientSocket_OBJECTS = \
"CMakeFiles/ClientSocket.dir/ClientSocket.cc.o"

# External object files for target ClientSocket
ClientSocket_EXTERNAL_OBJECTS =

Client/Socket/libClientSocket.a: Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o
Client/Socket/libClientSocket.a: Client/Socket/CMakeFiles/ClientSocket.dir/build.make
Client/Socket/libClientSocket.a: Client/Socket/CMakeFiles/ClientSocket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libClientSocket.a"
	cd /home/inspiration/samson/puspa/bin/Client/Socket && $(CMAKE_COMMAND) -P CMakeFiles/ClientSocket.dir/cmake_clean_target.cmake
	cd /home/inspiration/samson/puspa/bin/Client/Socket && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClientSocket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/Socket/CMakeFiles/ClientSocket.dir/build: Client/Socket/libClientSocket.a
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/build

Client/Socket/CMakeFiles/ClientSocket.dir/requires: Client/Socket/CMakeFiles/ClientSocket.dir/ClientSocket.cc.o.requires
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/requires

Client/Socket/CMakeFiles/ClientSocket.dir/clean:
	cd /home/inspiration/samson/puspa/bin/Client/Socket && $(CMAKE_COMMAND) -P CMakeFiles/ClientSocket.dir/cmake_clean.cmake
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/clean

Client/Socket/CMakeFiles/ClientSocket.dir/depend:
	cd /home/inspiration/samson/puspa/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inspiration/samson/puspa /home/inspiration/samson/puspa/Client/Socket /home/inspiration/samson/puspa/bin /home/inspiration/samson/puspa/bin/Client/Socket /home/inspiration/samson/puspa/bin/Client/Socket/CMakeFiles/ClientSocket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/Socket/CMakeFiles/ClientSocket.dir/depend
