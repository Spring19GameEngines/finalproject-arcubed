#ifndef FINALPROJECT_ARCUBED_GAMEENGINE_H
#define FINALPROJECT_ARCUBED_GAMEENGINE_H

#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include "GameObject.h"

class GameEngine {
 public:
  //! Get the state of the game
  static GameEngine &getInstance();
  //! Set up the state of the game
  void startUp();
  //! Sets the dimensions of the window.
  void setWindowSize(int width, int height);
  //! updates the game state
  void update();

 private:
  GameEngine();                        // Private Singleton
  GameEngine(GameEngine const &);      // Avoid copy constructor
  void operator=(GameEngine const &);  // Don't allow assignment.
  // variables
  std::vector<GameObject *> gameObjects;
  int w, h;
};

#endif
