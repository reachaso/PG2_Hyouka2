#pragma once
#include "Player.h"
#include "Enemy.h"
#include "struct.h"
#include "CollisonCheck.h"

class Scene
{

private:

	Player* player;
	Enemy* enemies[Enemy::kMaxEnemy]; // 敵の配列を宣言
	CollisonCheck* collisonCheck;

	bool AllEnemiesDefeated(); // 全ての敵が倒されたかどうかをチェックする関数を追加
	bool IsPlayerDead(); // プレイヤーが死んだかどうかをチェックする関数を追加

public:

	SceneType sceneType;

	Scene();
	~Scene();
	void Update(char* keys, char* preKeys);
	void Draw();

	void TitleUpdate(char* keys, char* preKeys);
	void TitleDraw();

	void GameUpdate(char* keys, char* preKeys);
	void GameDraw();

	void Reset();

};

