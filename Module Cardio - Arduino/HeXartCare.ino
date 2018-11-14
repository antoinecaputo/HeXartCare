#include "param.h"

void setup() {
  initialize();
}

void loop() {

  ReadIR();

  pulseLED(); // Allumage LED
  
}
