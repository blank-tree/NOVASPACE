/**
 * NOVASPACE - Light
 * @author: Fernando Obieta - blanktree.ch, Lukas Siegele & Fabrice Spahn
 * @date: 161025
 * @version: 0.5
 */

// Constants
const int LEDS_ARRAYSIZE = 3;
const int PINS_LEDS[LEDS_ARRAYSIZE] = {4, 5, 6}; // analog pins
const int LEDS_FADE_UP = 5;
const int LEDS_FADE_DOWN = 3;

// Variables
int LED_VALUES[LEDS_ARRAYSIZE];

void lightSetup() {

	for(int i=0; i<;LEDS_ARRAYSIZE i++){

		// init all leds as output
		pinMode(PINS_LEDS, OUTPUT);

		// init all variables
	    LED_VALUES[i] = 0;
	}
	
}

void lightLoop() {

	// count up or down?
	if (direction) {

		// iterate through all leds
		for(int i=0; i< LEDS_ARRAYSIZE; i++){

			// randomize if the value gets changed
			if (random(1)) {

				// increase or decrease the LED value and make sure
				// that the min of 0 and the max of 255 won't get overstepped 
				LED_VALUES[i] = LED_VALUES[i] + LEDS_FADE_UP > 255 ? 255 : LED_VALUES[i] + LEDS_FADE_UP;
			}
		    
		}
	} else {

		// iterate through all leds
		for(int i=0; i< LEDS_ARRAYSIZE; i++){

			// randomize if the value gets changed
			if (random(1)) {

				// increase or decrease the LED value and make sure
				// that the min of 0 and the max of 255 won't get overstepped 
				LED_VALUES[i] = LED_VALUES[i] - LEDS_FADE_DOWN < 0 ? 0 : LED_VALUES[i] - LEDS_FADE_DOWN;
			}
		}
	}

	// activate all leds with the correct brightness
	for(int i=0; i<LEDS_ARRAYSIZE; i++){
	    analogWrite(PINS_LEDS[i], LED_VALUES[i]);
	}
	
}