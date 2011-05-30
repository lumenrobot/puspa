set (HEADER_FILES
  SocketConfig.h
  ClientSocket.h
  )
set (SOURCE_FILES
  ClientSocket.cc
  )

include_directories (
  ${CMAKE_SOURCE_DIR}/Common
  )
add_library (ClientSocket
  ${HEADER_FILES}
  ${SOURCE_FILES}
  )

set (LINK_LIBRARIES
    Errors
)

if (WIN32)
  set (LINK_LIBRARIES
    ${LINK_LIBRARIES}
    ws2_32
    )
endif ()

target_link_libraries (ClientSocket
  ${LINK_LIBRARIES}
  )
