#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "TinyMath.h"

using namespace std;

class GameObject {
 public:
  //! constructor - Uses Default name and default position
  GameObject();
  //! constructor - Sets the name and location of the GameObject
  GameObject(string name, float x, float y);
  //! updates the object at a high priority
  // void earlyUpdate();
  //! updates the object at a normal priority
  virtual void update() = 0;
  //! updates the object at a low priority
  // void lateUpdate();
  //! adds a script to the object
  void addComponent(Component comp);
  vector<Component> getComponents();

  string toString() { return name + " at " + pos; }

 private:
  // Variables
  Vector2D pos;
  string name;
  vector<Component> components;
};

#endif
