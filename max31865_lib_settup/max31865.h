/*
 * max31865.h
 *
 * Created: 22-Dec-18 17:30:56
 *  Author: Edwin
 */ 


#ifndef MAX31865_H_
#define MAX31865_H_
#include <stdint.h>

typedef void (*fptr_t) ();

typedef struct
{
	fptr_t selectChip;
	fptr_t unselectChip;
	uint16_t rtd;
	uint16_t rref;
	uint16_t lowFaultThreshold;
	uint16_t highFaultThreshold;
	uint8_t configReg;
}max31865_t;

//////////////////////////////////////////////////////////////////////////

void max31865_SPIsetup();

void max31865_configDevice(max31865_t device);

uint16_t max31865_readADC(max31865_t device);

float max31865_readRTD(max31865_t device);

float max31865_readCelsius(max31865_t device);

float max31865_readKelvin(max31865_t device);

void max31865_setHighFaultThreshold(max31865_t device, uint16_t threshold);

void max31865_setLowFaultThreshold(max31865_t device, uint16_t threshold);

int8_t max31865_checkThresholdFault(max31865_t device);

void max31865_clearFault(max31865_t device);

#endif /* MAX31865_H_ */