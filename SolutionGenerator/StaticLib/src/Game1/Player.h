#pragma once
#include "MyLib\Collideable.h"
#include "MyLib\Entity.h"

class Rectangle; 
class Sprite;
class Input;
class Window;
class GameManager;



class Player : public Collideable, public Entity
{
private:

	Sprite* _sprite = nullptr;
	Input* _input = nullptr;
	GameManager* _manager;


	float _dashTimer = 0.f;
	float _dashDuration = 0.30f;
	float _dashSpeed = 50000.f;
	bool _isDashing = false;
	float _moveY = 0;
	float _moveX = 0;
	float _gravity = 0;
	float _timer = 0;
	float _progression = 0;
	int _groundAccumulator = 0;
	int _doubleJumpCount = 0;


public:

	Player(Vector2 pos, Vector2 scale, Vector2 origin, int tag = -1);
	
	~Player();
	
	void OnInitialize() override;
	void OnCollision(Collideable* other) override;
	void OnUpdate(float deltatime) override;
	void Draw(Window& window, Camera* _camera = nullptr) override;

	Player* GetPlayer();
	void Jump();
	void UpdatePos();
	void OnEnd() override;
	void UpdateXPos(float x);
	void UpdateYPos(float y);
	void Move(float delatime);
	void MoveUpdate(float x, float y);

	int GetProgression() { return _progression; };
	void SetSprite(Window& window, const char* asset, Camera* _camera) override;

	friend Camera;
	friend class LevelManager;
	friend class Point;
	friend  GameManager;
};

