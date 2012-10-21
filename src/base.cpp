#include "base.h"

#include <stdio.h>
#include <stdlib.h>

void CheckOpenGLError(const char* stmt, const char* fname, int line)
{
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("OpenGL error %d, at %s:%i - for %s\n", err, fname, line, stmt);
		switch(err)
		{
		case GL_INVALID_ENUM:
			printf("GL_INVALID_ENUM\n");
			break;
		case GL_INVALID_VALUE:
			printf("GL_INVALID_VALUE\n");
			break;
		case GL_INVALID_OPERATION:
			printf("GL_INVALID_OPERATION:");
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
			break;
		case GL_OUT_OF_MEMORY:
			printf("GL_OUT_OF_MEMORY\n");
			break;
		case GL_STACK_UNDERFLOW:
			printf("GL_STACK_UNDERFLOW\n");
			break;
		case GL_STACK_OVERFLOW:
			printf("GL_STACK_OVERFLOW\n");
			break;
		}
		abort();
	}
}
