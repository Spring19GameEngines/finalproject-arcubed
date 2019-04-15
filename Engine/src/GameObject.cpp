#include "GameObject.h"

//! constructor - Uses Default name and default position
GameObject::GameObject(std::string name) { this->name = name; };
//! constructor - Sets the name and location of the GameObject
GameObject::GameObject(std::string name, float x, float y, float w, float h) {
  this->name = name;
  this->pos = Vector2D(x, y);
  this->width = w;
  this->height = h;
  this->components = new ComponentContainer();
};

// updates the object and it's components
void GameObject::update() { components->update(); };
