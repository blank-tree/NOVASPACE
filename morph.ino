/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.3
 */

// Constants
const int PIN_LINEARACTUATOR = 5; // Digital PWM Pin
const int LA_MIN = 1050;
const int LA_MAX = 2000;

// Variables
Servo linearactuator;

void morphSetup() {

	// init linear actuator object
	linearactuator.attach(PIN_LINEARACTUATOR, LA_MIN, LA_MAX);
	
}

void morphLoop() {
	
}

/**
 * Function to morph the linearactuator in a certain direction
 * @param boolean direction     // true = move up; false = move down;
 */
void morphUp(boolean direction) {

}