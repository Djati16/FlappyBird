#include "Sprite.h"
#include "SDL_image.h"
#include "SDL.h"
#include "Window.h"
#include "MyMotor/Camera.h"


Sprite::Sprite(Vector2 pos, Vector2 scale, Vector2 origin) : Entity(pos, scale, origin)
{
}

void Sprite::OnInitialize()
{
}

void Sprite::OnUpdate(float deltatime)
{
}

void Sprite::OnEnd()
{
}


void Sprite::LoadImage(Window& window, const char* file)
{
	_tempsurface = IMG_Load(file);
	_texture = SDL_CreateTextureFromSurface(window.GetRenderer(), _tempsurface);
	SDL_QueryTexture(_texture, NULL, NULL, 0, 0);
	SDL_FreeSurface(_tempsurface);
	isLoaded = true;
}

void Sprite::Draw(Window& window, Camera* _camera)
{
	if (_camera)
		dstrect = { (int)(GetPos().GetX() - _camera->GetPos().GetX()), (int)(GetPos().GetY() - _camera->GetPos().GetY()),(int)GetScale().GetX(), (int)GetScale().GetY() };
	else
		dstrect = { (int)GetPos().GetX(), (int)GetPos().GetY(),(int)GetScale().GetX(), (int)GetScale().GetY() };

	SDL_RenderCopy(window.GetRenderer(), _texture, 0, &dstrect);
}

bool Sprite::hasBeenLoaded()
{
	return isLoaded;
}