#include "SoundComponent.h"

SoundComponent::SoundComponent() : Component("SOUNDCOMPONENT") {}
SoundComponent::SoundComponent(Component *component)
    : Component(component->getName()) {}

// Pops the sound queue and plays the sound
void SoundComponent::update() {
  if (musicQueue.size() > 0) {
    Mix_Music *music = musicQueue.front();
    musicQueue.pop();
    Mix_PlayMusic(music, -1);
  }
  if (effectQueue.size() > 0) {
    Mix_Chunk *chunk = effectQueue.front();
    effectQueue.pop();
    Mix_PlayChannel(-1, chunk, 0);
  }
}

// Loads a sound at the given path to the resource manager
void SoundComponent::loadMusic(string path) {
  if (loadedMusic.find(path) == loadedMusic.end()) {
    Mix_Music *music = nullptr;
    music = ResourceManager::getInstance().loadMusic(path);
    if (music != nullptr) {
      loadedMusic[path] = music;
    } else {
      cout << "Failed to load Music" << endl;
    }
  } else {
    cout << "Music already loaded" << endl;
  }
}

// Queues a sound to the queue only if it has been loaded by this component
void SoundComponent::playMusic(string path) {
  if (loadedMusic.find(path) != loadedMusic.end()) {
    Mix_Music *music = loadedMusic[path];
    musicQueue.push(music);
  } else {
    // cout << "Given sound" << path << " was never loaded" << endl;
    cout << "Play sound failed" << endl;
  }
}
// Loads a sound at the given path to the resource manager
void SoundComponent::loadEffect(string path) {
  if (loadedEffects.find(path) == loadedEffects.end()) {
    Mix_Chunk *chunk = nullptr;
    chunk = ResourceManager::getInstance().loadEffect(path);
    if (chunk != nullptr) {
      loadedEffects[path] = chunk;
    } else {
      cout << "Failed to load Effect" << endl;
    }
  } else {
    cout << "Effect already loaded" << endl;
  }
}

// Queues a sound to the queue only if it has been loaded by this component
void SoundComponent::playEffect(string path) {
  if (loadedEffects.find(path) != loadedEffects.end()) {
    Mix_Chunk *chunk = loadedEffects[path];
    effectQueue.push(chunk);
  } else {
    // cout << "Given sound" << path << " was never loaded" << endl;
    cout << "Play sound failed" << endl;
  }
}
// Allows the user to set a alias for a loaded sound path
void SoundComponent::setMusicAlias(string alias, string existingPath) {
  if (loadedMusic.find(existingPath) == loadedMusic.end()) {
    cout << "Existing path does not exist" << endl;
    return;
  }
  if (musicAliases.find(alias) != musicAliases.end()) {
    musicAliases[alias] = existingPath;
  } else {
    cout << "Sound alias already exists" << endl;
    return;
  }
}
// Allows the user to set a alias for a loaded sound path
void SoundComponent::setEffectAlias(string alias, string existingPath) {
  if (loadedEffects.find(existingPath) == loadedEffects.end()) {
    cout << "Existing path does not exist" << endl;
    return;
  }
  if (effectAliases.find(alias) != effectAliases.end()) {
    effectAliases[alias] = existingPath;
  } else {
    cout << "Sound alias already exists" << endl;
    return;
  }
}

// Returns an array of all loaded sounds paths
vector<string> SoundComponent::getMusicPaths() {
  vector<string> paths;
  for (auto &pair : loadedMusic) {
    paths.push_back(pair.first);
  }
  return paths;
}

// Returns an array of all loaded sounds paths
vector<string> SoundComponent::getEffectPaths() {
  vector<string> paths;
  for (auto &pair : loadedEffects) {
    paths.push_back(pair.first);
  }
  return paths;
}

vector<string> SoundComponent::getMusicAliases() {
  vector<string> aliases;
  for (auto &pair : musicAliases) {
    aliases.push_back("\"" + pair.first + "\" -> \"" + pair.second + "\"");
  }
  return aliases;
}

vector<string> SoundComponent::getEffectAliases() {
  vector<string> aliases;
  for (auto &pair : effectAliases) {
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
  if (musicAliases.find(action) != musicAliases.end()) {
    playMusic(musicAliases[action]);
  }
  if (effectAliases.find(action) != effectAliases.end()) {
    playEffect(effectAliases[action]);
  }
  return;
}
