# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/ssylla/cs315Fall2019/Lab01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/ssylla/cs315Fall2019/Lab01

# Include any dependencies generated for this target.
include CMakeFiles/lab01_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab01_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab01_2.dir/flags.make

CMakeFiles/lab01_2.dir/main.cpp.o: CMakeFiles/lab01_2.dir/flags.make
CMakeFiles/lab01_2.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab01_2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab01_2.dir/main.cpp.o -c /home/student/ssylla/cs315Fall2019/Lab01/main.cpp

CMakeFiles/lab01_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab01_2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/ssylla/cs315Fall2019/Lab01/main.cpp > CMakeFiles/lab01_2.dir/main.cpp.i

CMakeFiles/lab01_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab01_2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/ssylla/cs315Fall2019/Lab01/main.cpp -o CMakeFiles/lab01_2.dir/main.cpp.s

CMakeFiles/lab01_2.dir/Token.cpp.o: CMakeFiles/lab01_2.dir/flags.make
CMakeFiles/lab01_2.dir/Token.cpp.o: Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab01_2.dir/Token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab01_2.dir/Token.cpp.o -c /home/student/ssylla/cs315Fall2019/Lab01/Token.cpp

CMakeFiles/lab01_2.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab01_2.dir/Token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/ssylla/cs315Fall2019/Lab01/Token.cpp > CMakeFiles/lab01_2.dir/Token.cpp.i

CMakeFiles/lab01_2.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab01_2.dir/Token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/ssylla/cs315Fall2019/Lab01/Token.cpp -o CMakeFiles/lab01_2.dir/Token.cpp.s

CMakeFiles/lab01_2.dir/Tokenizer.cpp.o: CMakeFiles/lab01_2.dir/flags.make
CMakeFiles/lab01_2.dir/Tokenizer.cpp.o: Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab01_2.dir/Tokenizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab01_2.dir/Tokenizer.cpp.o -c /home/student/ssylla/cs315Fall2019/Lab01/Tokenizer.cpp

CMakeFiles/lab01_2.dir/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab01_2.dir/Tokenizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/ssylla/cs315Fall2019/Lab01/Tokenizer.cpp > CMakeFiles/lab01_2.dir/Tokenizer.cpp.i

CMakeFiles/lab01_2.dir/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab01_2.dir/Tokenizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/ssylla/cs315Fall2019/Lab01/Tokenizer.cpp -o CMakeFiles/lab01_2.dir/Tokenizer.cpp.s

CMakeFiles/lab01_2.dir/TagParser.cpp.o: CMakeFiles/lab01_2.dir/flags.make
CMakeFiles/lab01_2.dir/TagParser.cpp.o: TagParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab01_2.dir/TagParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab01_2.dir/TagParser.cpp.o -c /home/student/ssylla/cs315Fall2019/Lab01/TagParser.cpp

CMakeFiles/lab01_2.dir/TagParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab01_2.dir/TagParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/ssylla/cs315Fall2019/Lab01/TagParser.cpp > CMakeFiles/lab01_2.dir/TagParser.cpp.i

CMakeFiles/lab01_2.dir/TagParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab01_2.dir/TagParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/ssylla/cs315Fall2019/Lab01/TagParser.cpp -o CMakeFiles/lab01_2.dir/TagParser.cpp.s

# Object files for target lab01_2
lab01_2_OBJECTS = \
"CMakeFiles/lab01_2.dir/main.cpp.o" \
"CMakeFiles/lab01_2.dir/Token.cpp.o" \
"CMakeFiles/lab01_2.dir/Tokenizer.cpp.o" \
"CMakeFiles/lab01_2.dir/TagParser.cpp.o"

# External object files for target lab01_2
lab01_2_EXTERNAL_OBJECTS =

lab01_2: CMakeFiles/lab01_2.dir/main.cpp.o
lab01_2: CMakeFiles/lab01_2.dir/Token.cpp.o
lab01_2: CMakeFiles/lab01_2.dir/Tokenizer.cpp.o
lab01_2: CMakeFiles/lab01_2.dir/TagParser.cpp.o
lab01_2: CMakeFiles/lab01_2.dir/build.make
lab01_2: CMakeFiles/lab01_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable lab01_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab01_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab01_2.dir/build: lab01_2

.PHONY : CMakeFiles/lab01_2.dir/build

CMakeFiles/lab01_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab01_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab01_2.dir/clean

CMakeFiles/lab01_2.dir/depend:
	cd /home/student/ssylla/cs315Fall2019/Lab01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/ssylla/cs315Fall2019/Lab01 /home/student/ssylla/cs315Fall2019/Lab01 /home/student/ssylla/cs315Fall2019/Lab01 /home/student/ssylla/cs315Fall2019/Lab01 /home/student/ssylla/cs315Fall2019/Lab01/CMakeFiles/lab01_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab01_2.dir/depend

