set(TEST_SOURCES 
    test1.cpp
)
set(LIBRARY_INCLUDES
    "./"
)

add_library(${TEST_LIBRARY_NAME} STATIC ${TEST_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})