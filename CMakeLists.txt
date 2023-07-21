cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES "src/*")

message("=====================")
foreach(SOURCE ${SOURCE_FILES})
    message("Arquivo: ${SOURCE}")
endforeach()
message("=====================")


add_executable(wine "${SOURCE_FILES}")
