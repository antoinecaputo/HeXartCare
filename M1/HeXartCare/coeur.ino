#include "coeur.h"

void initialize() {
  // initialise chaque LED en sortie
  for (int i = 2; i <= nLED + 2; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  // initialise le port série
  Serial.begin(9600);
}


int pulse = 0; // Compteur de pulsation
int IRMemory = 0; // Valeur en mémoire
int stat = LOW; // Etat allumage LED

void ReadIR() {
  // Lecture du retour analogique du photo-transistor
  int IRval = analogRead(IR); // 0->0V - 1024->5V

  //Si pulsation ET front montant
  if ( (IRval >= 250 && IRval < 400) && (IRval > IRMemory ) && IRMemory < 100) {
    pulse++; // Ajoute une pulsation
    stat = HIGH; // Etat LED sur HAUT
  }

  IRMemory = IRval; // Sauvegarde la nouvelle valeur IR

  CalcPulse(); // Calcul du pouls
}

unsigned long LastSend = 0; // Stock la dernière fois que l'action à été exécutée
void CalcPulse() {
  byte pulseTime; // Durée de capture du pouls (de 0 à 60)
  unsigned long MillisCalc = millis(); // Temps écoulé en ms

  //Toutes les 10 sec
  if ( ((MillisCalc - LastSend) % 10000) == 0 ) {
    pulseTime += 10; // 10 sec se sont écoulées
    int bpm = ( pulse * (60 / pulseTime)  ); // Nombre de pulsation par minute
    sendSerial(millis() / 1000, bpm); // Envoi au port série l'instant et le pouls
  }

  // Apres 1 minute
  if ( (MillisCalc - LastSend) > 60100 ) {
    pulseTime = 0; // Remet le timer des pulsations à 0
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
unsigned long statMillis = 0; // stock la dernière fois que l'action a été exécutée
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

  if (stat == HIGH) {
    unsigned long timer = millis();
    if ( (timer - statMillis) >= 500) {
      stat = LOW;
      statMillis = timer;
    }
  }
}

void shutdownLED() {
  for (int i = 2; i <= nLED + 2; i++) {
    digitalWrite(i, LOW);
  }
}

void all() {
  for (int i = 2; i <= nLED + 2; i++) {
    digitalWrite(i, stat);
  }
}

void one_two() {
  for (int i = 2; i <= nLED + 2; i += 2) {
    digitalWrite(i, stat);
  }
}

void two_three() {
  digitalWrite(2, stat);
  digitalWrite(3, stat);
  digitalWrite(5, stat);
  digitalWrite(6, stat);
  digitalWrite(8, stat);
  digitalWrite(9, stat);
  digitalWrite(11, stat);
  digitalWrite(12, stat);
}

void chenille(){
  
}

void debug() {
  Serial.print(analogRead(0));
  Serial.print(",");
  Serial.print(pulse);
  Serial.println();
}
