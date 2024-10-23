#include "structer.h"
#include "effect.h"
#include "enemy.h"
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

const int kParticlesNum = 50;

//初期化の関数
void EffectInitialize(Effect effect[]) {

	//乱数値の取得
	srand((unsigned)time(NULL));

	for (int i = 0; i < kParticlesNum; i++){
		//一粒ずつの情報を取得
		effect[i].pos.x = {};
		effect[i].pos.y = {};

		effect[i].isActive = 0;
		effect[i].timer = 60;	

		effect[i].acceleration.y = 1.0f;
		effect[i].radius = 3.0f;
	}
}

//敵死亡時のエフェクトを出す関数
void EnemyParticles(Effect effect[], System* s, Enemy enemy[]) {

	//乱数値の取得
	srand((unsigned)time(NULL));

	for (int i = 0; i < s->enemyNum; i++) {
		if (enemy[i].isAlive == 0) {
			for (int j = 0; j < kParticlesNum; j++) {
				//敵が死んだらエフェクト発動
				effect[j].isActive = 1;

				//エフェクトの寿命
				effect[j].timer = 60;

				//エフェクトの角度を取得
				effect[j].radian = float(rand() % 360);

				//角度を変換
				effect[j].radian = ((effect[j].degree / 180.0f) * float(M_PI));

				//エフェクトの速さを取得
				effect[j].speed = float(rand() % 21 - 10);

				//ベクトル生成
				effect[j].vector.x = cosf(effect[j].radian);
				effect[j].vector.y = sinf(effect[j].radian);

				//速度の生成
				effect[j].velocity.x = effect[j].vector.x * effect[j].speed;
				effect[j].velocity.y = effect[j].vector.y * effect[j].speed;

				effect[j].pos.x = float(enemy[i].pos.x);
				effect[j].pos.y = float(enemy[i].pos.y);
			}
		}
	}

	for (int i = 0; i < kParticlesNum; i++) {
		if (effect[i].isActive == 1) {
			//アクティブになったら寿命を減らしていく
			effect[i].timer--;

			//エフェクトを動かす
			effect[i].velocity.y += effect[i].acceleration.y;

			effect[i].pos.x += effect[i].velocity.x;
			effect[i].pos.y += effect[i].velocity.y;
		}

		if (effect[i].timer <= 0) {
			effect[i].isActive = 0;
		}
	}
}

void DrawParticles(Effect effect[]) {
	for (int i = 0; i < kParticlesNum; i++) {
		if (effect[i].isActive == 1) {
			Novice::DrawEllipse(int(effect[i].pos.x), int(effect[i].pos.y),
				int(effect[i].radius), int(effect[i].radius),
				0.0f, WHITE, kFillModeSolid);
		}
	}
}