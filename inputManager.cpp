#include "inputManager.hpp"
#include <iostream>
#include <raylib.h>
#include  <SDL3/SDL_init.h>
#include <SDL3/SDL_joystick.h>

bool stickUp = false;
bool stickDown = false;
bool stickLeft = false;
bool stickRight = false;

bool buttonA = false;
bool buttonB = false;
bool buttonC = false;
bool buttonD = false;

bool initialized = false;
bool stickFound = false;

void updateInputState() {
    if (!initialized) {
        if (!SDL_Init(SDL_INIT_JOYSTICK)) {
            std::cerr << "failed to initialize SDL! "<<SDL_GetError()<<std::endl;
        }
    } else {
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
            case SDL_EVENT_JOYSTICK_ADDED:
                {
                    auto * stick = SDL_OpenJoystick(sdlEvent.jdevice.which);
                    std::string name = SDL_GetJoystickName(stick);
                    if (name != "Microntek USB Joystick") {
                        //we only care about the stick on the specific on the arcade cabinet
                        SDL_CloseJoystick(stick);
                    } else {
                        stickFound = true;
                    }
                }
                break;
            case SDL_EVENT_JOYSTICK_AXIS_MOTION:
                if (sdlEvent.jaxis.axis == 0) { // x axis
                    if (sdlEvent.jaxis.value <-1000) {
                        stickLeft = true;
                        stickRight = false;
                    } else if (sdlEvent.jaxis.value >1000) {
                        stickLeft = false;
                        stickRight = true;
                    } else {
                        stickLeft = false;
                        stickRight = false;
                    }
                } else if (sdlEvent.jaxis.axis == 1) { // y axis
                    if (sdlEvent.jaxis.value < -1000) {
                        stickUp = true;
                        stickDown = false;
                    } else if (sdlEvent.jaxis.value >1000) {
                        stickUp = false;
                        stickDown = true;
                    } else {
                        stickUp = false;
                        stickDown = false;
                    }
                }
                break;
            case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
                switch (sdlEvent.jbutton.button) {
                    case 0://A
                        buttonA = true;
                        break;
                    case 1://B
                        buttonB = true;
                        break;
                    case 3://C
                        buttonC = true;
                        break;
                    case 4://D
                        buttonD = true;
                        break;
                    default: break;
                }
                break;
            case SDL_EVENT_JOYSTICK_BUTTON_UP:
                switch (sdlEvent.jbutton.button) {
                case 0://A
                    buttonA = false;
                    break;
                case 1://B
                    buttonB = false;
                    break;
                case 3://C
                    buttonC = false;
                    break;
                case 4://D
                    buttonD = false;
                    break;
                default: break;
                }
                break;

            default:
                break;
            }
        }
    }

    // controller controls
    if (IsGamepadAvailable(0)) {
        Vector2 leftStick{};
        if (!stickFound) {
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
        }
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

void controllerShutdown() {
    if (initialized) {
        SDL_Quit();
    }
}
