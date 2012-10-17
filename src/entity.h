#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <GL/glew.h>
#include <vector>
#include <string>
class Entity
{
public:
	Entity();

	void setSize(int width, int height);
	std::vector<int> getSize();
	void setPosition(int x, int y);
	std::vector<int> getPosition();

	virtual void draw();

protected:
	GLuint CreateShader(GLenum eShaderType, const std::string &strShaderFile);
	GLuint CreateProgram(const std::vector<GLuint> &shaderList);

	int m_x, m_y, m_width, m_height;

	std::vector<GLuint> shaders;
	GLuint shaderProgram;

};


#endif //__ENTITY_H__
