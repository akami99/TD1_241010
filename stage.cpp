//ヘッダーファイルのインクルード
#include <Novice.h>
#include <structer.h>
#include <stage.h>

//グローバル変数の宣言
#define verticalBlock 7
#define besideBlock 7

//壁1,player2,敵3,穴4,空白0

void stage1(GameObject* go){
	go->mapChip[verticalBlock][besideBlock]{
		{1,1,1,1,1,1,0},
		{1,1,0,0,3,1,0},
		{1,0,2,0,0,1,0},
		{1,0,0,0,0,1,0},
		{1,3,0,0,0,1,0},
		{1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0},
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage2(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,0,3,0,2,1},
		{1,0,0,0,0,1},
		{1,0,0,0,0,1},
		{1,0,0,0,3,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage3(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,3,0,0,2,1},
		{1,4,0,0,3,1},
		{1,0,0,0,0,1},
		{1,3,0,0,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage4(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,0,0,0,0,1},
		{1,3,0,0,0,1},
		{1,0,0,0,0,0},
		{1,2,3,0,0,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage5(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,2,0,1,0,1},
		{1,1,0,0,0,1},
		{1,0,0,0,0,1},
		{1,0,3,3,3,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage6(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,0,0,0,0,1},
		{1,1,3,0,0,1},
		{1,0,0,3,1,1},
		{1,0,0,0,2,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage7(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,0,3,0,0,1},
		{1,0,1,2,0,1},
		{1,0,0,1,0,1},
		{1,0,0,0,3,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage8(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{1,2,0,0,1,3},
		{1,0,0,4,3,1},
		{1,0,0,0,0,1},
		{1,4,0,0,3,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}
		}
	}
};

void stage9(float& x, float& y, int& tileSize)
{
	int map[6][6]
	{
		{1,1,1,1,1,1},
		{3,4,0,0,0,1},
		{1,0,3,0,0,1},
		{1,0,0,4,3,1},
		{1,0,0,0,3,1},
		{1,1,1,1,1,1},
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[j][i] == 1)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0x7d7d7dFF, kFillModeSolid);
			}

			if (map[j][i] == 2)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			}

			if (map[j][i] == 3)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, RED, kFillModeSolid);
			}

			if (map[j][i] == 4)
			{
				x = float(j * tileSize);
				y = float(i * tileSize);

				Novice::DrawBox(int(x), int(y), tileSize, tileSize, 0.0f, BLUE, kFillModeSolid);
			}

		}
	}
