#include "Player.h"
#include <iostream>
#include "MyLib/Input.h"
#include "MyLib/Rectangle.h"
#include "MyLib/Sprite.h"
#include "MyMotor/RectCollider.h"
#include "MyLib/Window.h"
#include "MyMotor/GameManager.h"
#include "Point.h"
#include "Ground.h"
#include <Obstacle.h>

#define WIDTH 1000
#define HEIGHT 800



Player::Player(Vector2 pos, Vector2 scale, Vector2 origin, int tag) : Entity(pos, scale, origin, tag)
{
	_appliedGravity = true;
}

Player* Player::GetPlayer()
{
	return this;
}

Player::~Player()
{
	delete _sprite;
	delete _circleCollider;
	delete _rectCollider;
	_appliedGravity = false;
}

void Player::SetSprite(Window& window, const char* asset, Camera* _camera)
{
	_sprite->SetScale(GetScale().GetX() + 5, GetScale().GetY() + 5);
	_sprite->LoadImage(window, asset);
	_sprite->hasBeenLoaded();
}

void Player::OnInitialize()
{
	_input = _input->Get();
	_rectCollider = new RectCollider(_pos, _scale, _origin);
	_sprite = new Sprite(_pos, _scale, _origin);

	_rectCollider->SetOwner(this);
	_direction = { 0, 0 };
	_speed = 200;
	_velocityX = 1;
}

void Player::OnCollision(Collideable* other)
{
	std::cout << "Collision";

	if (_rectCollider->_collidingLeftRight == true)
	{
		UpdateXPos(_rectCollider->_overlapX);	
	}

	if (_rectCollider->_collidingTopBot == true)
	{
		UpdateYPos(_rectCollider->_overlapY);
		_isGrounded = true;

		if (_velocityY > 0) 
			_velocityY = 0;
	}

	if (dynamic_cast<Obstacle*>(other) != nullptr)
	{
		std::cout << "Player Dead\n";
		OnEnd();
	}
}

void Player::OnUpdate(float deltatime)
{
	_isGrounded = false;
	Gravity(deltatime);

	_moveX = 0;
	_moveY = 0;
	if(_canMove)
		Move(deltatime);

	UpdatePos();
}

void Player::UpdatePos()
{
	_sprite->SetPos(GetPos().GetX(), GetPos().GetY());
	_rectCollider->SetPos(GetPos().GetX(), GetPos().GetY());
}

void Player::UpdateXPos(float x)
{
	float newPosX = GetPos().GetX() + x;

	SetPosX(newPosX);
	_rectCollider->SetPosX(newPosX);
}

void Player::UpdateYPos(float y)
{
	float newPosY = GetPos().GetY() + y;

	SetPosY(newPosY);
	_rectCollider->SetPosY(newPosY);
}

void Player::Move(float deltatime)
{
	_moveX += _velocityX * deltatime * _speed;
	_moveY += _velocityY * deltatime;
	
	if (_input->IsKeyDown(KEYCODE_SPACE))
	{
		Jump();
	}
	if (_input->IsKeyHeld(KEYCODE_A))
	{
		_direction.InitX(-1);
	}
	if (_input->IsKeyHeld(KEYCODE_D))
	{
		_direction.InitX(1);
	}
	if (_moveX != 0 || _moveY != 0) 
	{
		MoveUpdate(_moveX, _moveY);
	}
}

void Player::Jump()
{
	_velocityY = -3.5 * (GetScale().GetX() + GetScale().GetY());
}

void Player::OnEnd()
{
	_destroyed = true;
}

void Player::MoveUpdate(float x, float y)
{
	float newPosX = GetPos().GetX() + x;
	float newPosY = GetPos().GetY() + y;

	SetPos(newPosX , newPosY);
	_rectCollider->SetPos(newPosX, newPosY);
}

void Player::Draw(Window& window, Camera* _camera)
{
	if (!_sprite->hasBeenLoaded())
		SetSprite(window, "zahouli.bmp", _camera);
	
	if (_show)
		_sprite->Draw(window, _camera);
}
