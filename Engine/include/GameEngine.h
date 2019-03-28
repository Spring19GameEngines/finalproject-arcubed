#ifndef FINALPROJECT_ARCUBED_GAMEENGINE_H
#define FINALPROJECT_ARCUBED_GAMEENGINE_H

#include "GameObject.h"
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

class GameEngine {
public:

    //! Sets the dimensions of the window.
    void setWindowSize(int width, int height);
    //! updates the game state
    void update();


private:

    //variables
    map<string, vector<GameObject>> objectMap;
    int w, h;
};


#endif
