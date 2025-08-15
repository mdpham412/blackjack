cmake_minimum_required(VERSION 3.15)

project(Blackjack VERSION 1.0
                  DESCRIPTION "A Blackjack CLI game"
                  LANGUAGES CXX)
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC src/game src/tests)
