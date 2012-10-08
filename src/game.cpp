#include "game.h"

void Game::initialize()
{
	m_display.createDisplay();
	return;
}

GameDisplay *Game::getDisplay()
{
	return &m_display;
}

