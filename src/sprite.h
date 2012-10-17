#include "entity.h"

class sprite : public Entity
{
public:
	sprite();
	void draw();

private:
	GLuint positionBufferObject;
	GLuint IndexBufferId;
};
