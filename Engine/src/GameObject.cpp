#include "GameObject.h"

//! constructor - Uses Default name and default position
GameObject::GameObject(std::string name) {
  this->name = name;
  this->pos = Vector2D(0, 0);
  this->width = 0;
  this->height = 0;
  this->components = new ComponentContainer();
};
//! constructor - Sets the name and location of the GameObject
GameObject::GameObject(std::string name, float x, float y, float w, float h) {
  this->name = name;
  this->pos = Vector2D(x, y);
  this->width = w;
  this->height = h;
  this->components = new ComponentContainer();
};

GameObject::~GameObject() { delete this->components; }

// updates the object and it's components
void GameObject::update() { components->update(); };

void GameObject::addComponent(Component *comp) {
  this->components->addComponent(comp);
}
void GameObject::removeComponent(std::string name) {
  this->components->removeComponent(name);
}
Component *GameObject::getComponent(std::string name) {
  return this->components->getComponent(name);
}
std::vector<Component *> GameObject::getComponents() {
  return this->components->getComponents();
}
