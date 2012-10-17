#include "sprite.h"
#include <GL/glew.h>

const std::string strVertexShader(
	"#version 330\n"
	"layout(location = 0) in vec4 position;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = position;\n"
	"}\n"
);

const std::string strFragmentShader(
	"#version 330\n"
	"out vec4 outputColor;\n"
	"void main()\n"
	"{\n"
	"   outputColor = vec4(0.5f, 1.0f, 1.0f, 1.0f);\n"
	"}\n"
);

sprite::sprite()
{
	const float vertexPositions[] = {
		0.75f, 0.75f, 0.0f, 1.0f,
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, 0.75f, 0.0f, 1.0f
	};

	const GLubyte indexPositions[] = {
		0, 1, 2,
		3, 2, 0
	};

	glGenBuffers(1, &positionBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &IndexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPositions), indexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	shaders.push_back(CreateShader(GL_VERTEX_SHADER, strVertexShader));
	shaders.push_back(CreateShader(GL_FRAGMENT_SHADER, strFragmentShader));
	shaderProgram = CreateProgram(shaders);
}


void sprite::draw()
{
	glUseProgram(shaderProgram);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (GLvoid*) 0);

	glUseProgram(0);
}
