#include "coeur.h"

unsigned int pulse = 0; // Compteur de pulsation

void initialize() {
  // initialise chaque LED en sortie
  for (int i = 0; i <= nLED; i++) {
    pinMode(i, OUTPUT);
  }
  // initialise le port série
  Serial.begin(9600);
}

void ReadIR() {
  // Lecture du retour analogique du photo-transistor
  int IRval = analogRead(IR); // 0->0V 1024->

  // Conversion en V
  //int IRv = ((IRval * 1024) / 5);

  // Si il y a une varation de +- 100
  static int IRMemory;
  if (IRMemory >= IRval + 100 || IRMemory <= IRval - 100) {
    pulseLED(); // Allumage LED
    pulse++; // Ajoute une pulsation
    IRMemory = IR; // Sauvegarde la nouvelle valeur IR
  }

  CalcPulse(); // Calcul du pouls
}

unsigned long LastCalc = 0; // Stock la dernière fois que l'action à été exécutée
void CalcPulse() {
  unsigned long MillisCalc = millis();//Temps écoulé en ms

  //Lorsque 10sec sont passées
  if (MillisCalc - LastCalc > 10000) {
    
    // Envoi au port série l'instant et le pouls
    int bpm = ( (pulse/2) * 10 );
    sendSerial(millis() / 1000, bpm);
    
    pulse = 0; // Remet le compteur de pulsation à 0
    
    LastCalc = MillisCalc;// Sauvegarde la dernière exécution
  }
}

void sendSerial(unsigned long _time, int _pulse) {
  Serial.print(_time);
  Serial.print("-");
  Serial.print(_pulse);
  Serial.print("\n");
}


/////////////////////////////////////
//---------------LED---------------//
/////////////////////////////////////

void pulseLED() {
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


// Allume toute les LEDs
unsigned long LastAllOn = 0;// stock la dernière fois que l'action a été exécutée
unsigned long LastAllOff = 0;// stock la dernière fois que l'action a été exécutée
void all() {
  unsigned long MillisAll = millis();//Temps écoulé

  //Lorsque 350ms sont passées
  if (MillisAll - LastAllOn > 2000) {
    for (int i = 0; i <= 9; i++) {
      digitalWrite(i, HIGH);
    }
    //sauvegarde la dernière éxecution
    LastAllOn = MillisAll;
  }

  if (MillisAll - LastAllOff > 2000) {
    for (int i = 0; i <= 9; i++) {
      digitalWrite(i, LOW);
    }
    //sauvegarde la dernière éxecution
    LastAllOff = MillisAll;
  }
}

// Allume une LED sur deux
void one_two() {
  for (int i = 0; i <= 9; i += 2) {
    digitalWrite(i, HIGH);
  }
  delay(350);
  for (int i = 0; i <= 9; i += 2) {
    digitalWrite(i, LOW);
  }
  delay(350);
}

// Allume deux LEDs sur trois
void two_three() {

  digitalWrite(0, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  delay(350);

  digitalWrite(0, LOW);
  digitalWrite(9, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(350);
}

// Allumage les unes après les autres en 'chenille'
void chenille() {
  for (int i = 0; i <= 9; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }

  delay(500);

  for (int i = 0; i <= 9; i++) {
    digitalWrite(i, LOW);
    delay(50);
  }
  delay(500);
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
