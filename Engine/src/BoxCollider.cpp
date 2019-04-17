#include "BoxCollider.h"
#include "ResourceManager.h"

using namespace std;

// Sends a message to the parent component container
void BoxCollider::send(string action, vector <std::string> args) {
    if (container != NULL) {
        container->send(action, args);
    } else {
        cout << "Failed to send message" << endl;
    }
}

// default
void BoxCollider::receive(string action, vector <string> args) {
    return;
}

void BoxCollider::update() {
    return;
}

vector <string> BoxCollider::checkCollision() {
    vector <string> hits;
    vector < GameObject * > boxColliders = ResourceManager::getInstance().gameObjects;
    for (int i = 0; i < boxColliders.size(); i++) {
        if (this->go->pos.x < boxColliders[i]->pos.x + boxColliders[i]->width * boxColliders[i]->scale &&
            this->go->pos.x + this->width * this->go->scale > boxColliders[i]->pos.x &&
            this->go->pos.y < boxColliders[i]->pos.y + boxColliders[i]->height * boxColliders[i]->scale &&
            this->go->pos.y + this->height * this->go->scale > boxColliders[i]->pos.y) {
            hits.push_back(boxColliders[i]->name);
        }
    }
    return hits;
}