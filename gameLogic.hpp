#pragma once

/**Initialize things, like graphics packs
 */
void init();

/**Draw the next frame
 * @param dt The number of seconds the last frame took to render
 */
void draw(float dt);

/**Unload things at the end of the program
 */
void unload();