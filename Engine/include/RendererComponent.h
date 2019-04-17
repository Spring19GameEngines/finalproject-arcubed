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

/*! \brief handles rendering for the parent gameObject
 *
 */
class RendererComponent : public Component
{
public:
  //! constructor
  RendererComponent(GameObject *go);
  //! constructor - used for static cast
  RendererComponent(Component *component);
  //! derived from component - loops through the currently selected animation frames
  void update();
  //! derived from component
  void send(string action, vector<string> args);
  //! derived from component
  void receive(string action, vector<string> args);

  //! loads an animation from the given path and stores the data of the starting frame, num frames, and total frames
  void loadAnimation(string path, int startingFrame, int numFrames, int totalSheetFrames);
  //! sets the angle for the sprite to be rotated by
  void setAngle(double angle);
  //! sets whether or not the sprite needs to be flipped horizontally
  void setFlipHorizontal(bool flag);
  //! sets whether or not the sprite needs to be flipped vertically
  void setFlipVertical(bool flag);
  //! sets the scale that the object will be multiplied by when rendered
  void setScale(int scale);
  //! sets the delay in frames before the animation moves to the next frame
  void setFrameDelay(int delay);
  //! sets an alias for the path to the sprite sheet.
  void setAnimationAlias(string alias, string existingPath);
  //! sets whether or not this object is the center of the camera
  void setCamCentered(bool flag);
  //! gets the list of aliases for the file path
  vector<string> getAnimationAliases();
  //! sets the current animation that will be used to render the object.
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
