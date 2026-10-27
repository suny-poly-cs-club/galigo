#include <iostream>
#include <raylib.h>
#include "inputManager.hpp"
#include "gameLogic.hpp"

int main() {

    //crate the window
    InitWindow(1200,500,"Galigo");
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

        Color c = {0,0,0,255};
        Color r = {255,0,0,255};
        DrawRectangle(10,10,20,20,controllerStickUp()?r:c);
        DrawRectangle(40,10,20,20,controllerStickDown()?r:c);
        DrawRectangle(70,10,20,20,controllerStickLeft()?r:c);
        DrawRectangle(100,10,20,20,controllerStickRight()?r:c);
        DrawRectangle(130,10,20,20,controllerButtonA()?r:c);
        DrawRectangle(160,10,20,20,controllerButtonB()?r:c);
        DrawRectangle(190,10,20,20,controllerButtonC()?r:c);
        DrawRectangle(220,10,20,20,controllerButtonD()?r:c);

        //submit the render commands and update what is on screen
        EndDrawing();
    }

    CloseWindow();
    controllerShutdown();
    return EXIT_SUCCESS;
}
