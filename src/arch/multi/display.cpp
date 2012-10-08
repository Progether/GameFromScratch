#include "display.h"
#include "stdio.h"

GameDisplay::~GameDisplay()
{
	glfwCloseWindow();
}

void GameDisplay::createDisplay()
{
	glfwInit();
	if(glfwOpenWindow(0,0,0,0,0,0,0,0,GLFW_WINDOW) != GL_TRUE)
		printf("Failed opening window\n");
	return;
}

void GameDisplay::getScreenSize(int* width, int*height)
{
	glfwGetWindowSize(width, height);
}
