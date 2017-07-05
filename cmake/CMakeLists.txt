cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
configure_file (
    "include/1.h.in"
    "include/1.h"
    )
include_directories (
    "include"
    )
add_library(xx src/1.cpp)
add_executable(Tutorial tutorial.cpp)
target_link_libraries (Tutorial xx)
install (TARGETS xx DESTINATION lib)
install (FILES 1.h DESTINATION include)
include(CTest)
add_test (TutorialRuns Tutorial 25)
add_test (TutorialComp25 Tutorial 25)
set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "hello world")
