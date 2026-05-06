#pragma once
#include "SDL.h"

class Drawable;
class SDL_Window;
class SDL_Renderer;
class RectCollider;
class Input;
class Scene;
class Camera;
class Ground;
class Player;

class Window
{
private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;

public:
	~Window();
	Window(const char* title, int x, int y, int w, int h, Uint32 flags = 0);
	void Event();
	bool IsOpen();
	void Update();
	void Clear();
	void End();

	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();

	void ShowDrawable(Drawable* drawable, Camera* _camera);
	void ShowCollider(RectCollider* rect, Camera* _camera);

	friend class Sprite;
	friend class Circle;
	friend class Rectangle;
	friend class Debug;
};

