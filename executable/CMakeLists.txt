#-----------------------------------------------------
# Simple build system using the modern CMake approach
#-----------------------------------------------------

# Minimum CMake version so that we can use the modern approach is 3.0
cmake_minimum_required (VERSION 3.16)

message(STATUS "----------")
message(STATUS "EXECUTABLE")
message(STATUS "----------")

# Project name, expected programming language is C++
project (Executable VERSION 1.0 LANGUAGES CXX)

# Make Conan quiet
set(CONAN_CMAKE_SILENT_OUTPUT TRUE)

# Set the paths so that Conan generated find* packages are found
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Find the package Library
find_package(Library 1.0 REQUIRED)

add_executable(executable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(executable Library::Library)

