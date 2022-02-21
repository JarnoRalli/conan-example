# conan-example
This example shows how to create a library that links against a 3rd party library, OpenCV in this case, using Conan. The example also shows how to export and install
the library, and link an executable against it.

# Build Status

[![Build and Test](https://github.com/JarnoRalli/conan-example/actions/workflows/build.yml/badge.svg)](https://github.com/JarnoRalli/conan-example/actions/workflows/build.yml)

## Conan Generators
This example shows how to use Conan
<a href="https://docs.conan.io/en/latest/reference/generators/cmake_find_package_multi.html" target="_blank">cmake_find_package_multi</a>
generator to install packages, and how to discover these. Long story short, `cmake_find_package_multi` generator
installs configuration files that allows for the packages to be discovered using CMake's 
<a href="https://cmake.org/cmake/help/latest/command/find_package.html" target="_blank">find_package</a>  in `CONFIG` mode.
This is the least intrusive way of using Conan with CMake, i.e. CMake is not aware of Conan in any way.

## How to Build

You first need to build and install the [library](library/README.md), and after that build the [executable](executable/README.md) and link against the library.

