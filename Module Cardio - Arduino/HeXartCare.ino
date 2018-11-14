#include "param.h"

void setup() {
  initialize();
}

void loop() {

  /*int IRval = analogRead(IR);
  Serial.print(IRval); // 0 - 1024
  Serial.print("\n");*/
  
  ReadIR();

}
