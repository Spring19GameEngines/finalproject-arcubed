#ifndef FINALPROJECT_ARCUBED_INPUTHANDLER_H
#define FINALPROJECT_ARCUBED_INPUTHANDLER_H

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
  Command* buttonW_;
  Command* buttonA_;
  Command* buttonS_;
  Command* buttonD_;
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
