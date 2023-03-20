cmake_minimum_required(VERSION 3.24)
project(A660_C_Homework C)

set(CMAKE_C_STANDARD 23)

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin/")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib/")
link_directories(${PROJECT_BINARY_DIR}/lib/)

#OpenCV 4.7
set(OpenCV_DIR ${PROJECT_SOURCE_DIR}/lib/OpenCV)
include_directories(${OpenCV_INCLUDE_DIR})
find_package(OpenCV REQUIRED)
#OpenVINO 2022.3
set(OpenVINO_DIR ${PROJECT_SOURCE_DIR}/lib/OpenVINO/runtime/cmake)
include_directories(${OpenVINO_INCLUDE_DIR})
find_package(OpenVINO REQUIRED)
#GTK4
set(PKG_CONFIG_EXECUTABLE ${PROJECT_SOURCE_DIR}/lib/gtk/bin/pkg-config.exe)
set(GTK4_DIR ${PROJECT_SOURCE_DIR}/lib/gtk)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED GTK4)
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_executable(A660_C_Homework main.c)
target_link_libraries(A660_C_Homework
        ${OpenCV_LIBS}
        openvino::runtime
        ${GTK4_LIBRARIES}
        )
