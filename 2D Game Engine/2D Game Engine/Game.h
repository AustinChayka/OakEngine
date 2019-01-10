#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game {

public:

	Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning();

	static SDL_Renderer * renderer;

private:

	bool running = false;
	SDL_Window * window;

};

#endif

