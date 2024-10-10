#pragma once

//ヘッダーファイルのインクルード
#include <Novice.h>
#include <structer.h>

//プレイヤーの情報を初期化する関数
void playerInitialize(GameObject* go);

//プレイヤーの動作に関する関数
void playerMove(GameObject* go, KeyInput* key);

//プレイヤーを描画する関数
void drawPlayer(GameObject* go);
