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

void TestObject::Update(LevelManager * game) {

	if(Game::event.type == SDL_KEYDOWN) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_w:
				up = true;
				break;

			case SDLK_s:
				down = true;
				break;

			case SDLK_a:
				left = true;
				break;

			case SDLK_d:
				right = true;
				break;


		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_w:
				up = false;
				break;

			case SDLK_s:
				down = false;
				break;

			case SDLK_a:
				left = false;
				break;

			case SDLK_d:
				right = false;
				break;


		}

	}

	if(up && vY > -4) vY -= .5f;
	if(down && vY < 4) vY += .5f;
	if(left && vX > -4) vX -= .5f;
	if(right && vX < 4) vX += .5f;

	if(!up && !down) vY /= 1.05f;
	if(!left && !right) vX /= 1.05f;

	x += vX;
	y += vY;

	tileX += .05f;
	if(tileX > 3) tileX = 0;

	Game::camera.x = (int)x - Game::camera.w / 2;
	Game::camera.y = (int)y - Game::camera.h / 2;
		
}
