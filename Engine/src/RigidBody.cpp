#include "RigidBody.h"


void RigidBody::update() {
    if (this->useGravity) {

    }

    if (this->isKinematic) {

    }

    this->go->posn.x = this->x;
    this->go->posn.y = this->y;
}

vector<string> RigidBody::action(string action, vector <string> args);