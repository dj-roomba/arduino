#include <elapsedMillis.h>

#define radSignal 2

#define alpha 0.3

volatile bool blip = false;

volatile int blipCt = 0;

float raw_cpm = 0;
float cpm_sample;
float cpm;
elapsedMillis period;

void setup() {
  pinMode(radSignal, INPUT);

  // pin 2 corresponds to interrupt vector 0
  attachInterrupt(0, onBlip, RISING);

  Serial.begin(9600);

  Serial.println("test");

  period = 0;
}

void loop() {
  /*if (blip && period != 0 && period != 0.1) {
    raw_cpm = 60. * 1000. / (float)period; // period in ms, cpm in 1/min

    // low pass filter, lower alpha means less sensitive to changes
    cpm += alpha * (raw_cpm - cpm);

    // print to serial monitor
    String cpmStr = String(cpm);
    Serial.println(cpmStr);

    period = 0;

    blip = false;
  }

  delay(1);*/

  delay(500);

  cpm_sample = blipCt * 120;  // counts in half a second to counts in one minute
  
  // low pass filter, lower alpha means less sensitive to changes
  cpm += alpha * (cpm_sample - cpm);
  
  // print to serial monitor
  String cpmStr = String(cpm);
  Serial.println(cpmStr);

  blipCt = 0;
}

void onBlip() {
  blip = true;
  blipCt++;
}

