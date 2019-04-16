#ifndef FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H
#define FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H

#include <iostream>
#include <vector>
#include "Component.h"

class ComponentContainer
{
public:
  // constructor - Uses Default name
  ComponentContainer();

  // updates each component
  void update();

  // Adds the given component to this container
  void addComponent(Component *comp);

  // Removes a component with the given ID from this container
  void removeComponent(std::string name);

  // Get a component with the given id
  Component *getComponent(std::string name);

  // Get a vector of all components
  std::vector<Component *> getComponents();

  // Send this message to all components
  void send(std::string action, std::vector<std::string> args);

private:
  std::vector<Component *> components;
};

#endif
