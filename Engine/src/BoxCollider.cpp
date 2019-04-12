#include "BoxCollider.h"

BoxCollider::BoxCollider(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};

/**
 * Collision function. Currently assumes that x and y are at the top left of the sprite
 *
 * @param x2
 * @param y2
 * @param width2
 * @param height2
 * @return
 */
vector <GameObject> BoxCollider::checkCollision(vector <GameObject> objects) {
    vector <GameObject> hits;
    for (int i = 0; i < objects.size(); i++) {
        if (
                x < objects[i]->BoxCollider->x + objects[i]->BoxCollider->width &&
                x + width > objects[i]->BoxCollider->x &&
                y < objects[i]->BoxCollider->y + objects[i]->BoxCollider->height &&
                y + height > objects[i]->BoxCollider->y) {
            hits.push_back(objects[i]);
        }
    }
    return hits;
}


void BoxCollider::setWidth(float w) {
    this->width = w;
}

void BoxCollider::setHeight(float h) {
    this->height = h;
}

void BoxCollider::shiftPosition(float x, float y) {
    this->x += x;
    this->y += y;
};