#include "assetLoader.hpp"
Texture2D loadCompiledTexture(const char* fileType, const uint8_t* data, const int size) {
    Image img = LoadImageFromMemory(fileType, data, size);
    Texture2D texture = LoadTextureFromImage(img);
    UnloadImage(img);
    return texture;
}
