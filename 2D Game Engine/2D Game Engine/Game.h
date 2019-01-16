#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include "StateManager.h"

class GameObject;
class StateManager;

class Game {

public:

	Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();
	
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool IsRunning();
	
	static SDL_Renderer * renderer;
	static SDL_Event event;
		
private:

	bool running = false;
	SDL_Window * window;

	StateManager * stateManager;
		
};

#endif

