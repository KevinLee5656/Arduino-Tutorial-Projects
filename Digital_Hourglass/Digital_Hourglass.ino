const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0, prevSwitchState = 0, led = 2;
long interval = 1000; 

void setup() {
  for(int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT); 
}

void loop() {
  unsigned long currentTime = millis(); 
  if(currentTime - previousTime > interval){
    previousTime = currentTime; 
    digitalWrite(led, HIGH); 
    led++; 
    if(led == 8) {
      delay(1000);
      for(int x = 2; x < 8; x++){
        digitalWrite (x, LOW);
      }
    }
  }
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite (x, LOW);
    }
    led = 2;
    previousTime = currentTime; 
  }
  prevSwitchState = switchState; 
}
