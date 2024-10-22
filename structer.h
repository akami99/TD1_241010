#pragma once

//ヘッダーファイルのインクルード
#include <Novice.h>
#include "enum.h"

//グローバル変数の宣言
#define verticalBlock 7
#define besideBlock 7

//-----------------------------//
//           構造体を宣言        //
//-----------------------------//

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

//キー入力の構造体
struct KeyInput {
    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
};

//プレイヤーの構造体
struct Player {
    Vector2 pos;
    Vector2 posTmp; //仮で入れておくための変数(マップチップで動かす用)
    IntVector2 mapNum; // マップチップ番号を格納する変数
    Vector2 velocity;
    float radius;
    int direction;
    int isHit;  //当たったかどうか
    int isMove; 
    int skip;
};

//システム面関連の構造体
struct System {
    Scene scene;
    int enemyNum; //ステージごとの敵の数
    int gameoverNum;
    int clearNum;
};

//敵に関係する構造体
struct Enemy {
    IntVector2 pos;   // 動かさないので使いやすいintにした
    IntVector2 mapNum;
    int direction;
    int isAlive;  // やられたかどうか
};

//弾に関係する構造体
struct Bullet {
    IntVector2 pos;
    IntVector2 respawnPos; //弾の初期位置を保存する変数
    IntVector2 mapNum;
    Vector2 velocity; // 基本プレイヤーと同じ(演出時は,safety->別の変数||係数とか利用,speedy->これを変化させる)
    float radius;
    int direction;
    int isReflect;
    int isShot;
};

//エフェクトに関係する構造体
struct Effect {
    Vector2 pos;
    Vector2 velocity;
    float radius;
    int timer;
    int isAlive;
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