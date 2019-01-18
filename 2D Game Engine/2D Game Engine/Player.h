#ifndef Player_h
#define Player_h

#include "GameObject.h"

class Player : public GameObject {

public:

	Player(float x, float y);
	~Player();
	
	void Update(LevelManager * game);

private:

	bool left = false, right = false;

};

#endif