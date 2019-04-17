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

class GameEngine {
 public:
  //! Get the state of the game
  static GameEngine &getInstance();

  GameObject *createGameObject(std::string name);
  GameObject *createGameObject(std::string name, float x, float y, float w,
                               float h);
  void deleteGameObject(std::string name);
  GameObject *getGameObject(std::string name);
  void run();

  //! updates the game state
  void update();
  //! Set up the state of the game
  int init(int w, int h);
  // VARIABLES:

  // The window we'll be rendering to
  SDL_Window *gWindow = NULL;
  // The window renderer
  SDL_Renderer *gRenderer = NULL;

  // Frame Capping Vars
  unsigned int fpsRendered = 0;
  unsigned int lastTime = SDL_GetTicks();
  const int DESIRED_FRAME_RATE = 60;
  const int SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;

 private:
  GameEngine();                        // Private Singleton
  GameEngine(GameEngine const &);      // Avoid copy constructor
  void operator=(GameEngine const &);  // Don't allow assignment.
  void renderBackground();
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
