#ifndef FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H
#define FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H

#include <iostream>
#include <vector>
#include "Component.h"
using namespace std;

class ComponentContainer {
 public:
  // constructor - Uses Default name
  ComponentContainer();

  // updates each component
  void update() {
    for (Component* c : components) {
      c->update();
    }
  };

  // Adds the given component to this container
  void addComponent(Component* comp) {
    comp->setContainer(this);
    components.push_back(comp);
  };

  // Removes a component with the given ID from this container
  void removeComponent(string id) {
    for (int i = 0; i < components.size(); i++) {
      if (components[i] != NULL) {
        if (components[i]->getID() == id) {
          components.erase(components.begin() + i);
        }
      }
    }
  };

  // Get a component with the given id
  Component* getComponent(string id) {
    for (int i = 0; i < components.size(); i++) {
      if (components[i] != nullptr) {
        if (components[i]->getID() == id) {
          return components[i];
        }
      }
    }
  }

  // Get a vector of all components
  vector<Component*> getComponents() { return components; };

  // Send this message to all components
  void send(string action, vector<string> args) {
    for (int i = 0; i < components.size(); i++) {
      if (components[i] != NULL) {
        components[i]->receive(action, args);
      }
    }
  };

 private:
  vector<Component*> components;
};

#endif
