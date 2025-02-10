// Player.cpp
#include "Player.h"
#include "Bullet.h"

// コンストラクタ
Player::Player()
{
    pos_ = { 640, 500 }; // 初期位置を設定
    radius_ = { 10, 10 }; // 初期半径を設定
    speed_ = 5.0f; // 初期速度を設定
    bulletIndex_ = 0; // 初期弾インデックスを設定
    bulletIntervalCounter_ = 0; // 初期カウンタを設定
    for (int i = 0; i < Bullet::kMaxBullet; ++i) {
        bullets_[i] = new Bullet(); // 弾のインスタンスを生成
    }
    isActive_ = true; // プレイヤーをアクティブにする
}

// デストラクタ
Player::~Player()
{
    for (int i = 0; i < Bullet::kMaxBullet; ++i) {
        delete bullets_[i]; // 弾のインスタンスを解放
    }
}

// プレイヤーの状態を更新する関数
void Player::Update(char* keys)
{
    // プレイヤーが非アクティブの場合、更新処理を行わない
    if (!isActive_) {
        return;
    }

    // 移動処理
    if (keys[DIK_W]) {
        pos_.y -= speed_; // 上に移動
    }
    if (keys[DIK_S]) {
        pos_.y += speed_; // 下に移動
    }
    if (keys[DIK_A]) {
        pos_.x -= speed_; // 左に移動
    }
    if (keys[DIK_D]) {
        pos_.x += speed_; // 右に移動
    }

    // 画面外に出ないように位置を制限
    if (pos_.x - radius_.x < 0) {
        pos_.x = 0 + radius_.x; // 左端に制限
    }
    if (pos_.x + radius_.x > 1280) {
        pos_.x = 1280 - radius_.x; // 右端に制限
    }
    if (pos_.y - radius_.y < 0) {
        pos_.y = 0 + radius_.y; // 上端に制限
    }
    if (pos_.y + radius_.y > 720) {
        pos_.y = 720 - radius_.y; // 下端に制限
    }

    // 弾発射処理
    if (keys[DIK_SPACE] && bulletIntervalCounter_ >= Bullet::kBulletInterval) {
        Shoot(); // 弾を発射
        bulletIntervalCounter_ = 0; // カウンタリセット
    }

    // 弾の更新
    for (int i = 0; i < Bullet::kMaxBullet; ++i) {
        bullets_[i]->Update(); // 各弾の状態を更新
    }

    // 発射間隔カウンタの更新
    if (bulletIntervalCounter_ < Bullet::kBulletInterval) {
        bulletIntervalCounter_++; // カウンタを増加
    }
}

// プレイヤーを描画する関数
void Player::Draw()
{
    // プレイヤーが非アクティブの場合、描画処理を行わない
    if (!isActive_) {
        return;
    }

    // プレイヤーを描画
    Novice::DrawEllipse(
        static_cast<int>(pos_.x),
        static_cast<int>(pos_.y),
        static_cast<int>(radius_.x),
        static_cast<int>(radius_.y),
        0.0f, WHITE, kFillModeSolid);

    // 弾の描画
    for (int i = 0; i < Bullet::kMaxBullet; ++i) {
        bullets_[i]->Draw(); // 各弾を描画
    }
}

// 弾を発射する関数
void Player::Shoot()
{
    bullets_[bulletIndex_]->Shoot(pos_, 10.0f); // 弾を発射
    bulletIndex_ = (bulletIndex_ + 1) % Bullet::kMaxBullet; // 次の弾のインデックスに更新
}

// プレイヤーの位置を設定する関数
void Player::SetPos(Vector2 pos)
{
    pos_ = pos; // プレイヤーの位置を設定
}

// プレイヤーの位置を取得する関数
Vector2 Player::GetPos()
{
    return pos_; // プレイヤーの位置を取得
}

// プレイヤーの半径を設定する関数
void Player::SetRadius(Vector2 radius)
{
    radius_ = radius; // プレイヤーの半径を設定
}

// プレイヤーの半径を取得する関数
Vector2 Player::GetRadius()
{
    return radius_; // プレイヤーの半径を取得
}

// プレイヤーの生存状態を設定する関数
void Player::SetActive(bool active)
{
    isActive_ = active; // プレイヤーの生存状態を設定
}

// プレイヤーの生存状態を取得する関数
bool Player::GetActive()
{
    return isActive_; // プレイヤーの生存状態を取得
}

// プレイヤーの状態をリセットする関数
void Player::Reset()
{
    pos_ = { 640, 500 }; // 初期位置を設定
    radius_ = { 10, 10 }; // 初期半径を設定
    speed_ = 5.0f; // 初期速度を設定
    bulletIndex_ = 0; // 初期弾インデックスを設定
    bulletIntervalCounter_ = 0; // 初期カウンタを設定
    for (int i = 0; i < Bullet::kMaxBullet; ++i) {
        bullets_[i]->SetActive(false); // 弾の状態を非アクティブにする
    }
    isActive_ = true; // プレイヤーをアクティブにする
}

// 指定したインデックスの弾のインスタンスを取得する関数
Bullet* Player::GetBullet(int index)
{
    return bullets_[index]; // 弾のインスタンスを取得
}
