#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "ComponentContainer.h"
#include "Vector2D.h"

class GameObject {
 public:
  //! constructor - Uses Default name and default position
  GameObject(std::string name);

  //! constructor - Sets the name and location of the GameObject
  GameObject(std::string name, float x, float y, float w, float h);

  // updates the object and it's components
  void update();

  // Variables
  Vector2D pos;
  std::string name;
  float width, height;
  int scale = 1;
  ComponentContainer* components;
};

#endif
