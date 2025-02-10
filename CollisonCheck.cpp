#include "CollisonCheck.h"
#include <Novice.h>

// プレイヤーと敵の衝突をチェックする関数
bool CollisonCheck::CheckCollision(Player* player, Enemy* enemy)
{
    // プレイヤーがアクティブでない、または敵が生存していない場合、衝突は発生しない
    if (!player->GetActive() || !enemy->GetIsAlive()) {
        return false;
    }

    // プレイヤーと敵の位置と半径を取得
    Vector2 playerPos = player->GetPos();
    Vector2 playerRadius = player->GetRadius();
    Vector2 enemyPos = enemy->GetPos();
    Vector2 enemyRadius = enemy->GetRadius();

    // プレイヤーと敵の中心間の距離を計算
    float dx = playerPos.x - enemyPos.x;
    float dy = playerPos.y - enemyPos.y;
    float distance = static_cast<float>(sqrt(dx * dx + dy * dy));

    // プレイヤーと敵の半径の合計よりも距離が小さい場合、衝突が発生している
    return distance < (playerRadius.x + enemyRadius.x);
}

// プレイヤーの弾と敵の衝突をチェックする関数
bool CollisonCheck::CheckCollision(Player* player, Enemy* enemy, int index)
{
    // 指定されたインデックスの弾がアクティブでない、または敵が生存していない場合、衝突は発生しない
    if (!player->GetBullet(index)->GetActive() || !enemy->GetIsAlive()) {
        return false;
    }

    // 弾と敵の位置と半径を取得
    Vector2 bulletPos = player->GetBullet(index)->GetPos();
    Vector2 bulletRadius = player->GetBullet(index)->GetRadius();
    Vector2 enemyPos = enemy->GetPos();
    Vector2 enemyRadius = enemy->GetRadius();

    // 弾と敵の中心間の距離を計算
    float dx = bulletPos.x - enemyPos.x;
    float dy = bulletPos.y - enemyPos.y;
    float distance = static_cast<float>(sqrt(dx * dx + dy * dy));

    // 弾と敵の半径の合計よりも距離が小さい場合、衝突が発生している
    return distance < (bulletRadius.x + enemyRadius.x);
}

