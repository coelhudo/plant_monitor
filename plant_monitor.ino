void setup() {
  pinMode(2, OUTPUT); //RED
  pinMode(3, OUTPUT); //RED
  pinMode(4, OUTPUT); //GREEN
  pinMode(5, OUTPUT); //GREEN
  
  pinMode(A0, INPUT);

  Serial.begin(9600);
}

void turnOnOff(int value, int valueExpected, int pin) {
  int pinValue = LOW;
  if(value >= valueExpected) {
    pinValue = HIGH;
  }

  digitalWrite(pin, pinValue);
  delay(500);
}

void loop() {

  int valueFromSensor = analogRead(A0);
  Serial.println(valueFromSensor);
  
  byte value = map(valueFromSensor, 0, 800, 0, 4);
  Serial.println(value);

  for(int i = 3; i >= 0; i--)
    turnOnOff(value, i, i+2);
}
