#pragma once

class RectCollider;
class CircleCollider;
class Entity;

class Collideable
{
protected:
	
	RectCollider* _rectCollider;
	CircleCollider* _circleCollider;

public:
	virtual ~Collideable() = default;
	virtual void OnCollision(Collideable* other) = 0;
	RectCollider* GetRectCollider();
	CircleCollider* GetCircleCollider();
	
};

