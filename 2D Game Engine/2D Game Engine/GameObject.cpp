#include "GameObject.h"
#include <cmath>

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height) {

	texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	spriteWidth = init_width;
	spriteHeight = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	width = (float)init_width;
	height = (float)init_height;
	
}

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
	float init_scale) {

	texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	spriteWidth = init_width;
	spriteHeight = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	width = init_width * init_scale;
	height = init_height * init_scale;

}

GameObject::~GameObject() {

	delete texture;

}

void GameObject::UpdateObject(LevelManager * game) {

	Update(game);

	x += vX;
	y += vY;

	grounded = false;
	if(collidable) for(auto go : game->GetObjects()) if(this->CollidesWith(go) && go->IsMoveable()) go->LockCollision(this);

	srcRect.x = (int)tileX * spriteWidth;
	srcRect.y = (int)tileY * spriteHeight;
	
	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}

void GameObject::RenderObject() {

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}

bool GameObject::CollidesWith(GameObject * go) {

	if(this == go) return false;

	return x < go->GetX() + go->GetWidth()
		&& x + width > go->GetX()
		&& y < go->GetY() + go->GetHeight()
		&& y + height > go->GetY();

}

float GameObject::GetX() {

	return x;

}

float GameObject::GetY() {

	return y;

}

float GameObject::GetVX() {

	return vX;

}

float GameObject::GetVY() {

	return vY;

}

int GameObject::GetWidth() {

	return (int)width;

}

int GameObject::GetHeight() {

	return (int)height;

}

void GameObject::LockX(GameObject * go) {

	if(x >= go->GetX()) x = go->GetX() + go->GetWidth();
	else x = go->GetX() - width;

	vX = 0;

}

void GameObject::LockY(GameObject * go) {

	if(y > go->GetY()) y = go->GetY() + go->GetHeight();
	else {
		y = go->GetY() - height;
		grounded = true;
	}

	vY = 0;

}

float GameObject::GetXCenter() {

	return x + width / 2;

}

float GameObject::GetYCenter() {

	return y + height / 2;

}

bool GameObject::IsDead() {

	return dead;

}

bool GameObject::IsMoveable() {

	return moveable;

}

void GameObject::LockCollision(GameObject * go) {

	int collisionWall = GetCollisionWall(go);

	if(collisionWall == Wall::RIGHT || collisionWall == Wall::LEFT) {

		LockX(go);

	} else {

		LockY(go);

	}

}

int GameObject::GetCollisionWall(GameObject * go) {

	if(!CollidesWith(go)) return -1;

	float dX, dY;

	if(x > go->GetX()) dX = go->GetX() + go->GetWidth() - x;
	else dX = x + width - go->GetX();

	if(y > go->GetY()) dY = go->GetY() + go->GetHeight() - y;
	else dY = y + height - go->GetY();

	if(dX > dY) {

		if(y > go->GetY()) return Wall::TOP;
		else return Wall::BOTTOM;

	} else {

		if(x > go->GetX()) return Wall::LEFT;
		else return Wall::RIGHT;

	}

}
