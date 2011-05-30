include_directories (
  ${CMAKE_SOURCE_DIR}/Client
  )

if (APPLE)
  include_directories (
    /opt/local/include
    /usr/local/include
    )
endif ()

add_library (Ear
  Ear.c
  Ear.h
  )

set (LINK_LIBRARIES
  )

if (APPLE)
  set (LINK_LIBRARIES
    /opt/local/lib/libesd.dylib
    /opt/local/lib/libjulius.a
    /opt/local/lib/libsent.a
    /opt/local/lib/libsndfile.dylib
    /opt/local/lib/libz.dylib
    /System/Library/Frameworks/AudioToolbox.framework
    /System/Library/Frameworks/AudioUnit.framework
    /System/Library/Frameworks/CoreAudio.framework
    /System/Library/Frameworks/CoreServices.framework
    )
elseif (UNIX)
  set (LINK_LIBRARIES
    asound
    esd
    julius
    pulse-simple
    sent
    sndfile
    z
    )
endif ()

target_link_libraries (Ear
  ${LINK_LIBRARIES}
  )

install (DIRECTORY julius-data
  DESTINATION "share/${PROJECT_NAME}"
  )
