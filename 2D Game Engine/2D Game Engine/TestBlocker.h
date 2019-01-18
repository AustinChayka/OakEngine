#ifndef TestBlocker_h
#define TestBlocker_h

#include "GameObject.h"
class TestBlocker :

	public GameObject {

public:

	TestBlocker(float x, float y);
	~TestBlocker();

	void Update(LevelManager * game);

};

#endif