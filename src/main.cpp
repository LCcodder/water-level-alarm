#include <Arduino.h>

#define _LED_INDICATOR_PIN 2
#define _BUZZER_PIN 4
#define _SENSOR_POWER_PIN 7
#define _SENSOR_READ_PIN A0
#define _SIGNAL_DELAY_MS 500

int water_level = 0;

void setup() {
  pinMode(_LED_INDICATOR_PIN, OUTPUT);
  pinMode(_BUZZER_PIN, OUTPUT);

  pinMode(_SENSOR_POWER_PIN, OUTPUT);
	digitalWrite(_SENSOR_POWER_PIN, LOW);

}


int readSensor() {
	digitalWrite(_SENSOR_POWER_PIN, HIGH);
	delay(10);			
	water_level = analogRead(_SENSOR_READ_PIN);	
	digitalWrite(_SENSOR_POWER_PIN, LOW);	
  
	return water_level;							
}


void loop() {
  int level = readSensor();
	
  if (level > 10) {
    digitalWrite(_LED_INDICATOR_PIN, HIGH);
    digitalWrite(_BUZZER_PIN, HIGH);

    delay(_SIGNAL_DELAY_MS);    

    digitalWrite(_LED_INDICATOR_PIN, LOW);
    digitalWrite(_BUZZER_PIN, LOW);
  }

	delay(_SIGNAL_DELAY_MS);  
}
