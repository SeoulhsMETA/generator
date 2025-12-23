int ss = 0;  // 변수 초기화 추가(버튼을 누르면 초기화)
const int analogPin = A0;
const int buttonPin = 0;
const int led1 = 1;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;
const int led6 = 6;
const int led7 = 7;
const int led8 = 8;
const int led9 = 9;
const int led10 = 10;
const float Vref = 5.0;   // 아두이노 기준 전압 (UNO 기준)


void setup() {
  pinMode(A0,INPUT);
  pinMode(0,INPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  
  Serial.begin(9600);  // 시리얼 통신 초기화 추가
}

void loop() {
    int adcValue = analogRead(analogPin);   // 0 ~ 1023
    float voltage = adcValue * (Vref / 1023.0);
      Serial.print("ADC 값: ");
    Serial.print(adcValue);
   Serial.print("  |  전압: ");
  Serial.print(voltage, 3);  // 소수점 3자리
  Serial.println(" V");

  if (voltage>= 0.02) {
    delay(0.5* 1000);
    ss += 1;
    Serial.print("Pin 0 Value: ");
    Serial.println(voltage);
    Serial.print("ss: ");
    Serial.println(ss);  // ss 변수 값 출력
  
  
  if (ss == 1) {
    digitalWrite(1, HIGH);
  }
  
  if (ss == 2) {
    digitalWrite(2, HIGH);
  }


  if (ss == 3) {
    digitalWrite(3, HIGH);
    }
  
    if (ss == 4) {
    digitalWrite(4, HIGH);
    }

    if (ss == 5) {
    digitalWrite(5, HIGH);
    }

    if (ss == 6) {
    digitalWrite(6, HIGH);
    }

    if (ss == 7) {
    digitalWrite(7, HIGH);
    }

    if (ss == 8) {
    digitalWrite(8, HIGH);
    }

    if (ss == 9) {
    digitalWrite(9, HIGH);
    }

    if (ss == 10) {
    digitalWrite(10, HIGH);
    }
    
    
}
}

























