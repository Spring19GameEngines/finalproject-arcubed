#ifndef FINALPROJECT_ARCUBED_SOUNDCOMPONENT_H
#define FINALPROJECT_ARCUBED_SOUNDCOMPONENT_H

#include <SDL_mixer.h>
#include <cmath>
#include <iostream>
#include <queue>
#include "Component.h"
#include "ResourceManager.h"

using namespace std;

/*! \brief Handles all sounds that this object is related to
 *
 */
class SoundComponent : public Component {
 public:
  //! constructor
  SoundComponent();
  //! constructor - used for static cast
  SoundComponent(Component *component);

  //! derived from component - plays all queued sounds
  void update();
  //! Loads a sound at the given path to the resource manager
  void loadMusic(string path);
  //! Queues a sound to the queue only if it has been loaded by this component
  void playMusic(string path);
  //! loads a sound effect into the component
  void loadEffect(string path);
  //! adds the sound effect to the queue
  void playEffect(string path);
  //! Allows the user to set a alias for a loaded music path
  void setMusicAlias(string alias, string existingPath);
  //! Allows the user to set a alias for a loaded effect path
  void setEffectAlias(string alias, string existingPath);

  //! derived from component
  void send(string action, vector<string> args);
  //! derived from component
  void receive(string action, vector<string> args);
  //! Returns an array of all loaded music paths
  vector<string> getMusicPaths();
  //! Returns an array of all loaded effect paths
  vector<string> getEffectPaths();

  //! Returns an array of all music path aliases
  vector<string> getMusicAliases();
  //! Returns an array of all effect path aliases
  vector<string> getEffectAliases();

 private:
  std::unordered_map<string, string> musicAliases;
  std::unordered_map<string, string> effectAliases;

  std::unordered_map<string, Mix_Music *> loadedMusic;
  std::unordered_map<string, Mix_Chunk *> loadedEffects;

  queue<Mix_Music *> musicQueue;
  queue<Mix_Chunk *> effectQueue;
};

#endif
