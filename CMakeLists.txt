CMAKE_MINIMUM_REQUIRED_VERSION(VERSION 3.16)

project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)          
set(CMAKE_CXX_STANDARD_REQUIRED ON)    
set(CMAKE_CXX_EXTENSIONS OFF)         

option(COMPILE_TEST "Compile with TEST LIBRARY" ON)
option(__DEBUG "Compile with -D __DEBUG" ON)

set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)
set(TEST_LIBRARY_NAME Test)

if(COMPILE_LIBRARY)
    add_subdirectory(Test)
endif()

add_subdirectory(Src)
add_subdirectory(App)