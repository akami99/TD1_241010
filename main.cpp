#include <Novice.h>
#include <player.h>
#include <structer.h>


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

    //構造体を格納するポインタ型変数の宣言
    KeyInput* key = &keyInput;
    GameObject* go = &gameObject;

    //各情報の初期化
    playerInitialize(go);

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

        playerMove(go, key);

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        drawPlayer(go);

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