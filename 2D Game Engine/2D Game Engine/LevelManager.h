#ifndef LevelManager_h
#define LevelManager_h

#include "StateManager.h"
#include <vector>
#include "GameObject.h"

class StateManager;
class GameObject;

class LevelManager {
	
public:

	LevelManager();

	~LevelManager();

	void LoadLevel(int n);

	void Update(StateManager * sm);
	void Render();

	void AddObject(GameObject * go);
	std::vector<GameObject *> GetObjects();

	void NextLevel();

private:

	std::vector<GameObject *> objects;

	int currentLevel = 0;

};

#endif