# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release"

# Include any dependencies generated for this target.
include CMakeFiles/Generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Generator.dir/flags.make

CMakeFiles/Generator.dir/generator.cpp.obj: CMakeFiles/Generator.dir/flags.make
CMakeFiles/Generator.dir/generator.cpp.obj: ../generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Generator.dir/generator.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Generator.dir\generator.cpp.obj -c "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\generator.cpp"

CMakeFiles/Generator.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generator.dir/generator.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\generator.cpp" > CMakeFiles\Generator.dir\generator.cpp.i

CMakeFiles/Generator.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generator.dir/generator.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\generator.cpp" -o CMakeFiles\Generator.dir\generator.cpp.s

# Object files for target Generator
Generator_OBJECTS = \
"CMakeFiles/Generator.dir/generator.cpp.obj"

# External object files for target Generator
Generator_EXTERNAL_OBJECTS =

Generator.exe: CMakeFiles/Generator.dir/generator.cpp.obj
Generator.exe: CMakeFiles/Generator.dir/build.make
Generator.exe: CMakeFiles/Generator.dir/linklibs.rsp
Generator.exe: CMakeFiles/Generator.dir/objects1.rsp
Generator.exe: CMakeFiles/Generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Generator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Generator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Generator.dir/build: Generator.exe

.PHONY : CMakeFiles/Generator.dir/build

CMakeFiles/Generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Generator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Generator.dir/clean

CMakeFiles/Generator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator" "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator" "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release" "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release" "C:\Computacao Grafica\Projeto\CG2021\parte2\Generator\cmake-build-release\CMakeFiles\Generator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Generator.dir/depend

