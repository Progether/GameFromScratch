#include <unistd.h>
#include <GL/gl.h>

#include "game.h"

int main()
{
	auto testGame = Game::getInstance();
	testGame->initialize();
	while(testGame->isRunning())
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.2, 0.3);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		testGame->getDisplay()->swapBuffers();
	}
	return 1;
}
