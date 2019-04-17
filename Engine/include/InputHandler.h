#ifndef FINALPROJECT_ARCUBED_INPUTHANDLER_H
#define FINALPROJECT_ARCUBED_INPUTHANDLER_H

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
#include "Command.h"

class InputHandler {
 public:
  // accesses keys that are pressed and executes the method that is bound to
  // them
  void handleInput();

  // binds a reference to a command to the pointer assigned with the desired
  // button
  void setButton(Command com, Command* point);

  // HAVE TO COME BACK TO THIS TO FIX
 private:
  Command* buttonA_;
  Command* buttonB_;
  Command* buttonC_;
  Command* buttonD_;
  Command* buttonE_;
  Command* buttonF_;
  Command* buttonG_;
  Command* buttonH_;
  Command* buttonI_;
  Command* buttonJ_;
  Command* buttonK_;
  Command* buttonL_;
  Command* buttonM_;
  Command* buttonN_;
  Command* buttonO_;
  Command* buttonP_;
  Command* buttonQ_;
  Command* buttonR_;
  Command* buttonS_;
  Command* buttonT_;
  Command* buttonU_;
  Command* buttonV_;
  Command* buttonW_;
  Command* buttonX_;
  Command* buttonY_;
  Command* buttonZ_;
};

#endif
