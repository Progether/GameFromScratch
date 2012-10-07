file(GLOB GameFromScratch_src
    "*.h"
    "*.cpp"
)

add_executable (GameFromScratch ${GameFromScratch_src})
#this checks if the filesystem is linux and links allegro and Opengl
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
target_link_libraries(GameFromScratch "-L/usr/local/lib -lallegro"  )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
