#include "ResourceManager.h"

ResourceManager::ResourceManager() {}

ResourceManager &ResourceManager::getInstance()
{
  static ResourceManager instance;
  return instance;
}

void ResourceManager::startUp() {}

void ResourceManager::shutDown()
{
  for (auto &t : textureMap)
  {
    if (t.second)
    {
      SDL_Log("Freeing texture %s", t.first.c_str());
      SDL_DestroyTexture(t.second);
      t.second = nullptr;
    }
  }

  for (auto &f : fontMap)
  {
    if (f.second)
    {
      SDL_Log("Freeing font %s", f.first.c_str());
      TTF_CloseFont(f.second);
      f.second = nullptr;
    }
  }

  for (auto &t : textMap)
  {
    SDL_Log("Freeing text for %s", t.first.c_str());
    if (std::get<0>(t.second))
    {
      SDL_DestroyTexture(std::get<0>(t.second));
    }
  }

  for (auto &e : effectMap)
  {
    if (e.second)
    {
      SDL_Log("Freeing sound effect %s", e.first.c_str());
      Mix_FreeChunk(e.second);
    }
  }

  for (auto &s : songMap)
  {
    if (s.second)
    {
      SDL_Log("Freeing music track %s", s.first.c_str());
      Mix_FreeMusic(s.second);
    }
  }
}

void ResourceManager::storeSDLRenderer(SDL_Renderer *gRenderer)
{
  this->gRenderer = gRenderer;
}

void ResourceManager::storeGameObject(GameObject *gameObject)
{
  gameObjects.push_back(gameObject);
}

void ResourceManager::removeGameObject(std::string name)
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    if (gameObjects[i] != NULL)
    {
      if (gameObjects[i]->name == name)
      {
        gameObjects.erase(gameObjects.begin() + i);
      }
    }
  }
}

SDL_Texture *ResourceManager::loadTexture(const std::string &path,
                                          SDL_Renderer *ren)
{
  auto storedTexture = textureMap.find(path);
  if (storedTexture != textureMap.end())
  {
    return storedTexture->second;
  }

  SDL_Texture *newTexture = NULL;
  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL)
  {
    SDL_Log("Failed to allocate surface: %s", path.c_str());
  }
  else
  {
    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(ren, loadedSurface);
    if (newTexture == NULL)
    {
      SDL_Log("Unable to create texture from %s! SDL Error: %s\n", path.c_str(),
              SDL_GetError());
    }
    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  // Update map with texture
  textureMap[path] = newTexture;

  return newTexture;
}

TTF_Font *ResourceManager::loadFont(const std::string &path, int size)
{
  auto key = path + std::to_string(size);
  auto storedFont = fontMap.find(key);
  if (storedFont != fontMap.end())
  {
    return storedFont->second;
  }

  // Open the font
  TTF_Font *loadedFont = TTF_OpenFont(path.c_str(), size);
  if (loadedFont == NULL)
  {
    SDL_Log("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
  }

  fontMap[key] = loadedFont;

  return loadedFont;
}

std::string colorAsString(SDL_Color &color)
{
  return "{" + std::to_string(color.r) + "," + std::to_string(color.g) + "," +
         std::to_string(color.b) + "," + std::to_string(color.a) + "}";
}

std::tuple<SDL_Texture *, int, int> ResourceManager::loadTextTexture(
    const std::string &path, int size, const std::string &text, SDL_Color color,
    SDL_Renderer *ren)
{
  // TODO: maybe find a better way to store already created texts
  auto key = path + "," + std::to_string(size) + "," + text + "," +
             colorAsString(color);
  auto storedText = textMap.find(key);
  if (storedText != textMap.end())
  {
    return storedText->second;
  }

  TTF_Font *font = loadFont(path, size);
  SDL_Texture *newTexture = NULL;
  int w;
  int h;
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
  if (textSurface == NULL)
  {
    SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n",
            TTF_GetError());
  }
  else
  {
    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    if (newTexture == NULL)
    {
      SDL_Log("Unable to create texture from rendered text! SDL Error: %s\n",
              SDL_GetError());
    }

    w = textSurface->w;
    h = textSurface->h;

    // Get rid of old surface
    SDL_FreeSurface(textSurface);
  }

  textMap[key] = std::make_tuple(newTexture, w, h);

  return textMap[key];
}

Mix_Chunk *ResourceManager::loadEffect(const std::string &path)
{
  auto foundEffect = effectMap.find(path);
  if (foundEffect != effectMap.end())
  {
    return foundEffect->second;
  }

  auto loadedEffect = Mix_LoadWAV(path.c_str());
  if (loadedEffect == NULL)
  {
    SDL_Log("Unable to create sound effect! Mix Error: %s\n", Mix_GetError());
  }

  effectMap[path] = loadedEffect;

  return loadedEffect;
}

Mix_Music *ResourceManager::loadMusic(const std::string &path)
{
  auto foundSong = songMap.find(path);
  if (foundSong != songMap.end())
  {
    return foundSong->second;
  }

  auto loadedSong = Mix_LoadMUS(path.c_str());
  if (loadedSong == NULL)
  {
    SDL_Log("Unable to create music! Mix Error: %s\n", Mix_GetError());
  }

  songMap[path] = loadedSong;

  return loadedSong;
}
