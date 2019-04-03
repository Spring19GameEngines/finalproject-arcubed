#ifndef FINALPROJECT_ARCUBED_COMPONENT_H
#define FINALPROJECT_ARCUBED_COMPONENT_H

#include <iostream>
#include <vector>
#include "TinyMath.h"

using namespace std;

class Component {
 public:
  //! constructor - Uses Default name and default position
  Component();
  //! updates the object at a high priority
  // void earlyUpdate();
  //! updates the object at a normal priority
  virtual void update() = 0;
  //! updates the object at a low priority
  // void lateUpdate();
  virtual void receive(int message) = 0;
  string toString() { return name; }

 private:
  // Variables
  string name;
};

#endif
