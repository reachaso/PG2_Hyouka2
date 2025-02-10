#include "Bullet.h"

Bullet::Bullet()
{
    pos_ = { 0, 0 }; // 初期位置を(0, 0)に設定
    speed_ = 0.0f; // 初期速度を0に設定
    radius_ = { 5, 5 }; // 初期半径を(5, 5)に設定
    active_ = false; // 初期状態は非アクティブに設定
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
    // 弾がアクティブな場合、位置を更新し、画面外に出たら非アクティブにする
    if (active_) {
        pos_.y -= speed_; // 弾を上方向に移動
        if (pos_.y < 0) { // 画面外に出た場合
            active_ = false; // 非アクティブにする
        }
    }
}

void Bullet::Draw()
{
    // 弾がアクティブな場合、画面に描画する
    if (active_) {
        Novice::DrawEllipse(
            static_cast<int>(pos_.x),
            static_cast<int>(pos_.y),
            static_cast<int>(radius_.x),
            static_cast<int>(radius_.y),
            0.0f, WHITE, kFillModeSolid);
    }
}

void Bullet::Shoot(Vector2 pos, float speed)
{
    // 弾が非アクティブな場合に発射位置と速度を設定し、アクティブにする
    if (!active_) {
        pos_ = pos; // 発射位置を設定
        speed_ = speed; // 発射速度を設定
        active_ = true; // 弾をアクティブにする
    }
}

void Bullet::SetPos(Vector2 pos)
{
	pos_ = pos; // 弾の位置を設定
}

Vector2 Bullet::GetPos()
{
	return pos_; // 弾の位置を取得
}

void Bullet::SetRadius(Vector2 radius)
{
	radius_ = radius; // 弾の半径を設定
}

Vector2 Bullet::GetRadius()
{
	return radius_; // 弾の半径を取得
}

void Bullet::SetActive(bool active)
{
	active_ = active; // 弾のアクティブ状態を設定
}

bool Bullet::GetActive()
{
	return active_; // 弾のアクティブ状態を取得
}

