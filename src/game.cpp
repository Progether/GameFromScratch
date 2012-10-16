#include "game.h"
#include "GL/glew.h"

bool Game::instanceFlag = false;
Game* Game::gameInstance = nullptr;

Game *Game::getInstance()
{
	if(!instanceFlag){
		gameInstance = new Game;
		instanceFlag = true;
	}
	return gameInstance;
}

void Game::initialize()
{
	m_display.createDisplay();
	glewInit();
}

GameDisplay *Game::getDisplay()
{
	return &m_display;
}

void Game::exitGame()
{
	m_running = false;
}

bool Game::isRunning()
{
	return m_running;
}

