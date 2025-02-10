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
