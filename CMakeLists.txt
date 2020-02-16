# 
# Author: Omer Zelig
#
# References:
# *) https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
# *) add gnu flags
# *) https://stackoverflow.com/questions/39863228/cmake-how-to-setup-unit-testing-of-a-library
#

#
# Validate minimum version
#
cmake_minimum_required(VERSION 3.14.6)

#
# Set Variables for readability
#
set(LIBRARY_NAME "zelig_static_interface")
set(LIBRARY_DESCRIPTION "Implementation of static interface in C++")
set(LIBRARY_FILES
    _src/src/WindowInterface.hpp
    _src/src/WindowInterface.cpp
)
set(TEST_NAME "zelig_static_interface_test")
set(TEST_FILES
    _src/test/main.cpp
)

#
# Set Standart
#
set(CXX_STANDARD 17)

#
# Set Project
#
project(${LIBRARY_NAME} VERSION 1.0.0 DESCRIPTION ${LIBRARY_DESCRIPTION})

#
# Easier installtion
#
include(GNUInstallDirs)

#
# Set compiler flags
#
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wextra")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wpedantic")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror")

#
# get all neceassry libraries
#
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#
# Creating the shared library
#
add_library(${LIBRARY_NAME} SHARED
    	    ${LIBRARY_FILES}
)
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER _src/src/WindowInterface.hpp
    )
target_include_directories(${LIBRARY_NAME} PRIVATE .)

message(${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS ${LIBRARY_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

#
# Creating the test executable
#
add_executable(${TEST_NAME}
               ${TEST_FILES}
               )

TARGET_LINK_LIBRARIES(${TEST_NAME}
    ${LIBRARY_NAME}
    Threads::Threads
    )
