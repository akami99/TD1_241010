#include "structer.h"
#include "system.h"
#include "enemy.h"
#include "stage.h"
#include "player.h"

void SystemInitialize(System* s) {
	s->enemyNum = 0;
	s->gameoverNum = 0;
	s->clearNum = 0;
}

//オブジェクトのマップ番号を取得する関数
void GetMapNum(GameObject* go, Bullet bullet[], System* s) {
	//プレイヤーのマップ番号
	go->player.mapNum.x = (int(go->player.pos.x) - go->mapChip.mapPos.x) / go->mapChip.blockSize;
	go->player.mapNum.y = (int(go->player.pos.y) - go->mapChip.mapPos.y) / go->mapChip.blockSize;

	//弾のマップ番号
	for (int i = 0; i < s->enemyNum; i++) {
		bullet[i].mapNum.x = (bullet[i].pos.x - go->mapChip.mapPos.x) / go->mapChip.blockSize;
		bullet[i].mapNum.y = (bullet[i].pos.y - go->mapChip.mapPos.y) / go->mapChip.blockSize;
	}
}

void TitleScreen() {
	Novice::ScreenPrintf(600, 360, "Hansya Hangeki");
	Novice::ScreenPrintf(600, 580, "START to SPACE");
}

void StageSelect(KeyInput* key, GameObject* go) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && go->mapChip.stageNum > 1) {
		go->mapChip.stageNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && go->mapChip.stageNum < 9) {
		go->mapChip.stageNum++;
	}
}

void StageSelectScreen(GameObject* go) {
	if (go->mapChip.stageNum == 1) {
		Novice::ScreenPrintf(600, 360, "STAGE 1");
	}
	else if (go->mapChip.stageNum == 2) {
		Novice::ScreenPrintf(600, 360, "STAGE 2");
	}
	else if (go->mapChip.stageNum == 3) {
		Novice::ScreenPrintf(600, 360, "STAGE 3");
	}
	else if (go->mapChip.stageNum == 4) {
		Novice::ScreenPrintf(600, 360, "STAGE 4");
	}
	else if (go->mapChip.stageNum == 5) {
		Novice::ScreenPrintf(600, 360, "STAGE 5");
	}
	else if (go->mapChip.stageNum == 6) {
		Novice::ScreenPrintf(600, 360, "STAGE 6");
	}
	else if (go->mapChip.stageNum == 7) {
		Novice::ScreenPrintf(600, 360, "STAGE 7");
	}
	else if (go->mapChip.stageNum == 8) {
		Novice::ScreenPrintf(600, 360, "STAGE 8");
	}
	else if (go->mapChip.stageNum == 9) {
		Novice::ScreenPrintf(600, 360, "STAGE 9");
	}
}

void GameOver(System* s, KeyInput* key) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && s->gameoverNum > 0) {
		s->gameoverNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && s->gameoverNum < 1) {
		s->gameoverNum++;
	}
}

void GameOverScreen(System* s) {
	Novice::ScreenPrintf(600, 360, "GameOver");
	Novice::ScreenPrintf(400, 580, "Back To Select");
	Novice::ScreenPrintf(800, 580, "Retry Stage");

	if (s->gameoverNum == 0) {
		Novice::DrawLine(400, 600, 525, 600, RED);
	}
	else if (s->gameoverNum == 1) {
		Novice::DrawLine(800, 600, 900, 600, RED);
	}
}

void Clear(System* s, KeyInput* key) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && s->clearNum > 0) {
		s->clearNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && s->clearNum < 1) {
		s->clearNum++;
	}
}

void ClearScreen(System* s) {
	Novice::ScreenPrintf(600, 360, "Stage Clear");
	Novice::ScreenPrintf(400, 580, "Back To Select");
	Novice::ScreenPrintf(800, 580, "Retry Stage");

	if (s->clearNum == 0) {
		Novice::DrawLine(400, 600, 525, 600, RED);
	}
	else if (s->clearNum == 1) {
		Novice::DrawLine(800, 600, 900, 600, RED);
	}
}