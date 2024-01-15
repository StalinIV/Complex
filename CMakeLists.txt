cmake_minimum_required(VERSION 3.25)
project(unti_tests)

set(CMAKE_CXX_STANDARD 17)

add_library(complex_class INTERFACE)
target_include_directories(complex_class INTERFACE scr)

include_directories(scr)

add_subdirectory(scr)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

set_target_properties(unti_tests PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(unti_tests_lib PROPERTIES LINKER_LANGUAGE CXX)
