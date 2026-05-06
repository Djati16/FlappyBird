#include "Ball.h"
#include "MyLib/Input.h"
#include <iostream>
#include "MyMotor/RectCollider.h"
#include "MyLib/Circle.h"

Ball::Ball(Vector2 pos, Vector2 scale, Vector2 origin) : Entity(pos, scale, origin)
{
}

Ball::~Ball()
{
}
void Ball::Init()
{
	_rectCollider = new RectCollider(_pos, _scale, _origin);

	_input = _input->Get();
	_sprite = new Circle(_pos, _scale, _origin);
	_direction = { 0, 0 };
	_speed = 100;
}

void Ball::OnCollision(Collideable* other)
{

}
void Ball::UpdatePos()
{
	SetPos(GetPos().GetX(), GetPos().GetY());
	_sprite->SetPos(GetPos().GetX(), GetPos().GetY());
	_rectCollider->SetPos(GetPos().GetX(), GetPos().GetY());

}

void Ball::OnUpdate(float deltatime)
{

	_moveX = 0;
	_moveY = 0;
	Move(deltatime);
	UpdatePos();

}

void Ball::OnEnd()
{
}

void Ball::Draw(Window& window, Camera* _camera)
{
	_sprite->Draw(window, _camera);
}


void Ball::Move(float deltatime)
{

	_moveX += _direction.GetX() * deltatime * _speed;
	_moveY += _direction.GetY() * deltatime * _speed;
	 

	if (_moveX != 0 || _moveY != 0)
	{
		MoveUpdate(_moveX, _moveY);
	}
}

void Ball::OnInitialize()
{
}

void Ball::UpdateXPos(float x)
{
	float newPosX = GetPos().GetX() + x;

	SetPosX(newPosX);

	_sprite->SetPosX(newPosX);
	_rectCollider->SetPosX(newPosX);
}


void Ball::UpdateYPos(float y)
{
	float newPosY = GetPos().GetY() + y;

	SetPosY(newPosY);
	_sprite->SetPosY(newPosY);
	_rectCollider->SetPosY(newPosY);
}

void Ball::MoveUpdate(float x, float y)
{
	float newPosX = GetPos().GetX() + x;
	float newPosY = GetPos().GetY() + y;

	SetPos(newPosX, newPosY);
	_sprite->SetPos(newPosX, newPosY);
	_rectCollider->SetPos(newPosX, newPosY);
}
