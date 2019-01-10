#include "GameObject.h"

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height) {

	texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	width = init_width;
	height = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	scale = 1;
	
}

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
	float init_scale) {

	texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	width = init_width;
	height = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	scale = init_scale;

}

GameObject::~GameObject() {}

void GameObject::UpdateObject() {

	Update();
	
	destRect.x = (int)x;
	destRect.y = (int)y;
	destRect.w = (int)(width * scale);
	destRect.h = (int)(height * scale);

}

void GameObject::RenderObject() {

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}
