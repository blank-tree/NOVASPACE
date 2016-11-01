/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161101
 * @version: 0.24
 */

// Includes
#include "DualVNH5019MotorShield.h"

// Constants
const int INTERVAL_UPDATE_MORPH = 125; // in ms
const int INTERVAL_UPDATE_LS = 375; // in ms
const int EMPTY_DISTANCE = 150;

// Variables
unsigned long currentTime;
unsigned long lastUpdateMorph;
long distance;
boolean direction;

// Testing

void setup() {

	// Start serial for debugging
	Serial.begin(9600);

	// init variables
	currentTime = 0;
	lastUpdateMorph = 0;
	distance = 100;
	direction = false;

	// start setup function of all other classes
	proximitySetup();
	morphSetup();
}

void loop() {

	// save the current time in a variable
	currentTime = millis();

	// is the distance shorter than the empty distance
	direction = distance > EMPTY_DISTANCE;

	// get the current reading of the proximity sensor for the distance variable
	proximityLoop();

	morphLoop();
}
