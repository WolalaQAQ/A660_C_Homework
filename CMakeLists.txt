cmake_minimum_required(VERSION 3.10)
project(A660_C_Homework C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/image_audio)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/css)

if(WIN32)
        set(PKG_CONFIG_EXECUTABLE ${PROJECT_SOURCE_DIR}/lib/gtk/bin/pkg-config.exe)
        set(GTK3_DIR ${PROJECT_SOURCE_DIR}/lib/gtk)
        set(OpenCV_DIR ${PROJECT_SOURCE_DIR}/lib/OpenCV)
        set(OpenVINO_DIR ${PROJECT_SOURCE_DIR}/lib/OpenVINO/runtime/cmake)
endif ()

#OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

#OpenVINO 2022.3
find_package(OpenVINO REQUIRED)
include_directories(${OpenVINO_INCLUDE_DIR})

#GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

#子目录
include_directories(${PROJECT_SOURCE_DIR}/base_toolkit)
add_subdirectory(base_toolkit)
aux_source_directory(./base_toolkit BASE_TOOLKIT_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/ml)
add_subdirectory(ml)
aux_source_directory(./ml ML_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/manager)
add_subdirectory(manager)
aux_source_directory(./manager MANAGER_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/GUI)
add_subdirectory(GUI)
aux_source_directory(./GUI GUI_SRCS)

set_source_files_properties(
        # ${ML_SRCS}
        PROPERTIES LANGUAGE CXX
)

#创建可执行文件并链接库
add_executable(A660_C_Homework
        main.c
        ${BASE_TOOLKIT_SRCS}
        # ${ML_SRCS}
        ${MANAGER_SRCS}
        ${GUI_SRCS}
        )
target_link_libraries(A660_C_Homework
        ${OpenCV_LIBS}
        openvino::runtime
        ${GTK3_LIBRARIES}
        )
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/image_audio
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/image_audio)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/css
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/css)