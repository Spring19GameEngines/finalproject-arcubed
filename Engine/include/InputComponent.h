#ifndef FINALPROJECT_ARCUBED_INPUTCOMPONENT_H
#define FINALPROJECT_ARCUBED_INPUTCOMPONENT_H

// Using SDL, SDL_image, standard IO, and strings
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
// Windows and Mac use a different path
// If you have compilation errors, change this as needed.
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#endif

// Binding to imgui???
#include <unordered_map>
#include "Command.h"
using namespace std;

/*! \brief handles all inputs from player and executes commands based upon the
 * input
 *
 */
class InputComponent : public Component {
 public:
  //! constructor
  InputComponent(GameObject *go);
  //! constructor - used for static casting
  InputComponent(Component *component);
  //! derived from component - handles input
  void update();
  //! derived from component
  void send(string action, vector<string> args);
  //! derived from component
  void receive(string action, vector<string> args);

  //! binds a reference to a command to the pointer assigned with the desired
  //! button
  void setButton(int key, Command *cmd);

 private:
  GameObject *go;
  std::unordered_map<SDL_Scancode, Command *> mappedKeys;
};

#endif  // FINALPROJECT_ARCUBED_INPUTCOMPONENT_H
