#pragma once

//敵の初期化
void EnemyInitialize(GameObject* go, Enemy enemy[], Bullet bullet[], System* s);

//弾の初期化
void BulletInitialize(System* s, Bullet bullet[], Enemy enemy[], GameObject* go);

//プレイヤーが動いた後の処理を行う関数
void EnemyAction(GameObject* go, Bullet bullet[], System* s);

//弾の当たり判定を行う関数
//void CollisionBullet(GameObject* go, Bullet bullet[]);

//弾の描画を行う関数
void DrawBullet(Bullet bullet[], System* s);

//弾の動き
//void BulletMove(GameObject* go, Bullet bullet[], Enemy enemy[]);