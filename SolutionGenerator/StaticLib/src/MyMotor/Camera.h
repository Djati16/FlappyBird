#pragma once
#include "SDL.h"

#include "MyLib/Entity.h"

class Player;
class SceneManager;
class Camera :public Entity

{
	Player* _player = nullptr;
	
	float _CamX;
	float _CamY;
	float _rightBorder;
	float _leftBorder;
public:

	Camera(Vector2 pos, Vector2 scale, Vector2 origin);
	void Draw(Window& window, Camera* _camera);
	void Initialize(Player* player);
	void OnInitialize() override;
	void OnUpdate(float deltatime) override;
	void OnEnd() override;
	float GetLeftBorder() { return _leftBorder; }
	float GetRightBorder() { return _rightBorder; }

	friend class  Player;
	friend class GameManager;
};



