#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "entity.h"

class Sprite : public Entity
{
public:
	Sprite();
	void draw();
	void setTexture();

private:
	GLuint positionBufferObject;
	GLuint IndexBufferId;
};



#endif //__SPRITE_H__
