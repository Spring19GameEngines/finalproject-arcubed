<<<<<<< HEAD
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

// Include the pybindings
#include <pybind11/pybind11.h>

namespace py = pybind11;

// Creates a macro function that will be called
// whenever the module is imported into python
// 'mygameengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(input, m) {
  m.doc() = "our game engine as a library";  // Optional docstring

  py::class_<InputEngine>(m, "InputEngine")
      .def(py::init())  // our constructor
      .def("handleInput", &InputEngine::handleInput)
      .def("setButton", &InputEngine::setButton);
  // We do not need to expose everything to our users!
  //            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow,
  //            py::return_value_policy::reference)
}

#endif
=======
// #ifndef FINALPROJECT_ARCUBED_INPUTHANDLER_H
// #define FINALPROJECT_ARCUBED_INPUTHANDLER_H

// // Binding to imgui???
// #include "Command.h"

// class InputHandler {
//  public:
//   // accesses keys that are pressed and executes the method that is bound to
//   // them
//   void handleInput();

//   // binds a reference to a command to the pointer assigned with the desired
//   // button
//   void setButton(Command com, Command* point);

//   // HAVE TO COME BACK TO THIS TO FIX
//  private:
//   Command* buttonW_;
//   Command* buttonA_;
//   Command* buttonS_;
//   Command* buttonD_;
// };

// // Include the pybindings
// #include <pybind11/pybind11.h>

// namespace py = pybind11;

// // Creates a macro function that will be called
// // whenever the module is imported into python
// // 'mygameengine' is what we 'import' into python.
// // 'm' is the interface (creates a py::module object)
// //      for which the bindings are created.
// //  The magic here is in 'template metaprogramming'
// PYBIND11_MODULE(input, m) {
//   m.doc() = "our game engine as a library";  // Optional docstring

//   py::class_<InputEngine>(m, "InputEngine")
//       .def(py::init())  // our constructor
//       .def("handleInput", &InputEngine::handleInput)
//       .def("setButton", &InputEngine::setButton);
//   // We do not need to expose everything to our users!
//   //            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow,
//   //            py::return_value_policy::reference)
// }

// #endif
>>>>>>> 391ab8e2f09c0be96cf92baed186ad14937ad32d
