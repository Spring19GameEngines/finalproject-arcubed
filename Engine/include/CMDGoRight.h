#ifndef FINALPROJECT_ARCUBED_CMDGORIGHT_H
#define FINALPROJECT_ARCUBED_CMDGORIGHT_H
#include "Command.h"
#include "RigidBody.h"
class CMDGoRight : public Command
{
  public:
    void execute()
    {
        // RigidBody *rb = static_cast<RigidBody>(this->go.components.getComponent("RIGIDBODYCOMPONENT"));
        go->pos.x += 2;
    }
};

#endif // FINALPROJECT_ARCUBED_CMDGORIGHT_H