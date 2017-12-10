#include <TimerOne.h>

void setup() {
  Serial.begin(115200);
  //pinMode(13, OUTPUT);
  
  Timer1.initialize(100000); //타이머 간격을 100000us로 설정)  0.1초
  Timer1.attachInterrupt(timerIsr);//초당 10번 timerlsr이 인터럽트 신호에 의해 호출된다.
}

void loop() {
  //digitalWrite(13,digitalRead(13)^1);
  noInterrupts(); //동시에 발생 안되도록 설정
  Serial.println("| ");
  interrupts();
}

void timerIsr(){
  Serial.println(" ]");
}

