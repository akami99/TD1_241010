#pragma once
#include "structer.h"

void GetMapNum(GameObject* go, Bullet bullet[], System* s);

void SystemInitialize(System* s);

void TitleScreen();

void StageSelect(KeyInput* key, GameObject* go);

void StageSelectScreen(GameObject* go);

void GameOver(System* s, KeyInput* key);

void GameOverScreen(System* s);

void Clear(System* s, KeyInput* key);

void ClearScreen(System* s);