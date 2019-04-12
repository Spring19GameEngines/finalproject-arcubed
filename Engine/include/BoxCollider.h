#ifndef FINALPROJECT_ARCUBED_BOXCOLLIDER_H
#define FINALPROJECT_ARCUBED_BOXCOLLIDER_H

#include <vector>
#include "GameObject.h"

/**
 * A BoxCollider object. Has a check collision function which returns true if this block is overlapping with the given
 * block.
 */

using namespace std;

class BoxCollider {
public:
    BoxCollider(float x, float y, float width, float height);
    vector<GameObject> checkCollision(vector<GameObject> objects);
    void setWidth(float w);
    void setHeight(float h);
    void shiftPosition(float x, float y);



private:
    float x, y, width, height;
};


#endif