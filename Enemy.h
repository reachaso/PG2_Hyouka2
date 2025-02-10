#pragma once
#include "struct.h"
#include <Novice.h>

class Enemy {

private:

	Vector2 pos_;
	Vector2 radius_;
	Vector2 speed_;

	bool isAlive_;
	int respawnTime_;
	static const int kRespawnTime = 60;

public:

	static const int kMaxEnemy = 3;

	Enemy();
	~Enemy();
	void Update();
	void Draw();
	void Reset();

	void SetPos(Vector2 pos);
	Vector2 GetPos();
	void SetRadius(Vector2 radius);
	Vector2 GetRadius();

	void SetIsAlive(bool isAlive);
	bool GetIsAlive();
};

