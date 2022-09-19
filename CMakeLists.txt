cmake_minimum_required(VERSION 3.14)

include(FetchContent)

project(duck)

include_directories(inc)

file(GLOB_RECURSE DUCK_MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(duck OBJECT ${DUCK_MAIN_SOURCES})

# https://github.com/google/googletest
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

file(GLOB_RECURSE DUCK_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cc)
add_executable(duck_test ${DUCK_TEST_SOURCES})
target_link_libraries(duck_test duck)
target_link_libraries(duck_test duck)
target_link_libraries(duck_test GTest::gtest_main)
gtest_discover_tests(duck_test)