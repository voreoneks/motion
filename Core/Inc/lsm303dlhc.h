#pragma once
#include "stdint.h"

uint8_t SendDataI2C(uint8_t reg, uint8_t data);
uint8_t RecieveDataI2C(uint8_t reg);
void GetData(int8_t *array, int8_t *low, int8_t *high, int8_t size, uint8_t slaveAdress);
int16_t ShiftValue(uint8_t high, uint8_t low);
void Accel_Init();
struct Accel_Type 
{
	int8_t XYZ_High[3];
	int8_t XYZ_Low[3];
	int8_t XYZ[3];
};

struct Magnetic_Type
{
	int8_t XYZ_High[3];
	int8_t XYZ_Low[3];
	int8_t XYZ[3];
	int16_t temp;
	int8_t temp_low;
	int8_t temp_high;
};