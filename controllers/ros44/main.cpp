#include "Ros.hpp"

int main(int argc, char **argv)
{

  Ros *controller = new Ros();
  controller->run(argc, argv);
  delete controller;
  return 0;
}
