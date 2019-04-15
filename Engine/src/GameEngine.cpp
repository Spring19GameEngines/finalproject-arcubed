#include "GameEngine.h"

GameEngine::GameEngine() {}

GameEngine &GameEngine::getInstance() {
  static GameEngine *instance = new GameEngine();
  return *instance;
}

void GameEngine::startUp() {
  // init gameobjects
}

void GameEngine::update() {
  for (GameObject *obj : gameObjects) {
    obj->update();
  }
}
