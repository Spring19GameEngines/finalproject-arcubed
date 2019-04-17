#ifndef FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H
#define FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H

#include <iostream>
#include <vector>
#include "Component.h"

/*!\brief Holds all the components that are contained by a game object. Allows
 * for messages to be sent to all components of a game object.
 */
class ComponentContainer {
 public:
  //! constructor
  ComponentContainer();

  //! destructor. gets called when pybind cleans up a game.
  ~ComponentContainer();

  //! updates each component by calling each component's generic update function
  void update();

  //! Adds the given component to this container
  void addComponent(Component *comp);

  //! Removes a component with the given name from this container
  void removeComponent(std::string name);

  //! Get a component with the given name
  Component *getComponent(std::string name);

  //! Get a vector of all components
  std::vector<Component *> getComponents();

  //! Send this message to all components
  void send(std::string action, std::vector<std::string> args);

 private:
  //! A list of all of the components in this container
  std::vector<Component *> components;
};

#endif
