#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "ComponentContainer.h"
#include "Vector2D.h"

class GameObject
{
public:
  //! constructor - Uses Default name and default position
  GameObject(std::string name);

  //! constructor - Sets the name and location of the GameObject
  GameObject(std::string name, float x, float y, float w, float h);

  // updates the object and it's components
  void update();
  // Adds the given component to this container
  void addComponent(Component *comp);

  // Removes a component with the given ID from this container
  void removeComponent(std::string name);

  // Get a component with the given id
  Component *getComponent(std::string name);

  // Get a vector of all components
  std::vector<Component *> getComponents();
  // Variables
  Vector2D pos;
  std::string name;
  float width, height;
  int scale = 1;
  ComponentContainer *components;
};

#endif
