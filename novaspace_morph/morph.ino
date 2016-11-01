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
 
	LAvalue = direction ? 400 : -400;

	// position the linear actuator
	linearactuator.setM1Speed(LAvalue);
}