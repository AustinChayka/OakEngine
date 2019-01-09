#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>

class Game {

public:

	Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning();

private:

	bool running = false;
	SDL_Window * window;
	SDL_Renderer * renderer;

};

#endif

