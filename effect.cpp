#include "structer.h"
#include "effect.h"
#include "enemy.h"
#include <time.h>

const int kParticlesNum = 100;
void EffectInitialize(Effect effect[]) {
	for (int i = 0; i < kParticlesNum; i++)
	{
		effect[i].pos.x = {};
		effect[i].pos.y = {};
		effect[i].radius = 2.0;
		effect[i].timer = 45;
		effect[i].isAlive = {};
	}
}

void EnemyParticles(Enemy enemy[], Effect effect[], System* s) {
	unsigned int currentTime = time(nullptr); //時間を小数に変換
	srand(currentTime);
	//パーティクルの位置を敵に合わせる
	for (int i = 0; i < s->enemyNum; i++) {	//敵の数
		if (enemy[i].isAlive == 0) {
			for (int j = 0; j < kParticlesNum; j++) {	//パーティクルの数
				//一粒ずつの情報を取得
				effect[j].pos.x = float(enemy[i].pos.x) + rand() % 21 - 10;
				effect[j].pos.y = float(enemy[i].pos.y) + rand() % 21 - 10;
				effect[j].velocity.x = rand() % 11 - 5;
				effect[j].velocity.y = rand() % 11 - 5;
				effect[j].isAlive = 1;

				//パーティクル演算
				effect[j].timer--;
				if (effect[j].timer != 0) {
					effect[j].pos.x += effect[j].velocity.x;
					effect[j].pos.y += effect[j].velocity.y;
					effect[j].radius -= 0.025;
				}
				else if (effect[j].timer == 0) {
					effect[j].isAlive = 0;
				}
			}
		}
	}
}

void DrawParticles(Effect effect[]) {
	for (int i = 0; i < kParticlesNum; i++) {
		if (effect[i].isAlive == 1) {
			Novice::DrawEllipse(int(effect[i].pos.x), int(effect[i].pos.y),
				int(effect[i].radius), int(effect[i].radius),
				0.0f, WHITE, kFillModeSolid);
		}
	}
}