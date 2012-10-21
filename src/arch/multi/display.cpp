#include <cstdio>

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
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	if(glfwOpenWindow(0,0,0,0,0,0,0,0,GLFW_WINDOW) != GL_TRUE)
		throw;

	glfwSetWindowCloseCallback(closeDisplay);
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

int GLFWCALL closeDisplay()
{
	Game::getInstance()->exitGame();
	glfwTerminate();
	return 1;
}
