#pragma once
#include "math.h"

#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

class CollisonCheck
{
public:
    static bool CheckCollision(Player* player, Enemy* enemy);
    static bool CheckCollision(Player* player, Enemy* enemy,int index);
};
