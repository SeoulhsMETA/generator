// 핀 설정
const int controlPin = 9; // 트랜지스터 조절 (11번 줄)
const int sensorPin = A0; // 전압 측정 (10번 줄)

void setup() {
  Serial.begin(9600); // 시리얼 모니터 속도
  pinMode(controlPin, OUTPUT);
  
  Serial.println("=====================================");
  Serial.println("   정밀 전압 측정 테스트 시작   ");
  Serial.println("=====================================");
}

void loop() {
  // 0부터 255까지 신호를 5단계씩 올려보겠습니다.
  for (int pwmValue = 0; pwmValue <= 255; pwmValue += 5) {
    analogWrite(controlPin, pwmValue);
    
    // 신호가 안정화될 때까지 기다림
    delay(50); 

    // --- 평균값 필터링 시작 ---
    long sum = 0;
    int samples = 10; // 10번 읽어서 평균을 냄
    for (int i = 0; i < samples; i++) {
      sum += analogRead(sensorPin);
      delay(2);
    }
    float averageRaw = (float)sum / samples;
    // --- 평균값 필터링 끝 ---

    // 전압 계산 (5V 기준)
    float voltage = averageRaw * (5.0 / 1023.0);

    // 시리얼 모니터 출력
    Serial.print("제어값(PWM): ");
    Serial.print(pwmValue);
    Serial.print("\t | 측정 전압: ");
    if (voltage < 0.1) Serial.print("0.00"); // 아주 낮은 값은 0으로 표시
    else Serial.print(voltage, 2); // 소수점 둘째자리까지
    Serial.println(" V");
  }

  Serial.println("-------------------------------------");
  Serial.println("한 사이클 완료! 2초 후 다시 시작합니다.");
  delay(2000); 
}