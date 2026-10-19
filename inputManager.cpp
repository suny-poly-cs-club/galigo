#include "inputManager.hpp"
#include <raylib.h>

bool stickUp = false;
bool stickDown = false;
bool stickLeft = false;
bool stickRight = false;

bool buttonA = false;
bool buttonB = false;
bool buttonC = false;
bool buttonD = false;

void updateInputState() {
    // controller controls
    if (IsGamepadAvailable(0)) {
        Vector2 leftStick{};
        //read the values for the left stick
        leftStick.x = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
        leftStick.y = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);

        stickUp = leftStick.y < -0.2;
        stickDown = leftStick.y > 0.2;
        stickLeft = leftStick.x < -0.2;
        stickRight = leftStick.x > 0.2;

        buttonA = IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
        buttonB = IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
        buttonC = IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
        buttonD = IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP);
    } else {
        // keyboard controls
        stickUp = IsKeyDown(KEY_W);
        stickDown = IsKeyDown(KEY_S);
        stickLeft = IsKeyDown(KEY_A);
        stickRight = IsKeyDown(KEY_D);

        buttonA = IsKeyDown(KEY_SPACE);
        buttonB = IsKeyDown(KEY_J);
        buttonC = IsKeyDown(KEY_K);
        buttonD = IsKeyDown(KEY_L);
    }
}

bool controllerStickUp(){
    return stickUp;
}
bool controllerStickDown(){
    return stickDown;
}
bool controllerStickLeft(){
    return stickLeft;
}
bool controllerStickRight(){
    return stickRight;
}

bool controllerButtonA(){
    return buttonA;
}
bool controllerButtonB(){
    return buttonB;
}
bool controllerButtonC(){
    return buttonC;
}
bool controllerButtonD(){
    return buttonD;
}