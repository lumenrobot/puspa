if (USE_OPENCOG)
  add_subdirectory (OpenCog)
  include_directories (${CMAKE_CURRENT_SOURCE_DIR}/OpenCog)
else ()
  add_subdirectory (libaiml)
  add_subdirectory (AIML)
  include_directories (${CMAKE_CURRENT_SOURCE_DIR}/libaiml)
endif ()

include_directories (
  ${CMAKE_SOURCE_DIR}/Common
  ${CMAKE_CURRENT_SOURCE_DIR}/Socket
  /usr/local/include
  )

add_subdirectory (Socket)

add_executable (puspad
  main.cc
  )

target_link_libraries (puspad
  Brain
  ServerSocket
  )

install (TARGETS puspad
  RUNTIME DESTINATION bin
  )
