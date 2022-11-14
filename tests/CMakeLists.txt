include(CTest)
set(TEST_MAIN "Unit tests")
set(TEST_SOURCES 
    main.cpp
)
set(TEST_INCLUDES
    "./"
)

add_executable(${TEST_MAIN} ${TEST_SOURCES})
#add_library(${TEST_LIBRARY_NAME} STATIC ${TEST_SOURCES})
target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME} ${CONAN_CATCH2})

add_test(NAME ${LIBRARY_NAME}.${TEST_MAIN} COMMAND ${TEST_MAIN})