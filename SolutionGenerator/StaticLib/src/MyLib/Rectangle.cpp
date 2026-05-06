#include "Rectangle.h"
#include <iostream>
#include "Window.h"
#include "MyMotor/Camera.h"


Rectangle::Rectangle(Vector2 pos, Vector2 scale, Vector2 origin) : Entity(pos, scale, origin)
{
	_rect = { _pos.GetX(), _pos.GetY(), _scale.GetX(), _scale.GetY() };
}

void Rectangle::OnInitialize()
{
}


void Rectangle::OnUpdate(float deltatime)
{
}

void Rectangle::OnEnd()
{
}


void Rectangle::Draw(Window& window, Camera* _camera)
{

	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	if (!_camera)
	{
		_rect.x = pos.GetX();
		_rect.y = pos.GetY();
		_rect.w = scale.GetX();
		_rect.h = scale.GetY();

	}
	else
	{
		_rect.x = pos.GetX() - _camera->GetPos().GetX();
		_rect.y = pos.GetY() - _camera->GetPos().GetY();
		_rect.w = scale.GetX();
		_rect.h = scale.GetY();
	}


	SDL_Renderer* renderer = window.GetRenderer();
	if (!renderer) {
		std::cout << "ERREUR: Renderer invalide dans Rectangle::Draw" << std::endl;
		return;
	}
	
	SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255);
	SDL_RenderDrawRectF(window.GetRenderer(), &_rect);
}
