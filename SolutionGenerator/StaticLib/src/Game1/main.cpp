#include <iostream>

#include "GameManager.h"
#include "PlayerScene.h"
#include "Game1Scene.h"

#define WIDTH 1000
#define HEIGHT 800

int main(int argc, char* argv[])
{

	GameManager gameManager("Game", 500, 250, WIDTH, HEIGHT);

	gameManager.GetSceneManager()->AddScene("Game1", new PlayerScene()); //pour tester le FlappyBeard Remplacez  Game1Scene()  par PlayerScene() et modifer le const char* Game dans le LevelManager.cpp

	gameManager.GetSceneManager()->SetCurrentScene("Game1");

	gameManager.Loop();

	return 0;
}