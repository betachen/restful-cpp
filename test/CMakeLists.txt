FILE(GLOB_RECURSE test_main_SOURCES "*.cpp")

ADD_EXECUTABLE(test-main ${test_main_SOURCES})

INSTALL(TARGETS test-main DESTINATION bin)
