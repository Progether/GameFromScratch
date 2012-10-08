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
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    #find_package(PkgConfig)

    list(APPEND GameFromScratch_src
        arch/linux/display.cpp
    )

    list(APPEND GameFromScratch_inc
        arch/linux/display.h
    )

    list(APPEND GameFromScratch_IncludeDirs
         ${CMAKE_CURRENT_SOURCE_DIR}/arch/linux/
    )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")


INCLUDE_DIRECTORIES(${GameFromScratch_IncludeDirs})


ADD_LIBRARY(GameFromScratch STATIC ${GameFromScratch_src} ${GameFromScratch_inc})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(X11 REQUIRED)
    if(X11_FOUND)
        INCLUDE_DIRECTORIES(${X11_INCLUDE_DIRS})
        target_link_libraries(GameFromScratch ${X11_LIBRARIES})
    endif(X11_FOUND)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

OPTION(USE_ALLEGRO "Build tests" OFF)
if(USE_ALLEGRO)
    find_package(PkgConfig)
    pkg_check_modules (ALLEGRO REQUIRED allegro-5.0)
    target_link_libraries(GameFromScratch ${ALLEGRO_LDFLAGS}  )
endif(USE_ALLEGRO)

