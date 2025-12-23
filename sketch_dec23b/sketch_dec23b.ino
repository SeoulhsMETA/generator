//Master
#include <Wire.h>                       //라이브러리 추가
#define SLAVE 4
byte count = 'A';                       // 카운터
void setup() {
  Wire.begin(SLAVE);                    // Wire 라이브러리 초기화 ,슬레이브로 참여하기 위해서는 주소를 지정해야 한다.
  Wire.onRequest(sendToMaster);         // 마스터의 데이터 전송 요구가 있을 때 처리할 함수 등록
}
 
void loop () {
}
 
void sendToMaster() {
  Wire.write(++count);                     // 카운터 값을 증가시키고 마스터로 전송
  
  if(count >= 'z'){                     // 대문자'A'부터 소문자 'z'까지 하나씩 증가시키며 전송
    count = 'A';
  }
}
