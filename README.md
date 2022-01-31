This repo is for personal use for practicing SDL2. It is an open source clone of the game ['Wordle'](https://www.powerlanguage.co.uk/wordle/).

## Installation

### MSYS2

Download and Install MSYS2 from https://www.msys2.org/ and follow the instructions for basic setup. A breakdown of the setup is:
1. Install MSYS2 under C:/msys64 (should be default location)
2. Run MSYS and enter the command `pacman -Syu`
3. Re-run MSYS and enter the command `pacman -Su`
4. Install mingw64 toolchain by entering the command `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`
5. Install GLFW by entering the command `pacman -S mingw-w64-x86_64-glfw`
6. Add `C:/msys64/mingw64/bin` to the Path environment variable to use mingw commands in cmd.
7. Install SDL2_ttf (and SDL2) using the command `pacman -S mingw-w64-x86_64-SDL2_ttf`

Following these steps installs gcc, g++, and gdb for compiling and debugging C/C++ programs as well as SDL2, SDL2_ttf

### GLAD

Go to https://glad.dav1d.de/ and enter the following fields:

Language = C/C++
Specification = OpenGL
API.gl = latest (version 4.6 currently)
Profile = Core

Then click 'Generate'. On the following page, download glad.zip and extract it to `C:/GLAD`

