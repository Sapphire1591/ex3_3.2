cmake_minimum_required(VERSION 3.6)
project(ex3)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-std=c99 -pedantic-errors -DNDEBUG")
SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SOURCE_FILES list.h
        list_mtm1.c
        list_mtm1.h
        list_example_test.c
        test_utilities.h
        orders.h
        orders.c)
add_executable(ex3 ${SOURCE_FILES})