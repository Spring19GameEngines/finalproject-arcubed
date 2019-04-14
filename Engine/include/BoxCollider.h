#ifndef FINALPROJECT_ARCUBED_BOXCOLLIDER_H
#define FINALPROJECT_ARCUBED_BOXCOLLIDER_H

#include <vector>
#include <string>
#include "GameObject.h"

/**
 * A BoxCollider object. Has a check collision function which returns true if this block is overlapping with the given
 * block.
 */

using namespace std;

class BoxCollider : public Component {
public:
    BoxCollider(GameObject* go) {
        this->x = go->pos.x;
        this->y = go->pos.y;
        this->width = go->width;
        this->height = go->height;
        this->go = go;
        this->id = "boxcollider";
    }

    void update();

    vector<string> receive(string action, vector<string> args);

private:
    //variables
    float x, y, width, height;

    //functions
    //! Checks to see if this box collider is currently overlapping with the given list of game objects
    vector<string> checkCollision(vector<string> boxColliders);
    void setWidth(float w);
    void setHeight(float h);
    void shiftPosition(float x, float y);
};


#endif