#include "TestObject.h"

#include "Game.h"
#include <cstdlib>
#include <algorithm>

TestObject::TestObject() : GameObject("assets/Test.png", 10, 10, 32, 32, 2) {

	vX = 0;
	vY = 0;

}

TestObject::~TestObject() {




}

void TestObject::Update(Game * game) {

	if(Game::event.type == SDL_KEYDOWN) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_w:
				vY = -3;
				break;

			case SDLK_s:
				vY = 3;
				break;

			case SDLK_a:
				vX = -3;
				break;

			case SDLK_d:
				vX = 3;
				break;


		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_w:
				vY = 0;
				break;

			case SDLK_s:
				vY  = 0;
				break;

			case SDLK_a:
				vX = 0;
				break;

			case SDLK_d:
				vX = 0;
				break;


		}

	}

	for(auto go : game->GetObjetcs()) if(this->CollidesWidth(go)) {
		
		int collisionWall = getCollisionWall(go);

		if(collisionWall == Wall::RIGHT || collisionWall == Wall::LEFT) {

			LockX(go);

		} else {

			LockY(go);

		}

	}

	x += vX;
	y += vY;
	
}
