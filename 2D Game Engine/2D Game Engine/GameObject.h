#ifndef GameObject_h
#define GameObject_h

#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class Game;

class GameObject {

public:

	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height);
	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
		float scale);

	~GameObject();

	void UpdateObject(Game * game);
	virtual void Update(Game * game) = 0;
	void RenderObject();

	bool CollidesWidth(GameObject * go);

	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();

protected:

	float x, y, width, height;
	int spriteWidth, spriteHeight;
	
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

	float getXCenter();
	float getYCenter();

	void LockCollision(GameObject * go);

	int getCollisionWall(GameObject * go);
	enum Wall {
		TOP = 1,
		RIGHT = 2,
		BOTTOM = 3,
		LEFT = 4
	};

private:

	void LockX(GameObject * go);
	void LockY(GameObject * go);
	
};

#endif