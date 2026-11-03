#include <iostream>
#include <raylib.h>
#include "inputManager.hpp"
#include "gameLogic.hpp"
#include "config.hpp"

int main() {

    //crate the window
    InitWindow(WIN_W,WIN_H,"Galigo");
    //set it to fullscreen mode
    ToggleBorderlessWindowed();
    SetTargetFPS(60);
    //call game logic init code
    init();

    //main loop
    while (!WindowShouldClose()) {
        //update the controller state
        updateInputState();
        //start recoding render commands
        BeginDrawing();
        //game logic and rendering
        draw(GetFrameTime());
        //submit the render commands and update what is on screen
        EndDrawing();
    }

    unload();
    CloseWindow();
    controllerShutdown();
    return EXIT_SUCCESS;
}
