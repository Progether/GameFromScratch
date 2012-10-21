#include "sprite.h"
#include "base.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <string>

const std::string strVertexShader(
		"#version 330\n"
		"in vec4 position;\n"
		"in vec2 texcoord;\n"
		"uniform vec4 transform;\n"
		"out vec2 Texcoord;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = position * transform;\n"
		"	Texcoord = texcoord;\n"
		"}\n"
		);

const std::string strFragmentShader(
		"#version 330\n"
		"out vec4 outputColor;\n"
		"in vec2 Texcoord;\n"
		"uniform sampler2D tex;"
		"void main()\n"
		"{\n"
		"   outputColor = texture( tex, Texcoord) * vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
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

	const float textureCoords[] =
	{
		-5.0, -5.0,
		5.0, -5.0,
		5.0, 5.0,
		-5.0, 5.0,
	};

	//Clear gl errors TODO:Need to look where the initial error is coming from.
	glGetError();
	GL_CHECK( glGenVertexArrays(1, &vao) );
	GL_CHECK( glBindVertexArray(vao) );

	shaders.push_back(CreateShader(GL_VERTEX_SHADER, strVertexShader));
	shaders.push_back(CreateShader(GL_FRAGMENT_SHADER, strFragmentShader));
	shaderProgram = CreateProgram(shaders);

	//Create buffer object to store vertex information
	GL_CHECK( glGenBuffers(1, &positionBufferObject) );
	GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject) );
	GL_CHECK( glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW));

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position" );
	GL_CHECK( glEnableVertexAttribArray(posAttrib));
	GL_CHECK( glVertexAttribPointer(posAttrib, 4, GL_FLOAT, GL_FALSE, 0, NULL) );

	//Create buffer object to store texture mappings
	GLuint textMapObject;
	GL_CHECK( glGenBuffers(1, &textMapObject));
	GL_CHECK( glBindBuffer(GL_ARRAY_BUFFER, textMapObject));
	GL_CHECK( glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoords), textureCoords, GL_STATIC_DRAW));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	GL_CHECK( glEnableVertexAttribArray(texAttrib));
	GL_CHECK( glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 0, NULL));

	//Create buffer object to store triangle indexes
	GL_CHECK( glGenBuffers(1, &IndexBufferId) );
	GL_CHECK( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId) );
	GL_CHECK( glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPositions), indexPositions, GL_STATIC_DRAW) );

	setTexture();
	setSize(0.25f, 0.25f);
	glBindVertexArray(0);

}


void Sprite::draw()
{
	GL_CHECK( glUseProgram(shaderProgram) );
	GL_CHECK( glBindVertexArray(vao) );
	setTransforms();

	GL_CHECK( glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (GLvoid*) 0) );
}

void Sprite::setTexture()
{
	GL_CHECK( glGenTextures(1, &textureId) );
	GL_CHECK( glBindTexture(GL_TEXTURE_2D, textureId) );

	GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT) );
	GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) );

	//set texture border color to transparent
	float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GL_CHECK( glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color));

	GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	//Simple checkerboard texture for testing
	float pixels[] = {
		0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f
	};
	GL_CHECK( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels) );

}

void Sprite::setTransforms()
{
	GLint transUnif;
	transUnif = glGetUniformLocation( shaderProgram, "transform");

	GL_CHECK( glUniform4f(transUnif, (float)m_width, (float)m_height, 1.0f, 1.0f) );
}
