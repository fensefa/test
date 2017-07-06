# CMake generated Testfile for 
# Source directory: /home/xujiang/test/cmake
# Build directory: /home/xujiang/test/cmake
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(TutorialRuns "Tutorial" "25")
ADD_TEST(TutorialComp25 "Tutorial" "25")
SET_TESTS_PROPERTIES(TutorialComp25 PROPERTIES  PASS_REGULAR_EXPRESSION "hello world")
