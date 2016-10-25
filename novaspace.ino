/**
 * NOVASPACE
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.9
 */

unsigned long currentTime;
long distance;

void setup() {

	// Start serial for debugging
	Serial.begin(9600);
	
	currentTime = 0;
	distance = 100;

	proximitySetup();
}

void loop() {

	currentTime = millis();

	proximityLoop();
	
}