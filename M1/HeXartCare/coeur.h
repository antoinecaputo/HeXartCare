
void initialize(void); // Initialisation LED & Serial
void debug (void); // Traceur série

void ReadIR(void); // Lecture des données infra-rouge et calcul du pouls
void CalcPulse(void); // Calcul du pouls
void sendSerial(unsigned long _time,int _pulse); // Envoi de l'instant et du pouls par port série

void pulseLED(void); // Eclairage LED
void shutdownLED(void);

void all(void); // Allume toute les LEDs
void one_two(void); // Allume une LED sur deux
void two_three(void); // Allume deux LEDs sur trois
void chenille(void); // Allumage les unes après les autres en 'chenille'
void wave(void); // Allumage les unes après les autres en 'vague'
