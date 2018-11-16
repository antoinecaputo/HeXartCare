#include "param.h"

// PROTOTYPES
void all(void); // Allume toute les LEDs
void one_two(void); // Allume une LED sur deux
void two_three(void); // Allume deux LEDs sur trois
void chenille(void); // Allumage les unes après les autres en 'chenille'
void wave(void); // Allumage les unes après les autres en 'vague'

void setup() {
  // initialise chaque LED en sortie et les 
  for (int i = 2; i <= nLED + 2; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // Allumage des LEDs en fonction du paramètre choisi
  switch (mode) {
    case 0 :
      all();
      break;
    case 1:
      one_two();
      break;
    case 2:
      two_three();
      break;
    case 3:
      chenille();
      break;
    case 4:
      wave();
      break;
  }
}

/////////////////////////////////////
//---------------LED---------------//
/////////////////////////////////////

// Allumer toute les LEDs
void all() {
  for (int i = 2; i <= nLED + 2; i++) {
    digitalWrite(i, HIGH);
  }

  delay(350);

  for (int i = 2; i <= nLED + 2; i++) {
    digitalWrite(i, HIGH);
  }

  delay(350);
}

// Allumer une LED sur deux
void one_two() {
  for (int i = 2; i <= nLED + 2; i += 2) {
    digitalWrite(i, HIGH);
  }

  delay(350);

  for (int i = 2; i <= nLED + 2; i += 2) {
    digitalWrite(i, HIGH);
  }

  delay(50);
}

// Allumer deux LEDs sur trois
void two_three() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  delay(350);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  delay(350);
}

// Allumage les unes après les autres en 'chenille'
void chenille() {
  for (int i = 2; i <= nLED+2; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }
  
  delay(350);

  for (int i = 2; i <= nLED+2; i++) {
    digitalWrite(i, LOW);
    delay(50);
  }
  
  delay(350);
}

// Allumage les unes après les autres en 'vague'
void wave() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(75);
  digitalWrite(1, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(75);
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  delay(75);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(0, LOW);
  digitalWrite(5, LOW);
  delay(75);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  delay(75);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(200);
}
