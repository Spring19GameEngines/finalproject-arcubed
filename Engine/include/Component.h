#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>
class ComponentContainer;
class GameObject;
class Component {
 public:
  // constructor
  Component(std::string id);

  //! updates this component
  virtual void update() = 0;
//
//  //! takes a string name Action, and performs the action based upon parameters
//  virtual vector<string> action(string action, vector<string> args) = 0;

  // Sends a message to the parent component container
  virtual void send(std::string action, std::vector<std::string> args) = 0;

  virtual void receive(std::string action, std::vector<std::string> args) = 0;
  void setContainer(ComponentContainer* container);
  std::string getID();

 protected:
  ComponentContainer* container;
  std::string id;
  GameObject* go;

 private:
  // Variables
};

#endif
