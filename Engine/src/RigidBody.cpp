#include "RigidBody.h"
#include <cmath>


void RigidBody::update() {
    if (this->useGravity) {
        this->velY - this->gravity;
        if (abs(this->velY) >= this->maxVelY) {
            this->velY = -this->maxVelY;
        }
    }

    if (this->isKinematic) {

    }

    this->x -= this->velX;
    this->y -= this->velY;
    this->velX += this->accelX;
    this->velY += this->accelY;
    this->accelX -= this->drag;
    this->accelY -= this->drag;
    this->go->posn.x = this->x;
    this->go->posn.y = this->y;
}

