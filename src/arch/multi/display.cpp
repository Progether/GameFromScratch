#include "display.h"
#include "stdio.h"
#include "game.h"

GameDisplay::GameDisplay()
{
}

GameDisplay::~GameDisplay()
{
	glfwCloseWindow();
}

void GameDisplay::createDisplay()
{
	glfwInit();
	if(glfwOpenWindow(0,0,0,0,0,0,0,0,GLFW_WINDOW) != GL_TRUE)
		throw -1;

	glfwSetWindowCloseCallback(closeDisplay);
	return;
}

void GameDisplay::getScreenSize(int* width, int*height)
{
	glfwGetWindowSize(width, height);
	return;
}

void GameDisplay::swapBuffers()
{
	glfwSwapBuffers();
	return;
}

int GLFWCALL closeDisplay()
{
	Game::getInstance()->exitGame();
	glfwTerminate();
	return 1;
}
