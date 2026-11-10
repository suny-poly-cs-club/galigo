#pragma once

#include "raylib.h"

struct Snake {
    Rectangle body;
    float startX;
    float startY;
    double startT;

    static constexpr float W = 25.0;
    static constexpr float H = 10.0;

    Snake(float x, float y) {
        body = {x, y, W, H};
        startX = x,
        startY = y;
        startT = GetTime();
    }

    void update();

    void draw();
};
