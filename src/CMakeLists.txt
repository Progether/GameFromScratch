#Set platform independent src and include files
set(GameFromScratch_src
    game.cpp
)

set(GameFromScratch_inc
    game.h
)

#Set the include directories
set(GameFromScratch_IncludeDirs
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#Set platform dependend files
OPTION(USE_GLFW "Use GLFW instead of custom opengl/window creation" ON)
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    IF(NOT USE_GLFW)
        set(Platform_Dir ${CMAKE_CURRENT_SOURCE_DIR}/arch/linux/)
    ENDIF(NOT USE_GLFW)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(USE_GLFW)
    set(Platform_Dir ${CMAKE_CURRENT_SOURCE_DIR}/arch/multi/)
    list(APPEND ${GameFromScratch_IncludeDirs}
)
ENDIF(USE_GLFW)

list(APPEND GameFromScratch_src
    ${Platform_Dir}display.cpp
)

list(APPEND GameFromScratch_inc
    ${Platform_Dir}display.h
)

list(APPEND GameFromScratch_IncludeDirs
    ${Platform_Dir}
)


INCLUDE_DIRECTORIES(${GameFromScratch_IncludeDirs})


ADD_LIBRARY(GameFromScratch STATIC ${GameFromScratch_src} ${GameFromScratch_inc})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

    IF(NOT USE_GLFW)
        find_package(X11 REQUIRED)
        if(X11_FOUND)

            INCLUDE_DIRECTORIES(${X11_INCLUDE_DIRS})
            target_link_libraries(GameFromScratch ${X11_LIBRARIES})

        endif(X11_FOUND)
    ENDIF(NOT USE_GLFW)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF( USE_GLFW)
    find_package(OpenGL)
    target_link_libraries(GameFromScratch
        glfw
        ${OPENGL_LIBRARIES}
    )
ENDIF(USE_GLFW)

OPTION(USE_ALLEGRO "Use allegro?" OFF)
if(USE_ALLEGRO)
    find_package(PkgConfig)
    pkg_check_modules (ALLEGRO REQUIRED allegro-5.0)
    target_link_libraries(GameFromScratch ${ALLEGRO_LDFLAGS}  )
endif(USE_ALLEGRO)

