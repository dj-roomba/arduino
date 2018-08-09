#include <elapsedMillis.h>

#define radSignal 2
#define led 13

volatile bool blip = false;

float raw_cpm = 0;
int cpm = 0;
elapsedMillis period;

void setup() {
  pinMode(radSignal, INPUT);
  pinMode(led, OUTPUT);

  // pin 2 corresponds to interrupt vector 0
  attachInterrupt(0, onBlip, RISING);

  digitalWrite(led, LOW);

  Serial.begin(9600);

  Serial.println("test");

  period = 0;
}

void loop() {
  if (blip && period != 0) {
    raw_cpm = 60. * 1000. / (float)period; // period in ms, cpm in 1/min
    String cpmStr = String(raw_cpm);
    Serial.println(cpmStr);

    period = 0;

    blip = false;
  }

  delay(1);
}

void onBlip() {
  blip = true;
}

