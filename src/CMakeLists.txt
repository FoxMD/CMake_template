set(LIBRARY_SOURCES 
    lib.cpp
)
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
# PUBLIC if A PUBLIC B and C PUBLIC A then C can use B
# PRIVATE same case only C does not implicit see C cannot use B
# INTERFACE nothing to compile, everything will be given forward (good for includes, virtual classes etc)
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})