#include "GameManager.h"
#include <cmath>
#include "MyLib\Collideable.h"
#include "MyMotor/RectCollider.h"
#include "Window.h"
#include "Input.h"
#include "MyMotor/Camera.h"
#include <iostream>
#include "Game1/Player.h"
#include <Game1/PlayerScene.h>
#include "Game1/LevelManager.h"
#include "Game1/Point.h"
#include "MyMotor/Timer.h"
#include "Shuffle/Ball.h"
#include "Clicker/ClickerManager.h"
#include "MyLib/Sprite.h"
#include <Clicker/Target.h>
#include "MyLib/Writer.h"


#define SCREENWIDTH 1000
#define SCREENHEIGHT 800

GameManager::GameManager(const char* title, int x, int y, int w, int h, unsigned int flags)
{
	_input = _input->Get();
	_window = new Window(title, x, y, w, h, flags);
	_camera = new Camera(Vector2(30, 30), Vector2(1, 1), Vector2(0, 0));
	_levelManager = new LevelManager();
	_writer = new Writer();
	_background = new Sprite(Vector2(0, 0), Vector2(100, 100), Vector2(0, 0));
}

GameManager::~GameManager()
{
	delete _window;
}

SceneManager* GameManager::GetSceneManager()
{
	return SceneManager::GetInstance();
}

void GameManager::Loop()
{
	//INITALISATION
	Player* player = SceneManager::GetInstance()->GetCurrentScene()->GetEntity<Player>();
	Ball* ball = SceneManager::GetInstance()->GetCurrentScene()->GetEntity<Ball>();
	std::vector<Target*> target = SceneManager::GetInstance()->GetCurrentScene()->GetAllEntity<Target>();
	_background->LoadImage(*_window, "jungle2.bmp");


	_camera->Initialize(player);
	
	_timer->Get_Deltatime();
 	_writer->Initialize();
	_writer->LoadFont();
	_writer->InitColor(0, 0, 0);

	//UPDATE
	while (_window->IsOpen())
	{

		_window->Clear();
		 _deltatime = _timer->Get_Deltatime();
		_camera->OnUpdate(_deltatime);
		_levelManager->SetCamera(_camera);
		_offsetX = fmod(_camera->GetPos().GetX(), SCREENWIDTH);
		_background->SetScale(SCREENWIDTH, SCREENHEIGHT);
		_background->SetPos(-_offsetX, 0);
		
		_background->Draw(*_window);
		
		_background->SetPos(-_offsetX + SCREENWIDTH, 0);
		_background->Draw(*_window);

		_writer->Write(std::to_string(player->GetProgression()).c_str(), *_window, 0, 0);
		
		_window->Event();
		Input::Get()->Update();

		
		std::vector<Entity*> entities = SceneManager::GetInstance()->GetCurrentScene()->GetAllEntity<Entity>();
		std::vector<Collideable*> collideables = SceneManager::GetInstance()->GetCurrentScene()->GetAllEntity<Collideable>();
		std::vector<Point*> checkPoints = SceneManager::GetInstance()->GetCurrentScene()->GetAllEntity<Point>();
		std::vector<RectCollider*> rectColliders = SceneManager::GetInstance()->GetCurrentScene()->GetAllColliders();
		

		SceneManager::GetInstance()->GetCurrentScene()->Update(_deltatime);
			
		for (int i = 0; i < rectColliders.size(); i++)
		{
			_window->ShowCollider(rectColliders[i], _camera);
		}
		for (int i = 0; i < collideables.size(); ++i)
		{
			for (int j = 0; j < collideables.size(); ++j)
			{
				if (collideables[i]->GetRectCollider()->IsColliding(collideables[j]->GetRectCollider()))
				{
					collideables[i]->OnCollision(collideables[j]);	
				}
			}
		}
		
		_levelManager->OnUpdate(_deltatime, player);

		
		//DRAW

		for (int i = 0; i < entities.size(); ++i)
		{
			float entitiePosX = (entities[i]->GetPos().GetX() + entities[i]->GetScale().GetX());
			float camRight = _camera->GetRightBorder();
			float camLeft = _camera->GetLeftBorder();
			
			if (entitiePosX <= camRight && entitiePosX >= camLeft)
				_entityInRange = true;

			else
				_entityInRange = false;
		
			if (entitiePosX < camLeft && _entityInRange == false)
				entities[i]->OnEnd();
		}

		//DESTROY ENTITIES
		for (int i = entities.size() - 1; i >= 0; i--)
		{
			if (entities[i]->IsDestroy() == true)
			{
				SceneManager::GetInstance()->GetCurrentScene()->DestroyEntity(entities[i]);
			}
		}

		_window->ShowDrawable(SceneManager::GetInstance()->GetCurrentScene(), _camera);
		_window->Update();

		//CLEAN
		if (!player)
		{
			_writer->Write("Final Score: ", *_window, 0, 0);
			_writer->FreeFont();
			_writer->Clean();
			_window->End();
		
		}
	}
}

Window& GameManager::GetWindow()
{
	return *_window;
}
