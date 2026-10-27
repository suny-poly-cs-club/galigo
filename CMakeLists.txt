cmake_minimum_required(VERSION 4.0)
project(galigo)

set(CMAKE_CXX_STANDARD 20)

# Ensure the policy is set to NEW to honor the empty submodule list
cmake_policy(SET CMP0096 NEW)
set(FETCHCONTENT_QUIET FALSE)

#if linux
if(UNIX AND NOT APPLE)
#-DSDL_X11_XSCRNSAVER=OFF -DSDL_X11_XTEST=OFF
    set(SDL_X11_XSCRNSAVER OFF CACHE BOOL "Disable X11 XScreenSaver support" FORCE)
    set(SDL_X11_XTEST OFF CACHE BOOL "Disable X11 tests" FORCE)
endif ()

# raylib
find_package(raylib QUIET)
include(FetchContent)
if (NOT raylib_FOUND)
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
find_package(SDL3 CONFIG QUIET)
if(NOT SDL3_FOUND)
    message("SDL3 not found installed on the system, downloading...")
    set(SDL_TESTS OFF CACHE BOOL "Disable SDL test suite" FORCE)
    # screw all that complicated install and command line args stuf, this is way easier
    FetchContent_Declare(
            SDL3
            GIT_REPOSITORY https://github.com/libsdl-org/SDL
            GIT_TAG release-3.4.14
            GIT_PROGRESS   TRUE
    )

    FetchContent_MakeAvailable(SDL3)
endif()


add_executable(galigo main.cpp inputManager.cpp
        gameLogic.cpp
        gameLogic.hpp)

target_link_libraries(galigo PRIVATE raylib SDL3::SDL3)
