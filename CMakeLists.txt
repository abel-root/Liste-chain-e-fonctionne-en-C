cmake_minimum_required(VERSION 3.23)

project(liste VERSION 1.0)

set(CMAKE_C_STANDARD  11 )
set(CMAKE_C_STANDARD_REQUIRED ON)


set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES
    ${SOURCE_DIR}/main.c
 )

 add_executable(liste ${SOURCES})

 target_include_directories(liste PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/inc
 )