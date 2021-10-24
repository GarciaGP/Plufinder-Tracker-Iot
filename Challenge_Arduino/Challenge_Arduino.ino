// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  11 // Pin 11 conectado ao trigger.
#define ECHO_PIN     12 // Pin 12 conectado ao TX.
#define MAX_DISTANCE 20 // Distância máxima de localização setada em 20cm

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  Serial.begin(115200); // Para utilizar a biblioteca NewPing a velocidade do serial precisa estar em 115200
}

void loop() {
  delay(2000);   // Aguarda 20s até iniciar um novo loop
  if(sonar.ping_cm() < 20 && sonar.ping_cm() > 0) {
    Serial.print("1");
  } else {
    Serial.print("0");
  }
}
