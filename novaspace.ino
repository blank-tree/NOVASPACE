/**
 * NOVASPACE
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.10
 */

// Includes
#include <Servo.h>

// Constants


// Variables
unsigned long currentTime;
long distance;
boolean direction;

void setup() {

	// Start serial for debugging
	Serial.begin(9600);

	currentTime = 0;
	distance = 100;
	direction = false;

	proximitySetup();
	morphSetup();
}

void loop() {

	currentTime = millis();

	proximityLoop();
	morphLoop();
	
}