#define radSignal 2
#define led 13

volatile bool blip = false;

void setup() {
  pinMode(radSignal, INPUT);
  pinMode(led, OUTPUT);

  // pin 2 corresponds to interrupt vector 0
  attachInterrupt(0, onBlip, RISING);

  digitalWrite(led, LOW);
}

void loop() {
  if (blip) {
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    blip = false;
  }

  delay(10);
}

void onBlip() {
  blip = true;
}

