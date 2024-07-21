cmake_minimum_required(VERSION 2.4...3.30)
project(TiPhone)
set(PROJECT_VERSION "v0.1.0")

option(PLATFORM_IS_LINUX "Is linux platform" ON)

message("platform is linux: ${PLATFORM_IS_LINUX}")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        src
        src/inc
        src/components
        src/components/dock
)

if (NOT PLATFORM_IS_LINUX)
    find_package(SDL2 REQUIRED SDL2)
    include_directories(${SDL2_INCLUDE_DIRS})
endif ()

file(GLOB SRC
        "src/*.c"
        "src/*.h"
        "src/**/*.c"
        "src/**/*.h"
        "src/**/**/*.c"
        "src/**/**/*.h"
)
file(GLOB_RECURSE IMAGES "resource/images/*.c")

message("source files ===> ${SRC}")

set(SOURCE
        ${SRC}
        ${IMAGES}
)

add_subdirectory(lvgl)

target_include_directories(
        lvgl PUBLIC ${PROJECT_SOURCE_DIR}
)

if (NOT PLATFORM_IS_LINUX)
    find_package(SDL2 REQUIRED SDL2)
    target_include_directories(
            lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS}
    )
endif ()

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
        lvgl
        lvgl::thorvg
        m
        pthread
)

if (NOT PLATFORM_IS_LINUX)
    find_package(SDL2 REQUIRED SDL2)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif ()
