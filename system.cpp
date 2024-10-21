#include "structer.h"
#include "system.h"
#include "enemy.h"
#include "stage.h"
#include "player.h"

void SystemInitialize(System* s) {
	s->enemyNum = 0;
}

void StageSelect(KeyInput* key, GameObject* go) {
	if (key->keys[DIK_A] && key->preKeys[DIK_A] == 0 && go->mapChip.stageNum > 1) {
		go->mapChip.stageNum--;
	}
	else if (key->keys[DIK_D] && key->preKeys[DIK_D] == 0 && go->mapChip.stageNum < 9) {
		go->mapChip.stageNum++;
	}
}