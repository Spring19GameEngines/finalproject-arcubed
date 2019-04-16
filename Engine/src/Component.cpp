
#include "Component.h"
// constructor
Component::Component(std::string name) { this->name = name; };

void Component::setContainer(ComponentContainer *container)
{
  this->container = container;
}
std::string Component::getName() { return name; }
