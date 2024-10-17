#pragma once

//ヘッダーファイルのインクルード
#include <Novice.h>

//グローバル変数の宣言
#define verticalBlock 7
#define besideBlock 7

//-----------------------------//
//           構造体を宣言        //
//-----------------------------//

//キー入力の構造体
struct KeyInput {
    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
};

//----ベクター構造体,intベクター構造体----
struct Vector2 {
    float x;
    float y;
};

struct IntVector2 {
    int x;
    int y;
};
//------------------------------------

//プレイヤーの構造体
struct Player {
    Vector2 pos;
    Vector2 posTmp; //仮で入れておくための変数(マップチップで動かす用)
    IntVector2 mapNum; // マップチップ番号を格納する変数
    Vector2 velocity;
    float radius;
    int direction;
};

//マップチップに関する構造体
struct MapChip {
    int map[verticalBlock][besideBlock];
    int stageNum;

    //マップ描画の初期位置
    IntVector2 pos;
    IntVector2 mapPos;

    //マップサイズ
    int blockSize;
};

//ゲーム内のオブジェクトをまとめる構造体
struct GameObject {
    Player player;
    MapChip mapChip;
};

//画像をまとめる構造体
struct Image {
    int box = { Novice::LoadTexture("white1x1.png") };
};

//画像の情報をまとめる構造体
struct ImageInfo {
    Image image;
   
};