cmake_minimum_required(VERSION 3.28)
project(TiPhone)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
        src
        src/inc
        /opt/homebrew/Cellar/sdl2/2.30.5/include
)
set(SOURCE
        src/main.c
        src/lv_conf.h
)

add_subdirectory(lvgl)
target_include_directories(
        lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(SDL2 REQUIRED SDL2)

include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
        lvgl
        lvgl::examples
        lvgl::demos
        lvgl::thorvg
        ${SDL2_LIBRARIES}
        m
        pthread
)
