#ifndef FINALPROJECT_ARCUBED_COMMAND_H
#define FINALPROJECT_ARCUBED_COMMAND_H
#include "GameObject.h"

/** \brief Allows for generic commands to be passed to components/objects when
 * certain conditions are met. A class must extend command and must overwrite
 * execute in order to have the command be read by the engine.
 */
class Command {
 public:
  //! destructor for a command. Gets called when pybind cleans up a game.
  virtual ~Command(){};

  //! executes a generic command written by the user.
  virtual void execute() = 0;

  //! sets the game object this Command will affect.
  virtual void setGameObject(GameObject *go) { this->go = go; }

 protected:
  //! The gameobject this belongs to
  GameObject *go;
};

// NOTE: All player made commands have to implement Command and overwrite the
// "execute" method
#endif
