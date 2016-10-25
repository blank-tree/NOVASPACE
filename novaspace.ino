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

	// init variables
	currentTime = 0;
	distance = 100;
	direction = false;

	// start setup function of all other classes
	proximitySetup();
	morphSetup();
}

void loop() {

	// save the current time in a variable
	currentTime = millis();

	// activate all other loops of the other classes
	proximityLoop();
	morphLoop();
	
}