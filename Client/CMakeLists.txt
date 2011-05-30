if (USE_AIML)
  include_directories (
    Socket
    ${CMAKE_SOURCE_DIR}/Common
    )
  add_subdirectory (Socket)
else ()
  include_directories (whirr-sockets)
  add_subdirectory (whirr-sockets)
endif ()

if (USE_OGRE)
  include_directories (OGRE)
else ()
  include_directories (default)
endif ()

if (NOT WIN32)
  add_subdirectory (eSpeak)
  add_subdirectory (Julius)
endif ()

if (USE_OGRE)

  set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
  
  if (CMAKE_BUILD_TYPE STREQUAL "")
    # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
    # differentiation between debug and release builds.
    set (CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
  endif ()
  
  set (CMAKE_DEBUG_POSTFIX "_d")
  
  find_package (OGRE REQUIRED)
  if (NOT "${OGRE_VERSION_NAME}" STREQUAL "Cthugha")
    message (SEND_ERROR "You need Ogre 1.7 Cthugha to build this.")
  endif()
  
  find_package (OIS REQUIRED)
  if (NOT OIS_FOUND)
    message (SEND_ERROR "Failed to find OIS.")
  endif ()
  
  find_package (CEGUI REQUIRED)
  if (NOT CEGUI_FOUND)
    message (SEND_ERROR "Failed to find CEGUI.")
  endif ()
  
  if (WIN32 OR APPLE)
    set (Boost_USE_STATIC_LIBS TRUE)
  else ()
    # Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
    set (Boost_USE_STATIC_LIBS ${OGRE_STATIC})
  endif ()
  if (MINGW)
    # this is probably a bug in CMake: the boost find module tries to look for
    # boost libraries with name libboost_*, but CMake already prefixes library
    # search names with "lib". This is the workaround.
    set (CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
  endif ()
  set (Boost_ADDITIONAL_VERSIONS "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
  # Components that need linking (NB does not include header-only components like bind)
  set (OGRE_BOOST_COMPONENTS thread date_time)
  find_package (Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
  if (NOT Boost_FOUND)
    # Try again with the other type of libs
    set (Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
    find_package (Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
  endif ()
  find_package (Boost QUIET)
  
  # Set up referencing of Boost
  include_directories (${Boost_INCLUDE_DIR})
  add_definitions (-DBOOST_ALL_NO_LIB)
  set (OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
  
  add_subdirectory (OGRE)
  add_subdirectory (CEGUI)

  include_directories (
    ${OGRE_INCLUDE_DIRS}
    ${OIS_INCLUDE_DIRS}
    ${CEGUI_INCLUDE_DIRS}
    CEGUI
    )
  
endif ()


include_directories (
  eSpeak
  Julius
  )

set (HEADER_FILES
  Agent.h
  )

set (SOURCE_FILES
  main.cc
  Agent.cc
  )

add_executable (PUSPA WIN32 MACOSX_BUNDLE
  ${HEADER_FILES}
  ${SOURCE_FILES}
  )

set_target_properties (PUSPA PROPERTIES DEBUG_POSTFIX _d)

if (USE_OGRE)
  set (LINK_LIBRARIES
    Face
    GUI
    )
endif ()

if (NOT WIN32)
  set (LINK_LIBRARIES
    ${LINK_LIBRARIES}
    Mouth
    Ear
    )
endif ()

if (USE_AIML)
  set (LINK_LIBRARIES
    ${LINK_LIBRARIES}
    ClientSocket
    )
else ()
  set (LINK_LIBRARIES
    ${LINK_LIBRARIES}
    whirr-sockets
    )
endif ()

target_link_libraries (PUSPA ${LINK_LIBRARIES})

if (UNIX AND NOT APPLE)
  install (TARGETS PUSPA
    RUNTIME DESTINATION bin
    )
endif ()
