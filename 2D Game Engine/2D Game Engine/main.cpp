#include "SDL.h"

#include "Game.h"

Game * game = NULL;

SDL_Renderer * Game::renderer = nullptr;

int main(int argc, char * argv[]) {

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game("OakEngine v0.1a", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while(game->isRunning()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

	}

	game->clean();
		
	return 0;

}