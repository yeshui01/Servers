# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tyh/project/TServerBaseEx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tyh/project/TServerBaseEx

# Include any dependencies generated for this target.
include Test/CMakeFiles/test.out.dir/depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/test.out.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/test.out.dir/flags.make

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o: Test/CMakeFiles/test.out.dir/flags.make
Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o: tlog/tboost_log.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tyh/project/TServerBaseEx/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o -c /home/tyh/project/TServerBaseEx/tlog/tboost_log.cpp

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.i"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tyh/project/TServerBaseEx/tlog/tboost_log.cpp > CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.i

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.s"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tyh/project/TServerBaseEx/tlog/tboost_log.cpp -o CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.s

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.requires:
.PHONY : Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.requires

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.provides: Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.requires
	$(MAKE) -f Test/CMakeFiles/test.out.dir/build.make Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.provides.build
.PHONY : Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.provides

Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.provides.build: Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o

Test/CMakeFiles/test.out.dir/main.cpp.o: Test/CMakeFiles/test.out.dir/flags.make
Test/CMakeFiles/test.out.dir/main.cpp.o: Test/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tyh/project/TServerBaseEx/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Test/CMakeFiles/test.out.dir/main.cpp.o"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.out.dir/main.cpp.o -c /home/tyh/project/TServerBaseEx/Test/main.cpp

Test/CMakeFiles/test.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.out.dir/main.cpp.i"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tyh/project/TServerBaseEx/Test/main.cpp > CMakeFiles/test.out.dir/main.cpp.i

Test/CMakeFiles/test.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.out.dir/main.cpp.s"
	cd /home/tyh/project/TServerBaseEx/Test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tyh/project/TServerBaseEx/Test/main.cpp -o CMakeFiles/test.out.dir/main.cpp.s

Test/CMakeFiles/test.out.dir/main.cpp.o.requires:
.PHONY : Test/CMakeFiles/test.out.dir/main.cpp.o.requires

Test/CMakeFiles/test.out.dir/main.cpp.o.provides: Test/CMakeFiles/test.out.dir/main.cpp.o.requires
	$(MAKE) -f Test/CMakeFiles/test.out.dir/build.make Test/CMakeFiles/test.out.dir/main.cpp.o.provides.build
.PHONY : Test/CMakeFiles/test.out.dir/main.cpp.o.provides

Test/CMakeFiles/test.out.dir/main.cpp.o.provides.build: Test/CMakeFiles/test.out.dir/main.cpp.o

# Object files for target test.out
test_out_OBJECTS = \
"CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o" \
"CMakeFiles/test.out.dir/main.cpp.o"

# External object files for target test.out
test_out_EXTERNAL_OBJECTS =

bin/test.out: Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o
bin/test.out: Test/CMakeFiles/test.out.dir/main.cpp.o
bin/test.out: Test/CMakeFiles/test.out.dir/build.make
bin/test.out: Test/CMakeFiles/test.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/test.out"
	cd /home/tyh/project/TServerBaseEx/Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/test.out.dir/build: bin/test.out
.PHONY : Test/CMakeFiles/test.out.dir/build

Test/CMakeFiles/test.out.dir/requires: Test/CMakeFiles/test.out.dir/__/tlog/tboost_log.cpp.o.requires
Test/CMakeFiles/test.out.dir/requires: Test/CMakeFiles/test.out.dir/main.cpp.o.requires
.PHONY : Test/CMakeFiles/test.out.dir/requires

Test/CMakeFiles/test.out.dir/clean:
	cd /home/tyh/project/TServerBaseEx/Test && $(CMAKE_COMMAND) -P CMakeFiles/test.out.dir/cmake_clean.cmake
.PHONY : Test/CMakeFiles/test.out.dir/clean

Test/CMakeFiles/test.out.dir/depend:
	cd /home/tyh/project/TServerBaseEx && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tyh/project/TServerBaseEx /home/tyh/project/TServerBaseEx/Test /home/tyh/project/TServerBaseEx /home/tyh/project/TServerBaseEx/Test /home/tyh/project/TServerBaseEx/Test/CMakeFiles/test.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/CMakeFiles/test.out.dir/depend

