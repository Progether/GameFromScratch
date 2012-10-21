
#include <GL/glew.h>
#include "game.h"
#include "sprite.h"
int main()
{
	auto testGame = Game::getInstance();
	testGame->initialize();

	Sprite sprite;
	while(testGame->isRunning())
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sprite.draw();
		testGame->getDisplay()->swapBuffers();
	}
	return 1;
}
