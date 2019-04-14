#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>
#include "ComponentContainer.h"
#include "GameObject.h"
using namespace std;

class Component {
 public:
  // constructor
  Component(string id) { this.id = id; };

  //! updates this component
  virtual void update() = 0;
//
//  //! takes a string name Action, and performs the action based upon parameters
//  virtual vector<string> action(string action, vector<string> args) = 0;

  // Sends a message to the parent component container
  void send(string action, vector<string> args) {
    if (container != NULL) {
      container.send(action, args);
    } else {
      std::cout << "Failed to send message" << std::endl;
    }
  }

  vector<string> receive(string action, vector<string> args) = 0;
  void setContainer(ComponentContainer* container) {
    this.container = container;
  }
  string getID() { return id; }

 protected:
  ComponentContainer container;
  string id;
  GameObject go;

 private:
  // Variables

};

#endif
