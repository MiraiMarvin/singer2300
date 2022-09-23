#include <Arduino.h>
#include "pitches.h"


#define echoPin 2
#define trigPin 3

long duration;
int distance;
const int buzPin  = 7;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance delta: ");
  Serial.print(distance);
  Serial.println(" cm");

  int melodyOn[] = {NOTE_G1,NOTE_FS2,NOTE_F3,NOTE_E4,NOTE_DS5,NOTE_D6,NOTE_CS7,NOTE_C8};

  int durationOn = 100;
  if(distance <= 10){
    tone(buzPin, melodyOn[0], durationOn);
    delay(100);
  }
  if (distance>10 && distance<30)
  {
    tone(buzPin, melodyOn[1], durationOn);
    delay(100);
  }
    if (distance>30 && distance<50)
  {
    tone(buzPin, melodyOn[2], durationOn);
    delay(100);
  }
    if (distance>50 && distance<70)
  {
    tone(buzPin, melodyOn[3], durationOn);
    delay(100);
  }
    if (distance>70 && distance<90)
  {
    tone(buzPin, melodyOn[4], durationOn);
    delay(100);
  }
    if (distance>90 && distance<110)
  {
    tone(buzPin, melodyOn[5], durationOn);
    delay(100);
  }
    if (distance>110 && distance<120)
  {
    tone(buzPin, melodyOn[6], durationOn);
    delay(100);
  }
    if (distance>120 && distance<150)
  {
    tone(buzPin, melodyOn[7], durationOn);
    delay(100);
}
}
