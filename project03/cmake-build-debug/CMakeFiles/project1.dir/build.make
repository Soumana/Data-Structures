# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/ssylla's home/cs315Fall2019/project03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/InfixToPostfix.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/InfixToPostfix.cpp.o: ../InfixToPostfix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/InfixToPostfix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/InfixToPostfix.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/InfixToPostfix.cpp"

CMakeFiles/project1.dir/InfixToPostfix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/InfixToPostfix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/InfixToPostfix.cpp" > CMakeFiles/project1.dir/InfixToPostfix.cpp.i

CMakeFiles/project1.dir/InfixToPostfix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/InfixToPostfix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/InfixToPostfix.cpp" -o CMakeFiles/project1.dir/InfixToPostfix.cpp.s

CMakeFiles/project1.dir/main.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/main.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/main.cpp"

CMakeFiles/project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/main.cpp" > CMakeFiles/project1.dir/main.cpp.i

CMakeFiles/project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/main.cpp" -o CMakeFiles/project1.dir/main.cpp.s

CMakeFiles/project1.dir/Token.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Token.cpp.o: ../Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project1.dir/Token.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Token.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/Token.cpp"

CMakeFiles/project1.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Token.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/Token.cpp" > CMakeFiles/project1.dir/Token.cpp.i

CMakeFiles/project1.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Token.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/Token.cpp" -o CMakeFiles/project1.dir/Token.cpp.s

CMakeFiles/project1.dir/TokenIterator.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/TokenIterator.cpp.o: ../TokenIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project1.dir/TokenIterator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/TokenIterator.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/TokenIterator.cpp"

CMakeFiles/project1.dir/TokenIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/TokenIterator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/TokenIterator.cpp" > CMakeFiles/project1.dir/TokenIterator.cpp.i

CMakeFiles/project1.dir/TokenIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/TokenIterator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/TokenIterator.cpp" -o CMakeFiles/project1.dir/TokenIterator.cpp.s

CMakeFiles/project1.dir/Number.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Number.cpp.o: ../Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project1.dir/Number.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Number.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/Number.cpp"

CMakeFiles/project1.dir/Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Number.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/Number.cpp" > CMakeFiles/project1.dir/Number.cpp.i

CMakeFiles/project1.dir/Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Number.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/Number.cpp" -o CMakeFiles/project1.dir/Number.cpp.s

CMakeFiles/project1.dir/Tokenizer.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Tokenizer.cpp.o: ../Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project1.dir/Tokenizer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Tokenizer.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/Tokenizer.cpp"

CMakeFiles/project1.dir/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Tokenizer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/Tokenizer.cpp" > CMakeFiles/project1.dir/Tokenizer.cpp.i

CMakeFiles/project1.dir/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Tokenizer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/Tokenizer.cpp" -o CMakeFiles/project1.dir/Tokenizer.cpp.s

CMakeFiles/project1.dir/SymbolTable.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/SymbolTable.cpp.o: ../SymbolTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project1.dir/SymbolTable.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/SymbolTable.cpp.o -c "/Volumes/ssylla's home/cs315Fall2019/project03/SymbolTable.cpp"

CMakeFiles/project1.dir/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/SymbolTable.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/ssylla's home/cs315Fall2019/project03/SymbolTable.cpp" > CMakeFiles/project1.dir/SymbolTable.cpp.i

CMakeFiles/project1.dir/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/SymbolTable.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/ssylla's home/cs315Fall2019/project03/SymbolTable.cpp" -o CMakeFiles/project1.dir/SymbolTable.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/InfixToPostfix.cpp.o" \
"CMakeFiles/project1.dir/main.cpp.o" \
"CMakeFiles/project1.dir/Token.cpp.o" \
"CMakeFiles/project1.dir/TokenIterator.cpp.o" \
"CMakeFiles/project1.dir/Number.cpp.o" \
"CMakeFiles/project1.dir/Tokenizer.cpp.o" \
"CMakeFiles/project1.dir/SymbolTable.cpp.o"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1: CMakeFiles/project1.dir/InfixToPostfix.cpp.o
project1: CMakeFiles/project1.dir/main.cpp.o
project1: CMakeFiles/project1.dir/Token.cpp.o
project1: CMakeFiles/project1.dir/TokenIterator.cpp.o
project1: CMakeFiles/project1.dir/Number.cpp.o
project1: CMakeFiles/project1.dir/Tokenizer.cpp.o
project1: CMakeFiles/project1.dir/SymbolTable.cpp.o
project1: CMakeFiles/project1.dir/build.make
project1: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1

.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	cd "/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/ssylla's home/cs315Fall2019/project03" "/Volumes/ssylla's home/cs315Fall2019/project03" "/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug" "/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug" "/Volumes/ssylla's home/cs315Fall2019/project03/cmake-build-debug/CMakeFiles/project1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

