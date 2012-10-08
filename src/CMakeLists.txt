file(GLOB GameFromScratch_src
    "*.h"
    "*.cpp"
)

add_executable (GameFromScratch ${GameFromScratch_src})
#this checks if the filesystem is linux and links allegro and Opengl
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
find_package(PkgConfig)
pkg_check_modules (ALLEGRO REQUIRED allegro-5.0) 
target_link_libraries(GameFromScratch ${ALLEGRO_LDFLAGS}  )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
