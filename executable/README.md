# Executable

This is the executable that links against the library. You first need to build and install the library.
After this, when configuring the executable in CMake, the variable ***Library_DIR*** needs to be set so that it points to the directory
where the file ***LibraryConfig.cmake*** resides, inside the directory where the library was installed. Also, the toolchain file (CMake)
needs to point to the same, or equivalent, toolchain file, named ***conan_paths.cmake***, that was used for building the library. Normally
this file is in the ***build*** directory.