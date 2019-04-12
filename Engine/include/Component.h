#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>
#include "ComponentContainer.h"
using namespace std;

class Component {
 public:
  // constructor
  Component(string id) { this.id = id; };

  //! updates this component
  virtual void update() = 0;
  // Sends a message to the parent component container
  void send(string msg) {
    if (container != NULL) {
      container.send(msg, this.id);
    } else {
      std::cout << "Failed to send message" << std::endl;
    }
  }
  void receive(string msg, string srcID) = 0;
  void setContainer(ComponentContainer* container) {
    this.container = container;
  }
  string getID() { return id; }
  //   string toString() { return id; }

 protected:
  ComponentContainer container;

 private:
  // Variables
  string id;
};

#endif
