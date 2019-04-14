#ifndef FINALPROJECT_ARCUBED_SOUNDCOMPONENT_H
#define FINALPROJECT_ARCUBED_SOUNDCOMPONENT_H

#include <SDL_mixer.h>
#include <cmath>
#include <iostream>
#include <queue>
#include "Component.h"
#include "ResourceManager.h"

using namespace std;

class SoundComponent : public Component {
 public:
  // constructor
  SoundComponent();
  void update();
  // Loads a sound at the given path to the resource manager
  void loadSound(string path);
  // Queues a sound to the queue only if it has been loaded by this component
  void playSound(string path);
  // Allows the user to set a alias for a loaded sound path
  void setSoundAlias(string msg, string existingPath);
  // Receive messages from the component container
  vector<string> receive(string action, vector<string> args);
  // Returns an array of all loaded sounds paths
  string[] getLoadedPaths();
  // Returns an array of all sound aliases
  string[] getSoundAliases();

 private:
  unordered_map<string, string> soundAliases;
  unordered_map<string, Mix_Music*> loadedSounds;
  queue<Mix_Music*> soundQueue;
};

#endif
