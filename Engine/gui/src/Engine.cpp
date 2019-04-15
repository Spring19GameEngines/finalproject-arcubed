#include "Engine.h"

/* INIT */

Engine::Engine() {}
Engine::~Engine() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
  ImGuiSDL::Deinitialize();

  SDL_Quit();
}

bool Engine::initSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool Engine::createWindow() {
  window = SDL_CreateWindow("Sprite Tool", 0, 0, 1, 1, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  SDL_GetWindowSize(window, &screenWidth, &screenHeight);
  return true;
}

bool Engine::initImGui() {
  ImGui::CreateContext();
  ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
  return true;
}

bool Engine::createRenderer() {
  // Create vsynced renderer for window
  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  ImGuiSDL::Initialize(renderer, screenWidth, screenHeight);
  return true;
}

void Engine::initAll() {
  initSDL();
  createWindow();
  initImGui();
  createRenderer();
}

/* MAIN */

int Engine::loop() {
  initAll();
  SpriteTool* spritetool = &SpriteTool::getInstance();
  spritetool->renderer = renderer;

  bool run = true;
  while (run) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT) run = false;
      if (event.type == SDL_WINDOWEVENT &&
          event.window.event == SDL_WINDOWEVENT_CLOSE &&
          event.window.windowID == SDL_GetWindowID(window))
        run = false;
    }

    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    // // Our window
    SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
    SDL_RenderClear(renderer);

    spritetool->renderGUI();

    ImGui::Render();
    ImGuiSDL::Render(ImGui::GetDrawData());

    SDL_RenderPresent(renderer);
  }

  return 0;
}
