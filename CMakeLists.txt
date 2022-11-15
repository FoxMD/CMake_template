cmake_minimum_required(VERSION 3.16)

project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX)
# Semantic versioning
# Patch - a bug was removed but no additional feature was added 
# Minor - a small feature was added, but everything is like it was (no braking changes)
# Major - braking changes

set(CMAKE_CXX_STANDARD 17)          
set(CMAKE_CXX_STANDARD_REQUIRED ON)    
set(CMAKE_CXX_EXTENSIONS OFF)         

option(COMPILE_TEST "Compile with TEST LIBRARY" ON)
option(__DEBUG "Compile with -D __DEBUG" ON)

set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)
set(TEST_LIBRARY_NAME Test)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(AddGitSubmodule)
add_git_submodule(external/json)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.1.0 
    )
    FetchContent_makeAvailable(fmt)
    
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0 
        )
        FetchContent_makeAvailable(spdlog)
        
        set(CONAN_DISABLE_CHECK_COMPILER TRUE)
        include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
        
        include(Docs)
        
        add_subdirectory(configured)
        add_subdirectory(external)
        add_subdirectory(src)
        add_subdirectory(app)
        #if(COMPILE_TEST)
            add_subdirectory(tests)
        #endif()