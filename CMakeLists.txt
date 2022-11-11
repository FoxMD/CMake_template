cmake_minimum_required(VERSION 3.16)

project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX)
# Semantic versioning
# Patch - a bug was removed but no additional feature was added 
# Minor - a small feature was added, but everything is like it was (no braking changes)
# Major - braking changes

set(CMAKE_CXX_STANDARD 17)          
set(CMAKE_CXX_STANDARD_REQUIRED ON)    
set(CMAKE_CXX_EXTENSIONS OFF)         

option(COMPILE_TEST "Compile with TEST LIBRARY" OFF)
option(__DEBUG "Compile with -D __DEBUG" ON)

set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)
set(TEST_LIBRARY_NAME Test)

if(COMPILE_LIBRARY)
    add_subdirectory(Test)
endif()

add_subdirectory(configured)
add_subdirectory(Src)
add_subdirectory(App)