/*******************************************************
 * C++ Example code for Traffic Signal Simulation using
 * Beaglebone Black running Debian 7 Linux distribution
 ********************************************************
 * Developed by MicroEmbedded Technologies
 *******************************************************/


/* ######################################################################
 * 	NOTES:
 * 	~~~~~~~~
 * 	1) 	Each traffic signal light has a particular LED associated with it
 * 		And each LED has particular GPIO PIN associted with it.
 * 		e.g.
 * 			traffic signal		LED		 	GPIO PIN
 * 			------------------------------------------
 * 			NORTH_GREEN 	= 	LED_1 	=	GPIO0_3
 *			NORTH_YELLOW	= 	LED_5	=	GPIO1_17
 *				...				 ...		  ...
 *				so				 and 		   so
 * ######################################################################
 */


/* standard C++ header files */
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<csignal>
#include <cstdlib>

/*
 *
 * GPIO LED Pin definitions for Traffic Light Simulation Board.
 *
 * These defines are specific to hardware design and cannot be changed.
 * [Pleaase refer "MicroEmbedded_BBB_Interfacing Details.pdf" for the detials.]
 *
 * */

#define 	LED_1		(0 * 32) + 3		/* GPIO0_3 */
#define 	LED_2		(0 * 32) + 23		/* GPIO0_23 */
#define 	LED_3		(0 * 32) + 2		/* GPIO0_2 */
#define 	LED_4		(0 * 32) + 26		/* GPIO0_26 */

#define 	LED_5		(1 * 32) + 17		/* GPIO1_17 */
#define 	LED_6		(1 * 32) + 15		/* GPIO1_15 */
#define 	LED_7		(0 * 32) + 15		/* GPIO0_15 */
#define 	LED_8		(1 * 32) + 14		/* GPIO1_14 */

#define 	LED_9		(0 * 32) + 14		/* GPIO0_14 */
#define 	LED_10		(0 * 32) + 27		/* GPIO0_27 */
#define 	LED_11		(0 * 32) + 22		/* GPIO0_22 */
#define 	LED_12		(2 * 32) + 1		/* GPIO2_1 */

/*
 *
 * DIRECTIN LEDs: to represent Traffic direction
 *
 * */
										/* Name on Traffic Light Simulation Board */
#define 	NORTH_GREEN			LED_1   	/* LD1 */
#define 	NORTH_YELLOW		LED_5		/* LD5 */
#define 	NORTH_RED			LED_9		/* LD9 */

#define 	EAST_GREEN			LED_2		/* LD2 */
#define 	EAST_YELLOW			LED_6		/* LD6 */
#define 	EAST_RED			LED_10		/* LD10 */

#define 	SOUTH_GREEN			LED_3		/* LD3 */
#define 	SOUTH_YELLOW		LED_7		/* LD7 */
#define 	SOUTH_RED			LED_11		/* LD11 */

#define 	WEST_GREEN			LED_4		/* LD4 */
#define 	WEST_YELLOW			LED_8		/* LD8 */
#define 	WEST_RED			LED_12		/* LD12 */


/* Use std namespace for various C++ definitions */
using namespace std;

/* PATH of a GPIO specific sysfs interfce directory on Linux system */
#define SYSFS_GPIO_DIR "/sys/class/gpio"


/********************************************************************************
 * Description : Write the GPIO PIN value on "/sys/class/gpio/export" file.
 * 				 This will export (make visible) the directory associated
 *				 with particular GPIO pin under sysfs interface.
 *				 e.g. if value of GPIO PIN is "23" then "/sys/class/gpio/gpio23"
 *				 directory will be exported (will become visible)
 * Input	   : @gpio = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Must be called for a particular GPIO PIN before using that PIN.
 *********************************************************************************/
void gpioExport(string gpio)
{
	   fstream fs;											/* Declare C++ file stream */
	   string path(SYSFS_GPIO_DIR);							/* Declare string variable path with value as sysfs gpio path */
	   fs.open((path + "/export").c_str(), fstream::out);	/* Using file stream fs, open the file "/sys/class/gpio/export" as output */
	   fs << gpio;											/* Write GPIO PIN (accepted in "gpio") on fs to export the PIN */
	   fs.close();											/* Close the file stream */
}


/*********************************************************************************
 * Description : Exactly opposite of export function above.
 * 				 Write the GPIO PIN value on "/sys/class/gpio/unexport" file.
 * 				 This will un-export (make invisible) the directory associated
 *				 with particular GPIO pin under sysfs interface.
 *				 e.g. if value of GPIO PIN is "23" then "/sys/class/gpio/gpio23"
 *				 directory will be unexported (will become invisible)
 * Input	   : @gpio = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Must be called for a particular GPIO PIN after it is used
 * 				 This makes a PIN free from GPIO functionality
 *********************************************************************************/
