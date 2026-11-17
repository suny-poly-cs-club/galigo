#include "snake.hpp"

Texture2D snakeTexture{};

void Snake::update() {
    // TODO
}

void Snake::draw() {
    DrawTexturePro(snakeTexture,{0,0,static_cast<float>(snakeTexture.width)/3,static_cast<float>(snakeTexture.height)},body, {0,0},0, WHITE);
}
