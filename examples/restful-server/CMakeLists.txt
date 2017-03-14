
FILE(GLOB_RECURSE restful_server_SOURCES "*.cpp")
ADD_EXECUTABLE(restful-server ${restful_server_SOURCES})

#LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF(ENABLE_SHARED_LIBS)
    TARGET_LINK_LIBRARIES(restful-server ${LIBRARY_OUTPUT_PATH}/librestful_cpp.so)
ELSE()
    TARGET_LINK_LIBRARIES(restful-server ${LIBRARY_OUTPUT_PATH}/librestful_cpp.a)
ENDIF()

INSTALL(TARGETS restful-server DESTINATION bin)
