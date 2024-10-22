#pragma once

//敵の初期化
void EnemyInitialize(GameObject* go, Enemy enemy[], Bullet bullet[], System* s);

//弾の初期化
void BulletInitialize(System* s, Bullet bullet[], Enemy enemy[], GameObject* go);

//プレイヤーが動いた後の処理を行う関数
void EnemyAction(GameObject* go, Bullet bullet[], System* s);

//弾の当たり判定を取る関数
void BulletCollision(GameObject* go, Bullet bullet[], System* s);

// 反射の判定(弾が動いた後に入れる)
void BulletReflect(GameObject* go, Bullet bullet[], System* s);

//弾の描画を行う関数
void DrawBullet(Bullet bullet[], System* s);