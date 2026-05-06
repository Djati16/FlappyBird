#include "Entity.h"
#include <iostream>


Entity::Entity(Vector2 pos, Vector2 scale, Vector2 origin, int tag) : Drawable(), Transformable(pos, scale, origin)
{
	_tag = tag;
}



void Entity::Gravity(float deltatime)
{
	if (_appliedGravity == true)
	{
		_velocityY += gravity * deltatime * (GetScale().GetX()  + GetScale().GetY() )/ 2;
		
	}
}

float Entity::GetGravityApplied()
{
	return gravityApplied;
}

void Entity::SetTag(int a)
{
	_tag = a;
}

void Entity::OnInitialize()
{

}

void Entity::OnUpdate(float deltatime)
{
	
}

void Entity::OnEnd()
{
	
	_destroyed = true;
	
}

bool Entity::IsDestroy()
{
	if (_destroyed == false)
		return false;
	return true;
}

Vector2 Entity::GetDirection()
{
	return _direction;
}

void Entity::SetSprite(Window& window, const char* asset, Camera* _camera)
{

}