#pragma once

//ヘッダーファイルのインクルード
#include <Novice.h>
#include <structer.h>

//プレイヤーの情報を初期化する関数
void PlayerInitialize(GameObject* go);

//マップ番号を取得する関数
void GetMapNum(GameObject* go);

//プレイヤーの動作に関する関数
void PlayerMove(GameObject* go, KeyInput* key);

//プレイヤーを描画する関数
void DrawPlayer(GameObject* go, ImageInfo* ii);
