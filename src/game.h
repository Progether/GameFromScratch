#ifndef __GAME_H__
#define __GAME_H__

#include "display.h"

class Game
{
public:
	static Game* getInstance();
	void initialize();

	GameDisplay *getDisplay();

	void exitGame();
	bool isRunning();

private:
	GameDisplay m_display;
	Game(){ m_running = true;}
	Game(const Game&);
	Game& operator=(const Game&);

	static bool instanceFlag;
	static Game* gameInstance;
	bool m_running;


};

#endif //__GAME_H__
