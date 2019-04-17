#include "GameEngine.h"
#include "SoundComponent.h"
#include "RendererComponent.h"
#include "InputComponent.h"
#include "CMDGoLeft.h"
#include "CMDGoRight.h"
#include "RigidBody.h"

GameEngine::GameEngine() {}

GameEngine &GameEngine::getInstance() {
    static GameEngine *instance = new GameEngine();
    return *instance;
}

GameObject *GameEngine::createGameObject(std::string name) {
    GameObject *obj = new GameObject(name);
    gameObjects.push_back(obj);
    ResourceManager::getInstance().storeGameObject(obj);
    return obj;
}

GameObject *GameEngine::createGameObject(std::string name, float x, float y, float w, float h) {
    GameObject *obj = new GameObject(name, x, y, w, h);
    gameObjects.push_back(obj);
    ResourceManager::getInstance().storeGameObject(obj);
    return obj;
}

void GameEngine::deleteGameObject(std::string name) {
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] != NULL) {
            if (gameObjects[i]->name == name) {
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
    if (gameObjects.size() < 1) {
//    Music
        std::string mus_path = "Assets/sound/music/level1.mp3";
        std::string sfx_path = "Assets/sound/effects/spin_jump.wav";

        GameObject *music = createGameObject("Music", 400, 400, 0, 0);
        SoundComponent *sc = new SoundComponent();
        sc->loadMusic(mus_path);
        sc->loadEffect(sfx_path);
        music->components->addComponent(sc);

//    Renderer
        RendererComponent *rc = new RendererComponent(music);
        rc->loadAnimation("Assets/art/character.png", 6, 6, 12);
        rc->setScale(3);
        rc->setFrameDelay(4);
        rc->setCamCentered(false);
        music->components->addComponent(rc);
        // rc->setCamCentered(true);
        
        // input
        InputComponent *ic = new InputComponent(music);
        CMDGoLeft *goLeft = new CMDGoLeft();
        CMDGoRight *goRight = new CMDGoRight();
        ic->setButton(SDL_SCANCODE_A, goLeft);
        ic->setButton(SDL_SCANCODE_D, goRight);
        music->components->addComponent(ic);
        SoundComponent *csc = static_cast<SoundComponent *>(music->components->getComponent("SOUNDCOMPONENT"));
        csc->playMusic(mus_path);
        csc->playEffect(sfx_path);

//    RIGID BOY
        RigidBody *rb1 = new RigidBody(music);
        rb1->setUseGravity(false);
        rb1->setIsKinematic(false);
        music->components->addComponent(rb1);
//    OTHER
        GameObject *asdf = createGameObject("asdf", 400, 100, 0, 0);
//    Renderer
        RendererComponent *rc2 = new RendererComponent(asdf);
        rc2->loadAnimation("Assets/art/character.png", 6, 6, 12);
        rc2->setScale(3);
        rc2->setFrameDelay(3);
        rc2->setCamCentered(false);
        asdf->components->addComponent(rc2);

//    RIGID BOY
        RigidBody *rb2 = new RigidBody(asdf);
        rb2->setUseGravity(true);
        rb2->setIsKinematic(false);
        asdf->components->addComponent(rb2);
    }

    for (
        GameObject *obj
            : gameObjects) {
        obj->

                update();
    }
}


void GameEngine::renderBackground() {
    // std::cout << "rendering" << std::endl;
    // Clear screen
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
    gWindow =
            SDL_CreateWindow("ARCubed Platformer", SDL_WINDOWPOS_CENTERED,
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
        unsigned int currentTime = SDL_GetTicks(); // Get frame start time
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
        SDL_RenderClear(gRenderer);
        renderBackground();
        update();
        // SDL_SetRenderDrawColor(gRenderer, 0x55, 0x55, 0x55, 0xFF); // Gray
        SDL_RenderPresent(gRenderer);
        // FPS Counter
        fpsRendered++; // Count frame
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
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int GameEngine::init(int w, int h) {
    // Start up SDL and create window
    if (initSDL()             // Initialize SDL
        && createWindow(w, h) // Setup window with game constants
        && createRenderer()   // Setup renderer with window
        && initSDLImage()     // Initialize PNG loading
        && initSDL_TTF()      // Initialize SDL_ttf
        && initSDLMixer())    // Initialize SDL_mixer

    {
        // EVERYTHING SUCCEEDED, LETS MAKE THOSE GAME OBJECTS NOW!
        printf("Initialized!\n");
    } else {
        printf("Failed to initialize!\n");
    }

    return 0;
}
