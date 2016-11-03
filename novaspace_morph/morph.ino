/**
 * NOVASPACE - Morph
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161101
 * @version: 0.20
 */

// Constants
const int MORPH_FADE_UP = 1800;
const int MORPH_FADE_DOWN = 2500;
const int MORPH_BREATH_INTERVAL = 1000;

// Variables
DualVNH5019MotorShield linearactuator;
int LAvalue;
unsigned long fadeTimer;
int fadeStatus;
int currentMorphDirection;
int lastDirection;

void morphSetup() {

	// init linear actuator object
	linearactuator.init();

	// init variables
	LAvalue = 0; // linear actuator value goes from 0 to 180
	fadeTimer = 0;
	fadeStatus = 0;
	lastDirection = 0;
	currentMorphDirection = 0;
	
}

void morphLoop() {
 
	LAvalue = direction ? 400 : -400;


	// compare last direction to current direction
	if (lastDirection != direction) {
		// reset fade process and timer
		fadeStatus = 0;
		fadeTimer = currentTime;
	}

	// assign lastDirection to current direction for the next loop comparison
	lastDirection = direction;

	if (fadeStatus) {
		currentMorphDirection = 1;

		fadeProcess(direction ? MORPH_FADE_UP : MORPH_BREATH_INTERVAL);
	} else {
		currentMorphDirection = 0;

		fadeProcess(direction ? MORPH_BREATH_INTERVAL : MORPH_FADE_DOWN);
	}

	LAvalue = currentMorphDirection ? 400 : -400;

	// position the linear actuator
	linearactuator.setM1Speed(LAvalue);
}

void morphIdle() {

}

void fadeProcess(int interval) {
	if (currentTime - fadeTimer > interval) {
		fadeStatus = !fadeStatus;
		fadeTimer = currentTime;
	}
}