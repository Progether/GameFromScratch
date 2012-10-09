#include <cstdio>

#include "display.h"

GameDisplay::~GameDisplay()
{
	glfwCloseWindow();
}

void GameDisplay::createDisplay()
{
	glfwInit();
	if(glfwOpenWindow(0,0,0,0,0,0,0,0,GLFW_WINDOW) != GL_TRUE)
		throw -1;
	return;
}

void GameDisplay::getScreenSize(int* width, int* height)
{
	glfwGetWindowSize(width, height);
	return;
}

void GameDisplay::swapBuffers()
{
	glfwSwapBuffers();
	return;
}
