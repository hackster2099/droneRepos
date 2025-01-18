#include <pigpio.h>
#include <iostream>
#include <unistd.h>  // For sleep() function
#include <termios.h>
#include <fcntl.h>




int hcTx = 14;
int hcRx = 15;
#define myLED 23

int  main() {

	if(gpioInitialise() < 0){

		std::cerr<<"gpio initialization failed"<<std::endl;
		return -1;

	}

	
	gpioSetMode(hcTx, PI_OUTPUT);
	gpioSetMode(hcRx, PI_INPUT);
	gpioSetMode(myLED,PI_INPUT);

	std::cerr<<"gpio is successfully initialized"<<std::endl;
	
	while (true ) {
			
		printf("this is the number: %i\n", hcRx);
		break;
	}
	
	gpioTerminate();
	return 0;
	

}
