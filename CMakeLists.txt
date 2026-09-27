cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(my_app
    src/main.cpp
    src/Items.cpp
    src/Parser.cpp
)

target_include_directories(my_app
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(my_app
    PRIVATE
        nlohmann_json::nlohmann_json
)

