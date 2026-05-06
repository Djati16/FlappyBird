#pragma once
#include "MyLib\Entity.h"

class  Circle;
class Input;
class ShufflePlayer : public Entity
{
private:
	Circle* _sprite = nullptr;
	float _moveY = 0;
	float _moveX = 0;
	Input* _input;
public:
	ShufflePlayer(Vector2 pos, Vector2 scale, Vector2 origin);
	void Init();
	void Move(float deltatime);
	void OnInitialize() override;
	void OnCollision(Entity* other) override;
	void OnUpdate(float deltatime) override;
	void OnEnd() override;
	void Draw(Window& window, Camera* _camera = nullptr) override;
	void UpdatePos();
	void UpdateXPos(float x);
	void UpdateYPos(float y);
	void MoveUpdate(float x, float y);
};

