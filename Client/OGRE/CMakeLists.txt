include_directories (
  ${OGRE_INCLUDE_DIRS}
  ${OIS_INCLUDE_DIRS}
  ${CEGUI_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/Client
  ${CMAKE_SOURCE_DIR}/Client/CEGUI
  )

set (HEADER_FILES
  Face.h
  )

set (SOURCE_FILES
  Face.cpp
  )

if (WIN32)
  set (RESOURCE_FILES plugins.cfg plugins_d.cfg)
elseif (APPLE)
  set (RESOURCE_FILES plugins.cfg)
else ()
  set (RESOURCE_FILES plugins-unix.cfg)
endif ()

set (RESOURCE_FILES
  ${RESOURCE_FILES}
  resources.cfg
  Media/facial.mesh
  Media/facial.material
  Media/Dr_Bunsen_Head.jpg
  )

add_library (Face
  ${HEADER_FILES}
  ${SOURCE_FILES}
  ${RESOURCE_FILES}
  )

target_link_libraries (Face
  ${OGRE_LIBRARIES}
  ${OIS_LIBRARIES}
  )

if (WIN32)

  set (TARGET_PATH ${CMAKE_CURRENT_BINARY_DIR}/..)

  install (DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/Media
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Release RelWithDebInfo Debug
    )

  install (FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources.cfg
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Release RelWithDebInfo Debug
    )

  install (FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins.cfg
    ${OGRE_BINARY_REL}
    ${OGRE_RenderSystem_GL_REL}
    ${OIS_BINARY_REL}
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Release RelWithDebInfo
    )

  install (FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins_d.cfg
    ${OGRE_BINARY_DBG}
    ${OGRE_RenderSystem_GL_DBG}
    ${OIS_BINARY_DBG}
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Debug
    )

elseif (APPLE)

  set (BUNDLE_CONTENTS_PATH ${CMAKE_CURRENT_BINARY_DIR}/../$(CONFIGURATION)/${PROJECT_NAME}.app/Contents)

  set (BUNDLE_FRAMEWORKS_PATH ${BUNDLE_CONTENTS_PATH}/Frameworks)
  add_custom_command (TARGET Face POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_FRAMEWORKS_PATH}
    COMMAND rm ARGS -r -f ${BUNDLE_FRAMEWORKS_PATH}/Ogre.framework
    COMMAND cp ARGS -R ${OGRE_LIBRARY_FWK} ${BUNDLE_FRAMEWORKS_PATH}
    COMMAND cp ARGS -f ${OIS_LIBRARY_REL} ${BUNDLE_FRAMEWORKS_PATH}
    )

  set (BUNDLE_PLUGINS_PATH ${BUNDLE_CONTENTS_PATH}/Plugins)
  add_custom_command (TARGET Face POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_PLUGINS_PATH}
    COMMAND cp ARGS -f ${OGRE_RenderSystem_GL_LIBRARY_REL} ${BUNDLE_PLUGINS_PATH}
    )

  set (BUNDLE_RESOURCES_PATH ${BUNDLE_CONTENTS_PATH}/Resources)
  add_custom_command (TARGET Face POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_RESOURCES_PATH}
    COMMAND cp ARGS -f ${CMAKE_CURRENT_SOURCE_DIR}/plugins.cfg ${BUNDLE_RESOURCES_PATH}
    COMMAND cp ARGS -f ${CMAKE_CURRENT_SOURCE_DIR}/resources.cfg ${BUNDLE_RESOURCES_PATH}
    COMMAND cp ARGS -R -f ${CMAKE_CURRENT_SOURCE_DIR}/Media ${BUNDLE_RESOURCES_PATH}
    )

elseif (UNIX)

  install (FILES ${RESOURCE_FILES}
    DESTINATION "share/${PROJECT_NAME}"
    )

endif ()
