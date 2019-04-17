#ifndef FINALPROJECT_ARCUBED_CMDGORIGHT_H
#define FINALPROJECT_ARCUBED_CMDGORIGHT_H
#include "Command.h"
#include "RigidBody.h"

/*! \brief A command for making the player go right if the "Right" button is pressed
 *
 */
class CMDGoRight : public Command
{
  public:
    //! derived from command
    void execute()
    {
        RigidBody *rb = static_cast<RigidBody *>(this->go->components->getComponent(
            "RIGIDBODYCOMPONENT"));
        rb->setForceX(3);
    }
};

#endif // FINALPROJECT_ARCUBED_CMDGORIGHT_H