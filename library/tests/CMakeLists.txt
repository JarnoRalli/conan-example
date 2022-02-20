find_package(GTest REQUIRED CONFIG)

add_executable(test_library src/test_library.cpp )

target_link_libraries(
    test_library
PRIVATE
    Library
    GTest::gtest
    GTest::gtest_main )

add_test(
  NAME
    test_library
  COMMAND
    test_library
)
