#ifndef FINALPROJECT_ARCUBED_RIGIDBODY_H
#define FINALPROJECT_ARCUBED_RIGIDBODY_H

#include "GameObject.h"

class RigidBody : public Component {
public:
    RigidBody(GameObject* go) {
        this->x = go->pos.x;
        this->y = go->pos.y;
        this->width = go->width;
        this->height = go->height;
        this->go = go;
        this->mass = this->width * this->height;
        this->drag = 1.0f;
        this->useGravity = true;
        this->isKinematic = true;
        this->velX = 0f;
        this->velY = 0f;
        this->gravity = 4f;
        this->id = "rigidbody";
    };

    void update();
    vector<string> receive(string action, vector <string> args);

private:
    //variables
    float x, y, width, height, mass, drag, velX, velY, maxVelX, maxVelY, gravity;
    bool useGravity, isKinematic;
    GameObject go;

    //functions
    void setWidth(float w);
    void setHeight(float h);
    void setGrav(float g)
    void shiftPosition(float x, float y);
    void setMass(float mass);
    void setDrag(float drag);
    void useGravity(bool huh);
    void isKinematic(bool huh);
    void addForce(float x, float y);


};


#endif
