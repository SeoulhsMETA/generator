int ss = -1;  // 변수 초기화 추가
const int electricPinA0 = A0;//정방향 전압
const int electricPinA1 = A1;//역방향 전압
const int modebuttonPin = A3;//모드 변경 버튼 핀
const float Vref = 5.0;   // 아두이노 기준 전압 (UNO 기준)
int lastButtonState = HIGH;
int mode = 0;               // 0: 윗코드, 1: 아랫코드
const float requiredmaintaintime = 285.0; // 5V 유지 시간 (밀리초 단위) led하나를 더켜기 위해 유지해야 하는시간

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(0, INPUT);  // TX 핀이므로 사용 주의
  pinMode(1, OUTPUT);  // TX 핀이므로 사용 주의
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(modebuttonPin,INPUT);
    
  Serial.begin(9600);  // 시리얼 통신 초기화 추가
}

void loop() {
  int buttonState = digitalRead(modebuttonPin);
  if (lastButtonState == HIGH && buttonState == LOW) { // 눌리는 순간
    mode = 1 - mode;   // 0이면 1, 1이면 0 으로 바뀜
    Serial.print("mode = ");
    Serial.println(mode);
    delay(50);         // 디바운스
  }
  lastButtonState = buttonState;//모드변경
  
  if (digitalRead(0) == LOW) {
    ss = 0;
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);//초기화
  }
  if (mode == 0) {
    int adcValue = analogRead(electricPinA0);   // 0 ~ 1023
    float voltageA0 = adcValue * (Vref / 1023.0);
    Serial.print("ADC 값: ");
    Serial.print(adcValue);                                 //정방향 전류흐름
    Serial.print("  |  정방향전압: ");
    Serial.print(voltageA0, 3);  // 소수점 3자리
    Serial.println("V");

    int adcValue = analogRead(electricPinA1);   // 0 ~ 1023
    float voltageA1 = adcValue * (Vref / 1023.0);
    Serial.print("ADC 값: ");
    Serial.print(adcValue);                                //역방향 전류흐름  +,- 전선 반대로꼽기
    Serial.print("  |  역방향전압: ");
    Serial.print(voltageA1, 3);  // 소수점 3자리
    Serial.println(" V");

    if (voltageA0 >= 5 || voltageA1 >= 5) {
      delay(requiredmaintaintime);
      ss += 1;
      Serial.print("Pin 0 Value: ");
      Serial.println(analogRead(0));  // 0번 핀의 아날로그 값 출력
      Serial.print("ss: ");
      Serial.println(ss);  // ss 변수 값 출력 ss는 현재 켜진 led 개수
    }

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









  else (mode == 1) {
    int adcValue = analogRead(analogPin);   // 0 ~ 1023
    float voltageA0= adcValue * (Vref / 1023.0);
    Serial.print("ADC 값: ");
    Serial.print(adcValue);                                //정방향 전류흐름                            
    Serial.print("  |  전압: ");
    Serial.print(voltage, 3);  // 소수점 3자리
    Serial.println(" V");


    int adcValue = analogRead(electricPinA1);   // 0 ~ 1023
    float voltageA1 = adcValue * (Vref / 1023.0);
    Serial.print("ADC 값: ");
    Serial.print(adcValue);                                //역방향 전류흐름  +,- 전선 반대로꼽기
    Serial.print("  |  역방향전압: ");
    Serial.print(voltageA1, 3);  // 소수점 3자리
    Serial.println(" V");







    if (voltageA0 >= 5 || voltageA1 >= 5) {
      delay(requiredmaintaintime);
      ss += 1;
      Serial.print("Pin 0 Value: ");
      Serial.println(analogRead(0));  // 0번 핀의 아날로그 값 출력
      Serial.print("ss: ");
      Serial.println(ss);  // ss 변수 값 출력
    }
    else  {
      delay(requiredmaintaintime);
      ss -= 1;
      Serial.print("Pin 0 Value: ");
      Serial.println(analogRead(0));  // 0번 핀의 아날로그 값 출력
      Serial.print("ss: ");
      Serial.println(ss);  // ss 변수 값 출력
    }
    if (ss >= 1) {
      digitalWrite(1, HIGH);
    }

    if (ss >= 2) {
      digitalWrite(2, HIGH);
    }

    if (ss >= 3) {
      digitalWrite(3, HIGH);
    }

    if (ss >= 4) {
      digitalWrite(4, HIGH);
    }

    if (ss >= 5) {
      digitalWrite(5, HIGH);
    }

    if (ss >= 6) {
      digitalWrite(6, HIGH);
    }
      if (ss >= 7) {
      digitalWrite(7, HIGH);
    }
    if (ss >= 8) {
      digitalWrite(8, HIGH);
    }
    if (ss >= 9) {
      digitalWrite(9, HIGH);
    }
    if (ss >= 10) {
      digitalWrite(10, HIGH);
    }
  }
  
}

