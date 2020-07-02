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
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

# This is an example of missing information propagation using cmake_paths generator. This is needed for the Conan package in Windows.
set(OpenCV_STATIC ON CACHE BOOL "For Windows: ON = static library/ OFF = dynamic library")
find_package(OpenCV 4.3.0 REQUIRED core)

# This is an example of missing information propagation using cmake_paths generator. This is needed for the Conan package in Windows.
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "For Windows: ON = static library/ OFF = dynamic library")
find_package(Boost 1.73.0 REQUIRED COMPONENTS filesystem)

# Find the package Library
find_package(Library 1.0 REQUIRED)

add_executable (executable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries (executable Library::Library)