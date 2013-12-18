project( ZombieDice )

cmake_minimum_required( VERSION 2.6.2 )
if( "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6 )
  if( "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3 )
    cmake_policy( VERSION 2.8.4 )
  else()
    cmake_policy( VERSION 2.6 )
  endif()
endif()

include_directories( include )

if (WIN32)
  add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /nologo" )
else ()
  add_definitions( "-Wall -Wextra -pedantic" )
endif ()

set( SRCS
    src/dice_set.cpp
    src/die.cpp
    src/display_tty.cpp
    src/main.cpp
    src/player.cpp
    )
  
add_executable( ZombieDice ${SRCS})
#this is a uselesss comment
