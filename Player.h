// Player.h
#pragma once
#include "struct.h"
#include "Bullet.h"

class Player
{
private:
    Vector2 pos_; // プレイヤーの位置
    Vector2 radius_; // プレイヤーの半径
    float speed_; // プレイヤーの移動速度
    Bullet* bullets_[Bullet::kMaxBullet]; // 弾の配列
    int bulletIndex_; // 現在の弾のインデックス
    int bulletIntervalCounter_; // 弾の発射間隔を管理するカウンタ

	bool isActive_; // プレイヤーがアクティブかどうかのフラグ

public:

    Player();
    ~Player();

    void Update(char* keys); // プレイヤーの状態を更新する
    void Draw(); // プレイヤーを描画する
    void Shoot(); // 弾を発射する

	// getter, setter
    void SetPos(Vector2 pos); // プレイヤーの位置を設定する
    Vector2 GetPos(); // プレイヤーの位置を取得する
    void SetRadius(Vector2 radius); // プレイヤーの半径を設定する
    Vector2 GetRadius(); // プレイヤーの半径を取得する

	void SetActive(bool active); // プレイヤーをアクティブにする
	bool GetActive(); // プレイヤーがアクティブかどうかを取得する

	void Reset(); // プレイヤーの状態をリセットする

    Bullet* GetBullet(int index); // 弾のインスタンスを取得する
};
