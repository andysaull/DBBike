#include <Arduino.h>
#include "uss.h"

Uss::Uss(){};

void Uss::iniUss()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin_L, INPUT);
	pinMode(echoPin_R, INPUT);
	//pinMode(echoPin_F, INPUT);
	//pinMode(echoPin_B, INPUT);
}

void Uss::updateDistance()				//Update the duration variables
{
	//Setting it low for clear the trigger.
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	
	//Start the trigger for 10 microseconds.
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	//Read echoPins
	duration_l = pulseIn(echoPin_L, HIGH);
	duration_r = pulseIn(echoPin_R, HIGH);
}

int Uss::getDistance(int number_uss)	//Return calculation from the distances
{
	//Distance in centimeters
	int distance;
	
	//Calculate distance of uss
	switch(number_uss)
	{
		case USS_LEFT: //Declared on uss header (uss.h)
			distance = duration_l*0.034/2;
			break;
			
		case USS_RIGHT:
			distance = duration_r*0.034/2;
			break;
	}
	
	return distance;
}

/*
long duration;
int distance;

void setup() {
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(5);

 // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance:
  distance = duration*0.034/2;
  
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}
*/