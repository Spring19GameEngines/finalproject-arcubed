#include "RigidBody.h"
#include <cmath>
#include "ResourceManager.h"

void RigidBody::update() {
  if (this->useGravity) {
    this->velY -= this->gravity;
    if (abs(this->velY) >= this->maxVelY) {
      this->velY = -this->maxVelY;
    }
  }

  if (this->isKinematic) {
    std::vector<GameObject*> objects =
        ResourceManager::getInstance().gameObjects;
    for (int i = 0; i < objects.size(); i++) {
      if (x < objects[i]->pos.x + objects[i]->width &&
          x + width > objects[i]->pos.x &&
          y < objects[i]->pos.y + objects[i]->height &&
          y + height > objects[i]->pos.y) {
        if (objects[i]->components->getComponent("rigidbody") != nullptr &&
            this->go->name != objects[i]->name) {
          RigidBody* that = static_cast<RigidBody*>(
              objects[i]->components->getComponent("rigidbody"));
          if (that->isKinematic) {
            float momentum1 =
                (float)sqrt(this->velX * this->velX + this->velY * this->velY) *
                this->mass;
            float angle = this->velX * that->velX + this->velY * that->velY;
            float momentum2 =
                (float)sqrt(that->velX * that->velX + that->velY * that->velY) *
                that->mass;
            momentum2 *= cos(angle);
          } else {
            this->velX -= this->velX;
            this->velY -= this->velY;
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

void RigidBody::receive(std::string action, std::vector<std::string> args) {}
void RigidBody::send(std::string action, std::vector<std::string> args) {
  if (container != NULL) {
    container->send(action, args);
  } else {
    std::cout << "Failed to send message" << std::endl;
  }
}

void RigidBody::setWidth(float w) {
    this->width = w;
};
void RigidBody::setHeight(float h) {
    this->height = h;
};
void RigidBody::setGrav(float g) {
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
void RigidBody::setGravity(bool huh) {
    this->useGravity = huh;
};
void RigidBody::setKinematic(bool huh) {
    this->isKinematic = huh;
};
void RigidBody::addForce(float x, float y) {
    this->velX += x;
    this->velY += y;
};