void gpioUnexport(string gpio)
{
	   fstream fs;											/* Declare C++ file stream */
	   string path(SYSFS_GPIO_DIR);							/* Declare string variable path with value as sysfs gpio path */
	   fs.open((path + "/unexport").c_str(), fstream::out);	/* Using file stream fs, open the file "/sys/class/gpio/unexport" as output */
	   fs << gpio;											/* Write GPIO PIN (accepted in "gpio") on fs to unexport the PIN */
	   fs.close();											/* Close the file stream */
}


/************************************************************************************************
 * Description : Write the direction ("in"/"out") on "/sys/class/gpio/gpioN/direction"
 *               where "gpioN" stands for the directory already exported.
 * 				 This will configure a particular GPIO PIN as an input or output pin.
 * Input	   : @gpio = Value of GPIO PIN (in the form of string)
 * 				 @dir  = Value of direction either "in" or "out"
 * Return	   : None
 * Note		   : Make sure to export a GPIO PIN (using gpioExport) before calling this function
 *************************************************************************************************/
void gpioSetDir(string gpio, string dir)
{
	   fstream fs;											/* Declare C++ file stream */
	   string path(SYSFS_GPIO_DIR);							/* Declare string variable path with value as sysfs gpio path */

	   /*
	    * Using file stream fs, open the file "/sys/class/gpio/gpioN/direction" as output stream
	    * where 'N' stands for GPIO PIN (accepted in "gpio")
	    * */
	   fs.open((path + "/gpio" + gpio + "/direction").c_str(), fstream::out);
	   fs << dir;											/* Write direction (accepted in "dir") on fs (GPIO PIN) */
	   fs.close();											/* Close the file stream */
}


/************************************************************************************************
 * Description : Write the value ("0"/"1") on "/sys/class/gpio/gpioN/value"
 *               where "gpioN" stands for the directory already exported.
 * 				 This will make particular GPIO PIN as LOW or HIGH (CLEAR or SET).
 * Input	   : @gpio = Value of GPIO PIN (in the form of string)
 * 				 @val  = Value of GPIO either "0" or "1"
 * Return	   : None
 * Note		   : Make sure to export a GPIO PIN (using gpioExport) and
 * 				 set the direction as "out" (using gpioSetDir) before calling this function
 *************************************************************************************************/
void gpioSetValue(string gpio, string val)
{
	   fstream fs;											/* Declare C++ file stream */
	   string path(SYSFS_GPIO_DIR);							/* Declare string variable path with value as sysfs gpio path */
	   /*
	    * Using file stream fs, open the file "/sys/class/gpio/gpioN/value" as output stream
	    * where 'N' stands for GPIO PIN (accepted in "gpio")
	    * */
	   fs.open((path + "/gpio" + gpio + "/value").c_str(), fstream::out);
	   fs << val;											/* Write value (accepted in "val") on fs (GPIO PIN) */
	   fs.close();											/* Close the file stream */
}


/*******************************************************************************
 * Description : Function to convert an integer into string (like itoa() in C)
 *				 This function uses "stringstream" to accomplish the job.
 * Input	   : @a = integer to be converted into string datatype
 * Return	   : A string version of an input value
 * Note		   : No C++ std function like C, hence this user-defined function
 *********************************************************************************/
string to_string(int a)
{
	ostringstream temp;					/* Declare a temp variable of type ostringstream */
	temp<<a;							/* Use redirection to copy value of variable 'a' as string */
	return temp.str();					/* return the converted string value */
}

/*******************************************************************************
 * Description : Function to clean up a particular traffic light
 *				 Means Clear the LED and unexport the GPIO PIN
 * Input	   : @light = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every traffic signal light
 *********************************************************************************/
