# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = D:/CMake/bin/cmake.exe

# The command to remove a file.
RM = D:/CMake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/HUAWEI/Desktop/reportFile/test-8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/HUAWEI/Desktop/reportFile/test-8/build

# Include any dependencies generated for this target.
include CMakeFiles/arrayList.cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/arrayList.cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/arrayList.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrayList.cpp.dir/flags.make

CMakeFiles/arrayList.cpp.dir/demo.cpp.obj: CMakeFiles/arrayList.cpp.dir/flags.make
CMakeFiles/arrayList.cpp.dir/demo.cpp.obj: ../demo.cpp
CMakeFiles/arrayList.cpp.dir/demo.cpp.obj: CMakeFiles/arrayList.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/HUAWEI/Desktop/reportFile/test-8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arrayList.cpp.dir/demo.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/arrayList.cpp.dir/demo.cpp.obj -MF CMakeFiles/arrayList.cpp.dir/demo.cpp.obj.d -o CMakeFiles/arrayList.cpp.dir/demo.cpp.obj -c C:/Users/HUAWEI/Desktop/reportFile/test-8/demo.cpp

CMakeFiles/arrayList.cpp.dir/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrayList.cpp.dir/demo.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/HUAWEI/Desktop/reportFile/test-8/demo.cpp > CMakeFiles/arrayList.cpp.dir/demo.cpp.i

CMakeFiles/arrayList.cpp.dir/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrayList.cpp.dir/demo.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/HUAWEI/Desktop/reportFile/test-8/demo.cpp -o CMakeFiles/arrayList.cpp.dir/demo.cpp.s

# Object files for target arrayList.cpp
arrayList_cpp_OBJECTS = \
"CMakeFiles/arrayList.cpp.dir/demo.cpp.obj"

# External object files for target arrayList.cpp
arrayList_cpp_EXTERNAL_OBJECTS =

arrayList.cpp.exe: CMakeFiles/arrayList.cpp.dir/demo.cpp.obj
arrayList.cpp.exe: CMakeFiles/arrayList.cpp.dir/build.make
arrayList.cpp.exe: CMakeFiles/arrayList.cpp.dir/linklibs.rsp
arrayList.cpp.exe: CMakeFiles/arrayList.cpp.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/HUAWEI/Desktop/reportFile/test-8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrayList.cpp.exe"
	D:/CMake/bin/cmake.exe -E rm -f CMakeFiles/arrayList.cpp.dir/objects.a
	C:/mingw64/bin/ar.exe qc CMakeFiles/arrayList.cpp.dir/objects.a @CMakeFiles/arrayList.cpp.dir/objects1.rsp
	C:/mingw64/bin/c++.exe -g -Wl,--whole-archive CMakeFiles/arrayList.cpp.dir/objects.a -Wl,--no-whole-archive -o arrayList.cpp.exe -Wl,--out-implib,libarrayList.cpp.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/arrayList.cpp.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/arrayList.cpp.dir/build: arrayList.cpp.exe
.PHONY : CMakeFiles/arrayList.cpp.dir/build

CMakeFiles/arrayList.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arrayList.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arrayList.cpp.dir/clean

CMakeFiles/arrayList.cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/HUAWEI/Desktop/reportFile/test-8 C:/Users/HUAWEI/Desktop/reportFile/test-8 C:/Users/HUAWEI/Desktop/reportFile/test-8/build C:/Users/HUAWEI/Desktop/reportFile/test-8/build C:/Users/HUAWEI/Desktop/reportFile/test-8/build/CMakeFiles/arrayList.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrayList.cpp.dir/depend
