#include "SoundComponent.h"

SoundComponent::SoundComponent() : Component(0) {}

// Pops the sound queue and plays the sound
void SoundComponent::update() {
  if (soundQueue.size() > 0) {
    Mix_Music* sound = soundQueue.pop();
    Mix_PlayMusic(sound, -1)
  }
}

// Loads a sound at the given path to the resource manager
void SoundComponent::loadSound(string path) {
  if (loadedSounds.find(path) != loadedSounds.end()) {
    Mix_Music* music = nullptr;
    music = ResourceManager::getInstance().loadMusic(path);
    if (music != nullptr) {
      loadedSounds[path] = music;
    }
  }
}

// Queues a sound to the queue only if it has been loaded by this component
void SoundComponent::playSound(path) {
  if (loadedSounds.find(path) != loadedSounds.end()) {
    Mix_Music* sound = loadedSounds[path];
    soundQueue.push(sound);
  } else {
    cout << "Given sound" << path << " was never loaded" << endl;
  }
}

// Allows the user to set a alias for a loaded sound path
void SoundComponent::setSoundAlias(string msg, string existingPath) {
  if (loadedSounds.find(existingPath) == loadedSounds.end()) {
    cout << "Existing path does not exist" << endl;
    return;
  }
  if (msgAliases.find(msg) != msgAliases.end()) {
    msgAliases[msg] = existingPath;
  } else {
    cout << "Sound alias already exists" << endl;
    return;
  }
}

// Returns an array of all loaded sounds paths
string[] getLoadedPaths() {
  string paths[loadedSounds.size()];
  int count = 0;
  for (auto& pair : loadedSounds) {
    paths[count] = pair.first;
    count++;
  }
  return paths;
}

string[] getSoundAliases() {
  string aliases[msgAliases.size()];
  int count = 0;
  for (auto& pair : msgAliases) {
    aliases[count] = "\"" pair.first + "\" -> \"" + pair.second + "\"";
    count++;
  }
  return aliases;
}

// default, if a msg contains a sound alias, queue it.
void SoundComponent::receive(string action, vector <string> args) {
  if (msgAliases.find(msg) != msgAliases.end()) {
    playSound(msgAliases[msg]);
  }
  return;
}