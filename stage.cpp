//ヘッダーファイルのインクルード
#include <Novice.h>
#include "structer.h"
#include "stage.h"

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

void Stage1(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 0, 0, 3, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 3, 0, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	}; 

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage2(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 3, 0, 2, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 3, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage3(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 3, 0, 0, 2, 1, 0 },
		{ 1, 4, 0, 0, 3, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 3, 0, 0, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage4(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 3, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 0, 0 },
		{ 1, 2, 3, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage5(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 2, 0, 1, 0, 1, 0 },
		{ 1, 1, 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 0, 3, 3, 3, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage6(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 1, 3, 0, 0, 1, 0 },
		{ 1, 0, 0, 3, 1, 1, 0 },
		{ 1, 0, 0, 0, 2, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage7(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 3, 0, 0, 1, 0 },
		{ 1, 0, 1, 2, 0, 1, 0 },
		{ 1, 0, 0, 1, 0, 1, 0 },
		{ 1, 0, 0, 0, 3, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage8(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 2, 0, 0, 1, 3, 0 },
		{ 1, 0, 0, 4, 3, 1, 0 },
		{ 1, 0, 0, 0, 0, 1, 0 },
		{ 1, 4, 0, 0, 3, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

void Stage9(GameObject* go) {
	int map[VerticalBlock][BesideBlock] = {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 3, 4, 0, 0, 0, 1, 0 },
		{ 1, 0, 3, 0, 0, 1, 0 },
		{ 1, 0, 0, 4, 3, 1, 0 },
		{ 1, 0, 0, 0, 3, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};

	//ステージの構成をmapChip.mapに代入する
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
			go->mapChip.map[j][i] = map[j][i];
		}
	}
};

//ステージをまとめて変数によって呼び出すための関数
void StageAggregate(GameObject* go) {
	//ステージセレクト用の変数の値によって呼び出すステージを変える
	if (go->mapChip.stageNum == 1) {
		Stage1(go);
	}
	else if (go->mapChip.stageNum == 2) {
		Stage2(go);
	}
	else if (go->mapChip.stageNum == 3) {
		Stage3(go);
	}
	else if (go->mapChip.stageNum == 4) {
		Stage4(go);
	}
	else if (go->mapChip.stageNum == 5) {
		Stage5(go);
	}
	else if (go->mapChip.stageNum == 6) {
		Stage6(go);
	}
	else if (go->mapChip.stageNum == 7) {
		Stage7(go);
	}
	else if (go->mapChip.stageNum == 8) {
		Stage8(go);
	}
	else if (go->mapChip.stageNum == 9) {
		Stage9(go);
	}
};

//ステージを描画するための関数
void DrawStage(GameObject* go, ImageInfo* ii) {
	for (int i = 0; i < BesideBlock; i++) {
		for (int j = 0; j < VerticalBlock; j++) {
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
					1, 1, go->mapChip.blockSize, go->mapChip.blockSize, ii->image.box, 0xffff00
				);
			}

			if (go->mapChip.map[j][i] == 3) {
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
		}
	}
};
