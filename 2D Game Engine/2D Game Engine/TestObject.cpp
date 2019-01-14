#include "TestObject.h"

#include "Game.h"
#include <cstdlib>

TestObject::TestObject() : GameObject("assets/Test.png", 10, 10, 32, 32, 1) {

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

		if(abs((y + height / 2) - (go->GetY() + go->GetHeight() / 2)) >
			abs((x + width / 2) - (go->GetX() + go->GetWidth() / 2))) {

			if(y > go->GetY()) y = go->GetY() + go->GetHeight();
			else y = go->GetY() - height;

		} else {

			if(x >= go->GetX()) x = go->GetX() + go->GetWidth();
			else x = go->GetX() - width;

		}
		
	}

	x += vX;
	y += vY;
	
}
