#include "entity.h"
#include "base.h"

#include <assert.h>
#include <GL/glfw.h>
#include <string>


Entity::Entity()
{

}

void Entity::setSize(float width, float height)
{
	m_width = width;
	m_height = height;
}


std::vector<float> Entity::getSize()
{
	std::vector<float> size;
	size.reserve(2);
	size[0] = m_width;
	size[1] = m_height;
	return size;
}


void Entity::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}


std::vector<float> Entity::getPosition()
{
	std::vector<float> pos;
	pos.reserve(2);
	pos[0] = m_x;
	pos[1] = m_y;
	return pos;
}


void Entity::draw()
{

}

GLuint Entity::CreateShader(GLenum eShaderType, const std::string &strShaderFile)
{
	GLuint shader = glCreateShader(eShaderType);
	const char *strFileData = strShaderFile.c_str();
	GL_CHECK( glShaderSource(shader, 1, &strFileData, NULL) );

	GL_CHECK( glCompileShader(shader) );

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch(eShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

	return shader;
}

GLuint Entity::CreateProgram(const std::vector<GLuint> &shaderList)
{
	GLuint program = glCreateProgram();

	for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		GL_CHECK( glAttachShader(program, shaderList[iLoop]) );

	GL_CHECK( glLinkProgram(program) );

	GLint status;
	glGetProgramiv (program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glDetachShader(program, shaderList[iLoop]);

	return program;
}
