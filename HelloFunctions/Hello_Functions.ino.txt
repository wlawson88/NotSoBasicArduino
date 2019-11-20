//Alden Dent 
//Hello Functions

#include <Servo.h>
#include "Arduino.h"
#include <Wire.h>
const int trigPin = 3;
const int echoPin = 2;
Servo servo1;
void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	servo1.attach(7);
	Serial.begin(9600);
}

void loop()
{
Serial.println(GetDistance());
rotate();
delay(200);
}

int GetDistance(){
	long duration;
	int distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	//distanceCm = duration * 0.0340 / 2;
	distance = duration * 0.01330 / 2;	//Turns the length of time into distance
	return distance;
}

void rotate(){
	servo1.write(GetDistance()*15);

}