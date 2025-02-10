#include "CollisonCheck.h"

bool CollisonCheck::CheckCollision(Player* player, Enemy* enemy)
{
    Vector2 playerPos = player->GetPos();
    Vector2 playerRadius = player->GetRadius();
    Vector2 enemyPos = enemy->GetPos();
    Vector2 enemyRadius = enemy->GetRadius();

    float dx = playerPos.x - enemyPos.x;
    float dy = playerPos.y - enemyPos.y;
    float distance = static_cast<float>(sqrt(dx * dx + dy * dy));

    return distance < (playerRadius.x + enemyRadius.x);
}

bool CollisonCheck::CheckCollision(Bullet* bullet, Enemy* enemy)
{
    if (!bullet->GetActive() || !enemy->GetIsAlive()) {
        return false;
    }

    Vector2 bulletPos = bullet->GetPos();
    Vector2 bulletRadius = bullet->GetRadius();
    Vector2 enemyPos = enemy->GetPos();
    Vector2 enemyRadius = enemy->GetRadius();

    float dx = bulletPos.x - enemyPos.x;
    float dy = bulletPos.y - enemyPos.y;
    float distance = static_cast<float>(sqrt(dx * dx + dy * dy));

    return distance < (bulletRadius.x + enemyRadius.x);
}
