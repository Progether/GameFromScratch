#include "GL/glfw.h"

class GameDisplay
{
public:
	GameDisplay(){/*...*/};
	~GameDisplay();

	void createDisplay();
	void getScreenSize(int *width, int *height);
};
