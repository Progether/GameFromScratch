#ifndef __GAME_H__
#define __GAME_H__

#include "display.h"

class Game
{
public:
	Game(){/*..*/};
	void initialize();

	GameDisplay *getDisplay();
	private:
	GameDisplay m_display;
};

#endif //__GAME_H__
