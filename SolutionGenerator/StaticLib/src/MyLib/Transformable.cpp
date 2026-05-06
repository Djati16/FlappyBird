#include "Transformable.h"

Transformable::Transformable(Vector2 pos, Vector2 scale, Vector2 origin)
{
	_pos = pos;
	_scale = scale;
	_origin = origin;
}

void Transformable::SetPos(float x, float y)
{
	_pos.InitX(x - (_scale.GetX() * _origin.GetX()));
	_pos.InitY(y - (_scale.GetY() * _origin.GetY()));
}

void Transformable::SetPosX(float x)
{
	_pos.InitX(x - (_scale.GetX() * _origin.GetX()));
}

void Transformable::SetPosY(float y)
{
	_pos.InitY(y - (_scale.GetY() * _origin.GetY()));
}

void Transformable::SetScale(float width, float height)
{
	_scale = { width, height };
}

void Transformable::SetOrigin(float anchorX, float anchorY)
{
	_origin = { anchorX, anchorY };
}


Vector2 Transformable::GetPos()
{
	Vector2 pos(_pos.GetX() + _scale.GetX() * _origin.GetX(), _pos.GetY() + _scale.GetY() * _origin.GetY());
	return pos;
}

Vector2 Transformable::GetOrigin()
{
	return _origin;
}

Vector2 Transformable::GetScale()
{
	return _scale;
}



