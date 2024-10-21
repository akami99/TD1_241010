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
    Scene scene = SELECT;

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


            break;
        case 4: //クリア画面



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



            break;
        case 1: //ステージセレクト



            break;
        case 2: //ゲームシーン
            DrawStage(go, ii);
            DrawPlayer(go, ii);
            DrawBullet(bullet, s);


            break;
        case 3: //ゲームオーバー
            Novice::ScreenPrintf(600, 360, "zakootu");


            break;
        case 4: //クリア画面
            Novice::ScreenPrintf(600, 360, "nice");


            break;
        }

        Novice::ScreenPrintf(20, 30, "stage %d", go->mapChip.stageNum);
        Novice::ScreenPrintf(20, 60, "isShot[0] : %d", bullet[0].isShot);
        Novice::ScreenPrintf(20, 90, "player.mapNum y:%d x:%d", go->player.mapNum.y, go->player.mapNum.x);
        Novice::ScreenPrintf(20, 120, "bullet.mapNum y:%d x:%d", bullet[1].mapNum.y, bullet[1].mapNum.x);
        for (int i = 0; i < s->enemyNum; i++) {
            Novice::ScreenPrintf(300, 30 + 30 * i, "bulletPos[%d] : %d", i, bullet[i].pos.y);
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