#include <iostream>
#include "main.h"
#include "GameManager.h"
#include "ShuffleScene.h"


#define WIDTH 1000
#define HEIGHT 800

int main(int argc, char* argv[])
{

	GameManager gameManager("Game1", 500, 250, WIDTH, HEIGHT);

	gameManager.GetSceneManager()->AddScene("Game1", new ShuffleScene());
	gameManager.GetSceneManager()->SetCurrentScene("Game1");

	gameManager.Loop();
	return 0;
}