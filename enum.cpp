#include "structer.h"
#include "enum.h"

//オブジェクトのマップ番号を取得する関数
void GetMapNum(GameObject* go, Bullet bullet[], System* s) {
	//プレイヤーのマップ番号
	go->player.mapNum.x = (int(go->player.pos.x) - go->mapChip.mapPos.x) / go->mapChip.blockSize;
	go->player.mapNum.y = (int(go->player.pos.y) - go->mapChip.mapPos.y) / go->mapChip.blockSize;

	//弾のマップ番号
	for (int i = 0; i < s->enemyNum; i++) {
		bullet[i].mapNum.x = (bullet[i].pos.x - go->mapChip.mapPos.x) / go->mapChip.blockSize;
		bullet[i].mapNum.y = (bullet[i].pos.y - go->mapChip.mapPos.y) / go->mapChip.blockSize;
	}
}

//内積で向きを返す関数
int Dot(const IntVector2 dir1, const IntVector2 dir2) {
	int result = 0;
	result = dir1.x* dir2.x + dir1.y * dir2.y;
	return result;
}