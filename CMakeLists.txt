cmake_minimum_required(VERSION 3.10.0)
project(KeyMapper VERSION 1.0.0)

add_executable(KeyMapper main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
