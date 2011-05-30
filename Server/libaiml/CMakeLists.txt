include_directories (
  ${CMAKE_SOURCE_DIR}/Common
  /usr/local/include
  )
link_directories (
  /usr/local/lib
  )

add_library (Brain
  Brain.h
  Brain.cc
  )

target_link_libraries (Brain
  aiml
  std_utils
  xml2
  )

install (FILES
  libaiml.xml
  userlist.xml
  DESTINATION "share/${PROJECT_NAME}"
  )
