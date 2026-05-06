#pragma once
#include "MyLib/Entity.h"
class Rectangle;
class RectCollider;
class Input;

class Target : public Entity
{
private:
	RectCollider* _collider;
	Rectangle* _sprite = nullptr;
	Input* _input;
public:
	Target(Vector2 pos, Vector2 scale, Vector2 origin);
	void OnInitialize() override;
	void OnUpdate(float deltatime) override;
	void Draw(Window& window, Camera* _camera = nullptr) override;
	void OnEnd() override;
	void UpdatePos();

};

