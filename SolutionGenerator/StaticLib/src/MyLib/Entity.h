#pragma once
#include "Vector2.h"
#include "Drawable.h"
#include "Transformable.h"
class Camera;
class Window;

class Entity : public Drawable, public Transformable
{
protected:

	Vector2 _direction;
	int _tag = -1;


	float _speed;
	float gravity = 35;
	float gravityApplied;
	float _velocityY = 0;
	float _velocityX = 0;

	bool _destroyed = false;
	bool _appliedGravity = true;
	bool _isGrounded = false;
	bool _canMove = true;
	bool _show = true;
public:

	Entity(Vector2 pos, Vector2 scale, Vector2 origin, int tag = -1);
	virtual ~Entity() = default;
	void Gravity(float deltatime);

	float GetGravityApplied();
	void SetTag(int a);
	int GetTag() { return _tag; };

	virtual void OnInitialize() = 0;
	virtual void OnUpdate(float deltatime) = 0;
	virtual void OnEnd() = 0;
	virtual void SetSprite(Window& window, const char* asset, Camera* _camera);
	Vector2 GetDirection();
	
	bool IsDestroy();


};

