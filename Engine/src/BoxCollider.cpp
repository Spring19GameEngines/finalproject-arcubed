#include "BoxCollider.h"

using namespace std;

vector <string> BoxCollider::receive(string action, vector <string> args) {
    vector <string> ret;
    if (action == "checkcollision") {
        ret = this->checkCollision(args);
    }
    if (action == "setwidth") {
        this->setWidth(stof(args[0]));
    }
    if (action == "setheight") {
        this->setWidth(stof(args[0]));
    }
    if (action == "shiftposition") {
        this->setWidth(stof(args[0]), stof(args[1]));
    }
    return ret;
}

vector <string> BoxCollider::checkCollision(vector <string> boxColliders) {
    vector <string> hits;
    for (int i = 0; i < boxColliders.size(); i++) {
        if (
                x < boxColliders[i]->x + boxColliders[i]->width &&
                x + width > boxColliders[i]->x &&
                y < boxColliders[i]->y + boxColliders[i]->height &&
                y + height > boxColliders[i]->y) {
            hits.push_back(boxColliders[i]->id);
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