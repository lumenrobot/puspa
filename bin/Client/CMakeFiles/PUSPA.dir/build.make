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
include Client/CMakeFiles/PUSPA.dir/depend.make

# Include the progress variables for this target.
include Client/CMakeFiles/PUSPA.dir/progress.make

# Include the compile flags for this target's objects.
include Client/CMakeFiles/PUSPA.dir/flags.make

Client/CMakeFiles/PUSPA.dir/main.cc.o: Client/CMakeFiles/PUSPA.dir/flags.make
Client/CMakeFiles/PUSPA.dir/main.cc.o: ../Client/main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/inspiration/samson/puspa/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Client/CMakeFiles/PUSPA.dir/main.cc.o"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PUSPA.dir/main.cc.o -c /home/inspiration/samson/puspa/Client/main.cc

Client/CMakeFiles/PUSPA.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PUSPA.dir/main.cc.i"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/inspiration/samson/puspa/Client/main.cc > CMakeFiles/PUSPA.dir/main.cc.i

Client/CMakeFiles/PUSPA.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PUSPA.dir/main.cc.s"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/inspiration/samson/puspa/Client/main.cc -o CMakeFiles/PUSPA.dir/main.cc.s

Client/CMakeFiles/PUSPA.dir/main.cc.o.requires:
.PHONY : Client/CMakeFiles/PUSPA.dir/main.cc.o.requires

Client/CMakeFiles/PUSPA.dir/main.cc.o.provides: Client/CMakeFiles/PUSPA.dir/main.cc.o.requires
	$(MAKE) -f Client/CMakeFiles/PUSPA.dir/build.make Client/CMakeFiles/PUSPA.dir/main.cc.o.provides.build
.PHONY : Client/CMakeFiles/PUSPA.dir/main.cc.o.provides

Client/CMakeFiles/PUSPA.dir/main.cc.o.provides.build: Client/CMakeFiles/PUSPA.dir/main.cc.o
.PHONY : Client/CMakeFiles/PUSPA.dir/main.cc.o.provides.build

Client/CMakeFiles/PUSPA.dir/Agent.cc.o: Client/CMakeFiles/PUSPA.dir/flags.make
Client/CMakeFiles/PUSPA.dir/Agent.cc.o: ../Client/Agent.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/inspiration/samson/puspa/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Client/CMakeFiles/PUSPA.dir/Agent.cc.o"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PUSPA.dir/Agent.cc.o -c /home/inspiration/samson/puspa/Client/Agent.cc

Client/CMakeFiles/PUSPA.dir/Agent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PUSPA.dir/Agent.cc.i"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/inspiration/samson/puspa/Client/Agent.cc > CMakeFiles/PUSPA.dir/Agent.cc.i

Client/CMakeFiles/PUSPA.dir/Agent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PUSPA.dir/Agent.cc.s"
	cd /home/inspiration/samson/puspa/bin/Client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/inspiration/samson/puspa/Client/Agent.cc -o CMakeFiles/PUSPA.dir/Agent.cc.s

Client/CMakeFiles/PUSPA.dir/Agent.cc.o.requires:
.PHONY : Client/CMakeFiles/PUSPA.dir/Agent.cc.o.requires

Client/CMakeFiles/PUSPA.dir/Agent.cc.o.provides: Client/CMakeFiles/PUSPA.dir/Agent.cc.o.requires
	$(MAKE) -f Client/CMakeFiles/PUSPA.dir/build.make Client/CMakeFiles/PUSPA.dir/Agent.cc.o.provides.build
.PHONY : Client/CMakeFiles/PUSPA.dir/Agent.cc.o.provides

Client/CMakeFiles/PUSPA.dir/Agent.cc.o.provides.build: Client/CMakeFiles/PUSPA.dir/Agent.cc.o
.PHONY : Client/CMakeFiles/PUSPA.dir/Agent.cc.o.provides.build

# Object files for target PUSPA
PUSPA_OBJECTS = \
"CMakeFiles/PUSPA.dir/main.cc.o" \
"CMakeFiles/PUSPA.dir/Agent.cc.o"

# External object files for target PUSPA
PUSPA_EXTERNAL_OBJECTS =

Client/PUSPA: Client/CMakeFiles/PUSPA.dir/main.cc.o
Client/PUSPA: Client/CMakeFiles/PUSPA.dir/Agent.cc.o
Client/PUSPA: Client/eSpeak/libMouth.a
Client/PUSPA: Client/Julius/libEar.a
Client/PUSPA: Client/Socket/libClientSocket.a
Client/PUSPA: Common/libErrors.a
Client/PUSPA: Client/CMakeFiles/PUSPA.dir/build.make
Client/PUSPA: Client/CMakeFiles/PUSPA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable PUSPA"
	cd /home/inspiration/samson/puspa/bin/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PUSPA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/CMakeFiles/PUSPA.dir/build: Client/PUSPA
.PHONY : Client/CMakeFiles/PUSPA.dir/build

Client/CMakeFiles/PUSPA.dir/requires: Client/CMakeFiles/PUSPA.dir/main.cc.o.requires
Client/CMakeFiles/PUSPA.dir/requires: Client/CMakeFiles/PUSPA.dir/Agent.cc.o.requires
.PHONY : Client/CMakeFiles/PUSPA.dir/requires

Client/CMakeFiles/PUSPA.dir/clean:
	cd /home/inspiration/samson/puspa/bin/Client && $(CMAKE_COMMAND) -P CMakeFiles/PUSPA.dir/cmake_clean.cmake
.PHONY : Client/CMakeFiles/PUSPA.dir/clean

Client/CMakeFiles/PUSPA.dir/depend:
	cd /home/inspiration/samson/puspa/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inspiration/samson/puspa /home/inspiration/samson/puspa/Client /home/inspiration/samson/puspa/bin /home/inspiration/samson/puspa/bin/Client /home/inspiration/samson/puspa/bin/Client/CMakeFiles/PUSPA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/CMakeFiles/PUSPA.dir/depend

