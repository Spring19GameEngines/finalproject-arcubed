#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "ComponentContainer.h"
#include "Vector2D.h"

/*! \brief a representation of a game object
 *
 */
class GameObject {
 public:
  //! constructor - Uses Default name and default position
  GameObject(std::string name);

  //! constructor - Sets the name and location of the GameObject
  GameObject(std::string name, float x, float y, float w, float h);

  //! destructor
  ~GameObject();

  //! updates the object and it's components
  void update();
  //! Adds the given component to this container
  void addComponent(Component *comp);

  //! Removes a component with the given ID from this container
  void removeComponent(std::string name);

  //! Get a component with the given id
  Component *getComponent(std::string name);

  //! Get a vector of all components
  std::vector<Component *> getComponents();

  //! The position of this game object
  Vector2D pos;
  //! Name of this game object
  std::string name;
  //! The width of this game object
  float width;
  //! The height of this game object
  float height;
  //! The scale of this game object
  int scale = 1;
  //! A component container containing all of the components this gameobject
  //! owns
  ComponentContainer *components;
};

#endif
