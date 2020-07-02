add_executable( test_library src/test_library.cpp )

target_link_libraries(
    test_library
PRIVATE
    Library
    CONAN_PKG::gtest )

add_test(
  NAME
    test_library
  COMMAND
    test_library
)
