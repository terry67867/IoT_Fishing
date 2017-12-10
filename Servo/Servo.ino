#include <Servo.h> 

Servo servo;

int servoPin = A2;
int angle = 0; // servo position in degrees 

void setup() 
{ 
  servo.attach(servoPin);
} 

void loop() 
{ 
  // rotate from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
