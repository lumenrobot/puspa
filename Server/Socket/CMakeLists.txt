include_directories (
  ${CMAKE_SOURCE_DIR}/Common
  )

add_library (ServerSocket
  ServerSocket.h
  ServerSocket.cc
  )

target_link_libraries (ServerSocket
  Errors
  )
