#include "RigidBody.h"
#include <cmath>
#include "ResourceManager.h"

using namespace std;

RigidBody::RigidBody(GameObject *go) : Component("RIGIDBODYCOMPONENT") {
    this->width = go->width;
    this->height = go->height;
    this->go = go;
    this->mass = 1;
    this->drag = 1.0f;
    this->useGravity = true;
    this->isKinematic = false;
    this->velX = 0.0f;
    this->velY = 0.0f;
    this->gravity = -4.0f;
    this->maxVelY = 10;
    this->maxVelX = 10;
    this->lastX = this->go->pos.x;
    this->lastY = this->go->pos.y;
}

void RigidBody::update() {
    if (!this->isKinematic) {
        if (this->useGravity) {
            this->velY -= this->gravity;
            if (abs(this->velY) >= this->maxVelY) {
                if (this->velY < 0) {
                    this->velY = -this->maxVelY;
                } else {
                    this->velY = this->maxVelY;
                }
            }
        }
        std::vector < GameObject * > objects = ResourceManager::getInstance().gameObjects;
        for (int i = 0; i < objects.size(); i++) {
            if (objects[i]->name != this->go->name) {
                if (this->go->pos.x < objects[i]->pos.x + objects[i]->width * objects[i]->scale &&
                    this->go->pos.x + width * this->go->scale > objects[i]->pos.x &&
                    this->go->pos.y < objects[i]->pos.y + objects[i]->height * objects[i]->scale &&
                    this->go->pos.y + height * this->go->scale > objects[i]->pos.y) {
                    if (objects[i]->components->getComponent("RIGIDBODYCOMPONENT") != nullptr) {
                        RigidBody *that = static_cast<RigidBody *>(objects[i]->components->getComponent(
                                "RIGIDBODYCOMPONENT"));
                        if (!that->isKinematic) {
                            float deltaX = this->velX - that->velX;
                            float deltaY = this->velY - that->velY;
                            float deltaLength = (float) sqrt(deltaX * deltaX + deltaY * deltaY);
                            float mtdX = deltaX * ((this->go->width + that->go->width - deltaLength) / deltaLength);
                            float mtdY = deltaY * ((this->go->height + that->go->height - deltaLength) / deltaLength);
                            float im1 = 1 / this->mass;
                            float im2 = 1 / that->mass;
                            float vX = this->velX - that->velX;
                            float vY = this->velY - that->velY;
                            float mtdM = (float) sqrt(mtdX * mtdX + mtdY * mtdY);
                            float vn = vX * (mtdX / mtdM) + vY * (mtdY / mtdM);
                            float i = (-1.85f * vn / (im1 + im2));
                            float impulseX = (mtdX / mtdM) * i;
                            float impulseY = (mtdY / mtdM) * i;
                            this->addForce(this->velX + (impulseX * im1), this->velY + (impulseY * im1));
                        } else {
                            this->go->pos.x = this->lastX;
                            this->go->pos.y = this->lastY;
                            this->velY = 0;
                        }
                    }
                }
            }
        }

    }

    // alter velocity based upon drag
    if (this->velX > 0) {
        this->velX -= this->drag;
        if (this->velX <= 0) {
            this->velX = 0;
        }
    }
    if (this->velX < 0) {
        this->velX += this->drag;
        if (this->velX >= 0) {
            this->velX = 0;
        }
    }
    if (this->velY > 0) {
        this->velY -= this->drag;
        if (this->velY <= 0) {
            this->velY = 0;
        }
    }
    if (this->velY < 0) {
        this->velY += this->drag;
        if (this->velY >= 0) {
            this->velY = 0;
        }
    }

    this->lastX = this->go->pos.x;
    this->lastY = this->go->pos.y;

    // update the game objects position
    this->go->pos.x += this->velX;
    this->go->pos.y += this->velY;

}

void RigidBody::receive(std::string action, std::vector <std::string> args) {}

void RigidBody::send(std::string action, std::vector <std::string> args) {
    if (container != NULL) {
        container->send(action, args);
    } else {
        std::cout << "Failed to send message" << std::endl;
    }
}

void RigidBody::setGravity(float g) {
    this->gravity = g;
};


void RigidBody::setMass(float mass) {
    this->mass = mass;
};

void RigidBody::setDrag(float drag) {
    this->drag = drag;
};

void RigidBody::setUseGravity(bool huh) {
    this->useGravity = huh;
};

void RigidBody::setIsKinematic(bool huh) {
    this->isKinematic = huh;
};

void RigidBody::addForce(float x, float y) {
    this->velX += x;
    this->velY += y;
};

void RigidBody::setForceX(float x) {
    this->velX = x;
}

void RigidBody::setForceY(float y) {
    this->velY = y;
};