CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(tests)
SET(CMAKE_CXX_STANDARD 11)

ENABLE_TESTING()

## for gtest
ADD_SUBDIRECTORY(deps/googletest EXCLUDE_FROM_ALL)
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include/ ${gtest_SOURCE_DIR})

## Wrap the generated files to the top target to build
ADD_CUSTOM_TARGET(tests)

INCLUDE_DIRECTORIES(include)

## header only library
ADD_LIBRARY(solver INTERFACE)
TARGET_LINK_LIBRARIES(solver)

## single test suite for problems
ADD_EXECUTABLE(solver_test
  test/solver_test.cpp)

TARGET_LINK_LIBRARIES(solver_test
  solver
  gtest
  gtest_main)

## This is for running "make test" command
ADD_TEST(NAME solver_test COMMAND solver_test)

ADD_DEPENDENCIES(tests
  solver_test)