/**
* NOVASPACE - Proximity
* @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
* @date: 161025
* @version: 0.5
*/

// Constants
const int PIN_TRIG = 8;
const int PIN_ECHO = 9;
const int INTERVAL_SENSOR = 250;
const int INTERVAL_SENSOR_SEND = 2;
const int INTERVAL_SENSOR_RECEIVE = 10;

// Variables
int sensorStatus;
int sensorTimer;
unsigned long lastMeasurement;

void proximitySetup() {

	// init variables
	sensorStatus = 0;
	sensorTimer = 0;
	lastMeasurement = 0;
}

void proximityLoop() {

	// check if the last measurment is 
	if (currentTime - lastMeasurement > INTERVAL_SENSOR) {

		switch (sensorStatus) {

			case 0:
				// give a low output signal to the trigger
				digitalWrite(PIN_TRIG, LOW);

				updateSensorStatus();
				break;

			case 1:
				// has the necessary time passed?
				if (currentTime - sensorTimer > INTERVAL_SENSOR_SEND) {
					// give a high output signal to the trigger
					digitalWrite(PIN_TRIG, HIGH);

					updateSensorStatus();
				}
				break;

			case 2:
				// has the necessary time passed?
				if (currentTime - sensorTimer > INTERVAL_SENSOR_RECEIVE) {
					// give a low output signal to the trigger
					digitalWrite(PIN_TRIG, LOW);

					// read the pulse in of the previously given trigger
					long duration = pulseIn(PIN_ECHO, HIGH);

					// calculate the distance
					distance = (duration/2) / 29.1;

					updateSensorStatus();

					// prohibit the code to run again before the necessary time has passed
					lastMeasurement = currentTime;
				}
				break;
		}
	}
}

/**
 * updateSensorStatus Function
 * Used the the proximityLoop switch case to update and determine at which point in the
 * switch case we need to continue
 */
void updateSensorStatus() {
	sensorStatus = sensorStatus + 1 > 2 ? 0 : sensorStatus + 1;
	sensorTimer = currentTime;
}