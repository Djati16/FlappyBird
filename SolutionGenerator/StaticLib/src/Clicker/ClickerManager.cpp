#include "ClickerManager.h"
#include "SceneManager.h"
#include "Target.h"
#include <random>
#include <iostream>

ClickerManager::ClickerManager()
{
	//MANANGER DU JEU
}

void ClickerManager::Start()
{
	std::cout << "CLICK ON THE TARGET THE FASTER YOU CAN\n";
	std::cout << "Wich mode do you want ?\n";
	std::cout << "Easy = e, Mid = m, Hard = h\n";
	std::cin >> answer;
}
void ClickerManager::Update(float deltatime)
{
	//GENERER DES COORDONNEES ALEATOIRE COMPRISE DANS L'ECRAN
	_miniTimer += deltatime;
	std::random_device rd;
	std::mt19937 random_engine(rd());
	std::uniform_int_distribution<int> distributionWidth(100, _widthScreen);
	std::uniform_int_distribution<int> distributionHeight(100, _heightScreen);
	float randomX = distributionWidth(rd);
	float randomY = distributionHeight(rd);


	//TEMPS DE VIE DES TARGET RELATIF AU NIVEAU DE DIFFICULTEE CHOISIT
	switch (answer)
	{
	case 'e':
		_aliveTime = 2.5f;
		_scoreToHave = 10;
		break;

	case 'm':
		_aliveTime = 1.8f;
		_scoreToHave = 20;
		break;

	case 'h':

		_aliveTime = 1.f;
		_scoreToHave = 30;
		break;
	}

	if (_miniTimer >= _aliveTime + 0.5)
	{
		SpawnTarget(randomX, randomY);
		_miniTimer = 0;
	}
	
}

void ClickerManager::SpawnTarget(float x, float y)
{
	switch (answer)
	{
		//RECTANGLES CREE AVEC UN SCALE RELATIF A LA DIFFICULTE LE SPAWN RESTE ALEATOIRE
		case 'e':
		{
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Target>(Vector2(x, y), Vector2(60, 60), Vector2(0.5, 0.5))->OnInitialize();
			break;
		}
		case 'm':
		{
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Target>(Vector2(x, y), Vector2(45, 45), Vector2(0.5, 0.5))->OnInitialize();
			break;
		}
		case 'h':
		{
			SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<Target>(Vector2(x, y), Vector2(30, 30), Vector2(0.5, 0.5))->OnInitialize();
			break;
		}

	}
}

void ClickerManager::AddScore()
{
	_score += 1;
}

int ClickerManager::GetScore()
{
	return _score;
}

float ClickerManager::GetAliveTime()
{
	return _aliveTime;
}

int ClickerManager::GetScoreToHave()
{
	return _scoreToHave;
}


