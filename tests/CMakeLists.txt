set(WindowTest_src
    windowTest.cpp
)

set(WindowTest_inc
    windowTest.h
)

#message(${GameFromScratch_IncludeDirs})

INCLUDE_DIRECTORIES(${GameFromScratch_IncludeDirs})

add_executable(WindowTest ${WindowTest_src} ${WindowTest_inc})

find_package(OpenGL)

target_link_libraries(WindowTest
    ${OPENGL_LIBRARIES}
)


LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)
TARGET_LINK_LIBRARIES(WindowTest GameFromScratch)
