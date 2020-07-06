# Executable

This is the executable that links against the library. You first need to build and install the library.

## Installing Conan packages
Install the missing packages using Conan. This installs the required files into the build directory

```bash
cd executable
mkdir build && cd build
conan install ../../conan/ --build missing
```

Since the libraries were already built/installed, when building the library, this will only install the required ***conanbuildinfo.cmake*** file.

## Building

After this, when configuring the executable in CMake, the variable ***Library_DIR*** needs to be set so that it points to the directory
where the file ***LibraryConfig.cmake*** resides, inside the directory where the library was installed.
Note that when building, the build type (Release, Debug, etc.), needs to match the one defined in the conanfile.txt.