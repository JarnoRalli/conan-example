find_package(GTest REQUIRED)

add_executable( test_library src/test_library.cpp )

target_link_libraries(
    test_library
PRIVATE
    Library
    GTest::GTest )

add_test(
  NAME
    test_library
  COMMAND
    test_library
)
