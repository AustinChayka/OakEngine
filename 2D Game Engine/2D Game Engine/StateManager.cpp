#include "StateManager.h"

LevelManager * levelManager = nullptr;
MenuState * mainMenu = nullptr;
MenuState * pauseMenu = nullptr;

StateManager::StateManager() : levelManager() {

	levelManager = new LevelManager();
	
	levelManager->LoadLevel(0);

}

StateManager::~StateManager() {}

void StateManager::Update() {

	levelManager->Update(this);

}

void StateManager::Render() {

	levelManager->Render();

}

void StateManager::ChangeState(int n) {


}
