#include "RigidBody.h"
#include <cmath>
#include "ResourceManager.h"

using namespace std;

RigidBody::RigidBody(GameObject *go) : Component("RIGIDBODYCOMPONENT") {
    this->x = go->pos.x;
    this->y = go->pos.y;
    this->width = go->width;
    this->height = go->height;
    this->go = go;
    this->mass = this->width * this->height;
    this->drag = 1.0f;
    this->useGravity = true;
    this->isKinematic = false;
    this->velX = 0.0f;
    this->velY = 0.0f;
    this->gravity = -4.0f;
    this->maxVelY = 10;
    this->maxVelX = 10;
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
                if (x < objects[i]->pos.x + objects[i]->width * objects[i]->scale &&
                    x + width * this->go->scale > objects[i]->pos.x &&
                    y < objects[i]->pos.y + objects[i]->height * objects[i]->scale &&
                    y + height * this->go->scale > objects[i]->pos.y) {
                    if (objects[i]->components->getComponent("RIGIDBODYCOMPONENT") != nullptr) {
                        RigidBody *that = static_cast<RigidBody *>(objects[i]->components->getComponent(
                                "RIGIDBODYCOMPONENT"));
                        if (!that->isKinematic) {
                            float deltaX = this->velX - that->velX;
                            float deltaY = this->velY - that->velY;
                            cout << "deltaX: " << deltaX << endl;
                            cout << "deltaY: " << deltaY << endl;
                            float deltaLength = (float) sqrt(deltaX * deltaX + deltaY * deltaY);
                            cout << "deltaLength: " << deltaLength << endl;
                            float mtdX = deltaX * ((float) sqrt(this->velX * this->velX + this->velY * this->velY) +
                                                   (float) sqrt(that->velX * that->velX + that->velY * that->velY) -
                                                   deltaLength) / deltaLength;
                            float mtdY = deltaY * ((float) sqrt(this->velX * this->velX + this->velY * this->velY) +
                                                   (float) sqrt(that->velX * that->velX + that->velY * that->velY) -
                                                   deltaLength) / deltaLength;
                            float im1 = 1 / this->mass;
                            float im2 = 1 / that->mass;

                            cout << "im1: " << im1 << endl;
                            cout << "im2: " << im2 << endl;

                            this->x += mtdX * (im1/ (im1 + im2));
                            this->y += mtdY * (im1/ (im1 + im2));
                            this->velX -= that->velX;
                            this->velY -= that->velY;
                            float mtdXM = (float) sqrt(mtdX * mtdX + mtdY * mtdY);

                            cout << "mtdX: " << mtdX << endl;
                            cout << "mtdXM: " << mtdXM << endl;

                            float vn = this->velX * mtdX/mtdXM + this->velY * mtdY/mtdXM;

                            cout << "Vel Y: " << this->velY << endl;

                            cout << "VN: " << vn << endl;
                            if (vn <= 0) {
                                float i = (-1.85f * vn /(im1 + im2));
                                float impulseX = mtdX/mtdXM * i;
                                float impulseY = mtdY/mtdXM * i;
                                this->velX += (impulseX * im1);
                                this->velY += (impulseY * im1);
                                if (abs(this->velY) >= this->maxVelY) {
                                    cout << this->velY << endl;
                                    if (this->velY < 0) {
                                        this->velY = -this->maxVelY;
                                    } else {
                                        this->velY = this->maxVelY;
                                    }
                                }
                            }
                        } else {
                            this->velX = 0;
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

    // add velocity to position
    this->x += this->velX;
    this->y += this->velY;

    // update the game objects position
    this->go->pos.x = this->x;
    this->go->pos.y = this->y;

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

void RigidBody::shiftPosition(float x, float y) {
    this->x += x;
    this->y += y;
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

void RigidBody::setForce(float x, float y) {
    this->velX = x;
    this->velY = y;
};