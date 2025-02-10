#include "Enemy.h"

Enemy::Enemy()
	: pos_({ 0, 0 }), radius_({ 10, 10 }), speed_({ 8.0f, 8.0f }), isAlive_(false), respawnTime_(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!isAlive_) {
		respawnTime_--;
		if (respawnTime_ <= 0) {
			isAlive_ = true;
			pos_ = { static_cast<float>(rand() % (1280 - static_cast<int>(radius_.x)) + radius_.x), static_cast<float>(rand() % (720 - static_cast<int>(radius_.y)) + radius_.y) };
			speed_ = { static_cast<float>((rand() % 5 + 3)), static_cast<float>((rand() % 5 + 3)) };
			respawnTime_ = kRespawnTime;
		}
		return;
	}

	// 位置を更新
	pos_.x += speed_.x;
	pos_.y += speed_.y;

	// 画面外に出そうになったら反射
	if (pos_.x - radius_.x < 0 || pos_.x + radius_.x > kScreenWidth) {
		speed_.x = -speed_.x;
	}
	if (pos_.y - radius_.y < 0 || pos_.y + radius_.x > kScreenHeight) {
		speed_.y = -speed_.y;
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_.x),
			static_cast<int>(radius_.y),
			0.0f, RED, kFillModeSolid);
	}
}

void Enemy::Reset()
{
	isAlive_ = false;
	respawnTime_ = 0;
}

void Enemy::SetPos(Vector2 pos)
{
	pos_ = pos;
}

Vector2 Enemy::GetPos()
{
	return pos_;
}

void Enemy::SetRadius(Vector2 radius)
{
	radius_ = radius;
}

Vector2 Enemy::GetRadius()
{
	return radius_;
}

void Enemy::SetIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

bool Enemy::GetIsAlive()
{
	return false;
}
