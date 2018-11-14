#include "coeur.h"

unsigned int pulse = 0; // Compteur de pulsation

void initialize() {
  // initialise chaque LED en sortie
  for (int i = 0; i <= nLED; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  // initialise le port série
  Serial.begin(9600);
}

int IRMemory = 0; // Valeur en mémoire
void ReadIR() {
  // Lecture du retour analogique du photo-transistor
  int IRval = analogRead(IR); // 0->0V - 1024->5V

  //Si pulsation ET qu'il y a un écart de 250
  if ( (IRval >= 250 && IRval < 400) && (IRval > IRMemory ) && IRMemory < 250) {
    pulse++; // Ajoute une pulsation
  }
  IRMemory = IRval; // Sauvegarde la nouvelle valeur IR

  CalcPulse(); // Calcul du pouls
}

unsigned long LastSend = 0; // Stock la dernière fois que l'action à été exécutée
void CalcPulse() {

  unsigned long MillisCalc = millis();//Temps écoulé en ms

  //Toutes les 10 sec
  if ( ( (MillisCalc - LastSend) % 10 ) == 0 ) {
    int bpm = ( (pulse) * (60 / (MillisCalc - LastSend) )  );
    // Envoi au port série l'instant et le pouls
    sendSerial(millis() / 1000, bpm);
  }

  // Apres 1 minute
  if ( (MillisCalc - LastSend) > 60100 ) {
    pulse = 0; // Remet le compteur de pulsation à 0
    LastSend = MillisCalc; // Sauvegarde la dernière exécution
  }

}

void sendSerial(unsigned long _time, int _pulse) {
  Serial.print(_time);
  Serial.print(";");
  Serial.print(_pulse);
  Serial.print("\n");
}


/////////////////////////////////////
//---------------LED---------------//
/////////////////////////////////////

void pulseLED() {
  int pulseMemory;
  if (pulse != pulseMemory) {
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
  pulseMemory = pulse;
}

void shutdownLED() {
  for (int i = 0; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
}


// Allume toute les LEDs
void all() {
  for (int i = 0; i <= nLED; i++) {
    digitalWrite(i, HIGH);
  }
  
  unsigned long timer = millis();
  if ( (millis() - timer ) >= 1000 ) {
    shutdownLED();
  }
}

// Allume une LED sur deux
void one_two() {
  for (int i = 0; i <= nLED; i += 2) {
    digitalWrite(i, HIGH);
  }
  delay(350);
  for (int i = 0; i <= nLED; i += 2) {
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
  /*
    delay(350);

    digitalWrite(0, LOW);
    digitalWrite(9, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    delay(350);*/
}

// Allumage les unes après les autres en 'chenille'
void chenille() {
  for (int i = 0; i <= nLED; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }

  delay(500);

  for (int i = 0; i <= nLED; i++) {
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
