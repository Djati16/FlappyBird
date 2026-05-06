#pragma once
#include "SceneManager.h"

class Window;
class Camera;
class LevelManager;
class Timer;
class ClickerManager;
class Input;
class Writer;
class Sprite;

class GameManager
{
private:
	Sprite* _background;
	Writer* _writer;
	Window* _window = nullptr;
	Camera* _camera = nullptr;
	Scene* _playerScene = nullptr;
	Timer* _timer;
	Input* _input;

	LevelManager* _levelManager = nullptr;
	ClickerManager* _clickerManager = nullptr;

	bool _entityInRange = false;
	float _deltatime;
	float fixedStep = 1.f / 60.f;
	float accumulator = 0.f;
	float _miniTimer = 0;
	float count;
	float _offsetX;
public:
	GameManager(const char* title = "Game", int x = 500, int y = 250, int w = 500, int h = 500, unsigned int flags = 0);
	~GameManager();
	SceneManager* GetSceneManager();
	void Loop();
	Window& GetWindow();
	
};