cmake_minimum_required(VERSION 3.0)

project(Gojuon)

set (CMAKE_CXX_STANDARD 11)

set(SOURCES
	src/Gojuon.h
	src/Test.h
	src/Gojuon.cpp
	src/Test.cpp
	src/main.cpp
)

add_executable(Gojuon ${SOURCES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Gojuon)
