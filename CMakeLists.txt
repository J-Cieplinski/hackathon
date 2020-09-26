cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HackathonArkanoid)

set(SRC_FILES main.cpp Ball.cpp Brick.cpp Game.cpp Paddle.cpp Background.cpp)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

add_executable(${PROJECT_NAME} ${SRC_FILES})
find_package(SFML COMPONENTS graphics window audio)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio)
