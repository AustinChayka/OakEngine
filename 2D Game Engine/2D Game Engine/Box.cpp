#include "Box.h"

#include "Player.h"

Box::Box(float x, float y) : GameObject("assets/Box.png", x, y, 32, 32, 3) {

	collidable = true;

}

Box::~Box() {}

void Box::Update(LevelManager * game) {

	vY += .9f;
	
}


