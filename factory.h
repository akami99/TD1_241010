#pragma once

struct Vector2
{
	float x;
	float y;
};

struct Player
{
	Vector2 pos;
	int radius;
	int speed;
};