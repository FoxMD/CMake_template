cmake_minimum_required(VERSION 3.16)

project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX)
# Semantic versioning
# Patch - a bug was removed but no additional feature was added 
# Minor - a small feature was added, but everything is like it was (no braking changes)
# Major - braking changes

set(CMAKE_CXX_STANDARD 17)          
set(CMAKE_CXX_STANDARD_REQUIRED ON)    
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_CXX_EXTENSIONS OFF)         

option(COMPILE_TEST "Compile with TEST LIBRARY" ON)
option(__DEBUG "Compile with -D __DEBUG" ON)

# Options
option(USE_CONAN            "Whether to use conan or vcpkg"         ON)
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)
option(ENABLE_TESTING       "Enable a Unit Testing build."          ON)
option(ENABLE_COVERAGE      "Enable a Code Coverage build."         OFF) # only for linux
option(ENABLE_CLANG_TIDY    "Enable to add clang tidy."             OFF)
option(ENABLE_CPPCHECK      "Enable to add cppcheck."               OFF)
option(ENABLE_CCACHE        "Enable to add Ccache."                 OFF)

set(LIBRARY_NAME    "lib")
set(EXECUTABLE_NAME "main")
set(TEST_LIBRARY_NAME Test)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(Warnings)
include(Docs)
include(AddGitSubmodule)
include(FetchContent)
include(Ccache)
include(StaticCodeAnalysis)

add_git_submodule(external/json)

if (ENABLE_TESTING)
    include(CTest)
    endif()
if (ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()
add_git_submodule(external/json)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 8.1.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.9.2
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

if(USE_CONAN)
    message("Using Conan")
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
# Note: VCPKG need more adaptations in cmake files
# Also, rename the _vcpkg.json file to vcpkg.json
    message("Using VCPKG")
    find_package(Catch2 CONFIG REQUIRED)
    find_package(cxxopts CONFIG REQUIRED)
endif()

### SUB DIRECTORIES

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

### INSTALL TARGETS

install(TARGETS ${EXECUTABLE_NAME}
        EXPORT ${LIBRARY_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(TARGETS ${LIBRARY_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)