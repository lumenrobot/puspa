cmake_minimum_required (VERSION 2.6)
project (PUSPA)

if (USE_AIML)
  add_subdirectory (Common)
  add_subdirectory (Server)
endif ()
add_subdirectory (Client)
