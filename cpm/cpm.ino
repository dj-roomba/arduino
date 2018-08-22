volatile int blipCt = 0;

float cpm = 0;

void setup() {
  pinMode(2, INPUT);

  // pin 2 corresponds to interrupt vector 0
  attachInterrupt(0, onBlip, RISING);

  Serial.begin(9600);
}

void loop() {
  delay(100);
  
  Serial.println(blipCt);
  blipCt = 0;
}

void onBlip() {
  blipCt++;
}

