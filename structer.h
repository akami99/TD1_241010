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
    int tutorial1Num;
    int tutorial2Num;
    int gameFrame;
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
    Vector2 vector;
    Vector2 velocity;
    float speed;
    Vector2 acceleration;
    float radian;
    float degree;
    float radius;
    int isActive;  
    int timer;//パーティクル用
};

//マップチップに関する構造体
struct MapChip {
    int map[verticalBlock][besideBlock];
    int stageNum;

    //チュートリアル用の初期位置
    IntVector2 tutorialPos;
    IntVector2 tutorialMapPos;

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
    int terop1 = { Novice::LoadTexture("./resources/images/Tutorial/tutorialTerop1.png") };
    int terop2 = { Novice::LoadTexture("./resources/images/Tutorial/tutorialTerop2.png") };
    int box = { Novice::LoadTexture("./Resources/Images/Players/player.png") };
    int player = { Novice::LoadTexture("./Resources/Images/Players/player.png") }; // プレイヤー
    int bullet = { Novice::LoadTexture("./Resources/Images/Bullets/enemyBullet.png") };// 弾
    int enemyUp = { Novice::LoadTexture("./Resources/Images/MapTips/enemyUp.png") }; // 敵
    int enemyLeft = { Novice::LoadTexture("./Resources/Images/MapTips/enemyLeft.png") }; // 敵
    int enemyDown = { Novice::LoadTexture("./Resources/Images/MapTips/enemyDown.png") }; // 敵
    int enemyRight = { Novice::LoadTexture("./Resources/Images/MapTips/enemyRight.png") }; // 敵
    int wall = { Novice::LoadTexture("./Resources/Images/MapTips/block.png") }; // 壁
    int pitFall = { Novice::LoadTexture("./Resources/Images/MapTips/pitFall.png") }; // 穴
    int titleBG = { Novice::LoadTexture("./Resources/Images/TitleScenes/titleBG.png") }; // タイトル画面
    int gameBG = { Novice::LoadTexture("./Resources/Images/GameScenes/stageBG.png") }; // ステージの背景
    int gameOverBG = { Novice::LoadTexture("./Resources/Images/GameOverScenes/gameOverBG.png") }; // ゲームオーバーの背景
    int clearBG = { Novice::LoadTexture("./Resources/Images/ClearScenes/clearBG.png") }; // クリアの背景
    int clear = { Novice::LoadTexture("./Resources/Images/ClearScenes/clear.png") }; // クリア
    int selectA = { Novice::LoadTexture("./Resources/Images/UIs/selectA.png") }; // Aでの操作を表す文字
    int selectD = { Novice::LoadTexture("./Resources/Images/UIs/selectD.png") }; // Dでの操作を表す文字
    int space = { Novice::LoadTexture("./Resources/Images/UIs/SPACE.png") }; // SPACEでの操作を表す文字
    int stage = { Novice::LoadTexture("./Resources/Images/UIs/stage.png") }; // Stageを表す文字
    int tutorial = { Novice::LoadTexture("./Resources/Images/UIs/tutorial.png") }; // Tutorialを表す文字
    int returns = { Novice::LoadTexture("./Resources/Images/UIs/returns.png") }; // StageかTitleを表す文字
    int number = { Novice::LoadTexture("./Resources/Images/UIs/number.png") }; // number
};

//画像の情報をまとめる構造体
struct ImageInfo {
    Image image;
   
};