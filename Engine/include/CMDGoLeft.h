#ifndef FINALPROJECT_ARCUBED_CMDGOLEFT_H
#define FINALPROJECT_ARCUBED_CMDGOLEFT_H
#include "Command.h"
#include "RigidBody.h"
class CMDGoLeft : public Command
{
  public:
    void execute()
    {
        RigidBody *rb = static_cast<RigidBody *>(this->go->components->getComponent(
            "RIGIDBODYCOMPONENT"));
        rb->setForceX(-3);
        // go->pos.x -= 2;
    }
};

#endif // FINALPROJECT_ARCUBED_CMDGOLEFT_H