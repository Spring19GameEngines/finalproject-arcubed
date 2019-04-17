#include "GameEngine.h"
/* MAIN */

int main(int argc, char *args[])
{
  GameEngine *engine = &GameEngine::getInstance();
  engine->init(1280, 720);
  engine->run();
  return 0;
}