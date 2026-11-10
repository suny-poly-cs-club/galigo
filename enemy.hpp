#pragma once

#include "snake.hpp"

#include <variant>
#include <vector>

/**
 * HOW TO USE
 * Each enemy type is a variant. The `Enemy` type should have all enemies in its variant.
 * For a type to be an enemy it just needs methods called `update` and `draw`.
 */

/** An enemy of any type. */
using Enemy = std::variant<Snake>;

/** The enemies. */
extern std::vector<Enemy> enemies;

/** Pushes the enemy. */
void addEnemy(Enemy e);

/** Updates the enemies. */
void updateEnemies();

/** Draws the enemies. */
void drawEnemies();
