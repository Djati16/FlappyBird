#pragma once
#include "MyLib\Collideable.h"

#include "MyLib\Entity.h"


class Circle;
class Input;
class Ball : public Collideable, public Entity
{
private:
	Circle* _sprite = nullptr;
	Input* _input;
public:
	float _moveY = 0;
	float _moveX = 0;

	Ball(Vector2 pos, Vector2 scale, Vector2 origin);

	~Ball();
	void Init();
	void Move(float deltatime); 
	void OnInitialize() override;
	void OnCollision(Collideable* other) override;
	void OnUpdate(float deltatime) override;
	void OnEnd() override;
	void Draw(Window& window, Camera* _camera = nullptr) override;
	void UpdatePos();
	void UpdateXPos(float x);
	void UpdateYPos(float y);
	void MoveUpdate(float x, float y);
	/*Ball* GetPlayer();

	void DoubleJump(float deltatime);

	
	
	void SetAllPositions(float x, float y);
	void Move(float delatime);
	*/
	friend class LevelManager;
	friend class GameManager;

};

