cmake_minimum_required (VERSION 2.8)
project (GameFromScratch)

# Put the binary file in /bin
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


add_subdirectory (src)

OPTION(ENABLE_TESTS "Build tests" ON)
if(ENABLE_TESTS )
    get_directory_property(GameFromScratch_IncludeDirs DIRECTORY src DEFINITION GameFromScratch_IncludeDirs)
    add_subdirectory(tests)
endif(ENABLE_TESTS )


