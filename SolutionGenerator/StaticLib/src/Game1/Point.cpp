#include "Point.h"
#include "MyLib/Circle.h"
#include "MyLib/Sprite.h"
#include "MyMotor/RectCollider.h"
#include "MyLib/Window.h"
#include "MyMotor/GameManager.h"
#include "Player.h"
#include <iostream>

Point::Point(Vector2 pos, Vector2 scale, Vector2 origin, int tag) : Entity(pos, scale, origin, tag)
{
}

Point::~Point()
{
	delete _sprite;
	_appliedGravity = false;
}

void Point::OnInitialize()
{
	_appliedGravity = false;
	_rectCollider = new RectCollider(_pos, _scale, _origin);
	_sprite = new Rectangle(_pos, _scale, _origin);
	_rectCollider->SetOwner(this);
	_direction = { 0, 0 };
	_speed = 100;
	_show = false;
}

void Point::OnEnd()
{
	_destroyed = true;
}

void Point::OnCollision(Collideable* other)
{
	if (dynamic_cast<Player*>(other) != nullptr)
	{
		if (Player* player = dynamic_cast<Player*>(other))
		{
			
			player->_progression += 1;
			OnEnd();
		}	
	}
}

void Point::OnUpdate(float deltatime)
{

}


void Point::Draw(Window& window, Camera* _camera)
{	if(_show)
		_sprite->Draw(window, _camera);
}
