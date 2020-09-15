

int const potPin = A0;
int potVal = 0, angle = 0; 

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15); 
}
