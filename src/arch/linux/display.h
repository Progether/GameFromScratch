#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <X11/Xlib.h>

class GameDisplay
{
public:
	GameDisplay(){/*.....*/};
	void createDisplay();
	void testDisplay();

private:
	Display *m_display;
	Window m_window;
	GC gc;
};

#endif //__DISPLAY_H__
