cmake_minimum_required(VERSION 3.13.4)
project(AutoHexProjectSetter)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -std=gnu++2a -Wno-deprecated-declarations -Wno-unneeded-internal-declaration")
include_directories(${AutoHexProjectSetter_SOURCE_DIR}/include)
ADD_EXECUTABLE( uploader_settings src/main.cpp src/jsoncpp.cpp )