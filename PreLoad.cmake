if(NOT ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
endif()
message("generator is set to ${CMAKE_GENERATOR}")