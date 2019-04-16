#ifndef FINALPROJECT_ARCUBED_RIGIDBODY_H
#define FINALPROJECT_ARCUBED_RIGIDBODY_H

#include "GameObject.h"

class RigidBody : public Component {
 public:
  RigidBody(GameObject* go) : Component("rigidbody") {
    this->x = go->pos.x;
    this->y = go->pos.y;
    this->width = go->width;
    this->height = go->height;
    this->go = go;
    this->mass = this->width * this->height;
    this->drag = 1.0f;
    this->useGravity = true;
    this->isKinematic = true;
    this->velX = 0.0f;
    this->velY = 0.0f;
    this->gravity = 4.0f;
  };

  void update();
  void send(std::string action, std::vector<std::string> args);
  void receive(std::string action, std::vector<std::string> args);

 protected:
  // variables
  float x, y, width, height, mass, drag, velX, velY, maxVelX, maxVelY, gravity;
  bool useGravity, isKinematic;
  GameObject* go;

  // functions
  void setWidth(float w);
  void setHeight(float h);
  void setGrav(float g);
  void shiftPosition(float x, float y);
  void setMass(float mass);
  void setDrag(float drag);
  void setGravity(bool huh);
  void setKinematic(bool huh);
  void addForce(float x, float y);
};

#endif
