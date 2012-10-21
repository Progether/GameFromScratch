#include "sprite.h"
#include "base.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <string>

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
		"   outputColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\n"
		);

Sprite::Sprite()
{
	const float vertexPositions[] =
	{
		0.75f, 0.75f, 0.0f, 1.0f,
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, 0.75f, 0.0f, 1.0f
	};

	const GLubyte indexPositions[] =
	{
		0, 1, 2,
		3, 2, 0
	};

	//Clear gl errors TODO:Need to look where the initial error is coming from.
	glGetError();
	GL_CHECK( glGenBuffers(1, &positionBufferObject) );
	GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject) );
	GL_CHECK( glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW));
	GL_CHECK( glVertexAttribPointer(positionBufferObject, 4, GL_FLOAT, GL_FALSE, 0, NULL) );
	GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, 0) );


	GL_CHECK( glGenBuffers(1, &IndexBufferId) );
	GL_CHECK( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId) );
	GL_CHECK( glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPositions), indexPositions, GL_STATIC_DRAW) );
	GL_CHECK( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0) );

	shaders.push_back(CreateShader(GL_VERTEX_SHADER, strVertexShader));
	shaders.push_back(CreateShader(GL_FRAGMENT_SHADER, strFragmentShader));
	shaderProgram = CreateProgram(shaders);
}


void Sprite::draw()
{
	GL_CHECK( glUseProgram(shaderProgram) );
	GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject) );
	GL_CHECK( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId) );
	GL_CHECK( glEnableVertexAttribArray(0) );
	GL_CHECK( glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0) );
	GL_CHECK( glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (GLvoid*) 0) );

	glUseProgram(0);
}

void Sprite::setTexture()
{

}
