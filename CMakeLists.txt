cmake_minimum_required(VERSION 3.1)
project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

set(engine_include_dir "${CMAKE_CURRENT_BINARY_DIR}/include" CACHE STRING "Sekai Engine include headers path")
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
add_subdirectory(vendors/raylib)


set(engine_public_headers
    src/core/GameObject.hpp
    src/core/Container.hpp
    src/core/Scence.hpp
)

set(engine_sources
    src/core/GameObject.cpp
    src/core/Container.cpp
    src/core/Scence.cpp
)

add_library(${PROJECT_NAME} STATIC ${engine_sources} ${engine_public_headers})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} raylib)
