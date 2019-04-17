#ifndef FINALPROJECT_ARCUBED_COMMAND_H
#define FINALPROJECT_ARCUBED_COMMAND_H
#include "GameObject.h"
class Command {
 public:
  virtual ~Command(){};
  virtual void execute() = 0;
  virtual void setGameObject(GameObject *go) { this->go = go; }

 protected:
  GameObject *go;
};

// NOTE: All player made commands have to implement Command and overwrite the
// "execute" method
#endif
