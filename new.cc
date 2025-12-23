const int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 1~9번 핀 사용
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
const int analogPin = A0;
const float Vref = 5.0;          // 기준 전압
const float threshold = 5.0;     // 켜질 전압 기준(필요 시 조정)
const unsigned long stepMs = 2000; // 임계 전압 유지 시 LED가 늘어나는 간격(ms)

int lit = 0;                     // 켜진 LED 개수
unsigned long lastStep = 0;

void setup() {
  pinMode(analogPin, INPUT);
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  Serial.begin(9600);
}

void setLeds(int count) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], i < count ? HIGH : LOW);
  }
}

void loop() {
  int adcValue = analogRead(analogPin);   // 0 ~ 1023
  float voltage = adcValue * (Vref / 1023.0); // A0 실제 전압

  // 시리얼 모니터 출력
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print("  |  V: ");
  Serial.println(voltage, 3);

  bool above = voltage >= threshold;

  if (above) {
    if (millis() - lastStep >= stepMs && lit < ledCount) {
      lastStep = millis();
      lit++; // 임계 전압을 유지하면 LED 하나씩 켬
    }
  } else {
    // 전압이 떨어지면 모두 끔
    lit = 0;
    lastStep = millis();
  }

  setLeds(lit);
  delay(50); // 과도한 루프 방지
}

























