#ifndef FINALPROJECT_ARCUBED_RIGIDBODY_H
#define FINALPROJECT_ARCUBED_RIGIDBODY_H

#include "GameObject.h"

/*! \brief Handles physics for game objects.
 *
 */
class RigidBody : public Component {
 public:
  //! constructor
  RigidBody(GameObject* go);
  //! derived from component - updates the position of the object every frame
  //! after applying gravity
  void update();
  //! derived from component
  void send(std::string action, std::vector<std::string> args);
  //! derived from component
  void receive(std::string action, std::vector<std::string> args);
  //! sets the gravity of the object
  void setGravity(float g);
  //! sets the mass of an object
  void setMass(float mass);
  //! sets the drag of the object
  void setDrag(float drag);
  //! sets a flag that tells the engine whether or not this object uses gravity
  void setUseGravity(bool huh);
  //! sets a flag that tells the engine whether or not this object is kinematic
  void setIsKinematic(bool huh);
  //! adds a force to the object
  void addForce(float x, float y);
  //! gets the X velocity
  float getForceX();
  //! gets the Y velocity
  float getForceY();
  //! sets the x velocity to the given x
  void setForceX(float x);
  //! sets the y velovity to the given y
  void setForceY(float y);
  //! sets the maximum velocity for an objects x component
  void setMaxForceX(float f);
  //! sets the maximum velocity for an objects x component
  void setMaxForceY(float f);

 protected:
  // variables
  float width, height, mass, drag, velX, velY, maxVelX, maxVelY, gravity;
  float lastX, lastY;
  bool useGravity, isKinematic;
  GameObject* go;
};

#endif
