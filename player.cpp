#include "player.h"
#include "raymath.h"
#include <algorithm>

Player::Player()
{
    width = 50.0f;
    height = 30.0f;
    speed = 100.0f;
    position = { 50.0f, (GetScreenHeight() / 2.0f) - (height / 2.0f) };
}

void Player::Update(float deltaT)
{
    Vector2 direction = { 0.0f, 0.0f };

    // if directionInput direction.x/y -= += 1.0f;

    //prevent faster diagonal movement

    position.x += direction.x * speed * deltaT;
    position.y += direction.y * speed * deltaT;

    //clamp to screen bounds (full vertical left quarter)
    float maxX = (GetScreenWidth() * 0.25f) - width;
    float maxY = GetScreenHeight() - height;

    position.x = std::clamp(position.x, 0.0f, maxX);
    position.y = std::clamp(position.y, 0.0f, maxY);
}

void Player::Draw() const
{
    //placeholder rectangle until we have Texture2d sprite
    DrawRectangleV(position, {width, height}, RED);
}