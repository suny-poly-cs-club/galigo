#include "gameLogic.hpp"
#include <raylib.h>
#include "inputManager.hpp"
#include "config.hpp"
#include "assetLoader.hpp"
#include <assets.h>
#include "enemy.hpp"
#include "snake.hpp"

Texture2D bgTexture{};

static Texture2D exampleTexture;
void init() {
    exampleTexture = loadCompiledTexture(".png",example_png_data, example_png_size);
    int area = BG_W * BG_H;
    Color* pixels = (Color*)MemAlloc(area * sizeof(Color));
    for (int i = 0; i < area; i++) {
        if (GetRandomValue(1, 400) == 1) {
            pixels[i] = WHITE;
        } else {
            pixels[i].a = 0;
        }
    }
    Image img = {
        .data = pixels,
        .width = BG_W,
        .height = BG_H,
        .mipmaps = 1,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
    };
    bgTexture = LoadTextureFromImage(img);
    UnloadImage(img);
    //let the source rect run off the edge of the texture and wrap around
    SetTextureWrap(bgTexture, TEXTURE_WRAP_REPEAT);

    snakeTexture = loadCompiledTexture(".png",vinomoose_png_data,vinomoose_png_size);
}

//remember the screen resolution of the arcade cabinet is: 1280x1024
//the window will fill your screen, but we want to ensure that gameplay fits the target screen

/**Draw the next frame
 * @param dt The number of seconds the last frame took to render
 */
void draw(float dt) {
    ClearBackground(BACKGROUND_COLOR);
    //scroll the starfield right to left, one full loop every BG_LOOP_SECONDS
    static float bgScroll = 0.0f;
    bgScroll += dt / BG_LOOP_SECONDS;
    bgScroll -= (int)bgScroll; //keep in [0,1) so precision never degrades
    float srcX = bgScroll * BG_W;
    DrawTexturePro(bgTexture, {srcX, 0, BG_W, BG_H}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0, WHITE);


    //draw the enemies
    drawEnemies();


    //update the enemies
    updateEnemies();
}

void unload() {
    UnloadTexture(exampleTexture);
    UnloadTexture(bgTexture);
    UnloadTexture(snakeTexture);
}
