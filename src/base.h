#ifndef __BASE_H__
#define __BASE_H__

#include <GL/glew.h>

void CheckOpenGLError(const char* stmt, const char* fname, int line);

#ifndef NDEBUG
	#define GL_CHECK(stmt) do { \
			stmt; \
			CheckOpenGLError(#stmt, __FILE__, __LINE__); \
		} while (0)
#else
	#define GL_CHECK(stmt) stmt
#endif

#endif //__BASE_H__
