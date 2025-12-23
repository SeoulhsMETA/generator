int transistorBase = 9; // PWM 신호 (조절용)
int readPin = A0;       // 전압 측정용

void setup() {
  Serial.begin(9600);
  pinMode(transistorBase, OUTPUT);
}

void loop() {
  // 0에서 255까지 신호를 높이며 전압을 변화시킵니다.
  for (int i = 0; i <= 255; i++) {
    analogWrite(transistorBase, i);
    
    delay(30); 
    
    int rawValue = analogRead(readPin);
    float voltage = rawValue * (5.0 / 1023.0);

    Serial.print("Control Value (PWM): ");
    Serial.print(i);
    Serial.print(" | Measured Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");
    
    // 여기서 전압(voltage) 값에 따라 LED를 켜는 코드를 추가할 수 있습니다.
  }
  delay(1000);
}