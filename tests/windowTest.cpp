#include <unistd.h>

#include "game.h"
#include "entity.h"
int main()
{
	auto testGame = Game::getInstance();
	testGame->initialize();

	Entity triangle;
	while(testGame->isRunning())
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		triangle.draw();
		testGame->getDisplay()->swapBuffers();
	}
	return 1;
}
