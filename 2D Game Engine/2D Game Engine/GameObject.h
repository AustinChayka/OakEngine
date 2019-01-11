#ifndef GameObject_h
#define GameObject_h

#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class GameObject {

public:

	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height);
	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
		float scale);

	~GameObject();

	void UpdateObject();
	virtual void Update() = 0;
	void RenderObject();

	bool CollidesWidth(GameObject * go);

	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

protected:

	float x, y, scale;
	int width, height;

	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

};

#endif