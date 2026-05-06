#pragma once
#include "SDL.h"
#include "MyLib/Entity.h"

class Window;
class Sprite;

class Rectangle : public Entity
{
protected:
    SDL_FRect _rect;
    Sprite* _sprite = nullptr;
public:
    Rectangle(Vector2 pos, Vector2 scale, Vector2 origin);
    void OnInitialize() override;
    void OnUpdate(float deltatime) override;
    void OnEnd() override;

    void Draw(Window& window, Camera* _camera = nullptr) override;

};
