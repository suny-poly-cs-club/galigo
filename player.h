#pragma once

#include <raylib.h>
#include "inputManager.hpp"

class Player {
    Vector2 position;
    float width;
    float height;
    float speed;

public:
    Player();

    void Update(float deltaTime);

    void Draw() const;

    // Getter so bullets/enemies know where the player is
    Vector2 GetPosition() const { return position; }
};