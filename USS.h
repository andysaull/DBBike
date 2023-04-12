/*
Made by Andy Saull:
USS is a class for reading various Ultra Sonic Sensor JSN-SR04T.

The module sensor must be triggered by sending a pulse for 10 microseconds in the TRIGGER pin.
Then, it sends a 40 kHz pulse and wait for a response, the width of the echo response can be transformed to the final distance.

Using: https://www.makerguides.com/es/jsn-sr04t-arduino-tutorial/
*/

#define USS_LEFT 1		//Name for left sensor
#define USS_RIGHT 2		//Name for right sensor
//#define USS_TOP 3		//Maybe in the future sensor for detect front cars.
//#define USS_BOTTOM 4

#define trigPin 27
#define echoPin_L 14
#define echoPin_R 12
//#define echoPin_F 3
//#define echoPin_B 4

class Uss
{
	private:
	
	//Duration from the pulse received from module
	long duration_l;
	long duration_r;
	//long duration_t;
	//long duration_b;
	
	public:
	
	Uss();
	void iniUss();						//Setup for pins
	void updateDistance();				//Update the duration variables
	int getDistance(int number_uss);	//Return calculation from the distances
};