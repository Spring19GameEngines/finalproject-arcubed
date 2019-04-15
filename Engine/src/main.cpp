/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

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
#include <string>
#include "Camera.h"
#include "GameEngine.h"
#include "ResourceManager.h"

// The window we'll be rendering to
SDL_Window *gWindow = NULL;
// The window renderer
SDL_Renderer *gRenderer = NULL;
// The game state
GameEngine *engine = NULL;

// Frame Capping Vars
unsigned int fpsRendered = 0;
unsigned int lastTime = SDL_GetTicks();
const int DESIRED_FRAME_RATE = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;

void renderBackground() {
  // Get Texture
  SDL_Texture *texture = ResourceManager::getInstance().loadTexture(
      "Assets/art/background.png", gRenderer);

  int background_width = 384;
  int background_height = 240;
  int multiplier = 4;
  SDL_Rect Src = {0, 0, background_width, background_height};
  SDL_Rect Dest = {0, 0, background_width * multiplier,
                   background_height * multiplier};
  SDL_RenderCopy(gRenderer, texture, &Src, &Dest);
}

void render() {
  // std::cout << "rendering" << std::endl;
  // Clear screen
  SDL_SetRenderDrawColor(gRenderer, 0x55, 0x55, 0x55, 0xFF);  // Gray
  SDL_RenderClear(gRenderer);

  renderBackground();

  // Update screen
  SDL_RenderPresent(gRenderer);
}
/* INITIALIZE GAME */
bool initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool createWindow() {
  // Set texture filtering to linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Warning: Linear texture filtering not enabled!");
  }
  // Create Window
  gWindow =
      SDL_CreateWindow("ARCubed Platformer", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool createRenderer() {
  // Create vsynced renderer for window
  gRenderer = SDL_CreateRenderer(
      gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gRenderer == NULL) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool initSDLImage() {
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
    return false;
  }
  return true;
}

bool initSDL_TTF() {
  if (TTF_Init() == -1) {
    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return false;
  }
  return true;
}

bool initSDLMixer() {
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
           Mix_GetError());
    return false;
  }
  return true;
}

bool initGameEngine() {
  engine = &GameEngine::getInstance();
  engine->startUp();
  return true;
}
void run() {
  // Main loop flag
  bool quit = false;

  // Event handler
  SDL_Event e;
  render();

  // While application is running
  while (!quit) {
    unsigned int currentTime = SDL_GetTicks();  // Get frame start time
    int elapsedTime = currentTime - lastTime;  // Time since last counted second

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      // User requests quit with "q" key
      if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_q:
            quit = true;
            break;
        }
      }
    }

    engine->update();
    render();

    // FPS Counter
    fpsRendered++;  // Count frame
    // If one second has past, print the FPS and reset
    if (elapsedTime >= 1000) {
      lastTime = currentTime;
      fpsRendered = 0;
    }
    // If frame finished early delay
    if (SDL_GetTicks() - currentTime < SCREEN_TICKS_PER_FRAME) {
      int t = SCREEN_TICKS_PER_FRAME - (SDL_GetTicks() - currentTime);
      SDL_Delay(t);
    }
  }
}

// Frees media and shuts down SDL
void close() {
  // Destroy window
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

bool init() {
  if (initSDL()            // Initialize SDL
      && createWindow()    // Setup window with game constants
      && createRenderer()  // Setup renderer with window
      && initSDLImage()    // Initialize PNG loading
      && initSDL_TTF()     // Initialize SDL_ttf
      && initSDLMixer()    // Initialize SDL_mixer
      && initGameEngine()) {
    // EVERYTHING SUCCEEDED, LETS MAKE THOSE GAME OBJECTS NOW!
    return true;
  }

  return false;
}

/* MAIN */

int main(int argc, char *args[]) {
  printf("%s", args[0]);
  // Start up SDL and create window
  if (!init()) {
    printf("Failed to initialize!\n");
  }

  else {
    run();
  }

  // Free resources and close SDL
  close();

  return 0;
}