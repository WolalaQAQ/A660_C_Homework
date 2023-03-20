cmake_minimum_required(VERSION 3.10)
project(A660_C_Homework C)

set(CMAKE_C_STANDARD 23)

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin/")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib/")
link_directories(${PROJECT_BINARY_DIR}/lib/)

#OpenCV
set(OpenCV_DIR ${PROJECT_SOURCE_DIR}/lib/OpenCV)
include_directories(${OpenCV_INCLUDE_DIR})
find_package(OpenCV REQUIRED)
#OpenVINO 2022.3
set(OpenVINO_DIR ${PROJECT_SOURCE_DIR}/lib/OpenVINO/runtime/cmake)
include_directories(${OpenVINO_INCLUDE_DIR})
find_package(OpenVINO REQUIRED)
#GTK4
set(PKG_CONFIG_EXECUTABLE ${PROJECT_SOURCE_DIR}/lib/gtk/bin/pkg-config.exe)
set(GTK3_DIR ${PROJECT_SOURCE_DIR}/lib/gtk)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

#子目录
include_directories(${PROJECT_SOURCE_DIR}/base_toolkit)
add_subdirectory(base_toolkit)
aux_source_directory(./base_toolkit MANAGER_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/ml)
add_subdirectory(ml)
aux_source_directory(./ml ML_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/manager)
add_subdirectory(manager)
aux_source_directory(./manager MANAGER_SRCS)

#创建可执行文件并链接库
add_executable(A660_C_Homework
        main.c
        ${ML_SRCS}
        ${MANAGER_SRCS}
        )
target_link_libraries(A660_C_Homework
        ${OpenCV_LIBS}
        openvino::runtime
        ${GTK3_LIBRARIES}
        )
