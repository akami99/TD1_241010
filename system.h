#pragma once
#include "structer.h"

void GetMapNum(GameObject* go, Bullet bullet[], System* s);

void SystemInitialize(System* s);

void TitleScreen(ImageInfo* ii);

void StageSelect(KeyInput* key, GameObject* go);

void StageSelectScreen(GameObject* go, ImageInfo* ii);

void GameOver(System* s, KeyInput* key);

void GameOverScreen(System* s, ImageInfo* ii);

void Clear(System* s, KeyInput* key);

void ClearScreen(System* s, ImageInfo* ii);