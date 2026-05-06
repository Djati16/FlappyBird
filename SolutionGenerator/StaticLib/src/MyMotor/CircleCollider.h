#pragma once
#include "MyLib/Circle.h"
#include "MyLib/Drawable.h"
#include "Collider.h"
#include "MyLib/Collideable.h"

class Vector2;

class CircleCollider : public Circle, public Collideable
{
private:
	bool _isEnable = true;
	Vector2 _center;
	Vector2 _rectCenter;
	Vector2 _rectShape;
	Vector2 _circleDistance;
	float  _cornerDistance;

public:

	CircleCollider(Vector2 pos, Vector2 scale, Vector2 origin);
	void EnableCollision();
	void DisableCollision();
	void OnCollision(Collideable* other) override;
	void RepulseCircle(RectCollider* other);
	void Draw(Window& window, Camera* _camera = nullptr) override;
	bool IsColliding(Entity* other);
	void Repulse(RectCollider* other);

};