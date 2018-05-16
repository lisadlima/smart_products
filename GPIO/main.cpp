// Filename: lab2_Q1.cpp 
// Compile using the terminal command: 
// -----------------------------------------------------------------------------------------------------------------------------------------
//       sudo g++ -o lab2_Q1 lab2_Q1.cpp lab2_gpio.cpp lab2_gpio.h 
// -----------------------------------------------------------------------------------------------------------------------------------------
#include "lab2_gpio.h"
#include <stdio.h>
#include<iostream>

int main()
{
	// Start the pin control session for memory mapping
	lab2_gpio Sess; // enables the constructor
	int pin_num = 17; // pin to control

	Sess.pinMode(pin_num, OUTPUT);// set the pinmode for output on pin 27

	Sess.digitalWrite(pin_num, LOW); // initally write set the pin to low 
	
	int pin_val = Sess.digitalRead(pin_num); // read the value of the pin

	std::cout<<"Value of pin "<<pin_num<< " is  " <<  pin_val <<std::endl; 
	Sess.digitalWrite(pin_num, HIGH); //write high to pin pin_num 
	pin_val = Sess.digitalRead(pin_num);// read the pin pin_num
	std::cout<<"Value of pin "<<pin_num<< " is  " <<  pin_val <<std::endl;

	Sess.~lab2_gpio();// invoke the destructor and unmap the address
	return 0;
}
