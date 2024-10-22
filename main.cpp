#include <Novice.h>
#include "player.h"
#include "structer.h"
#include "stage.h"
#include "enemy.h"
#include "system.h"

//グローバル変数
const char kWindowTitle[] = "反射反撃";

const int kMaxEnemy = 10;
const int kScreenWidth = 1280;
const int kScreenHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    //構造体の実体化
    KeyInput keyInput;
    GameObject gameObject;
    System system;
    ImageInfo imageinfo;
    Bullet bullet[kMaxEnemy];
    Enemy enemy[kMaxEnemy];
    Scene scene = TITLE;

    //構造体を格納するポインタ型変数の宣言
    KeyInput* key = &keyInput;
    GameObject* go = &gameObject;
    System* s = &system;
    ImageInfo* ii = &imageinfo;

    // 敵の全滅確認用(仮)
    int eliminate{};

    //各情報の初期化
    StageInfoInitialize(go);
    SystemInitialize(s);

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(key->preKeys, key->keys, 256);
        Novice::GetHitKeyStateAll(key->keys);

        ///
        /// ↓更新処理ここから
        ///

        switch (scene) {
        case 0: //タイトル
            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                scene = SELECT;
            }


            break;
        case 1: //ステージセレクト
            StageSelect(key, go);

            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                eliminate = 0;

                SystemInitialize(s);
                PlayerInitialize(go);
                StageAggregate(go, s, enemy, bullet);
                scene = GAME;
            }

            break;
        case 2: //ゲームシーン
            eliminate = 0;

            PlayerMove(go, bullet, key, s);
            BulletCollision(go, bullet, enemy, s);
            EnemyAction(go, bullet, enemy, s);
            BulletReflect(go, bullet, s);

            for (int i = 0; i < s->enemyNum; i++) {
                if (bullet[i].isShot == 0) {
                    enemy[i].isAlive = 0;
                }
                if (enemy[i].isAlive == 0) {
                    enemy[i].mapNum.x = (enemy[i].pos.x - go->mapChip.mapPos.x) / go->mapChip.blockSize;
                    enemy[i].mapNum.y = (enemy[i].pos.y - go->mapChip.mapPos.y) / go->mapChip.blockSize;
                    go->mapChip.map[enemy[i].mapNum.y][enemy[i].mapNum.x] = 0;
                }
            }

            for (int i = 0; i < s->enemyNum; i++) {
                if (enemy[i].isAlive == 0) {
                    eliminate++;
                }
                if (eliminate == s->enemyNum) {
                    scene = CLEAR;
                    break;
                }
            }
            if (go->player.isHit == 1) {
                scene = GAMEOVER;
            }


            break;
        case 3: //ゲームオーバー
            GameOver(s, key);
            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->gameoverNum == 0) {
                scene = SELECT;
            }
            else if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->gameoverNum == 1) {
                SystemInitialize(s);
                PlayerInitialize(go);
                StageAggregate(go, s, enemy, bullet);
                scene = GAME;            
            }

            break;
        case 4: //クリア画面
            Clear(s, key);
            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->clearNum == 0) {
                scene = SELECT;
            }
            else if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->clearNum == 1) {
                SystemInitialize(s);
                PlayerInitialize(go);
                StageAggregate(go, s, enemy, bullet);
                scene = GAME;
            }


            break;
        }


        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///


        switch (scene) {
        case 0: //タイトル
            TitleScreen();


            break;
        case 1: //ステージセレクト
            StageSelectScreen(go);


            break;
        case 2: //ゲームシーン
            DrawStage(go, ii);
            DrawPlayer(go, ii);
            DrawBullet(bullet, s);


            break;
        case 3: //ゲームオーバー
            GameOverScreen(s);


            break;
        case 4: //クリア画面
            ClearScreen(s);
            break;
        }
        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (key->preKeys[DIK_ESCAPE] == 0 && key->keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}