#include "SDL.h"

#include "Game.h"

Game * game = NULL;

int main(int argc, char * argv[]) {

	game = new Game("OakEngine v0.1a", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while(game->isRunning()) {

		game->handleEvents();
		game->update();
		game->render();

	}

	game->clean();
		
	return 0;

}