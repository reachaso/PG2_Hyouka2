#include "Scene.h"

Scene::Scene()
{
	sceneType = Title;
	player = new Player();
	// 敵の配列を初期化
	for (int i = 0; i < Enemy::kMaxEnemy; ++i) {
		enemies[i] = new Enemy();
	}

	collisonCheck = new CollisonCheck();
}

Scene::~Scene()
{
	delete player;
	for (int i = 0; i < Enemy::kMaxEnemy; ++i) {
		delete enemies[i];
	}
	delete collisonCheck;
}

void Scene::Update(char* keys, char* preKeys)
{
	switch (sceneType) {

	case Title:

		TitleUpdate(keys, preKeys);

		break;

	case Game:

		GameUpdate(keys, preKeys);

		break;
	}
}

void Scene::Draw()
{
	switch (sceneType) {

	case Title:

		TitleDraw();

		break;

	case Game:

		GameDraw();

		break;
	}
}

void Scene::TitleUpdate(char* keys, char* preKeys)
{
	if (keys[DIK_1] && preKeys[DIK_1]) {
		sceneType = Game;
	}
}

void Scene::TitleDraw()
{
	Novice::ScreenPrintf(100, 100, "Title");
}

void Scene::GameUpdate(char* keys, char* preKeys)
{
	// プレイヤーの更新処理
	player->Update(keys);

	// 各敵の更新処理
	for (int i = 0; i < Enemy::kMaxEnemy; ++i) {
		enemies[i]->Update();
	}

	//========================================================
	// 当たり判定のチェック
	//========================================================

	for (int i = 0; i < Enemy::kMaxEnemy; ++i)
	{
		for (int j = 0; j < Bullet::kMaxBullet; ++j)
		{
			if (collisonCheck->CheckCollision(player, enemies[i]))
			{
				// プレイヤーが敵に当たった場合、プレイヤーを非アクティブにする
				player->SetActive(false);
			}

			if (collisonCheck->CheckCollision(player->GetBullet(j), enemies[i]))
			{
				// 弾が敵に当たった場合、敵を非アクティブにする
				enemies[i]->SetIsAlive(false);
				player->GetBullet(j)->SetActive(false);
			}
		}
	}

	// リセット処理
	if (keys[DIK_R] && preKeys[DIK_R])
	{
		Reset();
	}
}

void Scene::GameDraw()
{
	// プレイヤーの描画処理
	player->Draw();

	// 各敵の描画処理
	for (int i = 0; i < Enemy::kMaxEnemy; ++i) {
		enemies[i]->Draw();
	}
}

void Scene::Reset()
{
	player->Reset();
	for (int i = 0; i < Enemy::kMaxEnemy; ++i) {
		enemies[i]->Reset();
	}
}
