 
String myString=""; //받는 문자열
 
void setup() {
  Serial.begin(115200);  //initial the Serial 
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);              // 5번핀을 출력모드로 설정합니다.
  pinMode(A2, OUTPUT);              // 6번핀을 출력모드로 설정합니다.
  pinMode(A3, OUTPUT);             // 10번핀을 출력모드로 설정합니다.
  pinMode(A4, OUTPUT);           // 11번핀을 출력모드로 설정합니다.
}

void loop() {
  while(Serial.available())  
  {
    char myChar = (char)Serial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }  
    //Serial.write(Serial.read());//send what has been received
    //Serial.println();   //print line feed character
    
  if(!myString.equals(""))  //myString 값이 있다면
  {
      Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
//Motor Control -----------------------------
   if(myString=="m")  //myString 값이 'on' 이라면
   {
    analogWrite(A1, 0);                   // 5번핀에 0(약 3V)의 신호를 출력합니다.
    analogWrite(A2, 150);              // 6번핀에 150(0V)의 신호를 출력합니다.
    analogWrite(A3, 0);                  // 9번핀에 0(약 3V)의 신호를 출력합니다.
    analogWrite(A4, 150);           // 10번핀에 150(0V)의 신호를 출력합니다.
    delay(3000);                           // 3초간 대기
    analogWrite(A1, 150);             // 5번핀에 150(약 3V)의 신호를 출력합니다.
    analogWrite(A2, 0);                 // 6번핀에 0(0V)의 신호를 출력합니다.
    analogWrite(A3, 150);            // 9번핀에 150(약 3V)의 신호를 출력합니다.
    analogWrite(A4, 0);              // 10번핀에 0(0V)의 신호를 출력합니다.
    delay(3000);                         // 3초간 대기
   }
   
 //LED Control--------------------------------------------
      if(myString=="on")  //myString 값이 'on' 이라면
      {
        analogWrite(A0, 255); //LED ON

       analogWrite(A1, 0);                   // 5번핀에 0(약 3V)의 신호를 출력합니다.
    analogWrite(A2, 150);              // 6번핀에 150(0V)의 신호를 출력합니다.
    analogWrite(A3, 0);                  // 9번핀에 0(약 3V)의 신호를 출력합니다.
    analogWrite(A4, 150);           // 10번핀에 150(0V)의 신호를 출력합니다.
    delay(3000);                           // 3초간 대기
    analogWrite(A1, 150);             // 5번핀에 150(약 3V)의 신호를 출력합니다.
    analogWrite(A2, 0);                 // 6번핀에 0(0V)의 신호를 출력합니다.
    analogWrite(A3, 150);            // 9번핀에 150(약 3V)의 신호를 출력합니다.
    analogWrite(A4, 0);              // 10번핀에 0(0V)의 신호를 출력합니다.
    delay(3000);                         // 3초간 대기
      } else {
        analogWrite(A0, 0);  //LED OFF
      }
    myString="";  //myString 변수값 초기화   //입력된 문자열 없애고 초기화하여 문자열 입력대기
  }
}




