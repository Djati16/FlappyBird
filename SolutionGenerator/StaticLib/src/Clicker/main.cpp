#include <iostream>
#include "MyMotor/GameManager.h"
#include "ClickerScene.h"

#define WIDTH 1000
#define HEIGHT 800

int main(int argc, char* argv[])
{

	GameManager gameManager("Clicker", 500, 250, WIDTH, HEIGHT);

	gameManager.GetSceneManager()->AddScene("Clicker", new ClickerScene());
	gameManager.GetSceneManager()->SetCurrentScene("Clicker");

	gameManager.Loop();
	return 0;
}