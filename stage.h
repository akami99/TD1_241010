#pragma once

//ヘッダーファイルのインクルード
#include "structer.h"

//ステージ情報を初期化する関数
void StageInfoInitialize(GameObject* go);

void ScreenSelectStage(GameObject* go);

//ステージ構成の関数
void Stage1(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage2(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage3(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage4(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage5(GameObject* go);
void Stage6(GameObject* go);
void Stage7(GameObject* go);
void Stage8(GameObject* go);
void Stage9(GameObject* go);

//ステージをまとめるための関数
void StageAggregate(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);

//ステージを描画するための関数
void DrawStage(GameObject* go, ImageInfo* ii);
