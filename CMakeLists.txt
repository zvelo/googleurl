CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(FLAGS "-Wall -W -fPIC -DCLD_WINDOWS -fvisibility=hidden -fvisibility-inlines-hidden")
SET(DEBUG_FLAGS "-O0 -g")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS} -Weffc++ ")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS} -Weffc++ ")
SET(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -Wl,--exclude-libs,ALL -Wl,--gc-sections")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/..)

SET(SOURCES
  base/string16.cc
  src/gurl.cc
  src/url_canon_etc.cc
  src/url_canon_fileurl.cc
  src/url_canon_filesystemurl.cc
  src/url_canon_host.cc
  src/url_canon_icu.cc
  src/url_canon_internal.cc
  src/url_canon_ip.cc
  src/url_canon_mailtourl.cc
  src/url_canon_path.cc
  src/url_canon_pathurl.cc
  src/url_canon_query.cc
  src/url_canon_relative.cc
  src/url_canon_stdurl.cc
  src/url_parse.cc
  src/url_parse_file.cc
  src/url_util.cc
)

SET(EXTERNAL_LIBRARIES
  ${CMAKE_BINARY_DIR}/external/lib/libicudata.a
  ${CMAKE_BINARY_DIR}/external/lib/libicui18n.a
  ${CMAKE_BINARY_DIR}/external/lib/libicuuc.a
)

ADD_LIBRARY(googleurl        SHARED ${SOURCES})
ADD_LIBRARY(googleurl-static STATIC ${SOURCES})

ADD_DEPENDENCIES(googleurl icu)
ADD_DEPENDENCIES(googleurl-static icu)

TARGET_LINK_LIBRARIES(googleurl LINK_PRIVATE ${EXTERNAL_LIBRARIES})
TARGET_LINK_LIBRARIES(googleurl-static ${EXTERNAL_LIBRARIES})

SET_TARGET_PROPERTIES(googleurl googleurl-static PROPERTIES
                      CLEAN_DIRECT_OUTPUT 1)

SET_TARGET_PROPERTIES(googleurl-static PROPERTIES OUTPUT_NAME "googleurl")

#SET(EXEC_SOURCES
#  src/gurl_test_main.cc
#  src/gurl_unittest.cc
#  src/url_canon_unittest.cc
#  src/url_parse_unittest.cc
#  src/url_util_unittest.cc
#)
#
#ADD_EXECUTABLE(googleurl-test ${EXEC_SOURCES})
#TARGET_LINK_LIBRARIES(googleurl-test googleurl)
#
#ADD_TEST(
#  NAME googleurl-test
#  COMMAND googleurl-test
#)
