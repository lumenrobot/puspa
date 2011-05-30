# Install script for directory: /home/inspiration/samson/puspa/Server/AIML

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PUSPA/AIML" TYPE FILE FILES
    "/home/inspiration/samson/puspa/Server/AIML/Adverbs.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/AI.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/ALICE.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Atomic.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Badanswer.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Biography.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Bot.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Botmaster.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Client.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Computers.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Date.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Default.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Dialog.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Drugs.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Emotion.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Food.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Gossip.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Human.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Humor.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Inquiry.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Integer.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Interjection.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/IU.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Money.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Movies.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/museumlskk.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Music.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Parts.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Personality.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Philosophy.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Pickup.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Predicates.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Psychology.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Reduce.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Reducer.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Reductions.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Salutations.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Science.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Sex.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Spam.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Sports.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Stack.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Stories.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/That.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/update.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Utilities.aiml"
    "/home/inspiration/samson/puspa/Server/AIML/Xfind.aiml"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

