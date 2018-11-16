#ifndef ACS712_h
#define ACS712_h

#include <Arduino.h>

#define ADC_SCALE 1023.0
#define VREF 5.0
#define DEFAULT_FREQUENCY 50

enum ACS712_type {ACS712_05B, ACS712_20A, ACS712_30A};

class ACS712 {
public:
	ACS712(ACS712_type type, uint8_t _pin);
	int calibrate();
	void setZeroPoint(int _zero);
	void setSensitivity(float sens);
	float getCurrentDC();
	float getCurrentAC();
	float getCurrentAC(uint16_t frequency);

private:
	float zero = 512.0;
	float sensitivity;
	uint8_t pin;
};

#endif