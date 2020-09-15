const int sensorPin = A1;
const float baselineTemp = 25.5;

void setup(){
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, HIGH);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degree in Celsius: ");
  float temperature = (voltage - .5) *100;
  Serial.println(temperature); 
  
  if(temperature < baselineTemp) {
    for(int pinNumber = 2; pinNumber < 5; pinNumber++){
      digitalWrite(pinNumber, LOW);
    }
  }
  else if(temperature >= baselineTemp+2 && temperature< baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
  }
  else if(temperature >= baselineTemp +4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6){
    for(int pinNumber = 2; pinNumber < 5; pinNumber++){
      digitalWrite(pinNumber, HIGH);
    }
  }
  delay(500); 
}
