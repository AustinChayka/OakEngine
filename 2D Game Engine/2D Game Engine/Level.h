#ifndef Level_h
#define Level_h

#include "GameState.h"
#include <vector>
#include "GameObject.h"

class Level : public GameState {

public:

	Level(char * stateName);
	~Level();

	void AddObject(GameObject * go);

	void Update();
	void Render();

private:

	std::vector<GameObject> objects;

};

#endif