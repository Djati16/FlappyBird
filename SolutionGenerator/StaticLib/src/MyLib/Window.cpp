#include "Window.h"
#include "MyMotor/Scene.h"
#include "Input.h"
#include "Entity.h"
#include <iostream>
#include "MyMotor/Camera.h"
#include "MyMotor/RectCollider.h"
#include "MyLib/Collideable.h"

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL| SDL_WINDOW_MOUSE_CAPTURE);
	_renderer = SDL_CreateRenderer(_window, 0, 0);   
	
	//SDL_RenderSetLogicalSize(_renderer, 0, 0);
	//DataManager::Get()->InitDataManager(this);
}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void Window::Event()
{
	SDL_Event events;
	SDL_bool run = SDL_TRUE;
	
	while (SDL_PollEvent(&events)) {

		switch (events.type) 
	    {
		case SDL_WINDOWEVENT:
			if (events.window.event == SDL_WINDOWEVENT_CLOSE)
				SDL_DestroyWindow(_window);
		}
	}
}

bool Window::IsOpen()
{
	if (!_window)
	{
		return false;
	}
	return true;
}

void Window::Clear()
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Window::GetRenderer()
{
	return _renderer;
}

SDL_Window* Window::GetWindow()
{
	return _window;
}

void Window::ShowDrawable(Drawable* drawable, Camera* _camera)
{
	drawable->Draw(*this, _camera);
}

void Window::ShowCollider(RectCollider* rect, Camera* _camera)
{
	rect->Draw(*this, _camera);
}


void Window::Update()
{
	SDL_RenderPresent(_renderer);
}

void Window::End()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

}
