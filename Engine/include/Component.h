#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>

/*! \brief a generic component that gets added to a gameObject. Contains functions update, send, and receive,
 * which add functionality to the gameObject once these virtual functions are overwritten.
 * */
class ComponentContainer;
class Component
{
public:
  //! constructor
  Component(std::string name);

  //! destructor. Gets called when pybind cleans up a game
  ~Component();

  //! updates this component. Called once per game loop
  virtual void update() = 0;

  //! Sends a message to the parent component container
  virtual void send(std::string action, std::vector<std::string> args) = 0;

  //! receives a message sent from the parent component container and adds functionality based upon the message
  virtual void receive(std::string action, std::vector<std::string> args) = 0;

  //! sets the parent container of the component
  virtual void setContainer(ComponentContainer *container);

  //! gets the name of the component
  virtual std::string getName();

protected:
  ComponentContainer *container;
  std::string name;

private:
  // Variables
};

#endif
