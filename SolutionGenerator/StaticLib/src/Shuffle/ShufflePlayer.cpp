#include "ShufflePlayer.h"
#include "MyLib/Input.h"
#include <iostream>
#include "RectCollider.h"
#include "MyLib/Circle.h"

ShufflePlayer::ShufflePlayer(Vector2 pos, Vector2 scale, Vector2 origin) : Entity(pos, scale, origin)
{
}



void ShufflePlayer::Init()
{
	_collider = new RectCollider(_pos, _scale, _origin);

	_input = _input->Get();
	_sprite = new Circle(_pos, _scale, _origin);
	_direction = { 0, 0 };
	_speed = 100;
}

void ShufflePlayer::OnInitialize()
{

}

void ShufflePlayer::OnCollision(Entity* other)
{

}

void ShufflePlayer::UpdatePos()
{
	SetPos(GetPos().GetX(), GetPos().GetY());
	_sprite->SetPos(GetPos().GetX(), GetPos().GetY());
	_collider->SetPos(GetPos().GetX(), GetPos().GetY());

}

void ShufflePlayer::OnUpdate(float deltatime)
{

	_moveX = 0;
	_moveY = 0;
	
	Move(deltatime);
	UpdatePos();
	

}

void ShufflePlayer::OnEnd()
{
}

void ShufflePlayer::Draw(Window& window, Camera* _camera)
{
	_sprite->Draw(window, _camera);
}


void ShufflePlayer::Move(float deltatime)
{

	_moveX += _direction.GetX() * deltatime * _speed;
	_moveY += _direction.GetY() * deltatime * _speed;

	if (_input->IsKeyHeld(KEYCODE_D))
	{
		_direction.InitX(1);

	}

	if (_input->IsKeyHeld(KEYCODE_A))
	{
		_direction.InitX(-1);
	}

	if (_input->IsKeyHeld(KEYCODE_S))
	{
		_direction.InitY(1);
	}

	if (_input->IsKeyHeld(KEYCODE_W))
	{
		_direction.InitY(-1);
	}

	if (_moveX != 0 || _moveY != 0)
	{
		MoveUpdate(_moveX, _moveY);
	}
}


void ShufflePlayer::UpdateXPos(float x)
{
	float newPosX = GetPos().GetX() + x;

	SetPosX(newPosX);

	_sprite->SetPosX(newPosX);
	_collider->SetPosX(newPosX);
}


void ShufflePlayer::UpdateYPos(float y)
{
	float newPosY = GetPos().GetY() + y;

	SetPosY(newPosY);
	_sprite->SetPosY(newPosY);
	_collider->SetPosY(newPosY);
}

void ShufflePlayer::MoveUpdate(float x, float y)
{
	float newPosX = GetPos().GetX() + x;
	float newPosY = GetPos().GetY() + y;

	SetPos(newPosX, newPosY);
	_sprite->SetPos(newPosX, newPosY);
	_collider->SetPos(newPosX, newPosY);
}
