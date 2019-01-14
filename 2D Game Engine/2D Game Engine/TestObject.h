#ifndef TestObject_h
#define TestObject_h

#include "GameObject.h"

class TestObject : public GameObject {

public:

	TestObject();
	~TestObject();
	
	void Update(Game * game);

private:

	float vX, vY;

};

#endif