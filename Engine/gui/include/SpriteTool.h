#ifndef SPRITE_TOOL
#define SPRITE_TOOL

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  // This works for Mac
#include "SDL2/SDL.h"
#include "SDL_image.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "imgui.h"
#include "imgui_impl_sdl.h"

// This class sets up a full graphics program
class SpriteTool {
 public:
  static SpriteTool& getInstance();
  void renderGUI();

  SDL_Renderer* renderer;

 private:
  // Constructors
  SpriteTool();
  ~SpriteTool();

  // Functions
  void setTexture();
  void getSrc();
  void getDest();

  // Constants to be set up
  float spriteWidth;
  float spriteHeight;
  int rows;
  int cols;
  int magnify;
  char asset_name[64];

  // Constants that are default
  int startingFrame;
  int currentFrame = 0;
  int numFrames;
  int currentTick = 0;
  int tickRate;
  SDL_Surface* spriteSheet = NULL;
  SDL_Texture* texture = NULL;
  SDL_Rect Src;
  SDL_Rect Dest;

  // ImGUI Constants
  const short INCREMENT = 1;
};

#endif
