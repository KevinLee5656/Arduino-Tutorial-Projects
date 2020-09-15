const int controlPin1 = 2, controlPin2 = 3, enablePin = 9, 
directionSwitchPin = 4, onOffSwitchStateSwitchPin = 5, potPin = A0;
int onOffSwitchState = 0, previousOnOffSwitchState = 0,
directionSwitchState = 0, previousDirectionSwitchState = 0;
int motorEnabled = 0, motorSpeed = 0, motorDirection = 1; 

void setup() {
  pinMode(directionSwitchPin, INPUT); 
  pinMode(onOffSwitchStateSwitchPin,INPUT);
  pinMode(controlPin1, OUTPUT); 
  pinMode(controlPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT); 
  digitalWrite(enablePin, OUTPUT); 
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin); 
  delay(1); 
  directionSwitchState = digitalRead(directionSwitchPin); 
  motorSpeed = analogRead(potPin)/4; 

  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled; 
    }
  }
  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  } 
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
