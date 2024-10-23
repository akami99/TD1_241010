#include <Novice.h>
#include "player.h"
#include "structer.h"
#include "stage.h"
#include "enemy.h"
#include "system.h"
#include "effect.h"

//グローバル変数
const char kWindowTitle[] = "反射反撃";

const int kMaxEnemy = 10;
const int kParticlesNum = 100;
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
    Effect effect[kParticlesNum];
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
    EffectInitialize(effect);
    SystemInitialize(s);
    PlayerInitialize(go);

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
        case TITLE: //タイトル
            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                eliminate = 0;
                EnemyInitialize(go, enemy, bullet, s);
                BulletInitialize(s, bullet, enemy, go);
                TutorialInitialize1(go);
                StageAggregate(go, s, enemy, bullet);
                scene = TUTORIAL;
            }

            break;
        case TUTORIAL:
            PlayerMove(go, bullet, key, s);
            BulletCollision(go, bullet, enemy, s);
            EnemyAction(go, bullet, enemy, s);
            BulletReflect(go, bullet, s, enemy);

            if (go->mapChip.stageNum == 100) {
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
                        s->tutorial1Num++;
                    }
                }
            }

            if (s->tutorial1Num == 1 && key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                go->mapChip.stageNum = 101;
                EnemyInitialize(go, enemy, bullet, s);
                BulletInitialize(s, bullet, enemy, go);
                TutorialInitialize2(go);
                StageAggregate(go, s, enemy, bullet);;
                go->player.skip = 1;
                eliminate = 0;
                break;
            }

            if (go->mapChip.stageNum == 101) {
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

                if (go->player.isHit == 1) {
                    s->tutorial2Num = 1;
                    go->mapChip.stageNum = 1;
                    scene = GAMEOVER;
                }
            }

            if (s->tutorial2Num == 1 && key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                go->mapChip.stageNum = 1;
                EnemyInitialize(go, enemy, bullet, s);
                BulletInitialize(s, bullet, enemy, go);
                StageAggregate(go, s, enemy, bullet);;
                eliminate = 0;
                scene = SELECT;
                break;
            }

            break;
        case SELECT: //ステージセレクト
            StageSelect(key, go);

            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0) {
                eliminate = 0;
                SystemInitialize(s);
                PlayerInitialize(go);
                StageAggregate(go, s, enemy, bullet);
                scene = GAME;
            }

            break;
        case GAME: //ゲームシーン
            eliminate = 0;

            PlayerMove(go, bullet, key, s);
            BulletCollision(go, bullet, enemy, s);
            EnemyAction(go, bullet, enemy, s);
            BulletReflect(go, bullet, s, enemy);
            /*EnemyParticles(effect, s, enemy);*/

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
        case GAMEOVER: //ゲームオーバー
            GameOver(s, key);
            if (s->tutorial2Num == 1 && key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->gameoverNum == 0) {
                scene = SELECT;
            }
            else if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->gameoverNum == 0) {
                SystemInitialize(s);
                PlayerInitialize(go);
                scene = SELECT;
            }
            else if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->gameoverNum == 1) {
                SystemInitialize(s);
                PlayerInitialize(go);
                StageAggregate(go, s, enemy, bullet);
                scene = GAME;            
            }

            break;
        case CLEAR: //クリア画面
            Clear(s, key);
            if (key->keys[DIK_SPACE] && key->preKeys[DIK_SPACE] == 0 && s->clearNum == 0) {
                SystemInitialize(s);
                PlayerInitialize(go);
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
        case TITLE: //タイトル
            TitleScreen(ii);
            break;
            
        case TUTORIAL:
            Novice::DrawSprite(0, 0, ii->image.gameBG, 1.0f, 1.0f, 0.0f, WHITE);
            DrawStage(go, ii);
            DrawPlayer(go, ii);
            DrawBullet(bullet,  enemy, s, ii);
            if (go->mapChip.stageNum == 100) {
                Novice::DrawSprite(400, 400, ii->image.terop1, 1.0f, 1.0f, 0.0f, WHITE);
            }
            if (go->mapChip.stageNum == 101) {
                Novice::DrawSprite(400, 496, ii->image.terop2, 1.0f, 1.0f, 0.0f, WHITE);
            }

            break;
            
        case SELECT: //ステージセレクト
           StageSelectScreen(go, ii);
            break;
            
        case GAME: //ゲームシーン
            Novice::DrawSprite(0, 0, ii->image.gameBG, 1.0f, 1.0f, 0.0f, 0xffffffff);
            DrawStage(go, ii);
            DrawPlayer(go, ii);
            DrawBullet(bullet,  enemy, s, ii);
            Novice::DrawQuad(140, 300, 204, 300, 140, 364, 204, 364, go->player.skip * 64, 0, 64, 64, ii->image.number, 0xffffffff);
            Novice::DrawSprite(45, 500, ii->image.space, 1.0f, 1.0f, 0.0f, 0xffffffff);
            break;
            
        case GAMEOVER: //ゲームオーバー
              GameOverScreen(s, ii);
            break;
            
        case CLEAR: //クリア画面
            ClearScreen(s, ii);

            break;
        }

        /*Novice::ScreenPrintf(20, 30, "scene:%d", scene);
        Novice::ScreenPrintf(20, 60, "stageNum:%d", go->mapChip.stageNum);
        Novice::ScreenPrintf(20, 90, "effect posX:%f", effect[0].pos.x);
        Novice::ScreenPrintf(20, 120, "effect posY:%f", effect[0].pos.y);
        Novice::ScreenPrintf(20, 150, "effect radius:%f", effect[0].radius);
        Novice::ScreenPrintf(20, 180, "enemy posX:%d", enemy[0].pos.x);
        Novice::ScreenPrintf(20, 210, "enemy posY:%d", enemy[0].pos.y);
        Novice::ScreenPrintf(20, 240, "enemy isAlive:%d", enemy[0].isAlive);*/

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