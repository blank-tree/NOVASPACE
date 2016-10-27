/**
 * NOVASPACE
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161027
 * @version: 0.18
 */

// Includes
#include <Servo.h>
#include "DualVNH5019MotorShield.h"

// Constants
const int INTERVAL_UPDATE_MORPH = 125; // in ms
const int INTERVAL_UPDATE_LS = 375; // in ms
const int EMPTY_DISTANCE = 50; // in cm

// Variables
unsigned long currentTime;
unsigned long lastUpdateMorph;
unsigned long lastUpdateLS;
long distance;
boolean direction;

void setup() {

	// Start serial for debugging
	Serial.begin(9600);

	// init variables
	currentTime = 0;
	lastUpdateMorph = 0;
	lastUpdateLS = 0;
	distance = 100;
	direction = false;

	// start setup function of all other classes
	proximitySetup();
	morphSetup();
	// lightSetup();
	soundSetup();
}

void loop() {

	// save the current time in a variable
	currentTime = millis();

	// is the distance shorter than the empty distance
	direction = distance < EMPTY_DISTANCE;

	// get the current reading of the proximity sensor for the distance variable
	proximityLoop();

	// every morph interval activate the morph loop
	if (currentTime - lastUpdateMorph > INTERVAL_UPDATE_MORPH) {
		morphLoop();
		lastUpdateMorph = currentTime;
	}

	// every light and sound interval activate the light and sound loop
	if (currentTime - lastUpdateLS > INTERVAL_UPDATE_LS) {
		// lightLoop();
		soundLoop();
		lastUpdateLS = currentTime;
	}	
}
