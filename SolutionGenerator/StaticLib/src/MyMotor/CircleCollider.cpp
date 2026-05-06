#include "CircleCollider.h"
#include "RectCollider.h"
#include "Collider.h"
#include <iostream>
#include "Window.h"
#include <cmath>



CircleCollider::CircleCollider(Vector2 pos, Vector2 scale, Vector2 origin) : Circle(pos, scale, origin)
{
	_sprite = new Circle(pos, scale, origin);
}

void CircleCollider::Draw(Window& window, Camera* _camera)
{
	_sprite->Draw(window, _camera);
}
bool CircleCollider::IsColliding(Entity* other)
{
	if (_isEnable)
	{
		if (CircleCollider* otherCircle = dynamic_cast<CircleCollider*> (other))
		{
			SetOrigin(0.5f, 0.5f);
			otherCircle->SetOrigin(0.5f, 0.5f);

			float radius1 = GetScale().GetX() / 2;
			float radius2 = otherCircle->GetScale().GetX() / 2;

			float distance = GetPos().GetDistance(otherCircle->GetPos());

			return distance <= (radius1 + radius2);
		}

		if (RectCollider* otherRect = dynamic_cast<RectCollider*> (other))
		{
			float radius = GetScale().GetX() / 2;
			_center = GetPos();
			_rectShape = other->GetScale();
			_rectCenter.InitX(other->GetPos().GetX() + _rectShape.GetX() / 2);
			_rectCenter.InitY(other->GetPos().GetY() + _rectShape.GetY() / 2);

			_circleDistance = { abs(_center.GetX() - _rectCenter.GetX()), abs(_center.GetY() - _rectCenter.GetY()) };

			if (_circleDistance.GetX() > (_rectShape.GetX() / 2) + radius)
				return false;

			if (_circleDistance.GetY() > (_rectShape.GetY() / 2) + radius)
				return false;

			if (_circleDistance.GetX() <= (_rectShape.GetX() / 2) + radius)
				return true;

			if (_circleDistance.GetY() <= (_rectShape.GetY() / 2) + radius)
				return true;

			_cornerDistance = (_circleDistance.GetX() - _rectShape.GetX() / 2) * (_circleDistance.GetX() - _rectShape.GetX() / 2) + (_circleDistance.GetY() - _rectShape.GetY() / 2) * (_circleDistance.GetY() - _rectShape.GetY() / 2);

			return (_cornerDistance <= (radius * 2));

		}
	}
}


void CircleCollider::RepulseCircle(RectCollider* other)
{
	float dx = GetPos().GetX() - other->GetPos().GetX();
	float dy = GetPos().GetY() - other->GetPos().GetY();

	if (abs(dx) > abs(dy))
		_direction.InitX(-_direction.GetX());
	else
		_direction.InitY(-_direction.GetY());
}
