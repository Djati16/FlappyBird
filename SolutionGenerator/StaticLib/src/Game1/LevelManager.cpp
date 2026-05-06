#include "LevelManager.h"
#include <MyLib/Vector2.h>
#include <Ground.h>
#include <PlayerScene.h>
#include <iostream>
#include "SceneManager.h"
#include "Point.h"
#include "Player.h"
#include <cmath>
#include "Camera.h"
#include <Obstacle.h>

#define HEIGHT 800
#define WIDTH 1000

//choices: "FlappyBird" || "DinoRun"
const char* Game = "FlappyBird";

LevelManager::LevelManager()
{
}

void LevelManager::SetCamera(Camera* camera)
{
	_camera = camera;
}

void LevelManager::OnInitialize()
{
}

void LevelManager::OnUpdate(float deltatime, Player* player)
{
	for (int i = 0 ; i <= 1; i++)
	{
	//	SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Ground>(Vector2(GetCamera()->GetLeftBorder(), HEIGHT), Vector2( GetCamera()->GetRightBorder(), 100 ), Vector2(0, 0), 1)->OnInitialize();
	}

	if (Game == "FlappyBird")
	{
		RandomPatern(player->_progression);
	}
	if (Game == "DinoRun")
	{
		RandomPatern(player->_groundAccumulator);
	}
}

void LevelManager::OnEnd()
{
}

void LevelManager::RandomPatern(int count)
{
	int randmomNumber = 0;
	char patern = ' ';
	
	for (_i; _i <= count; _i += 1)
	{
		if (Game == "FlappyBird")
		{
			randmomNumber = rand() % 5;
			switch (randmomNumber)
			{
			case 0:
				patern = 'l';
				ObstacleManager(patern, 0);//l
				break;
			case 1:
				patern = 'x';
				ObstacleManager(patern, 0);//mB
				break;
			case 2:
				patern = 'm';
				ObstacleManager(patern, 0);//m
				break;

			case 3:
				patern = 'y';
				ObstacleManager(patern, 0);//mT
				break;

			case 4:
				patern = 'h';
				ObstacleManager(patern, 0);//h
				break;
			}
		}

		if (Game == "DinoRun")
		{
			randmomNumber = rand() % 3;
			switch (randmomNumber)
			{
			case 0:
				patern = 'l';
				ObstacleManager(patern, 0);//l
				break;
			case 1:
				patern = 'm';
				ObstacleManager(patern, 0);//m
				break;
			case 2:
				patern = 'h';
				ObstacleManager(patern, 0);//h
				break;
			}
		}
	}
}

void LevelManager::ObstacleManager(char d, int count)
{
	if(Game == "FlappyBird")
	{
		float HeightLow = HEIGHT * 3 / 4;
		float HeightMid = HEIGHT * 2 / 4;
		float HeightHigh = HEIGHT * 1 / 4;

	
		float test = abs(HeightLow + 120) - abs(780);
		std::cout << test;
		if (SceneManager::GetInstance()->GetCurrentScene() == nullptr)
		{
			std::cout << "Scene pas encore init\n";
		}
		if (!_levelHasBegin)
		{
			_initialX = WIDTH;
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX, -660), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + 80, HeightMid), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX, HeightMid + 210), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
			_levelHasBegin = true;
		}
		

		else
		{
			_distance += 400;
			switch (d)
			{
			case 'l':
				std::cout << "Low";
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, -560), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + _distance + 80, HeightLow - 100), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, HeightLow + 115), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
				break;

			case 'x':
				std::cout << "MidBot";
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, -660), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + _distance + 80, HeightMid), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, HeightMid + 210), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
				break;

			case 'm':
				std::cout << "Mid";
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, -760), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + _distance + 80, HeightMid - 100), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, HeightMid + 110), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
				break;

			case 'y'://midTop
				std::cout << "MidTop";
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, -860), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + _distance + 80, HeightMid - 200), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, HeightMid + 10), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
				break;
			case 'h':
				std::cout << "High";
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, -965), Vector2(120, HEIGHT + 250), Vector2(0, 0), 1)->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_initialX + _distance + 80, HeightHigh - 100), Vector2(10, 200), Vector2(0, 0))->OnInitialize();
				SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_initialX + _distance, HeightHigh + 110), Vector2(120, HEIGHT + 250), Vector2(0, 0), 2)->OnInitialize();
				break;
			}
		}
	}

	else if (Game == "DinoRun")//DINORUN
	{
		_distance += 300;
		switch (d)
		{
		case 'l':
		
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance - 50 , (HEIGHT /2)), Vector2(20, 30), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_distance, (HEIGHT / 2) -100), Vector2(10, 100), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance, HEIGHT / 2 + 40), Vector2(600, 20), Vector2(0, 0))->OnInitialize();
			break;

		case 'm':
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance + 100, (HEIGHT / 2 -10)), Vector2(20, 50), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance - 50, (HEIGHT / 2)), Vector2(20, 30), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_distance, (HEIGHT / 2) - 100), Vector2(10, 100), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance, HEIGHT / 2 + 40), Vector2(600, 20), Vector2(0, 0))->OnInitialize();
			break;

		case 'h':
		
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance + 80, (HEIGHT / 2)), Vector2(20, 20), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance + 100, (HEIGHT / 2 - 15)), Vector2(20, 45), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Point>(Vector2(_distance,(HEIGHT / 2) - 100), Vector2(10, 100), Vector2(0, 0))->OnInitialize();
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Obstacle>(Vector2(_distance, HEIGHT / 2 + 40), Vector2(600, 20), Vector2(0, 0))->OnInitialize();
			break;


		}
	}
}
