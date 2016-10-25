/**
 * NOVASPACE - Proximity
 * @author: Fernando Obieta - blanktree.ch
 * @date: 161025
 * @version: 0.4
 */

 const int PIN_TRIG = 6;
 const int PIN_ECHO = 5;
 const int INTERVAL_SENSOR = 250;
 const int INTERVAL_SENSOR_SEND = 2;
 const int INTERVAL_SENSOR_RECEIVE = 10;

 int sensorStatus;
 int sensorTimer;
 unsigned long lastMeasurement;

 void proximitySetup() {
 	sensorStatus = 0;
 	sensorTimer = 0;
 	lastMeasurement = 0;
 }

 void proximityLoop() {
 	if (currentTime - lastMeasurement > INTERVAL_SENSOR) {

 		long duration;

 		switch (sensorStatus) {

 			case 0:
			// give a low output signal to the trigger
			digitalWrite(PIN_TRIG, LOW);
			updateSensorStatus();
			break;

			case 1:
			if (currentTime - sensorTimer > INTERVAL_SENSOR_SEND) {
				digitalWrite(PIN_TRIG, HIGH);
				updateSensorStatus();
			}
			break;

			case 2:
			if (currentTime - sensorTimer > INTERVAL_SENSOR_RECEIVE) {
				digitalWrite(PIN_TRIG, LOW);
				duration = pulseIn(echoPin, HIGH);
				distance = (duration/2) / 29.1;
				updateSensorStatus();
			}
			break;
		}

		lastMeasurement = currentTime;

	}
}

void updateSensorStatus() {
	sensorStatus = sensorStatus + 1 > 2 ? 0 : sensorStatus + 1;
	sensorTimer = currentTime;
}