# INSTALLATION INSTRUCTIONS

## Installing GLFW
Go to https://www.glfw.org/download.html and download the latest source package. Place this in the include directory at the root of the directory tree.

## Installing GLAD
Go to https://glad.dav1d.de/ make sure language is C/C++, Profile is core and gl API version is greater than 3.3

## Building
Start by constructing the build files with CMake

<code> cmake -S . -B build </code>

After this cd into the build directory

<code> make </code>

An executable will be make as ParticlePractice

<code> ./ParticlePractice </code>

