//ヘッダーファイルのインクルード
#include <Novice.h>
#include "structer.h"
#include "stage.h"
#include "enemy.h"

//グローバル変数の宣言
#define VerticalBlock 7
#define BesideBlock 7

//ステージの情報を初期化する関数
void StageInfoInitialize(GameObject* go) {
	go->mapChip.stageNum = 1;

	//マップ描画の初期位置の初期化
	go->mapChip.pos.x = 352;
	go->mapChip.pos.y = 72;

	go->mapChip.blockSize = 96;
};

//0 空白,1 壁,2 穴,
//4 自機
//6~9敵 6 上向き, 7 左向き, 8 下向き, 9 右向き
void Stage1(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 0, 0, 8, 1, 0 },
		{ 1, 0, 4, 0, 0, 1 ,0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 6, 0, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	}; 

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 192.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 192.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage2(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 8, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 7, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 384.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 96.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage3(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);

	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 8, 0, 0, 4, 1, 0 },
		{ 1, 0, 0, 0, 7, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 9, 0, 0, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 384.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 96.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage4(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);

	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 9, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 6, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 96.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 384.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage5(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 1, 0 },
		{ 1, 1, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 6, 6, 6, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 96.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 96.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage6(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 1, 9, 0, 0, 1, 0 },
		{ 1, 0, 0, 7, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 384.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 384.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage7(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 9, 0, 0, 1, 0 },
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 1, 0, 0, 1, 0, 1, 0 },
		{ 1, 0, 0, 0, 7, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 288.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 192.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage8(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 4, 0, 0, 8, 1, 0 },
		{ 1, 0, 0, 2, 7, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 4, 0, 0, 7, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 96.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 96.0f;
	go->player.posTmp.y = go->player.pos.y;
};

void Stage9(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 9, 2, 0, 0, 1, 0 },
		{ 1, 0, 8, 0, 0, 1, 0 },
		{ 1, 0, 0, 2, 7, 1, 0 },
		{ 1, 0, 0, 0, 4, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			if (map[j][i] == 4) { // 作成補助用
				map[j][i] = 0;
			}
			go->mapChip.map[j][i] = map[j][i];

			//敵の数をカウント
			if (map[j][i] >= 6 && map[j][i] <= 9) {
				s->enemyNum++;
			}
		}
	}

	EnemyInitialize(go, enemy, bullet, s);
	BulletInitialize(s, bullet, enemy, go);
	go->player.pos.x = 400.0f + 384.0f;
	go->player.posTmp.x = go->player.pos.x;
	go->player.pos.y = 120.0f + 384.0f;
	go->player.posTmp.y = go->player.pos.y;
};

//ステージをまとめて変数によって呼び出すための関数
void StageAggregate(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]) {
	//ステージセレクト用の変数の値によって呼び出すステージを変える
	if (go->mapChip.stageNum == 1) {
		Stage1(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 2) {
		Stage2(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 3) {
		Stage3(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 4) {
		Stage4(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 5) {
		Stage5(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 6) {
		Stage6(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 7) {
		Stage7(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 8) {
		Stage8(go, s, enemy, bullet);
	}
	else if (go->mapChip.stageNum == 9) {
		Stage9(go, s, enemy, bullet);
	}
};


//ステージを描画するための関数
void DrawStage(GameObject* go, ImageInfo* ii) {

	for (int i = 0; i < besideBlock; i++) {

		if (go->mapChip.map[0][i] !=0 && go->mapChip.stageNum == 0) {
			Novice::DrawQuad(
				//左上
				go->mapChip.pos.x + (go->mapChip.blockSize * i),
				go->mapChip.pos.y + (go->mapChip.blockSize),

				//右上
				(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
				go->mapChip.pos.y + (go->mapChip.blockSize),

				//左下
				go->mapChip.pos.x + (go->mapChip.blockSize * i),
				(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize),

				//右下
				(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
				(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize),

				//画像の情報
				1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, BLACK
			);

		}



		for (int j = 0; j < verticalBlock; j++) {

	
			if (go->mapChip.map[j][i] == 1) {
				Novice::DrawQuad(
					//左上
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//左下
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, BLACK
				);
			}

			if (go->mapChip.map[j][i] == 2) {
				Novice::DrawQuad(
					//左上
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//左下
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//画像の情報

					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, BLUE
				);
			}


			if (go->mapChip.map[j][i] == 4) {
				Novice::DrawQuad(
					//左上
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//左下
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, WHITE
				);
			}

			if (go->mapChip.map[j][i] == 6) {
				Novice::DrawQuad(
					//左上(頂点)
					int(go->mapChip.pos.x + (go->mapChip.blockSize * i) + (go->mapChip.blockSize * i / (2 * i))),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//右上(頂点)
					int(go->mapChip.pos.x + (go->mapChip.blockSize * i) + (go->mapChip.blockSize * i / (2 * i))),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//左下
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, RED


				);

			}

			if (go->mapChip.map[j][i] == 7) {

				Novice::DrawQuad(
					//左上(頂点)
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					int(go->mapChip.pos.y + (go->mapChip.blockSize * j) + (go->mapChip.blockSize * j / (2 * j))),

					///右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					///左下(頂点)
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					int(go->mapChip.pos.y + (go->mapChip.blockSize * j) + (go->mapChip.blockSize * j / (2 * j))),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, RED
				);
			}

			if (go->mapChip.map[j][i] == 8) {
				Novice::DrawQuad(
					//左上
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					//左下(頂点)
					int(go->mapChip.pos.x + (go->mapChip.blockSize * i) + (go->mapChip.blockSize * i / (2 * i))),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下(頂点)
					int(go->mapChip.pos.x + (go->mapChip.blockSize * i) + (go->mapChip.blockSize * i / (2 * i))),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),


					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, RED


				);

			}

			if (go->mapChip.map[j][i] == 9) {

				Novice::DrawQuad(
					//左上(頂点)
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					go->mapChip.pos.y + (go->mapChip.blockSize * j),

					///右上
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					int(go->mapChip.pos.y + (go->mapChip.blockSize * j) + (go->mapChip.blockSize * j / (2 * j))),

					///左下(頂点)
					go->mapChip.pos.x + (go->mapChip.blockSize * i),
					(go->mapChip.pos.y + go->mapChip.blockSize) + (go->mapChip.blockSize * j),

					//右下
					(go->mapChip.pos.x + go->mapChip.blockSize) + (go->mapChip.blockSize * i),
					int(go->mapChip.pos.y + (go->mapChip.blockSize * j) + (go->mapChip.blockSize * j / (2 * j))),

					//画像の情報
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, RED
				);
			}


		}
	}
};
