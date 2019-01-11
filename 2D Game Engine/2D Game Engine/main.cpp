#include "SDL.h"

#include "Game.h"
#include "TestObject.h"

Game * game = NULL;

int main(int argc, char * argv[]) {

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game("OakEngine v0.2a", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	game->AddObject(new TestObject());
	
	while(game->IsRunning()) {

		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

	}

	game->Clean();
		
	return 0;

}