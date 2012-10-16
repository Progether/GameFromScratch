#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <GL/glew.h>
#include <vector>
#include <string>
class Entity
{
public:
	Entity();

	void setTexture(const char *file);
	void setSize(int width, int height);
	std::vector<int> getSize();
	void setPosition(int x, int y);
	std::vector<int> getPosition();

	void draw();

private:
	int m_x, m_y, m_width, m_height;

	GLuint positionBufferObject;

	std::vector<GLuint> shaders;
	GLuint shaderProgram;

};
GLuint CreateShader(GLenum eShaderType, const std::string &strShaderFile);
GLuint CreateProgram(const std::vector<GLuint> &shaderList);

#endif //__ENTITY_H__
