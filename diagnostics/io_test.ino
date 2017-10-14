#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const float sprintr_ver = 1.0;
const bool dodebug = true;

#define OLED_RESET 4
Adafruit_SSD1306 oled(OLED_RESET);

// global IO vars
const int sw1out = 5;
const int sw2out = 6;
const int beamPort = 15;
const int sw1in = 10;
const int sw2in = 11;
const int relayPort = 12;
const int indPort = 13;

void setup() {
  pinMode(sw1out,OUTPUT);
  pinMode(sw2out,OUTPUT);
  pinMode(sw1in,INPUT_PULLUP);
  pinMode(sw2in,INPUT_PULLUP);
  pinMode(beamPort,INPUT_PULLUP);
  pinMode(relayPort,OUTPUT);
  pinMode(indPort,OUTPUT);

  if(dodebug == true) {
    Serial.begin(19200);
    Serial.println("Initialized");
  }
}

void loop() {
  digitalWrite(relayPort,0);
  digitalWrite(sw1out,digitalRead(sw1in));
  digitalWrite(sw2out,digitalRead(sw2in));
  if(dodebug == true) {
    Serial.print("sw1in: "); Serial.println(digitalRead(sw1in));
    Serial.print("sw2in: "); Serial.println(digitalRead(sw2in));
  }
}
