add_library (Brain
  opencog-chatbot.conf
  Brain.h
  Brain.cc
  )

install (FILES
  opencog-chatbot.conf
  DESTINATION "share/${PROJECT_NAME}"
  )
