# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bolidnik/Programs/Cpp_SFML_Game_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bolidnik/Programs/Cpp_SFML_Game_Engine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/bolidnik/Programs/Cpp_SFML_Game_Engine/CMakeFiles /home/bolidnik/Programs/Cpp_SFML_Game_Engine//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/bolidnik/Programs/Cpp_SFML_Game_Engine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

src/AnimationManager.o: src/AnimationManager.cpp.o
.PHONY : src/AnimationManager.o

# target to build an object file
src/AnimationManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/AnimationManager.cpp.o
.PHONY : src/AnimationManager.cpp.o

src/AnimationManager.i: src/AnimationManager.cpp.i
.PHONY : src/AnimationManager.i

# target to preprocess a source file
src/AnimationManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/AnimationManager.cpp.i
.PHONY : src/AnimationManager.cpp.i

src/AnimationManager.s: src/AnimationManager.cpp.s
.PHONY : src/AnimationManager.s

# target to generate assembly for a file
src/AnimationManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/AnimationManager.cpp.s
.PHONY : src/AnimationManager.cpp.s

src/ColorIDMap.o: src/ColorIDMap.cpp.o
.PHONY : src/ColorIDMap.o

# target to build an object file
src/ColorIDMap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ColorIDMap.cpp.o
.PHONY : src/ColorIDMap.cpp.o

src/ColorIDMap.i: src/ColorIDMap.cpp.i
.PHONY : src/ColorIDMap.i

# target to preprocess a source file
src/ColorIDMap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ColorIDMap.cpp.i
.PHONY : src/ColorIDMap.cpp.i

src/ColorIDMap.s: src/ColorIDMap.cpp.s
.PHONY : src/ColorIDMap.s

# target to generate assembly for a file
src/ColorIDMap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ColorIDMap.cpp.s
.PHONY : src/ColorIDMap.cpp.s

src/Layers.o: src/Layers.cpp.o
.PHONY : src/Layers.o

# target to build an object file
src/Layers.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Layers.cpp.o
.PHONY : src/Layers.cpp.o

src/Layers.i: src/Layers.cpp.i
.PHONY : src/Layers.i

# target to preprocess a source file
src/Layers.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Layers.cpp.i
.PHONY : src/Layers.cpp.i

src/Layers.s: src/Layers.cpp.s
.PHONY : src/Layers.s

# target to generate assembly for a file
src/Layers.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Layers.cpp.s
.PHONY : src/Layers.cpp.s

src/MusicSystem.o: src/MusicSystem.cpp.o
.PHONY : src/MusicSystem.o

# target to build an object file
src/MusicSystem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/MusicSystem.cpp.o
.PHONY : src/MusicSystem.cpp.o

src/MusicSystem.i: src/MusicSystem.cpp.i
.PHONY : src/MusicSystem.i

# target to preprocess a source file
src/MusicSystem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/MusicSystem.cpp.i
.PHONY : src/MusicSystem.cpp.i

src/MusicSystem.s: src/MusicSystem.cpp.s
.PHONY : src/MusicSystem.s

# target to generate assembly for a file
src/MusicSystem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/MusicSystem.cpp.s
.PHONY : src/MusicSystem.cpp.s

src/Node.o: src/Node.cpp.o
.PHONY : src/Node.o

# target to build an object file
src/Node.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Node.cpp.o
.PHONY : src/Node.cpp.o

src/Node.i: src/Node.cpp.i
.PHONY : src/Node.i

# target to preprocess a source file
src/Node.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Node.cpp.i
.PHONY : src/Node.cpp.i

src/Node.s: src/Node.cpp.s
.PHONY : src/Node.s

# target to generate assembly for a file
src/Node.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Node.cpp.s
.PHONY : src/Node.cpp.s

src/SoundSystem.o: src/SoundSystem.cpp.o
.PHONY : src/SoundSystem.o

# target to build an object file
src/SoundSystem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/SoundSystem.cpp.o
.PHONY : src/SoundSystem.cpp.o

src/SoundSystem.i: src/SoundSystem.cpp.i
.PHONY : src/SoundSystem.i

# target to preprocess a source file
src/SoundSystem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/SoundSystem.cpp.i
.PHONY : src/SoundSystem.cpp.i

src/SoundSystem.s: src/SoundSystem.cpp.s
.PHONY : src/SoundSystem.s

# target to generate assembly for a file
src/SoundSystem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/SoundSystem.cpp.s
.PHONY : src/SoundSystem.cpp.s

src/Standard/Math/transforms.o: src/Standard/Math/transforms.cpp.o
.PHONY : src/Standard/Math/transforms.o

# target to build an object file
src/Standard/Math/transforms.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Standard/Math/transforms.cpp.o
.PHONY : src/Standard/Math/transforms.cpp.o

src/Standard/Math/transforms.i: src/Standard/Math/transforms.cpp.i
.PHONY : src/Standard/Math/transforms.i

# target to preprocess a source file
src/Standard/Math/transforms.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Standard/Math/transforms.cpp.i
.PHONY : src/Standard/Math/transforms.cpp.i

