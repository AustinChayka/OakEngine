#include "Player.h"

#include "Game.h"
#include <cstdlib>
#include <algorithm>

Player::Player(float x, float y) : GameObject("assets/Player.png", x, y, 21, 36, 3) {

	vX = 0;
	vY = 0;

	collidable = true;
	
}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	if(Game::event.type == SDL_KEYDOWN) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_SPACE:
				if(grounded) vY = -12;
				break;

			case SDLK_a:
				left = true;
				break;

			case SDLK_d:
				right = true;
				break;

			case SDLK_UP:
				Game::camera->ChangeSize(.05f);
				break;

			case SDLK_DOWN:
				Game::camera->ChangeSize(-.05f);
				break;
				
		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {
			
			case SDLK_a:
				left = false;
				break;

			case SDLK_d:
				right = false;
				break;


		}

	}

	if(left) {
		if(vX > -5) vX -= .4f;
		tileY = 1;
		tileX += .17f;
	}
	if(right) {
		if(vX < 5) vX += .4f;
		tileY = 0;
		tileX += .17f;
	}

	if(!left && !right) {
		vX /= 1.2f;
		tileX = 0;
	}
			
	vY += .7f;

	if(tileX > 9) tileX = 1;
				
}
