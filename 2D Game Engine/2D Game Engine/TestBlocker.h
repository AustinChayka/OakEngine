#pragma once
#include "GameObject.h"
class TestBlocker :

	public GameObject {

public:

	TestBlocker();
	~TestBlocker();

	void Update(LevelManager * game);

};

