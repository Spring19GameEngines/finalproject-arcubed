#ifndef FINALPROJECT_ARCUBED_GAMEOBJECT_H
#define FINALPROJECT_ARCUBED_GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "TinyMath.h"

using namespace std;

class GameObject {
public:
    //! constructor for a GameObject - Uses Default name
    GameObject();
    //! constructor for a GameObject - Sets the name
    GameObject(string name);
    //! updates the object at a high priority
    void earlyUpdate();
    //! updates the object at a normal priority
    void update();
    //! updates the object at a low priority
    void lateUpdate();
    //! adds a script to the object
    void addScript(string path);
    //! gets the names of the scripts from this object
    vector<string> getScripts();
    //! gets variables from the scripts
    map<string, vector<int>> getScriptVars();
    //! transforms the object based on the given transformation matrix
    void translate(int x, int y);
    void rotate(int x, int y);
    void scale(int x, int y);



private:

    // Variables
    Vector3D posn;
    string name;
    vector<string> scriptList;
    Matrix3D transMat;

};


#endif
