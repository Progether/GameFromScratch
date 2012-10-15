#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "GL/glfw.h"

int GLFWCALL closeDisplay();

class GameDisplay
{
public:
	GameDisplay();
	~GameDisplay();

	void createDisplay();
	void getScreenSize(int *width, int *height);
	void swapBuffers();


};

#endif
