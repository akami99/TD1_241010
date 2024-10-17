//ヘッダーファイルのインクルード
#include <Novice.h>
#include "structer.h"
#include "player.h"

//グローバル変数の宣言
#define blockSize 96;

//プレイヤーの情報を初期化する関数
void PlayerInitialize(GameObject* go) {
	go->player.pos.x = 400.0f;
	go->player.pos.y = 120.0f;
	go->player.velocity.x = 96.0f;
	go->player.velocity.y = 96.0f;
	go->player.radius = 30.0f;
}

//プレイヤーの動作に関する関数
void PlayerMove(GameObject* go, KeyInput* key) {
	if (key->keys[DIK_W] && key->preKeys[DIK_W] == 0) {
		go->player.pos.y -= go->player.velocity.y;
	}
	else if (key->keys[DIK_S] && key->preKeys[DIK_S] == 0) {
		go->player.pos.y += go->player.velocity.y;
	}
	else if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0) {
		go->player.pos.x -= go->player.velocity.x;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0) {
		go->player.pos.x += go->player.velocity.x;
	}
}

//プレイヤーを描画する関数
void DrawPlayer(GameObject* go) {
	Novice::DrawEllipse(
		int(go->player.pos.x), int(go->player.pos.y), int(go->player.radius), int(go->player.radius),
		0.0f, WHITE, kFillModeSolid
	);
}