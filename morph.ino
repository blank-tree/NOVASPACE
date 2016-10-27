/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161027
 * @version: 0.8
 */

// Constants
const int MORPH_MIN = -1000;
const int MORPH_MAX = 1000;
const int MORPH_FADE_UP = 2;
const int MORPH_FADE_DOWN = -1;

// Variables
DualVNH5019MotorShield linearactuator;
int LAvalue;

void morphSetup() {

	// init linear actuator object
	linearactuator.init();

	// init variables
	LAvalue = 0; // linear actuator value goes from 0 to 180

	// position the linear actuator
	morph();
	
}

void morphLoop() {
	
	// increase or decrease the linear actuator value and make sure
	// that the min of 0 and the max of 180 won't get overstepped 
	if (direction) {
		LAvalue = LAvalue < 0 ? 0 : LAvalue;
		LAvalue = LAvalue + MORPH_FADE_UP > MORPH_MAX ? MORPH_MAX : LAvalue + MORPH_FADE_UP;
	} else {
		LAvalue = LAvalue > 0 ? 0 : LAvalue;
		LAvalue = LAvalue + MORPH_FADE_DOWN < MORPH_MIN ? MORPH_MIN : LAvalue + MORPH_FADE_DOWN;
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
	linearactuator.setM1Speed(LAvalue);
}