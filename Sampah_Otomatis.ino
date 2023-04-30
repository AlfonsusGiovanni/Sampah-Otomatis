#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  A0  
#define ECHO_PIN     A1
#define MAX_DISTANCE 100
 
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); 
  myservo.attach(10);
}

void loop() { 
  int jarak = 0;
  jarak = sonar.ping_cm();
  
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.print("cm");

  myservo.write(180);

  if(jarak>0&&jarak<50){
    Serial.println("Buka pintu!!!!!");

    myservo.write(0); 
  }

  delay(50);
}
