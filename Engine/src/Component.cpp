
#include "Component.h"
// constructor
Component::Component(std::string id) { this->id = id; };

void Component::setContainer(ComponentContainer* container) {
  this->container = container;
}
std::string Component::getID() { return id; }
