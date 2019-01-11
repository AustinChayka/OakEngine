#ifndef TestObject_h
#define TestObject_h

#include "GameObject.h"

class TestObject : public GameObject {

public:

	TestObject();
	~TestObject();
	
	void Update();

private:

	float vX, vY;

};

#endif