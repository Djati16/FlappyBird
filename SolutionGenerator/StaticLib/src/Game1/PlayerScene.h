#pragma once
#include "Scene.h"
class SceneManager;
class PlayerScene : public Scene
{
private:

public:
	PlayerScene();
	PlayerScene* GetPlayerScene();
	friend class LevelManager;
};

