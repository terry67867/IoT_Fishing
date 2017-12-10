//millis틀
int blink_en = 1;
int fading_en = 1;
int blinkRGB_en = 1;
int fadingRGB_en = 1;

void setup(){
  blink_setup();
  fading_setup();
  blinkRGB_setup();
  fadingRGB();

  serial_setup();
}

void loop(){
  if(blink_en == 1;)
    blink_loop();
  if(fading_en == 1)
    fading_loop();
  if(blinkRGB_en == 1)
    blinkRGB_loop();
  if(fadingRGB_en == 1)
    fadingRGB_loop();

  serial_loop();
  }
}

int blink_ledState = LOW;

long previousMIllis = 0;
long interval = 1000;

void blink_setup() {pinMode(13, OUTPUT);}

void blink_loop(){
  unsigned long currentMillis = millis();

  if(currentMIllis - blink_previousMillis >= blink_interval){
    blink_previousMillis = currentMillis;

    if(blink_ledState == LOW)
      blink_ledState = HIGH;
    else
      blink_ledState = LOW;

    digitalWrite(13, blink_ledState);
    //주기적인 작업
  }
}
