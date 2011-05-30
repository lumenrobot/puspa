if (APPLE)
  include_directories (
    /opt/local/include
    )
endif ()

if (WIN32)

add_library (Mouth
  speak_lib.h
  espeak.cpp
  Mouth.h
  )

else ()

add_library (Mouth
  compiledict.cpp
  dictionary.cpp
  intonation.cpp
  klatt.cpp
  mbrowrap.cpp
  numbers.cpp
  phonemelist.cpp
  readclause.cpp
  setlengths.cpp
  speak.cpp
  synth_mbrola.cpp
  synthdata.cpp
  synthesize.cpp
  tr_languages.cpp
  translate.cpp
  voices.cpp
  wavegen.cpp
  StdAfx.h
  phoneme.h
  speak_lib.h
  speech.h
  synthesize.h
  translate.h
  voice.h
  klatt.h
  mbrowrap.h
  wave.h
  sintab.h
  Mouth.h
  )

if (APPLE)
  target_link_libraries (Mouth
    /opt/local/lib/libportaudio.dylib
    )
else ()
  target_link_libraries (Mouth
    portaudio
    )
endif ()

endif ()

if (APPLE)

  set (BUNDLE_CONTENTS_PATH ${CMAKE_CURRENT_BINARY_DIR}/../$(CONFIGURATION)/${PROJECT_NAME}.app/Contents)
  set (BUNDLE_RESOURCES_PATH ${BUNDLE_CONTENTS_PATH}/Resources)
  add_custom_command (TARGET Mouth POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_RESOURCES_PATH}
    COMMAND cp ARGS -R -f ${CMAKE_CURRENT_SOURCE_DIR}/espeak-data ${BUNDLE_RESOURCES_PATH}
    )

elseif (UNIX)

  install (DIRECTORY espeak-data
    DESTINATION "share/${PROJECT_NAME}"
    )

endif ()
