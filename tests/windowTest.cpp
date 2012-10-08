#include <unistd.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include "game.h"

int main()
{
	Game testGame;
	testGame.initialize();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.2, 0.3);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	glfwSwapBuffers();
	sleep(5);
}
