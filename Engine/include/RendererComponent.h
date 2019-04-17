#ifndef FINALPROJECT_ARCUBED_RENDERERCOMPONENT_H
#define FINALPROJECT_ARCUBED_RENDERERCOMPONENT_H

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL_image.h>
#else
#include <SDL_image.h>
#endif

#include <iostream>
#include "Component.h"
#include "GameObject.h"
#include "ResourceManager.h"
using namespace std;

class RendererComponent : public Component
{
public:
  // constructor
  RendererComponent(GameObject *go);
  RendererComponent(Component *component);
  void update();
  // send to container
  void send(string action, vector<string> args);
  // Receive messages from the component container
  void receive(string action, vector<string> args);

  void loadAnimation(string path, int startingFrame, int numFrames, int totalSheetFrames);
  void setAngle(double angle);
  void setFlipHorizontal(bool flag);
  void setFlipVertical(bool flag);
  void setScale(int scale);
  void setFrameDelay(int delay);
  void setAnimationAlias(string alias, string existingPath);
  void setCamCentered(bool flag);
  vector<string> getAnimationAliases();
  void setAnimation(string alias);

private:
  int w;
  int h;
  int scale = 1;
  int frameDelay = 0;
  int framesPassed = 0;
  int currentFrame = 0;
  double angle = 0;
  bool flipHorizontal = false;
  bool flipVertical = false;

  bool camCentered = false;
  GameObject *go;
  SDL_RendererFlip getFlip();
  void render();
  std::string currentAnimationPath;
  std::unordered_map<string, SDL_Texture *> loadedAnimation;
  std::unordered_map<string, std::tuple<int, int>> animationFrames; // starting ->< Number of frames tuple
  std::unordered_map<string, string> animationAliases;
};

#endif //FINALPROJECT_ARCUBED_RENDERERCOMPONENT_H
