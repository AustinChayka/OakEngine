#include "LevelManager.h"

#include "TestObject.h"
#include "TestBlocker.h"

#include "Game.h"

LevelManager::LevelManager() {}

LevelManager::~LevelManager() {}

void LevelManager::LoadLevel(int n) {
	
	switch(n) {

		objects.clear();

		case 0:
			AddObject(new TestObject());
			AddObject(new TestBlocker());
			break;
			
		default:
			break;
	}

	currentLevel = n;

}

void LevelManager::Update(StateManager * sm) {
	
	for(auto go : objects) go->UpdateObject(this); 

}

void LevelManager::Render() {

	for(auto go : objects) go->RenderObject();

}

void LevelManager::AddObject(GameObject * go) {

	objects.push_back(go);

}

std::vector<GameObject*> LevelManager::GetObjects() {

	return objects;

}

void LevelManager::NextLevel() {

	currentLevel++;
	LoadLevel(currentLevel);

}
