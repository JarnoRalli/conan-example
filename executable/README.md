# Executable

This is an executable that links against the library we built previously. You can build the executable as follows:

```bash
cd executable
mkdir build
cd build
conan install ../conan --build=missing
cmake-gui ..
```

When you execute `cmake-gui ..`, you will get an error message saying that the `LibraryConfig.cmake` is not found. This is due to the
fact that CMake cannot, by default, find the directory where you installed the library. You need to set the CMake variable `Library_DIR` 
so that it points to `<path-to-the-installed-library>/lib/cmake/Library`. This is the directory where the file `LibraryConfig.cmake` resides.
After that you can build the executable by running the following from the `build` directory:

```bash
make
```

