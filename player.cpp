//ヘッダーファイルのインクルード
#include <Novice.h>
#include "structer.h"
#include "player.h"

//グローバル変数の宣言
#define HalfBlockSize 48;
#define DrawMapStartPosX 400;
#define DrawMapStartPosY 120;


//プレイヤーの情報を初期化する関数
void PlayerInitialize(GameObject* go) {
	go->player.pos.x = 400.0f + 192.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 192.0f;
	go->player.posTmp.y = go->player.pos.y;
	go->player.velocity.x = 96.0f;
	go->player.velocity.y = 96.0f;
	go->player.radius = 30.0f;
	go->player.direction = 0;//0->上　1->右　2->下　3->左
}

void GetMapNum(GameObject* go) {
	go->player.mapNum.x = (int(go->player.posTmp.x) - go->mapChip.mapPos.x) / go->mapChip.blockSize;
	go->player.mapNum.y = (int(go->player.posTmp.y) - go->mapChip.mapPos.y) / go->mapChip.blockSize;
}

//プレイヤーの動作に関する関数
void PlayerMove(GameObject* go, KeyInput* key) {
	go->mapChip.mapPos.x = DrawMapStartPosX;
	go->mapChip.mapPos.y = DrawMapStartPosY;

	//プレイヤーのマップ番号を取得
	GetMapNum(go);

	if (key->keys[DIK_W] && key->preKeys[DIK_W] == 0) {
		go->player.posTmp.y -= go->player.velocity.y;
		GetMapNum(go);
		go->player.direction = 0;
		if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
			go->player.pos.y -= go->player.velocity.y;
		}
		else {
			go->player.posTmp.y += go->player.velocity.y;
		}
	}
	else if (key->keys[DIK_S] && key->preKeys[DIK_S] == 0) {
		go->player.posTmp.y += go->player.velocity.y;
		GetMapNum(go);
		go->player.direction = 2;
		if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
			go->player.pos.y += go->player.velocity.y;
		}
		else {
			go->player.posTmp.y -= go->player.velocity.y;
		}
	}
	else if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0) {
		go->player.posTmp.x -= go->player.velocity.x;
		GetMapNum(go);
		go->player.direction = 3;
		if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
			go->player.pos.x -= go->player.velocity.x;
		}
		else {
			go->player.posTmp.x += go->player.velocity.x;
		}
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0) {
		go->player.posTmp.x += go->player.velocity.x;
		GetMapNum(go);
		go->player.direction = 1;
		if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
			go->player.pos.x += go->player.velocity.x;
		}
		else {
			go->player.posTmp.x -= go->player.velocity.x;
		}
	}

	//if (key->keys[DIK_W] && key->preKeys[DIK_W] == 0) {
	//	go->player.posTmp.y -= go->player.velocity.y;
	//	if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
	//		go->player.direction = 0;
	//		go->player.pos.y -= go->player.posTmp.y;
	//	}
	//	/*else {
	//		go->player.posTmp.y += go->player.velocity.y;
	//	}*/
	//}
	//else if (key->keys[DIK_S] && key->preKeys[DIK_S] == 0) {
	//	go->player.posTmp.y += go->player.velocity.y;
	//	/*if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
	//		go->player.direction = 2;
	//		go->player.pos.y += go->player.velocity.y;
	//	}
	//	else {
	//		go->player.posTmp.y -= go->player.velocity.y;
	//	}*/
	//}
	//else if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0) {
	//	go->player.posTmp.x -= go->player.velocity.x;
	//	/*if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
	//		go->player.direction = 3;
	//		go->player.pos.x -= go->player.velocity.x;
	//	}
	//	else {
	//		go->player.posTmp.x += go->player.velocity.x;
	//	}*/
	//}
	//else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0) {
	//	go->player.posTmp.x += go->player.velocity.x;
	//	/*if (go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] == 0) {
	//		go->player.direction = 1;
	//		go->player.pos.x += go->player.velocity.x;
	//	}
	//	else {
	//		go->player.posTmp.x -= go->player.velocity.x;
	//	}*/
	//}
}

//プレイヤーを描画する関数
void DrawPlayer(GameObject* go, ImageInfo* ii) {
	//プレイヤーの描画
	Novice::DrawEllipse(
		int(go->player.pos.x), int(go->player.pos.y), int(go->player.radius), int(go->player.radius),
		0.0f, WHITE, kFillModeSolid
	);

	//反射板の描画
	if (go->player.direction == 0) {
		Novice::DrawQuad(
			int(go->player.pos.x - 35), int(go->player.pos.y - 45),
			int(go->player.pos.x + 35), int(go->player.pos.y - 45),
			int(go->player.pos.x - 35), int(go->player.pos.y - 35),
			int(go->player.pos.x + 35), int(go->player.pos.y - 35),
			0, 0, 1, 1, ii->image.box, WHITE
		);
	}
	else if (go->player.direction == 1) {
		Novice::DrawQuad(
			int(go->player.pos.x + 35), int(go->player.pos.y - 35),
			int(go->player.pos.x + 45), int(go->player.pos.y - 35),
			int(go->player.pos.x + 35), int(go->player.pos.y + 35),
			int(go->player.pos.x + 45), int(go->player.pos.y + 35),
			0, 0, 1, 1, ii->image.box, WHITE
		);
	}
	else if (go->player.direction == 2) {
		Novice::DrawQuad(
			int(go->player.pos.x - 35), int(go->player.pos.y + 35),
			int(go->player.pos.x + 35), int(go->player.pos.y + 35),
			int(go->player.pos.x - 35), int(go->player.pos.y + 45),
			int(go->player.pos.x + 35), int(go->player.pos.y + 45),
			0, 0, 1, 1, ii->image.box, WHITE
		);
	}
	else if (go->player.direction == 3) {
		Novice::DrawQuad(
			int(go->player.pos.x - 45), int(go->player.pos.y - 35),
			int(go->player.pos.x - 35), int(go->player.pos.y - 35),
			int(go->player.pos.x - 45), int(go->player.pos.y + 35),
			int(go->player.pos.x - 35), int(go->player.pos.y + 35),
			0, 0, 1, 1, ii->image.box, WHITE
		);
	}
}