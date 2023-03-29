[![Linux](https://github.com/JarnoRalli/conan-example/actions/workflows/ubuntu_build.yml/badge.svg)](https://github.com/JarnoRalli/conan-example/actions/workflows/ubuntu_build.yml)   [![Win64](https://github.com/JarnoRalli/conan-example/actions/workflows/visual_studio_build.yml/badge.svg)](https://github.com/JarnoRalli/conan-example/actions/workflows/visual_studio_build.yml)

# Conan Example

This example shows how to create a C++ library, using a modern flavour of [CMake](https://cmake.org/) as the build system, that links against a 3rd party library, 
[OpenCV](https://github.com/opencv/opencv) in this case, using a **package manager** called [Conan](https://conan.io/). The example also shows how to export and install the library, 
and link an executable against it.

# 1 CMake

CMake is a pseudo-build system, meaning that it needs an actual build system to actually build the project. Such a concrete build system can be, for example:

* [GNU Make](https://www.gnu.org/software/make/)
* [Ninja](https://ninja-build.org/)
* [Visual Studio's MSBuild](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild?view=vs-2022)

What this means in practice is that if you write the build system using CMake, you can build your project easily in Linux or Windows using Visual Studio for example.

# 2 Conan Package Manager

C++ itself doesn't currently have a native package manager. What this means is that if you want to link your code against a library that someone else has written,
you need to build that library. If your own code and the 3rd party library both use the same build system, like CMake, then using the external library is not
that difficult. However, if the build systems are different, then it becomes slightly trickier. Also, maintaining different versions of the same library, built
with different compilers and different compiler switches, needs to be taken care of. In this example we use a package manager called Conan that can solve
the problems mentioned above.

## 2.1 Conan and CMake Integration

Conan can be integrated into CMake using so called generators. Generators define what kinds of files are generated by Conan packaged and how these
integrate into the build system. In this example we use a generator called [cmake_find_package_multi](https://docs.conan.io/1/reference/generators/cmake_find_package_multi.html).
This generator installs CMake configuration files for each Conan package, in the chosen directory, allowing the packages to be found using
[find_package](https://cmake.org/cmake/help/latest/command/find_package.html) in `CONFIG` mode. This is the least intrusive way of using Conan with CMake, i.e. CMake is not aware of Conan in any way.

# 3 How to Build

You first need to build and install the [library](library/README.md), and after that build the [executable](executable/README.md) and link against the library.

