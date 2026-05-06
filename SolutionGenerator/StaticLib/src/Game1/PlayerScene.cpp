#include "PlayerScene.h"
#include "Player.h"	
#include "Ground.h"
#include "RectCollider.h"
#include "Point.h"
#include "stdlib.h"
#include "LevelManager.h"
#include "SceneManager.h"

#define WIDTH 1000
#define HEIGHT 800

PlayerScene::PlayerScene()
{
	CreateEntity<Player>(Vector2(500, HEIGHT / 2), Vector2(80, 60), Vector2(0, 0))->OnInitialize();
}

PlayerScene* PlayerScene::GetPlayerScene()
{
	return this;
}


