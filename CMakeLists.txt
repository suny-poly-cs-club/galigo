cmake_minimum_required(VERSION 4.0)
project(galigo)

set(CMAKE_CXX_STANDARD 20)

# Ensure the policy is set to NEW to honor the empty submodule list
cmake_policy(SET CMP0096 NEW)
set(FETCHCONTENT_QUIET FALSE)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 6.2
            GIT_SUBMODULES ""
            GIT_PROGRESS   TRUE
    )

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(raylib)
endif()


add_executable(galigo main.cpp inputManager.cpp
        gameLogic.cpp
        gameLogic.hpp)

target_link_libraries(galigo PRIVATE raylib)
