/**
 * NOVASPACE - Sound
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.4
 */

// Constants
const int PIN_SERVO_VOLUME = 6;
const int PIN_SERVO_CTRL1 = 7;
const int SOUND_VOLUME_FADE_UP = 5;
const int SOUND_VOLUME_FADE_DOWN = 10;
const int SOUND_CTRL1_FADE_UP = 15;
const int SOUND_CTRL1_FADE_DOWN = 30;

// Variables
Servo volume;
Servo ctrl1;
int volumeValue;
int ctrl1Value;

void soundSetup() {

	// init servo objects
	volume.attach(PIN_SERVO_VOLUME);
	ctrl1.attach(PIN_SERVO_CTRL1);

	// init all variables
	volumeValue = 0;
	ctrl1Value = 0;
}

void soundLoop() {
	
}