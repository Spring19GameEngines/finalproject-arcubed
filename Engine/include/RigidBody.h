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
  void setMass(float mass);
  void setDrag(float drag);
  void setUseGravity(bool huh);
  void setIsKinematic(bool huh);
  void addForce(float x, float y);
  void setForceX(float x);
  void setForceY(float y);


 protected:
  // variables
  float width, height, mass, drag, velX, velY, maxVelX, maxVelY, gravity;
  float lastX, lastY;
  bool useGravity, isKinematic;
  GameObject* go;
};

#endif