src/Standard/Math/transforms.s: src/Standard/Math/transforms.cpp.s
.PHONY : src/Standard/Math/transforms.s

# target to generate assembly for a file
src/Standard/Math/transforms.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Standard/Math/transforms.cpp.s
.PHONY : src/Standard/Math/transforms.cpp.s

src/TestAnimatedCircle.o: src/TestAnimatedCircle.cpp.o
.PHONY : src/TestAnimatedCircle.o

# target to build an object file
src/TestAnimatedCircle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TestAnimatedCircle.cpp.o
.PHONY : src/TestAnimatedCircle.cpp.o

src/TestAnimatedCircle.i: src/TestAnimatedCircle.cpp.i
.PHONY : src/TestAnimatedCircle.i

# target to preprocess a source file
src/TestAnimatedCircle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TestAnimatedCircle.cpp.i
.PHONY : src/TestAnimatedCircle.cpp.i

src/TestAnimatedCircle.s: src/TestAnimatedCircle.cpp.s
.PHONY : src/TestAnimatedCircle.s

# target to generate assembly for a file
src/TestAnimatedCircle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TestAnimatedCircle.cpp.s
.PHONY : src/TestAnimatedCircle.cpp.s

src/TextureLoader.o: src/TextureLoader.cpp.o
.PHONY : src/TextureLoader.o

# target to build an object file
src/TextureLoader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoader.cpp.o
.PHONY : src/TextureLoader.cpp.o

src/TextureLoader.i: src/TextureLoader.cpp.i
.PHONY : src/TextureLoader.i

# target to preprocess a source file
src/TextureLoader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoader.cpp.i
.PHONY : src/TextureLoader.cpp.i

src/TextureLoader.s: src/TextureLoader.cpp.s
.PHONY : src/TextureLoader.s

# target to generate assembly for a file
src/TextureLoader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoader.cpp.s
.PHONY : src/TextureLoader.cpp.s

src/TextureLoaderPrototypeFactory.o: src/TextureLoaderPrototypeFactory.cpp.o
.PHONY : src/TextureLoaderPrototypeFactory.o

# target to build an object file
src/TextureLoaderPrototypeFactory.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoaderPrototypeFactory.cpp.o
.PHONY : src/TextureLoaderPrototypeFactory.cpp.o

src/TextureLoaderPrototypeFactory.i: src/TextureLoaderPrototypeFactory.cpp.i
.PHONY : src/TextureLoaderPrototypeFactory.i

# target to preprocess a source file
src/TextureLoaderPrototypeFactory.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoaderPrototypeFactory.cpp.i
.PHONY : src/TextureLoaderPrototypeFactory.cpp.i

src/TextureLoaderPrototypeFactory.s: src/TextureLoaderPrototypeFactory.cpp.s
.PHONY : src/TextureLoaderPrototypeFactory.s

# target to generate assembly for a file
src/TextureLoaderPrototypeFactory.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TextureLoaderPrototypeFactory.cpp.s
.PHONY : src/TextureLoaderPrototypeFactory.cpp.s

src/engine.o: src/engine.cpp.o
.PHONY : src/engine.o

# target to build an object file
src/engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine.cpp.o
.PHONY : src/engine.cpp.o

src/engine.i: src/engine.cpp.i
.PHONY : src/engine.i

# target to preprocess a source file
src/engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine.cpp.i
.PHONY : src/engine.cpp.i

src/engine.s: src/engine.cpp.s
.PHONY : src/engine.s

# target to generate assembly for a file
src/engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine.cpp.s
.PHONY : src/engine.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... src/AnimationManager.o"
	@echo "... src/AnimationManager.i"
	@echo "... src/AnimationManager.s"
	@echo "... src/ColorIDMap.o"
	@echo "... src/ColorIDMap.i"
	@echo "... src/ColorIDMap.s"
	@echo "... src/Layers.o"
	@echo "... src/Layers.i"
	@echo "... src/Layers.s"
	@echo "... src/MusicSystem.o"
	@echo "... src/MusicSystem.i"
	@echo "... src/MusicSystem.s"
	@echo "... src/Node.o"
	@echo "... src/Node.i"
	@echo "... src/Node.s"
	@echo "... src/SoundSystem.o"
	@echo "... src/SoundSystem.i"
	@echo "... src/SoundSystem.s"
	@echo "... src/Standard/Math/transforms.o"
	@echo "... src/Standard/Math/transforms.i"
	@echo "... src/Standard/Math/transforms.s"
	@echo "... src/TestAnimatedCircle.o"
	@echo "... src/TestAnimatedCircle.i"
	@echo "... src/TestAnimatedCircle.s"
	@echo "... src/TextureLoader.o"
	@echo "... src/TextureLoader.i"
	@echo "... src/TextureLoader.s"
	@echo "... src/TextureLoaderPrototypeFactory.o"
	@echo "... src/TextureLoaderPrototypeFactory.i"
	@echo "... src/TextureLoaderPrototypeFactory.s"
	@echo "... src/engine.o"
	@echo "... src/engine.i"
	@echo "... src/engine.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

