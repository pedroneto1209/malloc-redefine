cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)

set(EXTRA_COMPONENT_DIRS "../components")

set(TEST_COMPONENTS "malloc" CACHE STRING "List of components to test")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(unit_test)
