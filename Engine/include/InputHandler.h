#ifndef FINALPROJECT_ARCUBED_INPUTHANDLER_H
#define FINALPROJECT_ARCUBED_INPUTHANDLER_H

//Binding to imgui???

using namespace std;

class InputHandler {
 public:
  //accesses keys that are pressed and executes the method that is bound to them
  void handleInput();

  //binds a reference to a command to the pointer assigned with the desired button
  void setButton(Command com, Command* point);


// HAVE TO COME BACK TO THIS TO FIX
 private:
   Command* buttonW_;
   Command* buttonA_;
   Command* buttonS_;
   Command* buttonD_;

}
