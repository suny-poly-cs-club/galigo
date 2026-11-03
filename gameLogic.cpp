#include "gameLogic.hpp"
#include <raylib.h>
#include "inputManager.hpp"
#include "assetLoader.hpp"
#include <assets.h>

static Texture2D exampleTexture;
void init() {
    exampleTexture = loadCompiledTexture(".png",example_png_data, example_png_size);
}

//remember the screen resolution of the arcade cabinet is: 1280x1024
//the window will fill your screen, but we want to ensure that gameplay fits the target screen

/**Draw the next frame
 * @param dt The number of seconds the last frame took to render
 */
void draw(float dt) {
    ClearBackground({0,120,255,255});
}

void unload() {
    UnloadTexture(exampleTexture);
}
