#include "Enemy.h"
#include <Novice.h>

// コンストラクタ
Enemy::Enemy()
	: pos_({ 0, 0 }), radius_({ 10, 10 }), speed_({ 8.0f, 8.0f }), isAlive_(false), respawnTime_(10), lives_(3) // 残機を初期化
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 敵の状態を更新する関数
void Enemy::Update()
{
	// 敵が生存していない場合、リスポーンタイマーを減少させる
	if (!isAlive_) {
		respawnTime_--;
		// リスポーンタイマーが0以下になったら敵をリスポーンさせる
		if (respawnTime_ <= 0) {
			if (lives_ > 0) { // 残機がある場合のみリスポーン
				isAlive_ = true;
				// ランダムな位置に敵を配置
				pos_ = { static_cast<float>(rand() % (1280 - static_cast<int>(radius_.x)) + radius_.x), static_cast<float>(rand() % (720 - static_cast<int>(radius_.y)) + radius_.y) };
				// ランダムな速度を設定
				speed_ = { static_cast<float>((rand() % 5 + 3)), static_cast<float>((rand() % 5 + 3)) };
				// リスポーンタイマーをリセット
				respawnTime_ = kRespawnTime;
				// 残機を減らす
				lives_--;
			}
		}
		return;
	}

	// 敵の位置を更新
	pos_.x += speed_.x;
	pos_.y += speed_.y;

	// 画面外に出そうになったら反射させる
	if (pos_.x - radius_.x < 0 || pos_.x + radius_.x > kScreenWidth) {
		speed_.x = -speed_.x;
	}
	if (pos_.y - radius_.y < 0 || pos_.y + radius_.x > kScreenHeight) {
		speed_.y = -speed_.y;
	}
}

// 敵を描画する関数
void Enemy::Draw()
{
	// 敵が生存している場合のみ描画する
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_.x),
			static_cast<int>(radius_.y),
			0.0f, RED, kFillModeSolid);
	}
}

// 敵の状態をリセットする関数
void Enemy::Reset()
{
	isAlive_ = false; // 敵を非アクティブにする
	respawnTime_ = 0; // リスポーンタイマーをリセット
	lives_ = 3; // 残機をリセット
}

// 敵の位置を設定する関数
void Enemy::SetPos(Vector2 pos)
{
	pos_ = pos; // 敵の位置を設定
}

// 敵の位置を取得する関数
Vector2 Enemy::GetPos()
{
	return pos_; // 敵の位置を取得
}

// 敵の半径を設定する関数
void Enemy::SetRadius(Vector2 radius)
{
	radius_ = radius; // 敵の半径を設定
}

// 敵の半径を取得する関数
Vector2 Enemy::GetRadius()
{
	return radius_; // 敵の半径を取得
}

// 敵の生存状態を設定する関数
void Enemy::SetIsAlive(bool isAlive)
{
	isAlive_ = isAlive; // 敵の生存状態を設定
}

// 敵の生存状態を取得する関数
bool Enemy::GetIsAlive()
{
	return isAlive_; // 敵の生存状態を取得
}

// 残機を設定する関数
void Enemy::SetLives(int lives)
{
	lives_ = lives; // 残機を設定
}

// 残機を取得する関数
int Enemy::GetLives()
{
	return lives_; // 残機を取得
}
