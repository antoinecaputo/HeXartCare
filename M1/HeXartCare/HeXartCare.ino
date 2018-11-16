#include "param.h"

void setup() {
  initialize(); // Initialisation
}

void loop() {

  ReadIR(); // Lecture données IR

  pulseLED(); // Allumage LED

}
