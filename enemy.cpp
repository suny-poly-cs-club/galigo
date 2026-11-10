#include "enemy.hpp"

std::vector<Enemy> enemies{};

void addEnemy(Enemy e) {
    enemies.push_back(e);
}

void updateEnemies() {
    for (Enemy& enemy: enemies) {
        std::visit([](auto& x){ x.update(); }, enemy);
    }
}

void drawEnemies() {
    for (Enemy& enemy: enemies) {
        std::visit([](auto& x){ x.draw(); }, enemy);
    }
}
