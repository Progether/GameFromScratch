#include "game.h"

void Game::initialize()
{
	m_display.createDisplay();
}

GameDisplay *Game::getDisplay()
{
	return &m_display;
}

