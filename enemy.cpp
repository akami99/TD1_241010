#include "structer.h"
#include "enemy.h"
#include "enum.h"

void BulletInitialize(System* s, Bullet bullet[], Enemy enemy[], GameObject* go) {
	for (int i = 0; i < s->enemyNum; i++) {
		bullet[i].pos.x = enemy[i].pos.x;
		bullet[i].pos.y = enemy[i].pos.y;
		bullet[i].posTmp.x = enemy[i].pos.x;
		bullet[i].posTmp.y = enemy[i].pos.y;
		bullet[i].respawnPos.x = enemy[i].pos.x;
		bullet[i].respawnPos.y = enemy[i].pos.y;
		bullet[i].radius = 16.0f;
		bullet[i].velocity.x = 96.0f;
		bullet[i].velocity.y = 96.0f;
		bullet[i].mapNum.x = (bullet[i].pos.x - go->mapChip.mapPos.x) / go->mapChip.blockSize;
		bullet[i].mapNum.y = (bullet[i].pos.y - go->mapChip.mapPos.y) / go->mapChip.blockSize;
		bullet[i].direction = enemy[i].direction;
		bullet[i].isReflect = { 0 };
		bullet[i].isShot = { 1 };
	}
}


void EnemyInitialize(GameObject* go, Enemy enemy[], Bullet bullet[], System* s) {
	for (int num = 0; num < s->enemyNum; num++) {
		for (int i = 0; i < 7; i++) { // 7=>マップの最大数
			for (int j = 0; j < 7; j++) {
				if (go->mapChip.map[i][j] >= 6 && go->mapChip.map[i][j] <= 9) {//6<=x<=9
					enemy[num].pos.x = j * 96 + 400;//座標
					enemy[num].pos.y = i * 96 + 120;
					//敵の向き
					enemy[num].direction = go->mapChip.map[i][j];
					//bullet[num].direction = enemy[num].direction;
					BulletInitialize(s, bullet, enemy, go);
					num++;
				}
			}
		}
	}
}

void EnemyAction(GameObject* go, Bullet bullet[], System* s) {
	if (go->player.isMove == 1) {
		for (int i = 0; i < s->enemyNum; i++) {
			if (bullet[i].isShot == 1) {
				//弾の弾道計算
				if (bullet[i].direction == 6) {
					bullet[i].posTmp.y -= int(bullet[i].velocity.y);
					if (go->mapChip.map[bullet[i].mapNum.y - 1][bullet[i].mapNum.x] ==
						go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x] && go->player.direction != 2) {
						go->player.isHit = 1;
						bullet[i].isShot = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y - 1][bullet[i].mapNum.x] == 0) {
						bullet[i].pos.y -= int(bullet[i].velocity.y);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y - 1][bullet[i].mapNum.x] == 1) {
						bullet[i].pos.y -= int(bullet[i].velocity.y);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
					else {
						bullet[i].posTmp.y += int(bullet[i].velocity.y);
					}
				}
				if (bullet[i].direction == 8) {
					bullet[i].posTmp.y += int(bullet[i].velocity.y);
					if (go->mapChip.map[bullet[i].mapNum.y + 1][bullet[i].mapNum.x] == 0) {
						bullet[i].pos.y += int(bullet[i].velocity.y);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y + 1][bullet[i].mapNum.x] == 1) {
						bullet[i].pos.y += int(bullet[i].velocity.y);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
					else {
						bullet[i].posTmp.y -= int(bullet[i].velocity.y);
					}
				}
				if (bullet[i].direction == 7) {
					bullet[i].posTmp.x -= int(bullet[i].velocity.x);
					if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x - 1] == 0) {
						bullet[i].pos.x -= int(bullet[i].velocity.x);
						go->player.isMove = 0;
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x - 1] == 1) {
						bullet[i].pos.x -= int(bullet[i].velocity.x);
						bullet[i].isShot = 0;
					}
					else {
						bullet[i].posTmp.x += int(bullet[i].velocity.x);
					}
				}
				if (bullet[i].direction == 9) {
					bullet[i].posTmp.x += int(bullet[i].velocity.x);
					if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x + 1] == 0) {
						bullet[i].pos.x += int(bullet[i].velocity.x);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x + 1] == 1) {
						bullet[i].pos.x += int(bullet[i].velocity.x);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
					else {
						bullet[i].posTmp.x -= int(bullet[i].velocity.x);
					}
				}
			}

			//弾の復活処理
			if (bullet[i].isShot == 0) {
				bullet[i].pos.x = bullet[i].respawnPos.x;
				bullet[i].pos.y = bullet[i].respawnPos.y;
				bullet[i].isShot = 1;
			}
		}
	}
}

