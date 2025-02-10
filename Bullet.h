#pragma once
#include "struct.h"
#include <Novice.h>

class Bullet
{
private:
    // 弾の位置
    Vector2 pos_;
    // 弾の速度
    float speed_;
    // 弾の半径
    Vector2 radius_;
    // 弾がアクティブかどうかのフラグ
    bool active_;

public:
    // 弾の最大数
    static const int kMaxBullet = 30;
    // 弾の発射間隔
    static const int kBulletInterval = 5;

    // コンストラクタ
    Bullet();
    // デストラクタ
    ~Bullet();

    // 弾の状態を更新する関数
    void Update();
    // 弾を描画する関数
    void Draw();
   
    /// <summary>
    /// 弾を発射する関数
    /// </summary>
    /// <param name="pos">発射位置</param>
    /// <param name="speed">発射速度</param>
    void Shoot(Vector2 pos, float speed);

    void SetPos(Vector2 pos);
    Vector2 GetPos();
    void SetRadius(Vector2 radius);
    Vector2 GetRadius();

    void SetActive(bool active);
    bool GetActive();
};
