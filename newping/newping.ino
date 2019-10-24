#include <NewPing.h>
#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 200
int LedPin = 13;
int value = 0; // value is a variable that we'll use for our distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // this makes our call-sign, to get into the newping library
void setup()
{
	pinMode(LedPin, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	value = sonar.ping_cm(); // it gets the distance and saves it as "value"
	delay(50);
	Serial.println(value); // prints the distance back to you
	delay(50);
	// now you need to write an IF statment, and do something with it, like flash an LED
	// or move a servo
	// if distance goes past 10 cm turn on LED
	if (value != 0 && value < 200)
	{
		if (value < 10)
		{
			digitalWrite(LedPin, HIGH);
		}
		if (value > 10)
			digitalWrite(LedPin, LOW);
		{
			analogWrite(LedPin, value * 5);
		}
	}
}
