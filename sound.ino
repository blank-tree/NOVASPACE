/**
 * NOVASPACE - Sound
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161027
 * @version: 0.6
 */

// Constants
const int PIN_SERVO_VOLUME = A5;
const int PIN_SERVO_CTRL1 = A4;
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

	// increase or decrease the volume and ctrl1 values and make sure
	// that the min of 0 and the max of 180 won't get overstepped 
	if (direction) {
		volumeValue = volumeValue + SOUND_VOLUME_FADE_UP > 180 ? 180 : volumeValue + SOUND_VOLUME_FADE_UP;
		ctrl1Value = ctrl1Value + SOUND_VOLUME_FADE_UP > 180 ? 180 : ctrl1Value + SOUND_CTRL1_FADE_UP;
	} else {
		volumeValue = volumeValue - SOUND_VOLUME_FADE_DOWN < 0 ? 0 : volumeValue - SOUND_VOLUME_FADE_DOWN;
		ctrl1Value = ctrl1Value - SOUND_VOLUME_FADE_DOWN < 0 ? 0 : ctrl1Value - SOUND_CTRL1_FADE_DOWN;
	}

	// Write the values to the servos
	volume.write(volumeValue);
	ctrl1.write(ctrl1Value);

}