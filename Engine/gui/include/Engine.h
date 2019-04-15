#ifndef ENGINE
#define ENGINE

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  // This works for Mac
#include "SDL2/SDL.h"
#include "SDL_image.h"
#endif

#include <stdio.h>
#include "SpriteTool.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_sdl.h"

// This class sets up a full graphics program
class Engine {
 public:
  Engine();
  ~Engine();

  int loop();

 private:
  // Functions
  void initAll();

  bool initSDL();
  bool createWindow();
  bool initImGui();
  bool createRenderer();

  // Constants to be set up
  SDL_Window* window;
  SDL_Renderer* renderer;
  int screenWidth;
  int screenHeight;

  // Constants that are default
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
PYBIND11_MODULE(spritetool, m) {
  m.doc() = "our game engine as a library";  // Optional docstring

  py::class_<Engine>(m, "Engine")
      .def(py::init())  // our constructor
      .def("loop", &Engine::loop);
  // We do not need to expose everything to our users!
  //            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow,
  //            py::return_value_policy::reference)
}
#endif
