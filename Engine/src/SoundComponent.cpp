#include "SoundComponent.h"

SoundComponent::SoundComponent() : Component(0) {}

// Pops the sound queue and plays the sound
void SoundComponent::update() {
  if (soundQueue.size() > 0) {
    Mix_Music* sound = soundQueue.front();
    soundQueue.pop();
    Mix_PlayMusic(sound, -1);
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
void SoundComponent::playSound(string path) {
  if (loadedSounds.find(path) != loadedSounds.end()) {
    Mix_Music* sound = loadedSounds[path];
    soundQueue.push(sound);
  } else {
    // cout << "Given sound" << path << " was never loaded" << endl;
    cout << "Play sound failed" << endl;
  }
}

// Allows the user to set a alias for a loaded sound path
void SoundComponent::setSoundAlias(string alias, string existingPath) {
  if (loadedSounds.find(existingPath) == loadedSounds.end()) {
    cout << "Existing path does not exist" << endl;
    return;
  }
  if (soundAliases.find(alias) != soundAliases.end()) {
    soundAliases[alias] = existingPath;
  } else {
    cout << "Sound alias already exists" << endl;
    return;
  }
}

// Returns an array of all loaded sounds paths
vector<string> SoundComponent::getLoadedPaths() {
  vector<string> paths;
  for (auto& pair : loadedSounds) {
    paths.push_back(pair.first);
  }
  return paths;
}

vector<string> SoundComponent::getSoundAliases() {
  vector<string> aliases;
  for (auto& pair : soundAliases) {
    aliases.push_back("\"" + pair.first + "\" -> \"" + pair.second + "\"");
  }
  return aliases;
}
// Sends a message to the parent component container
void SoundComponent::send(string action, vector<std::string> args) {
  if (container != NULL) {
    container->send(action, args);
  } else {
    cout << "Failed to send message" << endl;
  }
}
// default, if a msg contains a sound alias, queue it.
void SoundComponent::receive(string action, vector<string> args) {
  if (soundAliases.find(action) != soundAliases.end()) {
    playSound(soundAliases[action]);
  }
  return;
}