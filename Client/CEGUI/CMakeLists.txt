include_directories (
  ${CEGUI_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${OIS_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/Client
  ${CMAKE_SOURCE_DIR}/Client/OGRE
  )

set (HEADER_FILES
  GUI.h
  )

set (SOURCE_FILES
  GUI.cpp
  )

set (RESOURCE_FILES
  datafiles/Console.layout
  datafiles/TaharezLook.scheme
  datafiles/TaharezLook.looknfeel
  datafiles/TaharezLook.imageset
  datafiles/TaharezLook.tga
  datafiles/DejaVuSans-10.font
  datafiles/DejaVuSans.ttf
  )

add_library (GUI
  ${HEADER_FILES}
  ${SOURCE_FILES}
  ${RESOURCE_FILES}
  )

target_link_libraries (GUI
  ${CEGUI_LIBRARIES}
  )

if (WIN32)

  set (TARGET_PATH ${CMAKE_CURRENT_BINARY_DIR}/..)

  install (DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/datafiles
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Release RelWithDebInfo Debug
    )

  install (FILES
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIBase.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIOgreRenderer.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIExpatParser.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIFalagardWRBase.dll
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Release RelWithDebInfo
    )

  install (FILES
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIBase_d.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIOgreRenderer_d.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIExpatParser_d.dll
    ${CEGUI_INCLUDE_DIR}/../../bin/CEGUIFalagardWRBase_d.dll
    DESTINATION ${TARGET_PATH}
    CONFIGURATIONS Debug
    )

elseif (APPLE)

  set (BUNDLE_CONTENTS_PATH ${CMAKE_CURRENT_BINARY_DIR}/../$(CONFIGURATION)/${PROJECT_NAME}.app/Contents)

  set (BUNDLE_FRAMEWORKS_PATH ${BUNDLE_CONTENTS_PATH}/Frameworks)
  add_custom_command (TARGET GUI POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_FRAMEWORKS_PATH}
    COMMAND rm ARGS -r -f ${BUNDLE_FRAMEWORKS_PATH}/CEGUIBase.framework
    COMMAND cp ARGS -R ${CEGUI_LIBRARY_FWK} ${BUNDLE_FRAMEWORKS_PATH}
    COMMAND rm ARGS -r -f ${BUNDLE_FRAMEWORKS_PATH}/CEGUIOgreRenderer.framework
    COMMAND cp ARGS -R ${CEGUI_OGRE_LIBRARY_REL} ${BUNDLE_FRAMEWORKS_PATH}
    )

  set (BUNDLE_PLUGINS_PATH ${BUNDLE_CONTENTS_PATH}/Plugins)
  add_custom_command (TARGET GUI POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_PLUGINS_PATH}
    COMMAND rm ARGS -r -f ${BUNDLE_PLUGINS_PATH}/CEGUIExpatParser.bundle
    COMMAND cp ARGS -R ${CEGUI_EXPAT_LIBRARY_REL} ${BUNDLE_PLUGINS_PATH}
    COMMAND rm ARGS -r -f ${BUNDLE_PLUGINS_PATH}/CEGUIFalagardWRBase.bundle
    COMMAND cp ARGS -R ${CEGUI_FALAGARD_LIBRARY_REL} ${BUNDLE_PLUGINS_PATH}
    )

  set (BUNDLE_RESOURCES_PATH ${BUNDLE_CONTENTS_PATH}/Resources)
  add_custom_command (TARGET GUI POST_BUILD
    COMMAND mkdir ARGS -p ${BUNDLE_RESOURCES_PATH}
    COMMAND cp ARGS -R -f ${CMAKE_CURRENT_SOURCE_DIR}/datafiles ${BUNDLE_RESOURCES_PATH}
    )

elseif (UNIX)

  install (FILES ${RESOURCE_FILES}
    DESTINATION "share/${PROJECT_NAME}"
    )

endif ()
