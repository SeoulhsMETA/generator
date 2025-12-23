int ss = 0;  // 변수 초기화 추가
const int analogPin = A0;
const float Vref = 5.0;   // 아두이노 기준 전압 (UNO 기준)


void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(0, INPUT);
  Serial.begin(9600);  // 시리얼 통신 초기화 추가
}

void loop() {
  if (0 == HIGH) {
    s = 0;
    int adcValue = analogRead(analogPin);   // 0 ~ 1023
    float voltage = adcValue * (Vref / 1023.0);
      Serial.print("ADC 값: ");
    Serial.print(adcValue);
   Serial.print("  |  전압: ");
  Serial.print(voltage, 3);  // 소수점 3자리
  Serial.println(" V");

  if (voltage>= 0.02) {
    delay(1 * 1000);
    ss += 1;
    Serial.print("Pin 0 Value: ");
    Serial.println(analogRead(0));  // 0번 핀의 아날로그 값 출력
    Serial.print("ss: ");
    Serial.println(ss);  // ss 변수 값 출력
  }
  
  if (ss == 10) {
    digitalWrite(2, HIGH);
  }
  
  if (ss == 30) {
    digitalWrite(3, HIGH);
  }
}

