void lightExit(string light)
{
	gpioSetValue(light, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
	gpioUnexport(light);				/* Unexport the GPIO PIN associated with LED */
}


/***********************************************************************************
 * Description : Function to initialize a particular traffic light
 *				 Means export the GPIO PIN for LED, Set its direction as "out"
 *				 and Clear the LED (Make it "OFF").
 *				 Initially we keep all the LEDs in OFF status.
 * Input	   : @light = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every traffic signal light
 *************************************************************************************/
void lightInit(string light)
{
	gpioExport(light);					/* Export the GPIO PIN associated with LED */
	gpioSetDir(light, "out");			/* Set direction of GPIO PIN as out */
	gpioSetValue(light, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
}


/***********************************************************************************
 * Description : Function to make a particular traffic light ON
 *				 Means make the LED "ON", by writing "1" to it's GPIO PIN
 * Input	   : @light = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Make sure to initialize a particular traffic signal light using
 * 				 lightInit() before calling this function
 *************************************************************************************/
void lightOn(string light)
{
	gpioSetValue(light, "1");			/* Glow the LED (Make it "ON"), by writing "1" to it's GPIO PIN */
}


/***********************************************************************************
 * Description : Function to make a particular traffic light OFF
 *				 Means make the LED "OFF", by writing "0" to it's GPIO PIN
 * Input	   : @light = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Make sure to initialize a particular traffic signal light using
 * 				 lightInit() before calling this function
 *************************************************************************************/
void lightOff(string light)
{
	gpioSetValue(light, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
}


/***********************************************************************************
 * Description : Initialize all the traffic signal lights one-by-one.
 *				 Observe that each time lightInit() is called, a traffic signal
 *				 light value is converted from integer number to a string and then
 *				 it is passed as a parameter to lightInit()
 * Input	   : None
 * Return	   : None
 * Note		   : This function should be called from the main() before starting
 * 				 the traffic light simulation loop
 *************************************************************************************/
void trafficInitAll(void)
{
		lightInit(to_string(NORTH_GREEN));
		lightInit(to_string(NORTH_YELLOW));
		lightInit(to_string(NORTH_RED));

		lightInit(to_string(EAST_GREEN));
		lightInit(to_string(EAST_YELLOW));
		lightInit(to_string(EAST_RED));

		lightInit(to_string(SOUTH_GREEN));
		lightInit(to_string(SOUTH_YELLOW));
		lightInit(to_string(SOUTH_RED));

		lightInit(to_string(WEST_GREEN));
		lightInit(to_string(WEST_YELLOW));
		lightInit(to_string(WEST_RED));
}


/***********************************************************************************
 * Description : Cleanup all the traffic signal lights one-by-one.
 *				 Observe that each time lightExit() is called, a traffic signal
 *				 light value is converted from integer number to a string and then
 *				 it is passed as a parameter to lightExit()
 * Input	   : None
 * Return	   : None
 * Note		   : This function can be called,
 * 					1) From main() after ending the traffic light simulation loop
 * 					2) From signal handler of SIGINT to clean-up and restore the
 * 					   LEDs, whenever CTRL+C is pressed (mostly from BBB shell prompt)
 *************************************************************************************/
void trafficExitAll(void)
{
		lightExit(to_string(NORTH_GREEN));
		lightExit(to_string(NORTH_YELLOW));
		lightExit(to_string(NORTH_RED));

		lightExit(to_string(EAST_GREEN));
		lightExit(to_string(EAST_YELLOW));
		lightExit(to_string(EAST_RED));

		lightExit(to_string(SOUTH_GREEN));
		lightExit(to_string(SOUTH_YELLOW));
		lightExit(to_string(SOUTH_RED));

		lightExit(to_string(WEST_GREEN));
		lightExit(to_string(WEST_YELLOW));
		lightExit(to_string(WEST_RED));
}


/***********************************************************************************
 * Description : Function to simulate North-South Flow of Traffic
 *               Means, Give RED signal (STOP) to East and West
 *               		Give Green signal (Go) to North and South
 *						Keep this status for 10 seconds
 *						Make Green signal of North and South OFF
 *						Give Yellow signal (Wait) to North and South for 1 second
 *						Keep all other signals (LEDs) OFF throughout the function
 * Input	   : None
 * Return	   : None
 * Note		   : Observe that each time lightOn() or lightOff() is called, a traffic
 *				 signal light value is converted from integer number to a string
 *				 and then it is passed as a parameter
 *************************************************************************************/
void northSouthOn(void)
{
	lightOff(to_string(EAST_YELLOW));		/* EAST_YELLOW not useful throughout this function, so make it OFF  */
	lightOff(to_string(WEST_YELLOW));		/* WEST_YELLOW not-useful throughout this function, so make it OFF */
	lightOff(to_string(NORTH_RED));			/* NORTH_RED not-useful throughout this function, so make it OFF */
	lightOff(to_string(SOUTH_RED));			/* SOUTH_RED not-useful throughout this function, so make it OFF */

	/* East-West traffic should STOP */
	lightOn(to_string(EAST_RED));			/* Make EAST_RED LED ON */
	lightOn(to_string(WEST_RED));			/* Make EAST_RED LED ON */

	/* North-South traffic should GO */
	lightOn(to_string(NORTH_GREEN));		/* Make NORTH_GREEN LED ON */
	lightOn(to_string(SOUTH_GREEN));		/* Make SOUTH_GREEN LED ON */

	/* Pause in this state for 10 seconds using sleep() */
	sleep(10);

	/*
	 * Its time for WAIT signal to North-South
	 * traffic, so lets make GREEN OFF
	 * */
	lightOff(to_string(NORTH_GREEN));		/* Make NORTH_GREEN LED OFF */
	lightOff(to_string(SOUTH_GREEN));		/* Make SOUTH_GREEN LED OFF */

	/* North-South traffic should WAIT */
	lightOn(to_string(NORTH_YELLOW));		/* Make NORTH_YELLOW LED ON */
	lightOn(to_string(SOUTH_YELLOW));		/* Make SOUTH_YELLOW LED ON */

	/* Wait for 1 second */
	sleep(1);
}

/***********************************************************************************
 * Description : Function to simulate East-West Flow of Traffic
 *               Means, Give RED signal (STOP) to North and South
 *               		Give Green signal (Go) to East and West
 *						Keep this status for 10 seconds
 *						Make Green signal of East and West OFF
 *						Give Yellow signal (Wait) to East and West for 1 second
 *						Keep all other signals (LEDs) OFF throughout the function
 * Input	   : None
 * Return	   : None
 * Note		   : Observe that each time lightOn() or lightOff() is called, a traffic
 *				 signal light value is converted from integer number to a string
 *				 and then it is passed as a parameter
 *************************************************************************************/
void eastWestOn(void)
{
	lightOff(to_string(NORTH_YELLOW));		/* NORTH_YELLOW not useful throughout this function, so make it OFF  */
	lightOff(to_string(SOUTH_YELLOW));		/* SOUTH_YELLOW not useful throughout this function, so make it OFF  */
	lightOff(to_string(EAST_RED));			/* EAST_RED not useful throughout this function, so make it OFF  */
	lightOff(to_string(WEST_RED));			/* WEST_RED not useful throughout this function, so make it OFF  */

	/* North-South traffic should STOP */
	lightOn(to_string(NORTH_RED));			/* Make NORTH_RED LED ON */
	lightOn(to_string(SOUTH_RED));			/* Make SOUTH_RED LED ON */

	/* East-West traffic should GO */
	lightOn(to_string(EAST_GREEN));			/* Make EAST_GREEN LED ON */
	lightOn(to_string(WEST_GREEN));			/* Make WEST_GREEN LED ON */

	/* Pause in this state for 10 seconds using sleep() */
	sleep(10);

	/*
	 * Its time for WAIT signal to North-South
	 * traffic, so lets make GREEN OFF
	 * */
	lightOff(to_string(EAST_GREEN));		/* Make EAST_GREEN LED OFF */
	lightOff(to_string(WEST_GREEN));		/* Make WEST_GREEN LED OFF */

	/* East-West traffic should WAIT */
	lightOn(to_string(EAST_YELLOW));		/* Make EAST_YELLOW LED ON */
	lightOn(to_string(WEST_YELLOW));		/* Make WEST_YELLOW LED ON */

	/* Wait for 1 second */
	sleep(1);
}

/***********************************************************************************
 * Description : Signal handler function for SIGINT
 *               This function will do the entire clean up, restore all the traffic
 *               LEDs to their original status and safely exit from the program.
 * Input	   : @s = signal number defined by OS (SIGINT here)
 * Return	   : None
 * Note		   : This function will be called whenever this program receives an
 *				 interrupt from other programs at runtime. Mostly a program running
 *				 on Linux Shell is interruped by pressing 'CTRL+C'.
 *************************************************************************************/
void sigfunc(int s)
{
	trafficExitAll();			/* Do the clean up */
	std::exit(0);				/* Call exit() to end the program */
}


/**********************************************************************************
 * The main() function. Your Program Starts from here.
 **********************************************************************************/
int main(int argc, char* argv[])
{
	cout << "\nTraffic Signal Light Simulation using C++" << endl;
	cout << "-----------------------------------------------" << endl;

	signal(SIGINT, sigfunc);				/* Register a function "sigfunc" as a signal handler for SIGINT */
	trafficInitAll();						/* First initialize all traffic signal lights/LEDs (i.e. corresponding GPIO PINs) */
	sleep(2);								/* Wait for few seconds after initialization (NOT MANDATORY) */
	for(int i=0; i<10; i++)					/* Run a traffic light simulation loop for 10 times */
	{
		/* Some prints to indicate traffic direction */
		cout << "\nNORTH-SOUTH	--> [GO]" << endl;
		cout << "EAST-WEST 		--> [STOP]\n" << endl;
		northSouthOn();						/* Call North-South traffic simulation */
		sleep(1);							/* small sleep */

		/* Some prints to indicate traffic direction */
		cout << "\nEAST-WEST 	--> [GO]" << endl;
		cout << "NORTH-SOUTH 	--> [STOP]\n" << endl;
		eastWestOn();						/* Call North-South traffic simulation */
		sleep(1);							/* small sleep */
	}
	trafficExitAll();						/* Once simulation loop is over; do the proper clean-up  */
	cout << "Done." << endl;				/* Program ENDs here */
}


