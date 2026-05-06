#pragma once
class Window;
class Camera;

class Drawable
{
public:

	virtual void Draw(Window& window, Camera* _camera = nullptr) = 0;
	virtual ~Drawable() = default;
};

