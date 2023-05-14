cmake_minimum_required(VERSION 3.1)
project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

set(RUN_TEST OFF CACHE BOOL "Set on for run testing engine")
message(STATUS "RUN_TEST=${RUN_TEST}")

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
add_subdirectory(vendors/raylib)


set(engine_public_headers
    src/utility/math.hpp
    src/api/Color.hpp
    src/api/Camera2D.hpp
    src/api/Monitor.hpp
    src/api/Window.hpp
    src/api/Vector.hpp
    src/api/Ticker.hpp
    src/api/Shape.hpp
    src/core/GameObject.hpp
    src/core/Container.hpp
    src/core/Scence.hpp
    src/application/Application.hpp
    src/renderable/Renderable.hpp
    src/renderable/RenderableProperties.hpp
)

set(engine_sources
    src/utility/math.cpp
    src/api/Color.cpp
    src/api/Camera2D.cpp
    src/api/Monitor.cpp
    src/api/Window.cpp
    src/api/Vector.cpp
    src/api/Ticker.cpp
    src/api/Shape.cpp
    src/core/GameObject.cpp
    src/core/Container.cpp
    src/core/Scence.cpp
    src/application/Application.cpp
    src/renderable/Renderable.cpp
    src/renderable/RenderableProperties.cpp
)

add_library(${PROJECT_NAME} STATIC ${engine_sources} ${engine_public_headers})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} raylib)

if(RUN_TEST)
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_executable(engine_test
        test/test.cpp
    )


    target_link_libraries(engine_test GTest::gtest_main ${PROJECT_NAME})
    target_include_directories(engine_test PUBLIC src/)

    include(GoogleTest)
    gtest_discover_tests(engine_test)
endif()