//void CollisionBullet(GameObject* go, Bullet bullet[]) {
//	IntVector2 playerDir = { 0 };
//	IntVector2 bulletDir[s->enemyNum] = { 0 };
//	IntVector2 bulletFutuerMap[s->enemyNum] = { 0 };
//
//	/// 向きの1次元配列化-------------------------
//	// プレイヤー
//	if (go->player.direction == 0) { // 上
//		playerDir.x = 0;
//		playerDir.y = -1;
//	}
//	else if (go->player.direction == 1) { // 右
//		playerDir.x = 1;
//		playerDir.y = 0;
//	}
//	else if (go->player.direction == 2) { // 下
//		playerDir.x = 0;
//		playerDir.y = 1;
//	}
//	else if (go->player.direction == 3) { // 左
//		playerDir.x = -1;
//		playerDir.y = 0;
//	}
//	// 弾
//	for (int i = 0; i < enemyArray; i++) {
//		if (bullet[i].direction == 6) { // 上
//			bulletDir[i].x = 0;
//			bulletDir[i].y = -1;
//		}
//		else if (bullet[i].direction == 9) { // 右
//			bulletDir[i].x = 1;
//			bulletDir[i].y = 0;
//		}
//		else if (bullet[i].direction == 8) { // 下
//			bulletDir[i].x = 0;
//			bulletDir[i].y = 1;
//		}
//		else if (bullet[i].direction == 7) { // 左
//			bulletDir[i].x = -1;
//			bulletDir[i].y = 0;
//		}
//		///----------------------------------------
//
//		// 弾のマップチップ上での位置
//		//bullet[i].mapNum.x = (int(bullet[i].pos.x) - 352) / 96; // -マップ初期位置/マップサイズ
//		//bullet[i].mapNum.y = (int(bullet[i].pos.y) - 72) / 96;
//
//		// 当たり判定
//		// プレイヤー->弾の時
//		if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x] ==
//			go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x]) {
//			if (Dot(playerDir, bulletDir[i]) < 0) {//正面衝突(反射)
//				bullet[i].isReflect = 1;//"反射した"フラグ
//			}
//			else {
//				bullet[i].isReflect = 0;
//				go->player.isHit = 1;        // "ヒットした"フラグ
//			}
//		}
//	
//		// プレイヤー行動後の弾の演算
//		bulletFutuerMap[i].x = bullet[i].mapNum.x + bulletDir[i].x;
//		bulletFutuerMap[i].y = bullet[i].mapNum.y + bulletDir[i].y;
//		// プレイヤー-><-弾の時
//		if (go->mapChip.map[bulletFutuerMap[i].y][bulletFutuerMap[i].x] ==
//			go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x]) {
//			if (Dot(playerDir, bulletDir[i]) < 0) { // 正面衝突(反射)
//				bullet[i].isReflect = 1; // "反射した"フラグ
//			}
//			else {
//				bullet[i].isReflect = 0;
//				go->player.isHit = 1;        // "ヒットした"フラグ
//			}
//		}
//	}
//}
//
////弾の動作に関する関数
//void BulletMove(GameObject* go, Bullet bullet[], Enemy enemy[]) {
//	IntVector2 enemyDir[s->enemyNum] = {};
//
//	// 敵の座標が出来ていたら省略(関数の外でやっておく<-本来は既に定義されているものとする)------------------------------------------------
//	for (int num = 0; num < enemyArray; num++) {
//		for (int i = 0; i < 7; i++) { // 7=>マップの最大数
//			for (int j = 0; j < 7; j++) {
//				if (go->mapChip.map[i][j] >= 6 && go->mapChip.map[i][j] <= 9) { // 6<=x<=9
//					enemy[num].pos.x = j * 96; // 座標
//					enemy[num].pos.y = i * 96;
//					// 敵の向き
//					enemy[num].direction = go->mapChip.map[i][j];
//					bullet[num].direction = enemy[num].direction;
//				}
//			}
//		}
//	}
//	//-----------------------------------------------------------------------------
//
//	/// 向きの1次元配列化-------------------------
//	// 敵
//	for (int i = 0; i < enemyArray; i++) {
//		if (enemy[i].direction == 6) { // 上
//			enemyDir[i].x = 0;
//			enemyDir[i].y = -1;
//		}
//		else if (enemy[i].direction == 9) { // 右
//			enemyDir[i].x = 1;
//			enemyDir[i].y = 0;
//		}
//		else if (enemy[i].direction == 8) { // 下
//			enemyDir[i].x = 0;
//			enemyDir[i].y = 1;
//		}
//		else if (enemy[i].direction == 7) { // 左
//			enemyDir[i].x = -1;
//			enemyDir[i].y = 0;
//		}
//
//		///----------------------------------------
//
//		// 敵のマップチップ上での位置
//		enemy[i].mapNum.x = (int(enemy[i].pos.x) - 352) / 96; // -マップ初期位置/マップサイズ
//		enemy[i].mapNum.y = (int(enemy[i].pos.y) - 72) / 96;
//
//		// 弾のマップチップ上での位置
//		//bullet[i].mapNum.x = (int(bullet[i].pos.x) - 352) / 96; // -マップ初期位置/マップサイズ
//		//bullet[i].mapNum.y = (int(bullet[i].pos.y) - 72) / 96;
//
//		if (bullet[i].isShot == 0) { // 発射されていない時
//			bullet[i].isShot = true; // 発射する
//
//			// プレイヤー行動後の弾の演算
//			if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x] !=
//				go->mapChip.map[go->player.mapNum.y][go->player.mapNum.x]) {
//				if (go->player.isMove == 1) { // プレイヤー動かすと
//					bullet[i].pos.x = (bullet[i].mapNum.y + enemyDir[i].x) * 96; // マップサイズ
//					bullet[i].pos.y = (bullet[i].mapNum.x + enemyDir[i].y) * 96;
//
//					go->player.isMove = 0; // プレイヤーの移動完了
//				}
//			}
//
//		}
//		
//	}
//}

	void DrawBullet(Bullet bullet[], System* s) {
		for (int i = 0; i < s->enemyNum; i++) {
			if (bullet[i].isShot == 1)
			{
				Novice::DrawEllipse(int(bullet[i].pos.x), int(bullet[i].pos.y),
					int(bullet[i].radius), int(bullet[i].radius), 0.0f, BLUE, kFillModeWireFrame);
			}
		}
	}