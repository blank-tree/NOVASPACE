/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161028
 * @version: 0.14
 */

// Constants
const int MORPH_MIN = -1000;
const int MORPH_MAX = 1000;
const int MORPH_FADE_UP = 200;
const int MORPH_FADE_DOWN = -100;

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
	
  /* old functionality. new version underneath

	// increase or decrease the linear actuator value and make sure
	// that the min and the max won't get overstepped 
	if (direction) {
		LAvalue = LAvalue < 0 ? 0 : LAvalue;
		LAvalue = LAvalue + MORPH_FADE_UP > MORPH_MAX ? MORPH_MAX : LAvalue + MORPH_FADE_UP;
	} else {
		LAvalue = LAvalue > 0 ? 0 : LAvalue;
		LAvalue = LAvalue + MORPH_FADE_DOWN < MORPH_MIN ? MORPH_MIN : LAvalue + MORPH_FADE_DOWN;
	}
  */
 
  LAvalue = direction ? 400 : -400;

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
