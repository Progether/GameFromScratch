#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <GL/glew.h>
#include <vector>
#include <string>
class Entity
{
public:
	Entity();

	void setSize(float width, float height);
	std::vector<float> getSize();
	void setPosition(float x, float y);
	std::vector<float> getPosition();

	virtual void draw();

protected:
	GLuint CreateShader(GLenum eShaderType, const std::string &strShaderFile);
	GLuint CreateProgram(const std::vector<GLuint> &shaderList);

	float m_x, m_y, m_width, m_height;

	std::vector<GLuint> shaders;
	GLuint shaderProgram;

};


#endif //__ENTITY_H__
