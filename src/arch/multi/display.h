#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <GL/glew.h>
#include <GL/glfw.h>


class GameDisplay
{
public:
	GameDisplay();
	~GameDisplay();

	void createDisplay();
	void getScreenSize(int *width, int *height);
	void swapBuffers();
};

int GLFWCALL closeDisplay();

#endif
