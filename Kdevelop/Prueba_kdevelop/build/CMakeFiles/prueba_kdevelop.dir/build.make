# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build

# Include any dependencies generated for this target.
include CMakeFiles/prueba_kdevelop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prueba_kdevelop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prueba_kdevelop.dir/flags.make

CMakeFiles/prueba_kdevelop.dir/main.c.o: CMakeFiles/prueba_kdevelop.dir/flags.make
CMakeFiles/prueba_kdevelop.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prueba_kdevelop.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prueba_kdevelop.dir/main.c.o   -c /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/main.c

CMakeFiles/prueba_kdevelop.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prueba_kdevelop.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/main.c > CMakeFiles/prueba_kdevelop.dir/main.c.i

CMakeFiles/prueba_kdevelop.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prueba_kdevelop.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/main.c -o CMakeFiles/prueba_kdevelop.dir/main.c.s

# Object files for target prueba_kdevelop
prueba_kdevelop_OBJECTS = \
"CMakeFiles/prueba_kdevelop.dir/main.c.o"

# External object files for target prueba_kdevelop
prueba_kdevelop_EXTERNAL_OBJECTS =

prueba_kdevelop: CMakeFiles/prueba_kdevelop.dir/main.c.o
prueba_kdevelop: CMakeFiles/prueba_kdevelop.dir/build.make
prueba_kdevelop: CMakeFiles/prueba_kdevelop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable prueba_kdevelop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prueba_kdevelop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prueba_kdevelop.dir/build: prueba_kdevelop

.PHONY : CMakeFiles/prueba_kdevelop.dir/build

CMakeFiles/prueba_kdevelop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prueba_kdevelop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prueba_kdevelop.dir/clean

CMakeFiles/prueba_kdevelop.dir/depend:
	cd /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build /home/agustin/Repositorios-Git/Ejercicios-UTN--C--/Kdevelop/Prueba_kdevelop/build/CMakeFiles/prueba_kdevelop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prueba_kdevelop.dir/depend

