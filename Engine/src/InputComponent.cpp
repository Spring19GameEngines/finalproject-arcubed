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
void InputComponent::setButton(SDL_Scancode key, Command *cmd)
{
  // Set command's game object to this game object
  cmd->setGameObject(this->go);

  switch (key)
  {
  case SDL_SCANCODE_A:
    buttonA_ = cmd;
    break;
  case SDL_SCANCODE_B:
    buttonB_ = cmd;
    break;
  case SDL_SCANCODE_C:
    buttonC_ = cmd;
    break;
  case SDL_SCANCODE_D:
    buttonD_ = cmd;
    break;
  case SDL_SCANCODE_E:
    buttonE_ = cmd;
    break;
  case SDL_SCANCODE_F:
    buttonF_ = cmd;
    break;
  case SDL_SCANCODE_G:
    buttonG_ = cmd;
    break;
  case SDL_SCANCODE_H:
    buttonH_ = cmd;
    break;
  case SDL_SCANCODE_I:
    buttonI_ = cmd;
    break;
  case SDL_SCANCODE_J:
    buttonJ_ = cmd;
    break;
  case SDL_SCANCODE_K:
    buttonK_ = cmd;
    break;
  case SDL_SCANCODE_L:
    buttonL_ = cmd;
    break;
  case SDL_SCANCODE_M:
    buttonM_ = cmd;
    break;
  case SDL_SCANCODE_N:
    buttonN_ = cmd;
    break;
  case SDL_SCANCODE_O:
    buttonO_ = cmd;
    break;
  case SDL_SCANCODE_P:
    buttonP_ = cmd;
    break;
  case SDL_SCANCODE_Q:
    buttonQ_ = cmd;
    break;
  case SDL_SCANCODE_R:
    buttonR_ = cmd;
    break;
  case SDL_SCANCODE_S:
    buttonS_ = cmd;
    break;
  case SDL_SCANCODE_T:
    buttonT_ = cmd;
    break;
  case SDL_SCANCODE_U:
    buttonT_ = cmd;
    break;
  case SDL_SCANCODE_V:
    buttonV_ = cmd;
    break;
  case SDL_SCANCODE_W:
    buttonW_ = cmd;
    break;
  case SDL_SCANCODE_X:
    buttonX_ = cmd;
    break;
  case SDL_SCANCODE_Y:
    buttonY_ = cmd;
    break;
  case SDL_SCANCODE_Z:
    buttonZ_ = cmd;
    break;
  }
}

void InputComponent::update()
{
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_A] && buttonA_ != nullptr)
  {
    buttonA_->execute();
  }
  if (keystates[SDL_SCANCODE_B] && buttonB_ != nullptr)
  {
    buttonB_->execute();
  }
  if (keystates[SDL_SCANCODE_C] && buttonC_ != nullptr)
  {
    buttonC_->execute();
  }
  if (keystates[SDL_SCANCODE_D] && buttonD_ != nullptr)
  {
    buttonD_->execute();
  }
  if (keystates[SDL_SCANCODE_E] && buttonE_ != nullptr)
  {
    buttonE_->execute();
  }
  if (keystates[SDL_SCANCODE_F] && buttonF_ != nullptr)
  {
    buttonF_->execute();
  }
  if (keystates[SDL_SCANCODE_G] && buttonG_ != nullptr)
  {
    buttonG_->execute();
  }
  if (keystates[SDL_SCANCODE_H] && buttonH_ != nullptr)
  {
    buttonH_->execute();
  }
  if (keystates[SDL_SCANCODE_I] && buttonI_ != nullptr)
  {
    buttonI_->execute();
  }
  if (keystates[SDL_SCANCODE_J] && buttonJ_ != nullptr)
  {
    buttonJ_->execute();
  }
  if (keystates[SDL_SCANCODE_K] && buttonK_ != nullptr)
  {
    buttonK_->execute();
  }
  if (keystates[SDL_SCANCODE_L] && buttonL_ != nullptr)
  {
    buttonL_->execute();
  }
  if (keystates[SDL_SCANCODE_M] && buttonM_ != nullptr)
  {
    buttonM_->execute();
  }
  if (keystates[SDL_SCANCODE_N] && buttonN_ != nullptr)
  {
    buttonN_->execute();
  }
  if (keystates[SDL_SCANCODE_O] && buttonO_ != nullptr)
  {
    buttonO_->execute();
  }
  if (keystates[SDL_SCANCODE_P] && buttonP_ != nullptr)
  {
    buttonP_->execute();
  }
  if (keystates[SDL_SCANCODE_Q] && buttonQ_ != nullptr)
  {
    buttonQ_->execute();
  }
  if (keystates[SDL_SCANCODE_R] && buttonR_ != nullptr)
  {
    buttonR_->execute();
  }
  if (keystates[SDL_SCANCODE_S] && buttonS_ != nullptr)
  {
    buttonS_->execute();
  }
  if (keystates[SDL_SCANCODE_T] && buttonT_ != nullptr)
  {
    buttonT_->execute();
  }
  if (keystates[SDL_SCANCODE_U] && buttonU_ != nullptr)
  {
    buttonU_->execute();
  }
  if (keystates[SDL_SCANCODE_V] && buttonV_ != nullptr)
  {
    buttonV_->execute();
  }
  if (keystates[SDL_SCANCODE_W] && buttonW_ != nullptr)
  {
    buttonW_->execute();
  }
  if (keystates[SDL_SCANCODE_X] && buttonX_ != nullptr)
  {
    buttonX_->execute();
  }
  if (keystates[SDL_SCANCODE_Y] && buttonY_ != nullptr)
  {
    buttonY_->execute();
  }
  if (keystates[SDL_SCANCODE_Z] && buttonZ_ != nullptr)
  {
    buttonZ_->execute();
  }
}
