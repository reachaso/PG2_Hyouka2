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
	int lives_; // 残機を表すメンバ変数を追加
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

	void SetLives(int lives); // 残機を設定する関数を追加
	int GetLives(); // 残機を取得する関数を追加
};
