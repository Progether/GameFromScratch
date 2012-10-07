cmake_minimum_required (VERSION 2.8)
project (GameFromScratch)

# Link against Allegro libraries
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lallegro")

# Put the binary file in /bin
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory (src)
