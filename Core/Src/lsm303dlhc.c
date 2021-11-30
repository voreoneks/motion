#include "lsm303dlhc.h"
#include "gpio.h"
#include "stm32f3xx_ll_i2c.h"
#include "stm32f3xx_it.h"


uint8_t SendDataI2C(uint8_t reg, uint8_t data)
{
	while (LL_I2C_IsActiveFlag_BUSY(I2C1)) ;
	LL_I2C_TransmitData8(I2C1, reg);
	LL_I2C_HandleTransfer(I2C1, 0b0011001 << 1, LL_I2C_ADDRSLAVE_7BIT, 2, LL_I2C_MODE_AUTOEND, LL_I2C_GENERATE_START_WRITE);
	while (!LL_I2C_IsActiveFlag_TXIS(I2C1));
	LL_I2C_TransmitData8(I2C1, data);
		
	return 0;
} 

uint8_t RecieveDataI2C(uint8_t reg)
{	
	while (LL_I2C_IsActiveFlag_BUSY(I2C1)); //Check the I2C bus
	
	LL_I2C_TransmitData8(I2C1, reg); //Prepare a hardware adress where read 
	LL_I2C_SetSlaveAddr(I2C1, 0b0011001 << 1); //Write slave adress. Leave first bit for read/write bit (setting automaticly)
	LL_I2C_SetTransferRequest(I2C1, LL_I2C_REQUEST_WRITE); //Set direction of transfer
	LL_I2C_SetTransferSize(I2C1, 2); //Set size (slave adress + hardware adress)
	
	LL_I2C_GenerateStartCondition(I2C1); //Start transfer
	while (!LL_I2C_IsActiveFlag_TXIS(I2C1)) ; //Wait full transmit
	LL_I2C_GenerateStopCondition(I2C1); //Stop transfer
	
	
	while (LL_I2C_IsActiveFlag_BUSY(I2C1)); //Check the I2C bus
	
	LL_I2C_SetSlaveAddr(I2C1, 0b0011001 << 1); //Write slave adress. Leave first bit for read/write bit (setting automaticly)
	LL_I2C_SetTransferRequest(I2C1, LL_I2C_REQUEST_READ); //Set direction of transfer
	LL_I2C_SetTransferSize(I2C1, 1); //Set size of read bytes
	LL_I2C_GenerateStartCondition(I2C1); //Start transfer
	
	while (!LL_I2C_IsActiveFlag_RXNE(I2C1)); //Wait full receiving
	LL_I2C_GenerateStopCondition(I2C1); //Stop transfer
	return LL_I2C_ReceiveData8(I2C1); //Get receiving data
} 

void Accel_Init()
{
	SendDataI2C(0x20, 0x77); //CTRL_REG1_A
	SendDataI2C(0x21, 0xB4); //CTRL_REG2_A
	SendDataI2C(0x23, 0x88); //CTRL_REG4_A
}


int16_t ShiftValue(uint8_t high, uint8_t low)
{
	int16_t output = 0;
	output = (((int16_t) low) << 4) | high;
	return output;
}

