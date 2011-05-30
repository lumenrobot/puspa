set (HEADER_FILES
  SocketConfig.h
  whirr-sockets.h
  )
set (SOURCE_FILES
  whirr-sockets.cc
  )

add_library (whirr-sockets
  ${HEADER_FILES}
  ${SOURCE_FILES}
  )

if (WIN32)
   target_link_libraries (whirr-sockets
   ws2_32
   )
endif ()
