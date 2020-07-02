cmake_minimum_required(VERSION 3.16)

message(STATUS "-------")
message(STATUS "Library")
message(STATUS "-------")

project(Library VERSION 1.0 LANGUAGES CXX)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

# Organize project into folders. Improves readability in IDEs that support this
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# To distinguish between 'release' and 'debug' builds
set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "File prefix for debug builds")

# ------------------------------------------------------------------------
# Generate documentation if Doxygen is found (requires CMake 3.3 to work)
# ------------------------------------------------------------------------
find_package(Doxygen COMPONENTS doxygen dot QUIET)
if( ${DOXYGEN_FOUND} )
    message( STATUS "\tDoxygen + dot found, building documentation" )
    set(DOXYGEN_GENERATE_HTML YES CACHE BOOL "Generate HTML")
    set(DOXYGEN_GENERATE_LATEX YES CACHE BOOL "General Latex")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc" CACHE PATH "Output directory")
    set(DOXYGEN_PROJECT_NAME "Example project" CACHE STRING "Project name")
    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
    )
else( ${DOXYGEN_FOUND} )
    message( STATUS "\tDoxygen + dot NOT found, NOT building documentation" )
endif(  ${DOXYGEN_FOUND}  )

# -----------------------------------
# Generate the library (i.e. target)
# -----------------------------------
list(   APPEND 
        src_files   
        src/library.cpp
)

list(   APPEND 
        header_files
        include/library/library.hpp
)

add_library (Library)

find_package(opencv 4.3.0 REQUIRED)
#find_package(Boost 1.73.0 REQUIRED filesystem)

# Add directories to the target
# PRIVATE and PUBLIC items will populate the INCLUDE_DIRECTORIES property of target
# PUBLIC and INTERFACE items will populate the INTERFACE_INCLUDE_DIRECTORIES property of target
target_include_directories (Library
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link against 3rd party libraries
target_link_libraries (Library
    PUBLIC
        opencv::opencv
#    PRIVATE
#        Boost::Boost #Broken in Windows/Linux https://github.com/conan-io/conan-center-index/issues/1245, https://github.com/bincrafters/community/issues/563
)

# Add sources to the library
# Header files are added only so that they appear in IDEs such as Visual Studio etc
# For INTERFACE libraries (header only) this is the only way to make the header
# files appear in the project in IDEs such as Visual Studio
target_sources (Library
    PRIVATE
        ${src_files}
        ${header_files}
)

# Source group makes the files appear in same places in the logical structure
# of the project as where they are in the disk. This is for IDEs such as Visual Studio
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src_files} ${header_files})

# Compile features for the target -> these get propagated to anyone linking against this library
target_compile_features (Library PRIVATE cxx_std_14)

#---------------------------
# Installation instructions
#---------------------------
include(GNUInstallDirs)

# Export the target
install(TARGETS Library
        EXPORT LibraryTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install the headers (nice one liner format)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export the targets to a script
install(EXPORT LibraryTargets
        FILE
            LibraryTargets.cmake
        NAMESPACE
            Library::
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/Library
)

# Create a LibStoryBoardConfigVersion.cmake file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/LibraryConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Create a configuration file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibraryConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/LibraryConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Library
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

# Install the version- and configuration files
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibraryConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibraryConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Library
)

# Add tests
include(CTest)
enable_testing()
add_subdirectory(tests)