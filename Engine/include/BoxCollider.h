#ifndef FINALPROJECT_ARCUBED_BOXCOLLIDER_H
#define FINALPROJECT_ARCUBED_BOXCOLLIDER_H

#include <string>
#include <vector>
#include "GameObject.h"

/**
 * A BoxCollider object. Has a check collision function which returns true if
 * this block is overlapping with the given block.
 */

using namespace std;

class BoxCollider : public Component {
 public:
  BoxCollider(GameObject* go);
  void update();
  void send(string action, vector<string> args);
  void receive(string action, vector<string> args);
  bool anyCollision();

  //! Checks to see if this box collider is currently overlapping with the given
  //! list of game objects
  vector<string> checkCollision();

 protected:
  // variables
  float width, height;
  GameObject* go;
};

#endif
