
# --------------- Common Definitions ------------------
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(restful-cpp)

SET(CMAKE_VERBOSE_MAKEFILE 1)
SET(MG_ENABLE_DEBUG    OFF CACHE BOOL   "Enable Mongoose debug.")
SET(ENABLE_SHARED_LIBS OFF CACHE BOOL   "Enable shared libs.")

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE DEBUG)
  #SET(CMAKE_BUILD_TYPE RELEASE)
  #SET(CMAKE_BUILD_TYPE RELWITHDEBINFO)
  #SET(CMAKE_BUILD_TYPE MINSIZEREL)
ENDIF()

# --------------- Compiler Definitions ------------------
STRING(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE)

SET(COMMON_WARN "-Wall -Werror -Wextra -Wstrict-aliasing=2 -Wno-unused-parameter -Wno-unused-variable -Wno-type-limits")
SET(COMMON_FLAGS "-fvisibility=hidden")
SET(COMMON_ARGS "${COMMON_FLAGS} ${COMMON_WARN}")

IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # SET(CMAKE_C_FLAGS "-std=c11 ${COMMON_ARGS}")
    SET(CMAKE_CXX_FLAGS "-std=c++14 ${COMMON_ARGS} -Wno-reorder")
ELSEIF("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # SET(CMAKE_C_FLAGS "-std=c11 ${COMMON_ARGS}")
    SET(CMAKE_CXX_FLAGS "-std=c++14 ${COMMON_ARGS} -Wno-reorder")
ENDIF()
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fPIC")

# --------------- Macro Definitions ------------------
#IF(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
#    ADD_DEFINITIONS(-DMGCPP_DEBUG=1)
#ENDIF()

# --------------- outputs path ---------------------
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

FILE(MAKE_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}")
FILE(MAKE_DIRECTORY "${LIBRARY_OUTPUT_PATH}")

#SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
SET(CMAKE_INSTALL_PREFIX "/usr/local/restful-cpp")

# ------------------ includes --------------------
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

# ------------------ sub-dir --------------------
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(examples)
