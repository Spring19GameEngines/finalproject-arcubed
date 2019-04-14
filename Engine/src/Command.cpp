#ifndef FINALPROJECT_ARCUBED_COMMAND_H
#define FINALPROJECT_ARCUBED_COMMAND_H

using namespace std;

class Command {
 public:
  virtual ~Command() {};
  virtual void execute() = 0;
}

//NOTE: All player made commands have to implement Command and overwrite the "execute" method
