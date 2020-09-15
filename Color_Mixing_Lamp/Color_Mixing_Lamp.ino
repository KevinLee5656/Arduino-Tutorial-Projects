const int greenLEDpin = 9, blueLEDpin = 10, redLEDpin = 11;
const int redSensorPin = A0, greenSensorPin = A1, blueSensorPin = A2;
int redValue = 0, greenValue = 0, blueValue = 0, redSensorValue = 0, greenSensorValue = 0, blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() {
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  redSensorValue = analogRead(redSensorPin); 

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: "); 
  Serial.print(greenSensorValue); 
  Serial.print("\t Green: ");
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue); 

  redValue = redSensorValue/4; 
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4; 

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue); 

  analogWrite(redLEDpin, redValue);
  analogWrite(greenLEDpin, greenValue);
  analogWrite(blueLEDpin, blueValue); 
}
