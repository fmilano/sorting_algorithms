# Main CMake file for compiling the examples and tests.
#
# Copyright (c) 2020 Federico E. Milano
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 

cmake_minimum_required(VERSION 2.6)
project(sorting_algorithms)

# Define useful variables to handle Compiler/IDE differences:
if (MSVC)
    # Flags for linking with multithread static C++ runtime
    set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE} /MT")
    set(CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
else (MSVC)
    if (CMAKE_COMPILER_IS_GNUCXX)
        # GCC flags
        add_definitions(-rdynamic -fstack-protector-all -Wall -Wextra -pedantic -Wformat-security -Winit-self -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wconversion -Wlogical-op -Winline)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # Clang flags
        add_definitions(-fstack-protector-all -Wall -Wextra -pedantic -Wformat-security -Winit-self -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wconversion -Winline)
    endif (CMAKE_COMPILER_IS_GNUCXX)
endif (MSVC)


## Core source code ##

# adding a new file require explicittly modifing the CMakeLists.txt
# so that CMake knows that it should rebuild the project (it is best practice)

# list of header files
set(SORTING_ALGORITHMS_INC
 ${PROJECT_SOURCE_DIR}/include/insertion_sort.hpp
 ${PROJECT_SOURCE_DIR}/include/merge_sort.hpp
)
source_group(inc FILES ${SORTING_ALGORITHMS_INC})

# TODO
# list of test files
#set(SORTING_ALGORITHMS_TESTS
# tests/sorting_tests.cpp
#)
#source_group(tests FILES ${SORTING_ALGORITHMS_TESTS})

# list of example files
set(SORTING_ALGORITHMS_EXAMPLES
 examples/main.cpp
)
source_group(examples FILES ${SORTING_ALGORITHMS_EXAMPLES})

# list of doc files of the library
set(SORTING_ALGORITHMS_DOC
 README.md
 LICENSE
)
source_group(doc FILES ${SORTING_ALGORITHMS_DOC})

# All includes are relative to the "include" directory 
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(sorting_example1 ${SORTING_ALGORITHMS_EXAMPLES} ${SORTING_ALGORITHMS_INC})