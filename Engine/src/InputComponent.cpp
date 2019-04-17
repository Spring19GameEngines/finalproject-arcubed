#include "InputComponent.h"

InputComponent::InputComponent(GameObject *go) : Component("INPUTCOMPONENT")
{
  this->go = go;
}
InputComponent::InputComponent(Component *component) : Component(component->getName()) {}

// Sends a message to the parent component container
void InputComponent::send(string action, vector<std::string> args)
{
  if (container != NULL)
  {
    container->send(action, args);
  }
  else
  {
    cout << "Failed to send message" << endl;
  }
}
// default
void InputComponent::receive(string action, vector<string> args)
{
  return;
}

// // Maybe this abstracts to something like this
void InputComponent::setButton(int key, Command *cmd)
{
  // Set command's game object to this game object
  cmd->setGameObject(this->go);
  if (cmd != nullptr)
  {
    auto keycode = static_cast<SDL_Scancode>(key);
    mappedKeys[keycode] = cmd;
  }
  else
  {
    cout << "Given command is null" << endl;
  }
}

void InputComponent::update()
{
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);
  for (auto &pair : mappedKeys)
  {
    SDL_Scancode key = pair.first;
    if (keystates[key])
    {
      mappedKeys[key]->execute();
    }
  }
}
