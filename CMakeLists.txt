cmake_minimum_required(VERSION 3.1)
project(HackathonArkanoid)

set(SRC_FILES main.cpp Ball.cpp Brick.cpp Game.cpp Paddle.cpp)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

add_compile_options(-std=c++17)

add_executable(${PROJECT_NAME} ${SRC_FILES})
find_package(SFML COMPONENTS graphics window)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)
