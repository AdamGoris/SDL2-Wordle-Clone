This repo is for personal use for practicing/learning SDL2.

## Installation

### MSYS2

Download and Install MSYS2 from https://www.msys2.org/ and follow the instructions for basic setup. A breakdown of the setup is:
1. Install MSYS2 under C:/msys64 (should be default location)
2. Run MSYS and enter the command `pacman -Syu`
3. Re-run MSYS and enter the command `pacman -Su`
4. Install mingw64 toolchain by entering the command `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`
5. Install GLFW by entering the command `pacman -S mingw-w64-x86_64-glfw`
6. Optional: Add `C:/msys64/mingw64/bin` to the Path environment variable to use mingw commands in cmd.

Following these steps installs gcc, g++, and gdb for compiling and debugging C/C++ programs.

### SDL2

Go to https://www.libsdl.org/download-2.0.php
Download and install the Windows 64 Runtime Binaries and the Development Libraries.

Extract both zips to `C:/SDL2`
Rename the runtime binaries folder to `SDL2-2.0.20`
Rename the development libraries folder to `SDL2-devel-2.0.20` 

### GLAD

Go to https://glad.dav1d.de/ and enter the following fields:

Language = C/C++
Specification = OpenGL
API.gl = latest (version 4.6 currently)
Profile = Core

Then click 'Generate'. On the following page, download glad.zip and extract it to `C:/GLAD`

