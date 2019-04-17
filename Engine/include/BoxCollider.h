#ifndef FINALPROJECT_ARCUBED_BOXCOLLIDER_H
#define FINALPROJECT_ARCUBED_BOXCOLLIDER_H

#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

/*! \brief Box collider extends component. Checks to see if this GameObject is
 * overlapping any other GameObject.
 */
class BoxCollider : public Component {
 public:
  //! constructor
  BoxCollider(GameObject* go);

  //! derived from component
  void update();
  //! derived from component
  void send(string action, vector<string> args);
  //! derived from component
  void receive(string action, vector<string> args);
  //! checks to see if this object has collided with any other object that has a
  //! boxcollider
  bool anyCollision();

  //! Returns all gameobjects this box collider is currently overlapping with
  vector<string> checkCollision();

 protected:
  // variables
  float width, height;
  GameObject* go;
};

#endif
