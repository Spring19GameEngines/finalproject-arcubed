#ifndef FINALPROJECT_ARCUBED_GAMEENGINE_H
#define FINALPROJECT_ARCUBED_GAMEENGINE_H

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

#include <stdio.h>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include "GameObject.h"
#include "ResourceManager.h"

/*! \brief Represents the state of a game engine
 *
 */
class GameEngine {
 public:
  //! Get the state of the game
  static GameEngine &getInstance();
  //! destructor
  ~GameEngine();
  //! creates a game object and adds it to the list of gameObjects. Uses default
  //! position and dimensions
  GameObject *createGameObject(std::string name);
  //! creates a game object and adds it to the list of gameObjects.
  GameObject *createGameObject(std::string name, float x, float y, float w,
                               float h);
  //! deletes a game object from the list and from the resource manager.
  void deleteGameObject(std::string name);
  //! gets a game object with the given id;
  GameObject *getGameObject(std::string name);

  //! runs the game.
  void run();
  //! updates the game state. Calls update on every object within the engine
  void update();
  //! Set up the state of the game
  int init(int w, int h);

  //! The window we'll be rendering to
  SDL_Window *gWindow = NULL;
  //! The window renderer
  SDL_Renderer *gRenderer = NULL;

  //! Frame Capping Vars
  unsigned int fpsRendered = 0;
  //! Frame Capping Vars
  unsigned int lastTime = SDL_GetTicks();
  //! Frame Capping Vars
  const int DESIRED_FRAME_RATE = 60;
  //! Frame Capping Vars
  const int SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;

 private:
  GameEngine();                        // Private Singleton
  GameEngine(GameEngine const &);      // Avoid copy constructor
  void operator=(GameEngine const &);  // Don't allow assignment.
  void render();
  bool initSDL();
  bool createWindow(int w, int h);
  bool createRenderer();
  bool initSDLImage();
  bool initSDL_TTF();
  bool initSDLMixer();
  bool initGameEngine();
  void close();
  // variables
  std::vector<GameObject *> gameObjects;
  int w, h;
};

#endif
