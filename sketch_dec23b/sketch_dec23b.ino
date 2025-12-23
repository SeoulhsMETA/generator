// 핀 설정
const int generatorPin = A0;   // 발전기 연결
const int led1 = 2;            // 첫 번째 LED (저전압)
const int led2 = 3;            // 두 번째 LED (중전압)
const int led3 = 4;            // 세 번째 LED (고전압)

float smoothedVoltage = 0;     // 부드러운 전압 변화를 위한 변수
float filterFactor = 0.1;      // 숫자가 낮을수록 LED가 천천히 반응함

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // 1. 교류 발전기의 피크(Peak) 전압 찾기
  int maxRaw = 0;
  for (int i = 0; i < 50; i++) {
    int val = analogRead(generatorPin);
    if (val > maxRaw) maxRaw = val;
    delay(1); 
  }

  // 2. 전압 계산 (0~5V)
  float currentVoltage = maxRaw * (5.0 / 1023.0);

  // 3. 필터를 적용해 전압 값을 부드럽게 (천천히 켜지고 꺼지게 함)
  smoothedVoltage = (currentVoltage * filterFactor) + (smoothedVoltage * (1.0 - filterFactor));

  // 4. 시리얼 모니터 확인용
  Serial.print("Voltage: ");
  Serial.println(smoothedVoltage);

  // 5. 단계별 점등 (발전기를 돌려보며 이 숫자들을 수정하세요)
  if (smoothedVoltage >= 0.5) digitalWrite(led1, HIGH); else digitalWrite(led1, LOW);
  if (smoothedVoltage >= 1.5) digitalWrite(led2, HIGH); else digitalWrite(led2, LOW);
  if (smoothedVoltage >= 2.5) digitalWrite(led3, HIGH); else digitalWrite(led3, LOW);

  delay(20); 
}