#include <Novice.h>
#include "player.h"
#include "structer.h"
#include "stage.h"

//グローバル変数
const char kWindowTitle[] = "反射反撃";

const int kScreenWidth = 1280;
const int kScreenHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    //構造体の実体化
    KeyInput keyInput;
    GameObject gameObject;
    ImageInfo imageinfo;

    //構造体を格納するポインタ型変数の宣言
    KeyInput* key = &keyInput;
    GameObject* go = &gameObject;
    ImageInfo* ii = &imageinfo;

    //各情報の初期化
    PlayerInitialize(go);
    StageInfoInitialize(go);

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

        PlayerMove(go, key);
        StageAggregate(go);

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        DrawStage(go, ii);
        ScreenSelectStage(go);
        DrawPlayer(go, ii);
        Novice::ScreenPrintf(20, 30, "mapNum:[%d][%d] = %d", int(go->player.mapNum.y), int(go->player.mapNum.x),
            go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x]);
        Novice::ScreenPrintf(20, 60, "playerPosTmp x:%d y:%d", int(go->player.posTmp.x), int(go->player.posTmp.y));
        Novice::ScreenPrintf(20, 90, "playerPos x:%d y:%d", int(go->player.pos.x), int(go->player.pos.y));

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