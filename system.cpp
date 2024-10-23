#include "structer.h"
#include "system.h"
#include "enemy.h"
#include "stage.h"
#include "player.h"

void SystemInitialize(System* s) {
	s->enemyNum = 0;
	s->gameoverNum = 0;
	s->clearNum = 0;
	s->tutorial1Num = 0;
	s->tutorial2Num = 0;
	s->gameFrame = 0;
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

void TitleScreen(ImageInfo* ii) {
	Novice::DrawSprite(0, 0, ii->image.titleBG, 1.0f, 1.0f, 0.0f, 0xffffffff);
}

void StageSelect(KeyInput* key, GameObject* go) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && go->mapChip.stageNum > 1) {
		go->mapChip.stageNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && go->mapChip.stageNum < 9) {
		go->mapChip.stageNum++;
	}
}

void StageSelectScreen(GameObject* go, ImageInfo* ii) {
	Novice::DrawSprite(0, 0, ii->image.gameBG, 1.0f, 1.0f, 0.0f, 0xffffffff);
	Novice::DrawSprite(440, 264, ii->image.stage, 1.0f, 1.0f, 0.0f, 0xffffffff);
	Novice::DrawQuad(686, 280, 750, 280, 686, 344, 750, 344, go->mapChip.stageNum * 64, 0, 64, 64, ii->image.number, 0xffffffff);
	Novice::DrawSprite(340, 250, ii->image.selectA, 1.0f, 1.0f, 0.0f, 0xffffffff);
	Novice::DrawSprite(830, 250, ii->image.selectD, 1.0f, 1.0f, 0.0f, 0xffffffff);
	Novice::DrawSprite(500, 500, ii->image.space, 1.0f, 1.0f, 0.0f, 0xffffffff);
}

void GameOver(System* s, KeyInput* key) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && s->gameoverNum > 0) {
		s->gameoverNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && s->gameoverNum < 1) {
		s->gameoverNum++;
	}
}

void GameOverScreen(System* s, ImageInfo* ii) {
	Novice::DrawSprite(0, 0, ii->image.gameOverBG, 1.0f, 1.0f, 0.0f, 0xffffffff);

	Novice::DrawSprite(0, 0, ii->image.returns, 1.0f, 1.0f, 0.0f, 0xffffffff);

	if (s->gameoverNum == 0) {
		Novice::DrawLine(125, 600, 550, 600, RED);
	}
	else if (s->gameoverNum == 1) {
		Novice::DrawLine(800, 600, 1150, 600, RED);
	}
}

void Clear(System* s, KeyInput* key) {
	if (s->gameFrame < 80) {
		s->gameFrame++;
	} else if (s->gameFrame > 140) {
		s->gameFrame -= 2;
	}

	if (s->gameFrame > 80 && s->gameFrame <= 140) {
		s->gameFrame = 140;
	}
	if (s->gameFrame == 80) {
		s->gameFrame = 180;
	}

	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && s->clearNum > 0) {
		s->clearNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && s->clearNum < 1) {
		s->clearNum++;
	}
}

void ClearScreen(System* s, ImageInfo* ii) {
	Novice::DrawSprite(0, 0, ii->image.clearBG, 1.0f, 1.0f, 0.0f, 0xffffffff);

	if (s->gameFrame >= 140) {
		Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 1280 * ((s->gameFrame - 100) / 10), 0, 1280, 720, ii->image.clear, 0xffffffff);
	} else if (s->gameFrame <= 80) {
		Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 1280 * (s->gameFrame / 10), 0, 1280, 720, ii->image.clear, 0xffffffff);
	}
	Novice::DrawSprite(0, 0, ii->image.returns, 1.0f, 1.0f, 0.0f, 0x000000ff);

	if (s->clearNum == 0) {
		Novice::DrawLine(125, 600, 550, 600, RED);
	}
	else if (s->clearNum == 1) {
		Novice::DrawLine(800, 600, 1150, 600, RED);
	}
}