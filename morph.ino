/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.7
 */

// Constants
const int PIN_LINEARACTUATOR = 5; // Digital PWM Pin
const int LA_MIN = 1050;
const int LA_MAX = 2000;

// Variables
Servo linearactuator;
int LAvalue;

void morphSetup() {

	// init linear actuator object
	linearactuator.attach(PIN_LINEARACTUATOR, LA_MIN, LA_MAX);

	// init variables
	LAvalue = 0; // linear actuator value goes from 0 to 180

	// position the linear actuator
	morph();
	
}

void morphLoop() {
	
	// increase or decrease the linear actuator value and make sure
	// that the min of 0 and the max of 180 won't get overstepped 
	if (direction) {
		LAvalue = LAvalue + 2 > 180 ? 180 : LAvalue + 2;
	} else {
		LAvalue = LAvalue - 1 < 0 ? 0 : LAvalue - 1;
	}

	// position the linear actuator
	morph();
}

/**
 * Morph Function
 * Writes the linear actuator value to the linear actuator
 * also maps the value in the opposite direction (so that the
 * code makes more sense)
 */
void morph() {
	linearactuator.write(map(LAvalue, 0, 180, 180, 0));
}