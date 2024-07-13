cmake_minimum_required(VERSION 3.28)
project(TiPhone)
set(PROJECT_VERSION "v0.1.0")

option(PLATFORM_FOR_LINUX "linux platform" OFF)
option(PLATFORM_FOR_MAC "mac platform" OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        src
        src/inc
)

if (PLATFORM_FOR_LINUX)

endif (PLATFORM_FOR_LINUX)

find_package(SDL2)
if (PLATFORM_FOR_MAC)
    find_package(SDL2 REQUIRED SDL2)
    include_directories(${SDL2_INCLUDE_DIRS})
endif (PLATFORM_FOR_MAC)

file(GLOB_RECURSE IMAGES "resource/images/*.c")

set(SOURCE
        src/main.c
        src/lv_conf.h
        ${IMAGES}
)

add_subdirectory(lvgl)

find_package(PNG REQUIRED)
target_include_directories(
        lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${PNG_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
        lvgl
        lvgl::thorvg
        ${PNG_LIBRARY}
        m
        pthread
)

if (PLATFORM_FOR_LINUX)

endif (PLATFORM_FOR_LINUX)

if (PLATFORM_FOR_MAC)
    find_package(SDL2 REQUIRED SDL2)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif ()
