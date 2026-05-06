#include "Target.h"
#include "MyLib/Rectangle.h"
#include "MyMotor/RectCollider.h"
#include "MyLib/Input.h"
#include "SceneManager.h"

Target::Target(Vector2 pos, Vector2 scale, Vector2 origin) : Entity(pos, scale, origin)
{
}

void Target::OnInitialize()
{
	_collider = new RectCollider(_pos, _scale, _origin);
	_sprite = new Rectangle(_pos, _scale, _origin);
	_direction = { 0, 0 };
	_speed = 100;
	_input = _input->Get();

}

void Target::OnUpdate(float deltatime)
{

	UpdatePos();
}

void Target::Draw(Window& window, Camera* _camera)
{
	_sprite->Draw(window, _camera);
}

void Target::OnEnd()
{

	_destroyed = true;
}

void Target::UpdatePos()
{
	SetPos(GetPos().GetX(), GetPos().GetY());
	_sprite->SetPos(GetPos().GetX(), GetPos().GetY());
	_collider->SetPos(GetPos().GetX(), GetPos().GetY());

}
