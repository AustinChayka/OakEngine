#ifndef GameObject_h
#define GameObject_h

#include "SDL.h"
#include "TextureManager.h"
#include "LevelManager.h"
#include "Game.h"

class LevelManager;
class Game;

class GameObject {

public:

	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height);
	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
		float scale);

	~GameObject();

	void UpdateObject(LevelManager * game);
	virtual void Update(LevelManager * game) = 0;
	void RenderObject();

	bool CollidesWidth(GameObject * go);

	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();

protected:

	float x, y, width, height, tileX = 0, tileY = 0;
	int spriteWidth, spriteHeight;
	
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

	float getXCenter();
	float getYCenter();

	bool collidable = false;
	void LockCollision(GameObject * go);
	int GetCollisionWall(GameObject * go);
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