#include "structer.h"
#include "enemy.h"
#include "system.h"
#include "effect.h"

void BulletInitialize(System* s, Bullet bullet[], Enemy enemy[], GameObject* go) {
	for (int i = 0; i < s->enemyNum; i++) {
		bullet[i].pos.x = enemy[i].pos.x;
		bullet[i].pos.y = enemy[i].pos.y;
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
					enemy[num].isAlive = 1;// 生存フラグ
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


void EnemyAction(GameObject* go, Bullet bullet[],  Enemy enemy[], System* s) {

	if (go->player.isMove == 1) {
		for (int i = 0; i < s->enemyNum; i++) {
			if (bullet[i].isShot == 1 && enemy[i].isAlive == 1) {
				//弾の弾道計算
				if (bullet[i].direction == 6) {
					if (go->mapChip.map[bullet[i].mapNum.y - 1][bullet[i].mapNum.x] != 1) {
						bullet[i].pos.y -= int(bullet[i].velocity.y);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y - 1][bullet[i].mapNum.x] == 1) {
						bullet[i].pos.y -= int(bullet[i].velocity.y);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
				}
				if (bullet[i].direction == 8) {
					if (go->mapChip.map[bullet[i].mapNum.y + 1][bullet[i].mapNum.x] != 1) {
						bullet[i].pos.y += int(bullet[i].velocity.y);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y + 1][bullet[i].mapNum.x] == 1) {
						bullet[i].pos.y += int(bullet[i].velocity.y);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
				}
				if (bullet[i].direction == 7) {
					if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x - 1] != 1) {
						bullet[i].pos.x -= int(bullet[i].velocity.x);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x - 1] == 1) {
						bullet[i].pos.x -= int(bullet[i].velocity.x);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
					}
				}
				if (bullet[i].direction == 9) {
					if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x + 1] != 1) {
						bullet[i].pos.x += int(bullet[i].velocity.x);
						go->player.isMove = 0;
					}
					else if (go->mapChip.map[bullet[i].mapNum.y][bullet[i].mapNum.x + 1] == 1) {
						bullet[i].pos.x += int(bullet[i].velocity.x);
						bullet[i].isShot = 0;
						go->player.isMove = 0;
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
// 当たり判定
void BulletCollision(GameObject* go, Bullet bullet[], Enemy enemy[], System* s) {
	for (int i = 0; i < s->enemyNum; i++) {
		if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y && enemy[i].isAlive == 1) {
			if (bullet[i].direction == 6) { // 上
				if (go->player.direction != 2 && go->player.direction != 0) {
					go->player.isMove = 0;
					go->player.isHit = 1;
					bullet[i].isShot = 0;
				}
			}
			if (bullet[i].direction == 8) { // 下
				if (go->player.direction != 0 && go->player.direction != 2) {
					go->player.isMove = 0;
					go->player.isHit = 1;
					bullet[i].isShot = 0;
				}
			}
			if (bullet[i].direction == 7) { // 左
				if (go->player.direction != 1 && go->player.direction != 3) {
					go->player.isMove = 0;
					go->player.isHit = 1;
					bullet[i].isShot = 0;
				}
			}
			if (bullet[i].direction == 9) { // 右
				if (go->player.direction != 3 && go->player.direction != 1) {
					go->player.isMove = 0;
					go->player.isHit = 1;
					bullet[i].isShot = 0;
				}
			}
		}
	}
}

// 反射の判定(弾が動いた後に入れる)
void BulletReflect(GameObject* go, Bullet bullet[], System* s, Enemy enemy[]) {
	for (int i = 0; i < s->enemyNum; i++) {
		if (bullet[i].direction == 6) { // 上
			// 隣接時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y + go->player.velocity.y == go->player.pos.y) { // 1手前
				if (go->player.direction == 2) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
			// 重なっている時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) { 
				if (go->player.direction == 2) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
		}
		if (bullet[i].direction == 8) { // 下
			// 隣接時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y - go->player.velocity.y == go->player.pos.y) { // 1手前
				if (go->player.direction == 0) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
			// 重なっている時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) {
				if (go->player.direction == 0) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
		}
		if (bullet[i].direction == 7) { // 左
			// 隣接時の反射
			if (bullet[i].pos.x + go->player.velocity.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) { // 1手前
				if (go->player.direction == 1) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
			// 重なっている時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) {
				if (go->player.direction == 1) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
		}
		if (bullet[i].direction == 9) { // 右
			// 隣接時の反射
			if (bullet[i].pos.x - go->player.velocity.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) { // 1手前
				if (go->player.direction == 3) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
			// 重なっている時の反射
			if (bullet[i].pos.x == go->player.pos.x && bullet[i].pos.y == go->player.pos.y) {
				if (go->player.direction == 3) { // 逆向き
					bullet[i].isShot = 0;
				}
			}
		}
		if (bullet[i].isShot == 0 && enemy[i].isAlive == 1) {
			bullet[i].pos.x = bullet[i].respawnPos.x;
			bullet[i].pos.y = bullet[i].respawnPos.y;
		}
		if (enemy[i].isAlive == 0) {
			enemy[i].mapNum.x = (enemy[i].pos.x - go->mapChip.mapPos.x) / go->mapChip.blockSize;
			enemy[i].mapNum.y = (enemy[i].pos.y - go->mapChip.mapPos.y) / go->mapChip.blockSize;
			go->mapChip.map[enemy[i].mapNum.y][enemy[i].mapNum.x] = 0;
		}
	}
}

void DrawBullet(Bullet bullet[], Enemy enemy[], System* s, ImageInfo* ii) {
		for (int i = 0; i < s->enemyNum; i++) {
			if (bullet[i].isShot == 1 && enemy[i].isAlive == 1)
			{
				Novice::DrawSprite(
					400 + bullet[i].mapNum.x * 96 - int(bullet->radius) * 3,
					120 + bullet[i].mapNum.y * 96 - int(bullet->radius) * 3,
					ii->image.bullet, 1.0f, 1.0f, 0.0f, 0xffffffff);
			}
		}
	}