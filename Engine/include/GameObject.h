#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "Component.h"
#include "Vector2D.h"

using namespace std;

class GameObject {
 public:
  //! constructor - Uses Default name and default position
  GameObject(string name);

  //! constructor - Sets the name and location of the GameObject
  GameObject(string name, float x, float y) {
    this->name = name;
    this->pos = Vector2D(x, y);
    this->components = ComponentContainer();
  };

  // updates the object and it's components
  void update() { components.update(); };

  //   string toString() { return name + " at " + pos; }

 protected:
  // Variables
  Vector2D pos;
  string name;
  ComponentContainer components;
  BoxCollider *collider;
};

#endif
