#include "structer.h"
#include "enum.h"


//内積で向きを返す関数
int Dot(const IntVector2 dir1, const IntVector2 dir2) {
	int result = 0;
	result = dir1.x* dir2.x + dir1.y * dir2.y;
	return result;
}