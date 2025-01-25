// Summery:	This is a program written in C++ for Raspberry pi Computers in C++, which its purpose is to find the 
// 		address of the system peripherals that are connected to the raspberry pi and use I2C as the method
// 		of Serial Communication.  This Code leverages the pigpio library, which is an advance library that is intended 
// 		for high level control over the GPIO pins such as PWM.  The rest of the libraries are the standard C++ 
// 		Libraries.



#include <iostream>
#include <pigpio.h>
#include <unistd.h>


// creating two constant values, which its the domain of the addresses being analyzed
const int START_ADDR = 0x03;
const int END_ADDR = 0x77;


// this is the main function, which would check all the available devices for I2C communication

int main() {


	// if the gpio is not succcesfully initialized, display the error massage
	if (gpioInitialise() < 0){

		std::cerr << "GPIO initialization failed" << std::endl;

	}
		

	
	std::cout << "Initialization of GPIO worked" << std::endl;
	
	// begin analyzing all the i2c Addresses available using a for loop	
	for ( int addrs = START_ADDR; addrs <= END_ADDR; addrs++){
		
		// handle is the variable associated with the available i2c pin	
		// status is the variable associated with reading a byte from the i2c pin, which if connected, it will return non zero integer
		int handle = i2cOpen(1, addrs, 0);
		int status = i2cReadByte(handle);

		if (status > 0){

			std::cout << "Found Address at 0x" << addrs << std::endl;
			i2cClose(handle);
			usleep(10000);

		}

		else {

			std::cout << "NO address found at 0x" << addrs << std::endl;
			i2cClose(handle);
			usleep(10000);

		}



	}

	gpioTerminate();
	return 0;

}


