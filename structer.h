#pragma once

//-----------------------------//
//           構造体を宣言           //
//-----------------------------//

//キー入力の構造体
struct KeyInput {
    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
};

//ベクター構造体
struct Vector2 {
    float x;
    float y;
};

//プレイヤーの構造体
struct Player {
    Vector2 pos;
    Vector2 velocity;
    float radius;
};

//ゲーム内のオブジェクトをまとめる構造体
struct GameObject {
    Player player;
};