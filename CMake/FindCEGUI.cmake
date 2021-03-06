# Try to find CEGUI
# Once done, this will define
# CEGUI_FOUND - system has CEGUI
# CEGUI_INCLUDE_DIRS - the CEGUI include directories 
# CEGUI_LIBRARIES - link these to use CEGUI
include (FindPkgMacros)
findpkg_begin (CEGUI)
# Get path, convert backslashes as ${ENV_${var}}
getenv_path (CEGUI_HOME)
getenv_path (CEGUI_SDK)
getenv_path (OGRE_SOURCE)
getenv_path (OGRE_HOME)
# construct search paths
set (CEGUI_PREFIX_PATH ${CEGUI_HOME} ${ENV_CEGUI_HOME}
  ${OGRE_SOURCE}/Dependencies
  ${ENV_OGRE_SOURCE}/Dependencies
  ${OGRE_HOME} ${ENV_OGRE_HOME})
create_search_paths (CEGUI)
# redo search if prefix path changed
clear_if_changed (CEGUI_PREFIX_PATH
  CEGUI_LIBRARY_FWK
  CEGUI_LIBRARY_REL
  CEGUI_LIBRARY_DBG
  CEGUI_INCLUDE_DIR
  )
set (CEGUI_LIBRARY_NAMES CEGUIBase CEGUIOgreRenderer CEGUIExpatParser CEGUIFalagardWRBase)
get_debug_names (CEGUI_LIBRARY_NAMES)
use_pkgconfig (CEGUI_PKGC CEGUI)
findpkg_framework (CEGUI)
find_path (CEGUI_INCLUDE_DIR NAMES CEGUI.h HINTS ${CEGUI_FRAMEWORK_INCLUDES} ${CEGUI_INC_SEARCH_PATH} ${CEGUI_PKGC_INCLUDE_DIRS} PATH_SUFFIXES CEGUI)
find_library (CEGUI_LIBRARY_REL NAMES ${CEGUI_LIBRARY_NAMES} HINTS ${CEGUI_LIB_SEARCH_PATH} ${CEGUI_PKGC_LIBRARY_DIRS} PATH_SUFFIXES "" release relwithdebinfo minsizerel)
find_library (CEGUI_LIBRARY_DBG NAMES ${CEGUI_LIBRARY_NAMES_DBG} HINTS ${CEGUI_LIB_SEARCH_PATH} ${CEGUI_PKGC_LIBRARY_DIRS} PATH_SUFFIXES "" debug)
make_library_set (CEGUI_LIBRARY)
findpkg_finish (CEGUI)
add_parent_dir (CEGUI_INCLUDE_DIRS CEGUI_INCLUDE_DIR)
# CEGUI_OGRE_FOUND - system has the CEGUI Ogre renderer
# CEGUI_OGRE_LIBRARIES - link these to use the CEGUI Ogre renderer
# look for CEGUI Ogre Renderer, Expat Parser, and Falagard WR Base
if (CEGUI_FOUND)
  get_filename_component (CEGUI_LIBRARY_DIR_REL ${CEGUI_LIBRARY_REL} PATH)
  get_filename_component (CEGUI_LIBRARY_DIR_DBG ${CEGUI_LIBRARY_DBG} PATH)
  set (CEGUI_OGRE_LIBRARY_NAMES CEGUIOgreRenderer)
  get_debug_names (CEGUI_OGRE_LIBRARY_NAMES)
  find_library (CEGUI_OGRE_LIBRARY_REL NAMES ${CEGUI_OGRE_LIBRARY_NAMES} PATHS ${OGRE_LIB_SEARCH_PATH} ${OGRE_CMAKE_LIBRARY_DIRS} ${OGRE_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_REL}) 
  find_library (CEGUI_OGRE_LIBRARY_DBG NAMES ${CEGUI_OGRE_LIBRARY_NAMES_DBG} PATHS ${OGRE_LIB_SEARCH_PATH} ${OGRE_CMAKE_LIBRARY_DIRS} ${OGRE_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_DBG}) 
  make_library_set (CEGUI_OGRE_LIBRARY)
  if  (CEGUI_OGRE_LIBRARY)
    set (CEGUI_OGRE_FOUND TRUE)
    set (CEGUI_OGRE_LIBRARIES ${CEGUI_OGRE_LIBRARY})
  endif ()
  set (CEGUI_EXPAT_LIBRARY_NAMES CEGUIExpatParser)
  get_debug_names (CEGUI_EXPAT_LIBRARY_NAMES)
  find_library (CEGUI_EXPAT_LIBRARY_REL NAMES ${CEGUI_EXPAT_LIBRARY_NAMES} PATHS ${EXPAT_LIB_SEARCH_PATH} ${EXPAT_CMAKE_LIBRARY_DIRS} ${EXPAT_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_REL}) 
  find_library (CEGUI_EXPAT_LIBRARY_DBG NAMES ${CEGUI_EXPAT_LIBRARY_NAMES_DBG} PATHS ${EXPAT_LIB_SEARCH_PATH} ${EXPAT_CMAKE_LIBRARY_DIRS} ${EXPAT_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_DBG}) 
  make_library_set (CEGUI_EXPAT_LIBRARY)
  if  (CEGUI_EXPAT_LIBRARY)
    set (CEGUI_EXPAT_FOUND TRUE)
    set (CEGUI_EXPAT_LIBRARIES ${CEGUI_EXPAT_LIBRARY})
  endif ()
  set (CEGUI_FALAGARD_LIBRARY_NAMES CEGUIFalagardWRBase)
  get_debug_names (CEGUI_FALAGARD_LIBRARY_NAMES)
  find_library (CEGUI_FALAGARD_LIBRARY_REL NAMES ${CEGUI_FALAGARD_LIBRARY_NAMES} PATHS ${FALAGARD_LIB_SEARCH_PATH} ${FALAGARD_CMAKE_LIBRARY_DIRS} ${FALAGARD_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_REL}) 
  find_library (CEGUI_FALAGARD_LIBRARY_DBG NAMES ${CEGUI_FALAGARD_LIBRARY_NAMES_DBG} PATHS ${FALAGARD_LIB_SEARCH_PATH} ${FALAGARD_CMAKE_LIBRARY_DIRS} ${FALAGARD_PKGC_LIBRARY_DIRS} ${CEGUI_LIBRARY_DIR_DBG}) 
  make_library_set (CEGUI_FALAGARD_LIBRARY)
  if  (CEGUI_FALAGARD_LIBRARY)
    set (CEGUI_FALAGARD_FOUND TRUE)
    set (CEGUI_FALAGARD_LIBRARIES ${CEGUI_FALAGARD_LIBRARY})
  endif ()
endif ()
set (CEGUI_LIBRARIES ${CEGUI_LIBRARIES} ${CEGUI_OGRE_LIBRARIES} ${CEGUI_EXPAT_LIBRARIES} ${CEGUI_FALAGARD_LIBRARIES})
