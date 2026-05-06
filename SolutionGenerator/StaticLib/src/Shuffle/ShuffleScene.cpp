#include "ShuffleScene.h"
#include "Ball.h"
#include "ShufflePlayer.h"

ShuffleScene::ShuffleScene()
{
	CreateEntity<ShufflePlayer>(Vector2(200, 200), Vector2(50, 50), Vector2(0.5, 0.5))->Init();
	
	CreateEntity<Ball>(Vector2(101, 100), Vector2(50, 50), Vector2(0.5, 0.5))->Init();
}

ShuffleScene* ShuffleScene::GetSelf()
{
	return this;
}