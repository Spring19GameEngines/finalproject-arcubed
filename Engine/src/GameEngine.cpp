#include "GameEngine.h"
#include "CMDGoLeft.h"
#include "CMDGoRight.h"
#include "InputComponent.h"
#include "RendererComponent.h"
#include "RigidBody.h"
#include "SoundComponent.h"

GameEngine::GameEngine() {}

<<<<<<< HEAD
GameEngine &GameEngine::getInstance() {
=======
GameEngine::~GameEngine()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    if (gameObjects[i] != nullptr)
    {
      delete gameObjects[i];
    }
  }
}
GameEngine &GameEngine::getInstance()
{
>>>>>>> 55bbf8d3bfcf37200bbfe95bb6e654e6da2a7a48
  static GameEngine *instance = new GameEngine();
  return *instance;
}

GameObject *GameEngine::createGameObject(std::string name) {
  GameObject *obj = new GameObject(name);
  gameObjects.push_back(obj);
  ResourceManager::getInstance().storeGameObject(obj);
  return obj;
}

GameObject *GameEngine::createGameObject(std::string name, float x, float y,
                                         float w, float h) {
  GameObject *obj = new GameObject(name, x, y, w, h);
  gameObjects.push_back(obj);
  ResourceManager::getInstance().storeGameObject(obj);
  return obj;
}

<<<<<<< HEAD
void GameEngine::deleteGameObject(std::string name) {
  for (int i = 0; i < gameObjects.size(); i++) {
    if (gameObjects[i] != NULL) {
      if (gameObjects[i]->name == name) {
=======
void GameEngine::deleteGameObject(std::string name)
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    if (gameObjects[i] != nullptr)
    {
      if (gameObjects[i]->name == name)
      {
>>>>>>> 55bbf8d3bfcf37200bbfe95bb6e654e6da2a7a48
        gameObjects.erase(gameObjects.begin() + i);
      }
    }
  }
}

// Get a component with the given id
GameObject *GameEngine::getGameObject(std::string name) {
  for (int i = 0; i < gameObjects.size(); i++) {
    if (gameObjects[i] != nullptr) {
      if (gameObjects[i]->name == name) {
        return gameObjects[i];
      }
    }
  }
  // didnt find it
  return nullptr;
}

void GameEngine::update() {
  for (GameObject *obj : gameObjects) {
    obj->update();
  }
}

/* INITIALIZE GAME */
bool GameEngine::initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool GameEngine::createWindow(int w, int h) {
  // Set texture filtering to linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Warning: Linear texture filtering not enabled!");
  }
  // Create Window
  gWindow = SDL_CreateWindow("ARCubed Platformer", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  ResourceManager::getInstance().SCREEN_WIDTH = w;
  ResourceManager::getInstance().SCREEN_HEIGHT = h;
  return true;
}

bool GameEngine::createRenderer() {
  // Create vsynced renderer for window
  gRenderer = SDL_CreateRenderer(
      gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gRenderer == NULL) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  ResourceManager::getInstance().storeSDLRenderer(gRenderer);
  return true;
}

bool GameEngine::initSDLImage() {
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
    return false;
  }
  return true;
}

bool GameEngine::initSDL_TTF() {
  if (TTF_Init() == -1) {
    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return false;
  }
  return true;
}

bool GameEngine::initSDLMixer() {
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
           Mix_GetError());
    return false;
  }
  return true;
}

void GameEngine::run() {
  // Main loop flag
  bool quit = false;

  // Event handler
  SDL_Event e;
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
    SDL_SetRenderDrawColor(gRenderer, 0x55, 0x55, 0x55, 0xFF);  // Gray
    SDL_RenderClear(gRenderer);
    update();
    SDL_RenderPresent(gRenderer);

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

  close();
}

// Frees media and shuts down SDL
void GameEngine::close() {
  // Destroy window
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  gRenderer = nullptr;

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

int GameEngine::init(int w, int h) {
  // Start up SDL and create window
  if (initSDL()              // Initialize SDL
      && createWindow(w, h)  // Setup window with game constants
      && createRenderer()    // Setup renderer with window
      && initSDLImage()      // Initialize PNG loading
      && initSDL_TTF()       // Initialize SDL_ttf
      && initSDLMixer())     // Initialize SDL_mixer

  {
    // EVERYTHING SUCCEEDED, LETS MAKE THOSE GAME OBJECTS NOW!
    printf("Initialized!\n");
  } else {
    printf("Failed to initialize!\n");
  }

  return 0;
}
