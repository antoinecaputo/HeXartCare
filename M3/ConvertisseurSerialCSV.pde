//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

PFont Font;
PFont HeartFont;


void setup() {
  size(350, 125);
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");

  textSize(20);
  Font = createFont("calibri.ttf",20);
  HeartFont = createFont("MWHeart.ttf",30);
}

void draw() {
  if (udSerial.available() > 0) {
    String SenVal = udSerial.readString();
    if (SenVal != null) {
      output.println(SenVal);
    }
  }

  background(0);
  textFont(Font);
  text("Récupération des données ...", 50, 30);
  text("Timer : " + millis()/1000 + "sec", 100, 60);
  textFont(HeartFont);
  text("Q L Q L Q L Q L", 20, 100);
}

void keyPressed() {
  output.flush();
  output.close();
  exit();
}
