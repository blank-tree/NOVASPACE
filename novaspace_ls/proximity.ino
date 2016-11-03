/**
* NOVASPACE - Proximity
* @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
* @date: 161101
* @version: 0.10
*/

// Constants
const int PIN_PROXIMITY = A4;
const int INTERVAL_SENSOR = 250;

// Variables
unsigned long lastMeasurement;

void proximitySetup() {

	// init variables
	lastMeasurement = 0;
}

void proximityLoop() {

	// check if the last measurment is 
	if (currentTime - lastMeasurement > INTERVAL_SENSOR) {

		distance = analogRead(PIN_PROXIMITY);

		// Serial.println(distance);

		lastMeasurement = currentTime;
	}
}