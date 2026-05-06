#pragma once
#include "Entity.h"
#include "SDL.h"
class Window;
class SDL_Surface;
class SDL_Texture;
class SDL_Rect;
class Camera;
class Sprite : public Entity
{
private:

	SDL_Rect dstrect;
	SDL_Surface* _tempsurface = nullptr;
	SDL_Texture* _texture = nullptr;
	bool isLoaded = false;
public:
	Sprite(Vector2 pos, Vector2 scale, Vector2 origin);
	void Draw(Window& window, Camera* _camera = nullptr) override;
	void OnInitialize() override;
	void OnUpdate(float deltatime) override;
	void OnEnd() override;
	void LoadImage(Window& window, const char* file);
	bool hasBeenLoaded();
	friend class Player;
};

