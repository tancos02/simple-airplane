# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/paulus/Tugas/GrafKom/simple-airplane

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paulus/Tugas/GrafKom/simple-airplane/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/Model.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Model.cpp.o -c /home/paulus/Tugas/GrafKom/simple-airplane/src/Model.cpp

CMakeFiles/main.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulus/Tugas/GrafKom/simple-airplane/src/Model.cpp > CMakeFiles/main.dir/src/Model.cpp.i

CMakeFiles/main.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulus/Tugas/GrafKom/simple-airplane/src/Model.cpp -o CMakeFiles/main.dir/src/Model.cpp.s

CMakeFiles/main.dir/src/Model.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/Model.cpp.o.requires

CMakeFiles/main.dir/src/Model.cpp.o.provides: CMakeFiles/main.dir/src/Model.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Model.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/Model.cpp.o.provides

CMakeFiles/main.dir/src/Model.cpp.o.provides.build: CMakeFiles/main.dir/src/Model.cpp.o


CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/paulus/Tugas/GrafKom/simple-airplane/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulus/Tugas/GrafKom/simple-airplane/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulus/Tugas/GrafKom/simple-airplane/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/main.cpp.o.requires

CMakeFiles/main.dir/src/main.cpp.o.provides: CMakeFiles/main.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/main.cpp.o.provides

CMakeFiles/main.dir/src/main.cpp.o.provides.build: CMakeFiles/main.dir/src/main.cpp.o


CMakeFiles/main.dir/common/shader.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/common/shader.cpp.o: ../common/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/common/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/common/shader.cpp.o -c /home/paulus/Tugas/GrafKom/simple-airplane/common/shader.cpp

CMakeFiles/main.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/common/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulus/Tugas/GrafKom/simple-airplane/common/shader.cpp > CMakeFiles/main.dir/common/shader.cpp.i

CMakeFiles/main.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/common/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulus/Tugas/GrafKom/simple-airplane/common/shader.cpp -o CMakeFiles/main.dir/common/shader.cpp.s

CMakeFiles/main.dir/common/shader.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/common/shader.cpp.o.requires

CMakeFiles/main.dir/common/shader.cpp.o.provides: CMakeFiles/main.dir/common/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/common/shader.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/common/shader.cpp.o.provides

CMakeFiles/main.dir/common/shader.cpp.o.provides.build: CMakeFiles/main.dir/common/shader.cpp.o


CMakeFiles/main.dir/common/controls.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/common/controls.cpp.o: ../common/controls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/common/controls.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/common/controls.cpp.o -c /home/paulus/Tugas/GrafKom/simple-airplane/common/controls.cpp

CMakeFiles/main.dir/common/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/common/controls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulus/Tugas/GrafKom/simple-airplane/common/controls.cpp > CMakeFiles/main.dir/common/controls.cpp.i

CMakeFiles/main.dir/common/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/common/controls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulus/Tugas/GrafKom/simple-airplane/common/controls.cpp -o CMakeFiles/main.dir/common/controls.cpp.s

CMakeFiles/main.dir/common/controls.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/common/controls.cpp.o.requires

CMakeFiles/main.dir/common/controls.cpp.o.provides: CMakeFiles/main.dir/common/controls.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/common/controls.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/common/controls.cpp.o.provides

CMakeFiles/main.dir/common/controls.cpp.o.provides.build: CMakeFiles/main.dir/common/controls.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/Model.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/common/shader.cpp.o" \
"CMakeFiles/main.dir/common/controls.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/Model.cpp.o
main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/common/shader.cpp.o
main: CMakeFiles/main.dir/common/controls.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib/x86_64-linux-gnu/libGL.so
main: /usr/lib/x86_64-linux-gnu/libGLU.so
main: external/glfw-3.1.2/src/libglfw3.a
main: external/libGLEW_1130.a
main: /usr/lib/x86_64-linux-gnu/librt.so
main: /usr/lib/x86_64-linux-gnu/libm.so
main: /usr/lib/x86_64-linux-gnu/libX11.so
main: /usr/lib/x86_64-linux-gnu/libXrandr.so
main: /usr/lib/x86_64-linux-gnu/libXinerama.so
main: /usr/lib/x86_64-linux-gnu/libXi.so
main: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
main: /usr/lib/x86_64-linux-gnu/libXcursor.so
main: /usr/lib/x86_64-linux-gnu/librt.so
main: /usr/lib/x86_64-linux-gnu/libm.so
main: /usr/lib/x86_64-linux-gnu/libX11.so
main: /usr/lib/x86_64-linux-gnu/libXrandr.so
main: /usr/lib/x86_64-linux-gnu/libXinerama.so
main: /usr/lib/x86_64-linux-gnu/libXi.so
main: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
main: /usr/lib/x86_64-linux-gnu/libXcursor.so
main: /usr/lib/x86_64-linux-gnu/libGL.so
main: /usr/lib/x86_64-linux-gnu/libGLU.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /home/paulus/Tugas/GrafKom/simple-airplane/build/./main /home/paulus/Tugas/GrafKom/simple-airplane/src/

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/Model.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/common/shader.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/common/controls.cpp.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/paulus/Tugas/GrafKom/simple-airplane/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paulus/Tugas/GrafKom/simple-airplane /home/paulus/Tugas/GrafKom/simple-airplane /home/paulus/Tugas/GrafKom/simple-airplane/build /home/paulus/Tugas/GrafKom/simple-airplane/build /home/paulus/Tugas/GrafKom/simple-airplane/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

