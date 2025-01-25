// Summery:     This is the code for the data Transmitter, which is specifically designed for HC12 TX/RX.  In this code, the data is specifically taken from a joystick as analog
//              input signal, which that data is processed from an integer to char value by simply leveraging the map function.  The main reason why is because the data is processed 
//              much faster by the receiver if its sent as a ASCII character rather than an integer value.

// importing the softwareSerial library, which is used to handle the comminucation between the HC12 and the arduino
#include <SoftwareSerial.h>

// Declearing the variables for pins and values

int yInput = A0;  // this is the variable for the input taken from the joystick
int yValue;       // this is the variable that specifically takes input from the y axis of the joystick
int mapY;         // creating a variable that maps the values from int into char later


// creating an object from the library and calling it HC12, which uses full parameters
SoftwareSerial HC12(3, 2); // setting up pin 3 as TX, while pin 2 has been set up as RX


void setup() {

// setting up the standard baut rate for both HC12 and serial monitor, which can be increased later
Serial.begin(9600);
HC12.begin(9600);

// defining the pin to be in INPUT mode
pinMode(yInput, INPUT);

}

void loop() {

  yValue = analogRead(yInput);
  mapY = map(yValue, 0, 1024, 48, 70);
  char convertChar = (char)(mapY);
  
  Serial.println(convertChar);
  HC12.println(convertChar);
  // since the print fucntion is buffered, we will make sure that all the data is flushed out of the array by using the flush function
  Serial.flush();

}
