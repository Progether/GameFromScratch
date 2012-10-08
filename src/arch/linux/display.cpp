#include <assert.h>

#include "display.h"

void GameDisplay::createDisplay()
{
	m_display = XOpenDisplay(NULL);
	assert(m_display);

	int blackColor = BlackPixel(m_display, DefaultScreen(m_display));
	int whiteColor = WhitePixel(m_display, DefaultScreen(m_display));

	//Create the window
	Window m_window = XCreateSimpleWindow(m_display, DefaultRootWindow(m_display), 0, 0, 200, 100, 0, blackColor, blackColor);

	XSelectInput(m_display, m_window, StructureNotifyMask);
	XMapWindow(m_display, m_window);

	// Create a "Graphics Context"
	gc = XCreateGC(m_display, m_window, 0, NULL);

	// Tell the GC we draw using the white color
	XSetForeground(m_display, gc, whiteColor);

	for(;;) {
	  XEvent e;
	  XNextEvent(m_display, &e);
	  if (e.type == MapNotify)
		break;
	}

	// Draw the line
	XDrawLine(m_display, m_window, gc, 10, 60, 180, 20);
	XFlush(m_display);
}
