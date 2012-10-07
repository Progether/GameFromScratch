cmake_minimum_required (VERSION 2.8)
project (GameFromScratch)

IF(WIN32)
# Link against Allegro libraries if on windows
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lallegro")
ENDIF(WIN32)
# Put the binary file in /bin
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory (src)


    
