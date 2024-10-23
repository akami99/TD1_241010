#pragma once

//ヘッダーファイルのインクルード
#include "structer.h"

//ステージ情報を初期化する関数
void StageInfoInitialize(GameObject* go);
void TutorialInitialize1(GameObject* go);
void TutorialInitialize2(GameObject* go);

//ステージ構成の関数
void StageTutorial1(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void StageTutorial2(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage1(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage2(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage3(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage4(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage5(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage6(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage7(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage8(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);
void Stage9(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);

//ステージをまとめるための関数
void StageAggregate(GameObject* go, System* s, Enemy enemy[], Bullet bullet[]);

//ステージを描画するための関数
void DrawStage(GameObject* go, ImageInfo* ii);
