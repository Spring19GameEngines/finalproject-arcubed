#ifndef FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H
#define FINALPROJECT_ARCUBED_COMPONENT_CONTAINER_H

#include <iostream>
#include <vector>
#include "TinyMath.h"

using namespace std;

class ComponentContainer {
 public:
  // constructor - Uses Default name
  ComponentContainer();

  // updates each component
  void update() {
    for (Component c : components) {
      c.update();
    }
  };

  // Adds the given component to this container
  void addComponent(Component comp) {
    comp.setContainer(this);
    components.push_back(comp);
  };

  // Removes a component with the given ID from this container
  void removeComponent(int id) {
    for (int i = 0; i < components.length(); i++) {
      if (components[i] != NULL) {
        if (components[i].id = id) {
          components.erase(components.begin() + i);
        }
      }
    }
  };

  // Get a component with the given id
  Component getComponent(int id) {
    for (int i = 0; i < components.length(); i++) {
      if (components[i] != NULL) {
        if (components[i].id = id) {
          return components[i];
        }
      }
    }
  }

  // Get a vector of all components
  vector<Component> getComponents() { return components; };

  // Send this message to all components
  void send(int message, int srcID) {
    for (int i = 0; i < components.length(); i++) {
      if (components[i] != NULL) {
        components[i]->receive(message, srcID);
      }
    }
  };

 private:
  vector<Component> components;
};

#endif
