// Filename: lab2_gpio.cpp
#include "lab2_gpio.h"
#include <iostream>
#include <stdlib.h>

// ------------------------------------ Class Definitions ------------------------------------------

// Purpose: This function sets the pin mode for the desired pin mode
int lab2_gpio::pinMode(int pinNum, pinModes pMode)
{
	void *ptr_sel1, *ptr_read;
	unsigned long read_result, read_result2;

	if (pinNum<10)
	{
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL0; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);
	}
	
	else if(9<pinNum && pinNum<20)
	{
		// ---------------------------pins 10-19 ----------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL1; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum-10)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum-10)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);	
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else if(19<pinNum && pinNum<30)
	{
		// ---------------------------pins 20-29 ----------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL2; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum-20)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum-20)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(29<pinNum && pinNum<40)
	{
		// ---------------------------pins 30-39 ----------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL3; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum-30)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum-30)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(39<pinNum && pinNum<50)
	{
		// ---------------------------pins 40-49 ----------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL4; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum-40)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum-40)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(49<pinNum && pinNum<54)
	{
		// ---------------------------pins 50-53 ----------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL5; 
	
		//cast ptr_sel1 to read value at address
		read_result = *((unsigned long *)ptr_sel1);
	
		//current configuration of the pin selected
		printf("Current I/O Configuration %X \n", read_result);
	
		//pin position = 3*pinNum+shift
		//shift input mask over to pin selected
		read_result2 = pMode << ((pinNum-50)*3); 
	
		//create a mask to have all 0's in place of pin position
		unsigned long bitmask = ~(GP_MASK<<((pinNum-50)*3)); 
	
		//take the current config and zero out pin selected
		unsigned long filtSelect = read_result & bitmask; 
	
		//create new config, only pin selected is changed
		unsigned long newSelect = filtSelect | read_result2;
	
		//now write
		*((unsigned long *)ptr_sel1) = newSelect;

		printf("Pin %d configuration %X \n",pinNum, read_result2);
		printf("Bitmask for pin is %X \n", bitmask);
		printf("New configuration is %X \n", newSelect);
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}	
	return 0;
}

int lab2_gpio::pinModeRead(int pinNum, pinModes pMode)
{
// Purpose: This function reads the current pin mode of pinNum and compares it to the 
//		   desired pin mode pMode, returns 1 if it matches and -1 if it does not

	void *ptr_sel1, *ptr_base;
	unsigned long desired_result, read_result;

	if (pinNum<10)
	{
		// ---------------------------pins 0-9 -------------------------------------------
		//get the address of the the pin position
		ptr_sel1 = ptr_base+(off_t)GPFSEL0; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << 3*pinNum;

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<pinNum*3); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else if(9<pinNum && pinNum<20)
	{
		// ---------------------------pins 10-19 ----------------------------------------
		ptr_sel1 = ptr_base+(off_t)GPFSEL1; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << (3*(pinNum-10));

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<((pinNum-10)*3)); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else if(19<pinNum && pinNum<30)
	{
		// ---------------------------pins 20-29 ----------------------------------------
		ptr_sel1 = ptr_base+(off_t)GPFSEL2; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << (3*(pinNum-20));

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<((pinNum-20)*3)); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(29<pinNum && pinNum<40)
	{
		// ---------------------------pins 30-39 ----------------------------------------
		ptr_sel1 = ptr_base+(off_t)GPFSEL3; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << (3*(pinNum-30));

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<((pinNum-30)*3)); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(39<pinNum && pinNum<50)
	{
		// ---------------------------pins 40-49 ----------------------------------------
		ptr_sel1 = ptr_base+(off_t)GPFSEL4; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << (3*(pinNum-40));

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<((pinNum-40)*3)); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(49<pinNum && pinNum<54)
	{
		// ---------------------------pins 50-53 ----------------------------------------
		ptr_sel1 = ptr_base+(off_t)GPFSEL5; 

		//ptr_read = ptr_base+(off_t)GPIO_READ0;
		read_result = *((unsigned long *)ptr_sel1);
		
		//current configuration
		desired_result = pMode << (3*(pinNum-50));

		//create a mask to have all 1's in place of pin position
		unsigned long bitmask = (GP_MASK<<((pinNum-50)*3)); 
	
		//take the current config and one out pin selected
		unsigned long filtSelect = read_result & bitmask;
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}	
	return 0;
}


int lab2_gpio::digitalRead(int pinNum)
{
// Purpose: This function reads the value of the pin pinNum and returns 1 if high and 
//		   0 if low, if it is neither then return -1.
	unsigned long bitHigh, pinNvalue, read_result;
	void *ptr_base, *ptr_read;

	if (0<= pinNum && pinNum<32)
	{
		// ---------------------------pins 0-31 -------------------------------------------
		ptr_read = ptr_base+(off_t)GPIO_READ0; //read pointer, header file has #define GPIO_READ0 0x0034
		read_result = *((unsigned long*)ptr_read);

		//shift input mask over to pin selected
		bitHigh = 1 << pinNum;

		pinNvalue = bitHigh & read_result;
		// -----------------------------------------------------------------------------------------------------------------------
		if (pinNvalue == 1)  return 1;
		else if(pinNvalue == 0) return 0;
		else{
			printf("Read value of pin %d is %X pinNvalue \n", pinNum, pinNvalue);
			return -1;
		}
	}
	else if(31< pinNum && pinNum<54)
	{
		// ---------------------------pins 32-53 -----------------------------------------
		ptr_read = ptr_base+(off_t)GPIO_READ1; //read pointer, header file has #define GPIO_READ0 0x0034
		read_result = *((unsigned long*)ptr_read);

		//shift input mask over to pin selected
		bitHigh = 1 << pinNum;

		pinNvalue = bitHigh & read_result;
		// -----------------------------------------------------------------------------------------------------------------------
		if (pinNvalue == bitHigh)  return 1;
		else	if(pinNvalue == 0) return 0;
		else{
			printf("Read value of pin %d is %X pinNvalue\n", pinNum, pinNvalue);
			return -1;
		}
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}
}

int lab2_gpio::digitalWrite(int pinNum, outValue out_v)
{
// Purpose: This function first checks that the pin mode of the pin you wish to write to 
// 		   is set to OUTPUT. It then writes high or low to the pin.

	unsigned long read_result, read_result2, pMask, pMask2;
	void *ptr_read, *ptr_base, *ptr_write_H, *ptr_write_L;

	int status = lab2_gpio::pinModeRead(pinNum, OUTPUT);

	if(status == -1) 
	{
		printf("Pin mode is not in output mode\n");
		return -1;
	}
	if (0<= pinNum && pinNum<32)
	{
		if(out_v == HIGH)
		{
		// ---------------------------pins 0-31 HIGH -------------------------------------------
			//get the address of the the pin position
			ptr_read = ptr_base+(off_t)GPIO_HIGH0; 
	
			read_result = *((unsigned long *)ptr_read);

	
			//shift input mask over to pin selected. 1 for high
			pMask = 1<< pinNum; //1 bit per pin 
			//pMask = read_result2 | read_result;

			pMask2 = read_result &  pMask;

			*((unsigned long *)ptr_read) = pMask2;
			
			printf("test1 high \n");
			//ptr_write_H = ptr_base +(off_t)GPIO_HIGH0; //write high pointer??
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
		else if(out_v == LOW)
		{
		// ---------------------------pins 0-31 LOW-------------------------------------------
			printf("test2 low \n");
			//get the address of the the pin position
			ptr_read = ptr_base+(off_t)GPIO_LOW0; 
	
			read_result = *((unsigned long *)ptr_read);
	
			//shift input mask over to pin selected. 1 for high
			pMask = 1<< pinNum; //1 bit per pin 
			//pMask = read_result2 | read_result;

			pMask2 = read_result &  pMask;

			*((unsigned long *)ptr_read) = pMask2;
			//ptr_write_L = ptr_base+(off_t)GPIO_LOW0; //write low pointer
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
	}
	else if(31< pinNum && pinNum<54)
	{
		if(out_v == HIGH)
		{
		// ---------------------------pins 0-31 -------------------------------------------
			//get the address of the the pin position
			ptr_read = ptr_base+(off_t)GPIO_HIGH1; 
	
			read_result = *((unsigned long *)ptr_read);
	
			//shift input mask over to pin selected. 1 for high
			pMask = 1<< pinNum; //1 bit per pin 
			//pMask = read_result2 | read_result;

			pMask2 = read_result &  pMask;

			*((unsigned long *)ptr_read) = pMask2;
			//ptr_write_L = ptr_base+(off_t)GPIO_LOW0; //write low pointer
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
		else if(out_v == LOW)
		{
		// ---------------------------pins 32-53-------------------------------------------
			//get the address of the the pin position
			ptr_read = ptr_base+(off_t)GPIO_LOW1; 
	
			read_result = *((unsigned long *)ptr_read);
	
			//shift input mask over to pin selected. 1 for high
			pMask = 1<< pinNum; //1 bit per pin 
			//pMask = read_result2 | read_result;

			pMask2 = read_result &  pMask;

			*((unsigned long *)ptr_read) = pMask2;
			//ptr_write_L = ptr_base+(off_t)GPIO_LOW0; //write low pointer
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
	}
	else{
		printf("Pin number  %d out of range \n", pinNum);
		return -1;
	}
}
