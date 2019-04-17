#include "ComponentContainer.h"

ComponentContainer::ComponentContainer() {}

ComponentContainer::~ComponentContainer()
{
  for (int i = 0; i < components.size(); i++)
  {
    if (components[i] != nullptr)
    {
      delete components[i];
    }
  }
}

// updates each component
void ComponentContainer::update()
{
  for (Component *c : components)
  {
    c->update();
  }
};

// Adds the given component to this container
void ComponentContainer::addComponent(Component *comp)
{
  comp->setContainer(this);
  components.push_back(comp);
};

// Removes a component with the given ID from this container
void ComponentContainer::removeComponent(std::string name)
{
  for (int i = 0; i < components.size(); i++)
  {
    if (components[i] != nullptr)
    {
      if (components[i]->getName() == name)
      {
        components.erase(components.begin() + i);
      }
    }
  }
};

// Get a component with the given id
Component *ComponentContainer::getComponent(std::string name)
{
  for (int i = 0; i < components.size(); i++)
  {
    if (components[i] != nullptr)
    {
      if (components[i]->getName() == name)
      {
        return components[i];
      }
    }
  }
  // didnt find it
  return nullptr;
}
// Send this message to all components
void ComponentContainer::send(std::string action,
                              std::vector<std::string> args)
{
  for (int i = 0; i < components.size(); i++)
  {
    if (components[i] != nullptr)
    {
      components[i]->receive(action, args);
    }
  }
}

// Get a vector of all components
std::vector<Component *> ComponentContainer::getComponents()
{
  return components;
};
