#ifndef TestObject_h
#define TestObject_h

#include "GameObject.h"

class TestObject : public GameObject {

public:

	TestObject();
	~TestObject();
	
	void Update(LevelManager * game);

private:

	float vX, vY;
	bool left  = false, right = false, up = false, down = false;

};

#endif