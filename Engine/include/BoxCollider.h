#ifndef FINALPROJECT_ARCUBED_BOXCOLLIDER_H
#define FINALPROJECT_ARCUBED_BOXCOLLIDER_H

/**
 * A BoxCollider object. Has a check collision function which returns true if this block is overlapping with the given
 * block.
 */
class BoxCollider {
public:
    BoxCollider(float x, float y, float width, float height);
    bool checkCollision(float x2, float y2, float width2, float height2);
    void setWidth(float w);
    void setHeight(float h);
    void shiftPosition(float x, float y);



private:
    float x, y, width, height;
};


#endif