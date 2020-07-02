# Library
Before building the library, you need to configure Conan, and then use Conan
to install the missing libraries.


## Configuring Conan
Configure Conan, i.e. generate a default profile. This is stored in a directory called **.conan**.

```bash
conan profile new default --detect  # Generates default profile detecting the system compiler
```

#### Installing Conan packages
Install the missing packages using Conan. This installs the required files into the build directory

```bash
cd library
mkdir build && cd build
conan install ../../conan/ --build missing
```

## Run CMake

Run cmake (preferrably the GUI version), click on **Configure** and set the **generator** so that it matches the one in the Conan default profile. Set the **Optional platform for generator** so that
it matches the one in the Conan default profile.

If the configuration phase was completed successfully, set the **cmake_install_prefix** to the directory where you want to install the library and click **Configure** again. 
If everything has been configured correctly, click **Generate** (and **Open Project** if in Windows).

## Building and Installing

Build and install the library