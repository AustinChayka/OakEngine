#include "LevelManager.h"

#include "Player.h"
#include "TestBlocker.h"
#include "Box.h"

#include "Game.h"

LevelManager::LevelManager() {}

LevelManager::~LevelManager() {}

void LevelManager::LoadLevel(int n) {
	
	switch(n) {

		objects.clear();

		case 0:
			AddObject(new Player(50, 50));
			AddObject(new TestBlocker(50, 300));
			AddObject(new Box(200, 20));
			Game::camera->SetTarget(objects.at(0));
			break;
			
		default:
			break;
	}

	currentLevel = n;

}

void LevelManager::Update(StateManager * sm) {
	
	for(int i = 0; i < objects.size(); i++) {

		objects.at(i)->UpdateObject(this);
		if(objects.at(i)->IsDead()) {
			delete objects.at(i);
			objects.erase(objects.begin() + i);
		}

	}

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
