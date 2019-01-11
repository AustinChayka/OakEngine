#include "Level.h"

Level::Level(char * stateName) : GameState(stateName) {

	

}


Level::~Level() {



}

void Level::AddObject(GameObject * go) {

	objects.push_back(go);

}

void Level::Update() {

	for(auto go : objects) go.Update();

}

void Level::Render() {

	for(auto go : objects) go.RenderObject();

}
