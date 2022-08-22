cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(advent-of-code)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


function(advent_of_code YEAR DAY PART_1_RESULT PART_2_RESULT)
	include(GoogleTest)

	set(LIB_TARGET "${YEAR}_${DAY}_lib")
	set(MAIN_TARGET "${YEAR}_${DAY}_main")
	set(TEST_TARGET "${YEAR}_${DAY}_test")


	configure_file(example.txt example.txt COPYONLY)
	configure_file(${CMAKE_SOURCE_DIR}/common/lib.hpp lib.hpp)
	configure_file(${CMAKE_SOURCE_DIR}/common/main.cpp main.cpp)
	configure_file(${CMAKE_SOURCE_DIR}/common/test.cpp test.cpp)


	add_library(${LIB_TARGET} lib.cpp lib.hpp)

	add_executable(${MAIN_TARGET} main.cpp)
	target_link_libraries(${MAIN_TARGET} ${LIB_TARGET})

	add_executable(${TEST_TARGET} test.cpp)
	target_link_libraries(${TEST_TARGET} ${LIB_TARGET} GTest::gtest_main)
	gtest_discover_tests(${TEST_TARGET})

endfunction()


add_subdirectory(2021)
