#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>
class ComponentContainer;
class Component
{
public:
  // constructor
  Component(std::string name);
  ~Component();

  //! updates this component
  virtual void update() = 0;
  //
  //  //! takes a string name Action, and performs the action based upon
  //  parameters virtual vector<string> action(string action, vector<string>
  //  args) = 0;

  // Sends a message to the parent component container
  // TODO:: If we could find away to define this function in the cpp without
  // ruining the forward declaration that would be awesome
  virtual void send(std::string action, std::vector<std::string> args) = 0;

  virtual void receive(std::string action, std::vector<std::string> args) = 0;
  virtual void setContainer(ComponentContainer *container);
  virtual std::string getName();

protected:
  ComponentContainer *container;
  std::string name;

private:
  // Variables
};

#endif
