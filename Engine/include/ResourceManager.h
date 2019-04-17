#ifndef RESOURCEMANAGER
#define RESOURCEMANAGER

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#else

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#endif

#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include "GameObject.h"

/*! \brief Manages resources and ensures objects are only loaded once.
 * Provides support for loading textures, fonts, text, background music, and
 * sound effects
 */
class ResourceManager
{
public:
  //! Gets singleton instance
  static ResourceManager &getInstance();

  //! Completes any necessary startup logic for manager
  void startUp();

  //! Frees any resources acquired using manager
  void shutDown();

  void storeSDLRenderer(SDL_Renderer *gRenderer);
  // Store gameObject pointers for global reference
  void storeGameObject(GameObject *gameObject);

  // Remove gameObject 44from global reference
  void removeGameObject(std::string name);

  //! Loads texture from map and saves to map if loaded for the first time
  SDL_Texture *loadTexture(const std::string &path, SDL_Renderer *ren);

  //! Loads font from map and saves to map if loaded for the first time
  TTF_Font *loadFont(const std::string &path, int size);

  /*!
   * Uses provided path and size to load font
   * Will try to load text from map if already created previously
   * Returns tuple with texture as well as width and height of the created
   * texture
   */
  std::tuple<SDL_Texture *, int, int> loadTextTexture(const std::string &path,
                                                      int size,
                                                      const std::string &text,
                                                      SDL_Color color,
                                                      SDL_Renderer *ren);

  //! Loads sfx from map and saves to map if loaded for the first time
  Mix_Chunk *loadEffect(const std::string &path);

  //! Loads music from map and saves to map if loaded for the first time
  Mix_Music *loadMusic(const std::string &path);

  std::vector<GameObject *> gameObjects;
  SDL_Renderer *gRenderer;
  int camX = 0;
  int camY = 0;

private:
  ResourceManager();                        // Private Singleton
  ResourceManager(ResourceManager const &); // Avoid copy constructor
  void operator=(ResourceManager const &);  // Don't allow assignment.

  std::unordered_map<std::string, SDL_Texture *> textureMap;
  std::unordered_map<std::string, TTF_Font *> fontMap;
  std::unordered_map<std::string, std::tuple<SDL_Texture *, int, int>> textMap;
  std::unordered_map<std::string, Mix_Chunk *> effectMap;
  std::unordered_map<std::string, Mix_Music *> songMap;
};

#endif
