#ifndef FINALPROJECT_ARCUBED_RIGIDBODY_H
#define FINALPROJECT_ARCUBED_RIGIDBODY_H

#include "GameObject.h"

class RigidBody : public Component {
 public:
  RigidBody(GameObject* go);

  void update();
  void send(std::string action, std::vector<std::string> args);
  void receive(std::string action, std::vector<std::string> args);
  void setGravity(float g);
  void shiftPosition(float x, float y);
  void setMass(float mass);
  void setDrag(float drag);
  void setUseGravity(bool huh);
  void setIsKinematic(bool huh);
  void addForce(float x, float y);
  void setForce(float x, float y);


 protected:
  // variables
  float x, y, width, height, mass, drag, velX, velY, maxVelX, maxVelY, gravity;
  bool useGravity, isKinematic;
  GameObject* go;
};

#endif
