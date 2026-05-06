#pragma once


class ClickerManager
{
private:
	int _score = 0;
	float _heightScreen = 800;
	float _widthScreen = 1000;
	float _miniTimer = 0;
	float _aliveTime = 0;
	int _scoreToHave = 0;
	char answer;
public:
	ClickerManager();
	void Start();
	void AddScore();
	int GetScore();
	float GetAliveTime();
	int GetScoreToHave();
	void SpawnTarget(float x, float y);
	void Update(float deltatime);

};

