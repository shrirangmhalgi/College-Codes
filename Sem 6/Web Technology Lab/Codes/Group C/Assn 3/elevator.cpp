/*******************************************************
 * C++ Example code for Lift Operation Simulation using
 * Beaglebone Black running Debian 7 Linux distribution
 ********************************************************
 * Developed by MicroEmbedded Technologies
 *******************************************************/

/* ######################################################################
 * 	NOTES:
 * 	~~~~~~~~
 * 	1) 	Each liftLED and button has a particular LED/BUTTON associated with it
 * 		And each LED/BUTTON has particular GPIO PIN associted with it.
 * 		e.g.
 * 			liftLED				LED		 	GPIO PIN
 * 			------------------------------------------
 * 			LIFT_LED_0	 	= 	LED_1 	=	GPIO0_3
 *			LIFT_POS_0		= 	LED_5	=	GPIO1_17
 *			LIFT_BUTTON_0	=	SW_1	=	GPIO0_14
 *				...				 ...		  ...
 *				so				 and 		   so
 * ######################################################################
 */


/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* Standard C++ Header Files */
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<csignal>
#include <cstdlib>

/* *
 * GPIO LED Pin definitions for Lift (Elevator) Simulation Board.
 * There are total 15 LEDs and 4 Switches (Buttons) on the Elevator Board
 *
 * These defines are specific to hardware design and cannot be changed.
 * [Pleaase refer "MicroEmbedded_BBB_Interfacing Details_New.pdf" for the detials.]
 *
 * */

/*
 * GPIO PIN definitions for the button press LEDs (RED LEDs on Board)
 * */
#define 	LED_1		(0 * 32) + 3		/* GPIO0_3 */
#define 	LED_2		(0 * 32) + 23		/* GPIO0_23 */
#define 	LED_3		(0 * 32) + 2		/* GPIO0_2 */
#define 	LED_4		(0 * 32) + 26		/* GPIO0_26 */


/*
 * GPIO PIN definitions for the lift position LEDs (GREEN LEDs on Board)
 * */
#define 	LED_5		(1 * 32) + 17		/* GPIO1_17 */
#define 	LED_6		(1 * 32) + 15		/* GPIO1_15 */
#define 	LED_7		(0 * 32) + 15		/* GPIO0_15 */
#define 	LED_8		(1 * 32) + 14		/* GPIO1_14 */


/*
 * GPIO PIN definitions for the direction LEDs (YELLOW LEDs on Board)
 * */
#define 	LED_9		(0 * 32) + 30		/* GPIO0_30 */
#define 	LED_10		(2 * 32) + 2		/* GPIO2_2 */
#define 	LED_11		(1 * 32) + 28		/* GPIO1_28 */
#define 	LED_12		(2 * 32) + 3		/* GPIO2_3 */
#define 	LED_13		(0 * 32) + 31		/* GPIO0_31 */
#define 	LED_14		(2 * 32) + 5		/* GPIO2_5 */
#define 	LED_15		(1 * 32) + 18		/* GPIO1_18 */


/*
 * GPIO PIN definitions for the lift BUTTONs (Buttons on Board)
 * */
#define 	SW_1		(0 * 32) + 14		/* GPIO0_14 */
#define 	SW_2		(0 * 32) + 27		/* GPIO0_27 */
#define 	SW_3		(0 * 32) + 22		/* GPIO0_22 */
#define 	SW_4		(2 * 32) + 1		/* GPIO2_1 */


/*
 * LIFT DIRECTION: LEDs to represent lift direction (up or down)
 * */
											/* Name on Lift Simulation Board */
#define 	LIFT_DIR_1			LED_9		/* LD9 */
#define 	LIFT_DIR_2			LED_10		/* LD10 */
#define 	LIFT_DIR_3			LED_11		/* LD11 */
#define 	LIFT_DIR_4			LED_12		/* LD12 */
#define 	LIFT_DIR_5			LED_13		/* LD13 */
#define 	LIFT_DIR_6			LED_14		/* LD14 */
#define 	LIFT_DIR_7			LED_15		/* LD15 */


/*
 * LIFT POSITION: LEDs to indicate the current position of Lift
 * */
#define 	LIFT_POS_0			LED_5		/* LD5 */
#define 	LIFT_POS_1			LED_6		/* LD6 */
#define 	LIFT_POS_2			LED_7		/* LD7 */
#define 	LIFT_POS_3			LED_8		/* LD8 */


/*
 * LIFT BUTTONS: Buttons corresponding to each floor of the Lift
 * */
#define 	LIFT_BUTTON_0		SW_1		/* SW1 */
#define 	LIFT_BUTTON_1		SW_2		/* SW2 */
#define 	LIFT_BUTTON_2		SW_3		/* SW3 */
#define 	LIFT_BUTTON_3		SW_4		/* SW4 */

/*
 * LIFT LEDS: LEDs to indicate the BUTTON Press on each floor
 * */
#define 	LIFT_LED_0			LED_1		/* LD1 */
#define 	LIFT_LED_1			LED_2		/* LD2 */
#define 	LIFT_LED_2			LED_3		/* LD3 */
#define 	LIFT_LED_3			LED_4		/* LD4 */


/*
 * An array of DIRECTION LEDS
 * */
unsigned int dir_leds[] =
{
		LIFT_DIR_1,
		LIFT_DIR_2,
		LIFT_DIR_3,
		LIFT_DIR_4,
		LIFT_DIR_5,
		LIFT_DIR_6,
		LIFT_DIR_7
};


/*
 * An array of POSITION LEDS
 * */
unsigned int pos_leds[] =
{
		LIFT_POS_0,
		LIFT_POS_1,
		LIFT_POS_2,
		LIFT_POS_3
};


/*
 * An array of lift BUTTONs
 * */
unsigned int lift_buttons[] =
{
		LIFT_BUTTON_0,
		LIFT_BUTTON_1,
		LIFT_BUTTON_2,
		LIFT_BUTTON_3
};


/*
 * An array of BUTTON PRESS LEDS
 * */

unsigned int lift_leds[] =
{
		LIFT_LED_0,
		LIFT_LED_1,
		LIFT_LED_2,
		LIFT_LED_3
};


#define NO_OF_FLOORS		4			/* No of floors for Lift Simulation Operation */
#define NO_OF_DIR_LEDS		7			/* No of LEDs used for the lift direction (on Board) */
#define DEFAULT_LIFT_POS	0			/* The floor no where lift is positioned when program is executed */


/*
 * A structure to have a lift BUTTON, button press LED and a File
 * Discrptor of the button value file together.
 *
 * Whenever BUTTON is pressed; we get an event from Linux on the associated
 * Button File discriptor and then we glow the associated LED.
 *
 * */
struct floor
{
	int fd;						/* File descriptor of a button */
	unsigned int button;		/* The Lift Button for a particular floor */
	unsigned int led;			/* The Lift LED accociated with floor */
};


/*
 * The array of structures have its size = NO_OF_FLOORS (i.e. 4 in this case)
 * Each element in this array is a structure of type "struct floor"
 * The array index correspons to the floor number of a particular element.
 * Hence 0th element correspnds to 0th floor, 1st corresponds to 1st and so on.
 * As per definition of "struct floor", each array element has three members as,
 * 				fd 		= 	File Descriptor (Initialized to -1)
 * 				button	= 	Button for Nth floor
 * 				led		= 	Button press LED for Nth floor
 *
 * */

struct  floor floor_set[NO_OF_FLOORS] =
{
		{-1, LIFT_BUTTON_0, LIFT_LED_0},			/* fd, Button and LED for 0th (Ground) Floor */

		{-1, LIFT_BUTTON_1, LIFT_LED_1},			/* fd, Button and LED for 1st Floor */

		{-1, LIFT_BUTTON_2, LIFT_LED_2},			/* fd, Button and LED for 2nd Floor */

		{-1, LIFT_BUTTON_3, LIFT_LED_3}				/* fd, Button and LED for 3rd Floor */
};


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


/************************************************************************************************
 * Description : Write the Edge value on "/sys/class/gpio/gpioN/edge"
 *               where "gpioN" stands for the directory already exported.
 * 				 This will set the GPIO edge value.
 * 				 Edge can be set to any of the 4 values
 * 				 			"falling"	"rising" 	"both"		"none"
 *
 * Input	   : @gpio = Value of GPIO PIN (in the form of string)
 * 				 @edge  = Value of GPIO edge
 * Return	   : None
 * Note		   : Make sure to export a GPIO PIN (using gpioExport) before calling this function
 *************************************************************************************************/
void gpioSetEdge(string gpio, string edge)
{
	   fstream fs;											/* Declare C++ file stream */
	   string path(SYSFS_GPIO_DIR);							/* Declare string variable path with value as sysfs gpio path */
	   /*
	   	* Using file stream fs, open the file "/sys/class/gpio/gpioN/edge" as output stream
	   	* where 'N' stands for GPIO PIN (accepted in "gpio")
	   	* */
	   fs.open((path + "/gpio" + gpio + "/edge").c_str(), fstream::out);
	   fs << edge;											/* Write edge value (accepted in "edge") on fs (GPIO PIN) */
	   fs.close();											/* Close the file stream */
}


#define MAX_BUF			1			/* Size of buffer for button read operation */
char *buf[MAX_BUF];					/* Buffer for button read data */

fd_set read_fds;					/* Set of file discriptors (FDSET) for select() function	 */
int max_fd;							/* Variable to hold the Maximum value of file descriptor for select() */

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
 * Description : Function to clean up a particular liftLED
 *				 Means Clear the LED and unexport the GPIO PIN
 * Input	   : @liftLED = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every LED on lift simulation board
 *********************************************************************************/
void liftLEDExit(string liftLED)
{
	gpioSetValue(liftLED, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
	gpioUnexport(liftLED);				/* Unexport the GPIO PIN associated with LED */
}


/***********************************************************************************
 * Description : Function to initialize a particular liftLED
 *				 Means export the GPIO PIN for LED, Set its direction as "out"
 *				 and Clear the LED (Make it "OFF").
 *				 Initially we keep all the LEDs in OFF status.
 * Input	   : @liftLED = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every liftLED
 *************************************************************************************/
void liftLEDInit(string liftLED)
{
	gpioExport(liftLED);				/* Export the GPIO PIN associated with LED */
	gpioSetDir(liftLED, "out");			/* Set direction of GPIO PIN as out */
	gpioSetValue(liftLED, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
}


/***********************************************************************************
 * Description : Function to make a particular liftLED ON
 *				 Means make the LED "ON", by writing "1" to it's GPIO PIN
 * Input	   : @liftLED = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Make sure to initialize a particular liftLED using
 * 				 liftLEDInit() before calling this function
 *************************************************************************************/
void liftLEDOn(string liftLED)
{
	gpioSetValue(liftLED, "1");			/* Glow the LED (Make it "ON"), by writing "1" to it's GPIO PIN */
}


/***********************************************************************************
 * Description : Function to make a particular liftLED OFF
 *				 Means make the LED "OFF", by writing "0" to it's GPIO PIN
 * Input	   : @liftLED = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : Make sure to initialize a particular liftLED using
 * 				 liftLEDInit() before calling this function
 *************************************************************************************/
void liftLEDOff(string liftLED)
{
	gpioSetValue(liftLED, "0");			/* Clear the LED (Make it "OFF"), by writing "0" to it's GPIO PIN */
}


/*******************************************************************************
 * Description : Function to clean up a particular lift button
 *				 It will unexport the GPIO PIN associated with lift button
 * Input	   : @button = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every lift button.
 *********************************************************************************/
void liftButtonExit(string button)
{
	gpioUnexport(button);				/* Unexport the GPIO PIN associated with BUTTON */
}

/***********************************************************************************
 * Description : Function to initialize a particular button
 *				 Means export the GPIO PIN for button, Set its direction as "in"
 *				 and set its edge as "falling".
 * Input	   : @button = Value of GPIO PIN (in the form of string)
 * Return	   : None
 * Note		   : This function is called for every lift button.
 *************************************************************************************/
void liftButtonInit(string button)
{
	gpioExport(button);					/* Export the GPIO PIN associated with BUTTON */
	gpioSetDir(button, "in");			/* Set direction of GPIO PIN as "in"; since it is a BUTTON */
	gpioSetEdge(button, "falling");		/* Set edge of GPIO PIN as "falling" */
}



/***********************************************************************************
 * Description : Initialize all the lift LEDs and BUTTONs one-by-one.
 *				 Observe that each time liftLEDInit() or liftButtonInit() is called,
 *				 LED/BUTTON value is converted from integer number to a string
 *				 and then it is passed as a parameter.
 * Input	   : None
 * Return	   : None
 * Note		   : This function should be called from the main() before starting
 * 				 the lift simulation loop
 *************************************************************************************/
void liftInitAll(void)
{
	unsigned char i;								/* Counter variable */

	for(i=0; i<NO_OF_DIR_LEDS; i++)					/* loop for no of direction LEDs */
			liftLEDInit(to_string(dir_leds[i]));	/* Initialize each LED from array of direction leds */

	for(i=0; i<NO_OF_FLOORS; i++)					/* loop for no of floors defined */
	{
		liftLEDInit(to_string(pos_leds[i]));		/* Initialize each LED from array of lift position leds */
		liftLEDInit(to_string(lift_leds[i]));		/* Initialize each LED from array of button press leds */
		liftButtonInit(to_string(lift_buttons[i]));	/* Initialize each BUTTON from array of lift buttons */
	}
}

/***********************************************************************************
 * Description : Cleanup all the lift LEDs and BUTTONs one-by-one.
 *				 Observe that each time liftLEDExit() or liftButtonExit is called,
 *				 LED/BUTTON is converted from integer number to a string and then
 *				 it is passed as a parameter.
 * Input	   : None
 * Return	   : None
 * Note		   : This function can be called,
 * 					1) From main() after ending the liftLED simulation loop
 * 					2) From signal handler of SIGINT to clean-up and restore the
 * 					   LEDs, whenever CTRL+C is pressed (mostly from BBB shell prompt)
 *************************************************************************************/
void liftExitAll()
{
	unsigned char i;								/* Counter variable */

	for(i=0; i<NO_OF_DIR_LEDS; i++)					/* loop for no of direction LEDs */
			liftLEDExit(to_string(dir_leds[i]));	/* Clean-up each LED from array of direction leds */

	for(i=0; i<NO_OF_FLOORS; i++)					/* loop for no of floors defined */
	{
		liftLEDExit(to_string(pos_leds[i]));		/* Clean-up each LED from array of lift position leds */
		liftLEDExit(to_string(lift_leds[i]));		/* Clean-up each LED from array of button press leds */
		liftButtonExit(to_string(lift_buttons[i]));	/* Clean-up each BUTTON from array of lift buttons */
	}
	cout << "\n=== Demonstration END ===\n" << endl;
}


/***********************************************************************************
 * Description : Set the default position of the lift,
 *				 by glowing the position LED defined by DEFAULT_LIFT_POS
 *				 (DEFAULT_LIFT_POS = 0th floor i.e. ground floor)
 * Input	   : None
 * Return	   : None
 * Note		   : This function must be called from main() after inititalization
 *************************************************************************************/
void liftDefaultPos(void)
{
	liftLEDOn(to_string(pos_leds[DEFAULT_LIFT_POS]));	/* Make the 0th (Ground) Floor position LED ON */
}


/***********************************************************************************
 * Description : Glow the direction LEDs in upward direction.
 *				 This indicates that lift is going to upper floor(s).
 * Input	   : None
 * Return	   : None
 * Note		   : This function is used when lift is called from upper
 * 				 floor than the current position of the lift
 *************************************************************************************/
void liftDirUp(void)
{
	unsigned char i;								/* Counter variable */

	/* Simulate lift going UP */
	for(i=0; i<NO_OF_DIR_LEDS; i++)					/* loop for no of direction LEDs */
	{
			liftLEDOn(to_string(dir_leds[i]));		/* Turn the (i)th direction led ON (indexed by i) */
			usleep(1000 * 500);						/* sleep for 500 millisecond */
	}

	/* Turn all the direction LEDs OFF */
	for(i=0; i<NO_OF_DIR_LEDS; i++)					/* loop for no of direction LEDs */
		liftLEDOff(to_string(dir_leds[i]));			/* Trun the (i)th direction led OFF */
}

/***********************************************************************************
 * Description : Glow the direction LEDs in downward direction.
 *				 This indicates that lift is going to lower floor(s).
 * Input	   : None
 * Return	   : None
 * Note		   : This function is used when lift is called to lower
 * 				 floor than the current position of the lift
 *************************************************************************************/
void liftDirDown(void)
{
	char i;											/* Counter variable */

	/* Simulate lift going DOWN */
	for(i=NO_OF_DIR_LEDS; i>0; i--)					/* loop for no of direction LEDs (decrementing loop) */
	{
		liftLEDOn(to_string(dir_leds[i-1]));		/* Turn the (i-1)th direction led ON */
		usleep(1000 * 500);							/* sleep for 500 millisecond */
	}

	/* Turn all the direction LEDs OFF */
	for(i=0; i<NO_OF_DIR_LEDS; i++)					/* loop for no of direction LEDs */
		liftLEDOff(to_string(dir_leds[i]));			/* Trun the (i)th direction led OFF */
}

/************************************************************************************************
 * Description : Open the file "/sys/class/gpio/gpioN/value" and return its file descriptor.
 *               Here "gpioN" stands for the directory already exported.
 * Input	   : @gpio = GPIO PIN value (integer)
 * Return	   : File descriptor of the GPIO file
 * Note		   : Make sure to export a GPIO PIN (using gpioExport) before calling this function
 *************************************************************************************************/
int gpioFdOpen(unsigned int gpio)
{
    int fd;											/* Variable for file descriptor */

    string gp_num = to_string(gpio);				/* Conver the gpio pin value from int to string */
    string path(SYSFS_GPIO_DIR);					/* Declare string variable path with value as sysfs gpio path */
    												/* Construct a FULL path of the GPIO file */
    const char *gp_file = (path + "/gpio" + gp_num + "/value").c_str();

    fd = open(gp_file, O_RDONLY);					/* open the said GPIO file in read-ony mode */

    if (fd < 0)										/* If invalid fd is returned (i.e. fd value is -ve)  */
    {
        perror("gpioFdOpen");						/* Print an error message using perror() */
    }
    return fd;										/* Return the value of FD */
}

/************************************************************************************************
 * Description : Open the button of the lift and store its file descriptor into 'fd' field of
 * 				 corresponding (struct floor) element in floor_set[] array.
 *				 Initially 'fd' field of each (struct floor) element in floor_set[] array is set
 *				 to -1; but after this function it will hold valid file descriptor value.
 * Input	   : None
 * Return	   : None
 *************************************************************************************************/
void liftButtonOpen(void)
{

	unsigned char i;									/* Counter Variable */
	int button_fd;										/* Variable for file descriptor */

	for(i=0; i<NO_OF_FLOORS; i++)						/* Run a loop for all floors */
	{
		button_fd = gpioFdOpen(floor_set[i].button);	/* Open and get file descriptor of button file of each floor */
		 if (button_fd < 0)								/* Error chceking */
		 {
		        printf("Cannot open file handle for Lift button #%d\n", i);		/* In case of ERROR; give proper message and */
		        exit(0);														/* Exit from the program */
		  }

		floor_set[i].fd = button_fd;					/* Otherwise store the value of FD in floor_set array.
		 	 	 	 	 	 	 	 	 	 	 	 	   This time it MUST be a valid FD value */
	}
}

/************************************************************************************************
 * Description : Prepare all the button file descriptors for select() system call.
 * 				 Store all file descriptors from  floor_set array into the set of FDs (read_fds).
 * 				 read_fds is a global variable defined above. It is nothing but a list of FDs
 * 				 required by select() system call to watch for data availability.
 * 				 This function, takes each fd from floor_set and
 * 				 		1) Store it in fd_set variable called read_fds,
 * 				 		2) current fd is greater than max_fd value, then set current fd as max_fd
 * 				 		3) Seek a position of fd to 0 means let fd point at begining of the file
 * 				 		4) Make a dummy read on the fd
 *				In short, this function will prepare all the button fds for select() system call.
 * Input	   : None
 * Return	   : None
 *************************************************************************************************/
void seekAllButtons(void)
{
	int i;											/* Counter Variable */

	FD_ZERO(&read_fds);								/* Fill read_fds variable with zeros */
	max_fd = 0;										/* Set max_fd variable to zero */

	for(i=0; i<NO_OF_FLOORS; i++)					/* Run a loop for all floors */
	{
		FD_SET(floor_set[i].fd, &read_fds);			/* Store the current button FD from floor_set array into read_fds */
		if(floor_set[i].fd > max_fd)				/* If current fd is > max_fd value */
			max_fd = floor_set[i].fd;				/* Store value of current fd into max_fd variable */

		lseek(floor_set[i].fd, 0, SEEK_SET);		/* Seek a current fd to 0th position means fd will point at begining of the file */
		read(floor_set[i].fd, buf, MAX_BUF);		/* Make a dummy read call on the current fd to flush all the previous data */
	}
}


/************************************************************************************************
 * Description : This function actually returns the floor number at which lift button is pressed.
 * 				 It will prepare all the button FDs for select() by calling seekAllButtons()
 * 				 Then a select() system call will block and wait for button press event from OS
 *				 As soon as select() returns; traverse and check for each fd if it is SET.
 *				 If it is SET then event has happned on that fd; so data is available on that fd,
 *				 if necessary go and read the data from that fd.
 *
 *				 Once fd is detected, it is simple that coresponding button is pressed and so glow
 *				 the corresponding LED from floor_set array. Here index i represents the floor
 *				 number where button is pressed.
 * Input	   : None
 * Return	   : Floor Number of lift where button is pressed
 *************************************************************************************************/
int liftGetInput(void)
{
	int ret=-1, fds;										/* Variables: ret=return value (initialized to -1) and fds = temp fd value */
	unsigned int i;											/* Counter variable */

	seekAllButtons();										/* Make pre-requisites before calling select() function */

	cout << "\nPress any LIFT button..." << endl;			/* Ask user to press any lift button */


	/*
	 * Blocking select() call: Program will wait until any of the lift button is pressed by user
	 *
	 * Parameters: max_fd+1 	= max value of file descriptor across all the sets, plus 1
	 * 			   &read_fds	= address of variable read_fds of type fd_set
	 *					          this is a list of FDs whose status is monitored by select() (Linux OS) for availability of data
	 *			   Rest all parameters are passed as NULL
	 **/
	ret = select(max_fd+1, NULL, NULL, &read_fds, NULL);

	if(ret < 0)												/* If return value is negative means some error has occured */
	{
		  perror("select failed");							/* Print an error message using perror() */
		  exit(0);											/* Exit from the program */
	}

	for(i=0; i<NO_OF_FLOORS; i++)							/* Run a loop for all floors */
	{
		fds = floor_set[i].fd;								/* Get fd (indexed by i) from floor_set array into temporary varialble 'fds' */

		if(FD_ISSET(fds, &read_fds))						/* check if current fd is SET or not? Simple check value in fds is a part of read_fds or not */
		{													/* when select returns it will keep only those FDs in read_fds on which data is available */

			cout << "LIFT button is pressed for floor #" << i << endl;	/* if macro FD_ISSET returns true then print floor no represented by i */
			liftLEDOn(to_string(floor_set[i].led));			/* Glow the corresponding LED for floor indicated by i to show button press event */
			sleep(1);										/* pause for 1 second */
			ret = i;										/* Store value in variable i as return value; since i represent floor number */
			break;											/* break the loop since we have detected which button is pressed */
		}
	}
  return ret;												/* Return the Floor Number for which button is pressed */
}

/***********************************************************************************
 * Description : Signal handler function for SIGINT
 *               This function will do the entire clean up, restore all the
 *               LEDs to their original status and safely exit from the program.
 * Input	   : @s = signal number defined by OS (SIGINT here)
 * Return	   : None
 * Note		   : This function will be called whenever this program receives an
 *				 interrupt from other programs at runtime. Mostly a program running
 *				 on Linux Shell is interruped by pressing 'CTRL+C'.
 *************************************************************************************/
void sigfunc(int s)
{
	liftExitAll();				/* Do the clean up */
	exit(0);					/* Call exit() to end the program */
}


/**********************************************************************************
 * The main() function. Your Program Starts from here.
 **********************************************************************************/
int main(int argc, char* argv[])
{
	int cur_flr, new_flr, tmp;									/* Variable to store current floor no, new floor no and tmp */

	cout << "Lift Operation Simulation using C++" << endl;
	cout << "-----------------------------------------------" << endl;
	signal(SIGINT, sigfunc);									/* Register a function "sigfunc" as a signal handler for SIGINT */
	liftInitAll();												/* First initialize all Lift LEDs and Buttons (their associated GPIOs) */

	liftButtonOpen();											/* Opne button files and fill those values in floor_set array for corresponding floors */
	liftDefaultPos();											/* Glow the position LED associated with the default floor number (DEFAULT_LIFT_POS) */

   cur_flr = DEFAULT_LIFT_POS;									/* Initially lift is at default position; so set cur_flr to default position (0th floor) */


	  while(1)													/* Run an infinite loop */
	  {
		  new_flr = liftGetInput();								/* Get new floor value by detecting a floor number to which button will be pressed by user */
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	/* At this function; program will wait for user input; new_flr = destination floor */

		  if(new_flr < 0)										/* Continue loop till we get valid floor number */
			  continue;

		  /* Case 1: Lift is called on upper floor */
		  if(new_flr > cur_flr)											/* if (new floor > current floor) mean take lift to upper floor */
		  {
			  tmp = cur_flr;											/* Store current floor no in tmp variable */
			  cout << "LIFT going UP to floor #" << new_flr << endl;	/* Print the destination floor number */
			  while (tmp != new_flr)									/* Use tmp value (incremental) till it becomes destination floor */
			  {
				  liftDirUp();											/* Glow the Direction LEDs in upward direction */
				  usleep(100);											/* sleep for 100 micro-seconds */
				  liftLEDOff(to_string(pos_leds[tmp]));					/* Turn off the position LED for the floor pointed by tmp */
				  tmp++;												/* Increse the floor number (value of tmp) by 1; since lift is going UP */
	 			  liftLEDOn(to_string(pos_leds[tmp]));					/* Turn ON position LED for the floor pointed by tmp. Now tmp is 1 floor UP
	 			  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	than its previous value */
	 			  usleep(1000 * 500);									/* sleep for 500 micro-seconds */
			  }
		  }

		  /* Case 2: Lift is called to lower floor */
		  else if (new_flr < cur_flr)									/* if (new floor < current floor) mean take lift to lower floor */
		  {
			  tmp = cur_flr;											/* Store current floor no in tmp variable */
			  cout << "LIFT going DOWN to floor #" << new_flr << endl;	/* Print the destination floor number */
			  while (tmp != new_flr)									/* Use tmp value (decremental) till it becomes destination floor */
			  {
				liftDirDown();											/* Glow the Direction LEDs in downward direction */
			 	usleep(100);											/* sleep for 100 micro-seconds */
			 	liftLEDOff(to_string(pos_leds[tmp]));					/* Turn off the position LED for the floor pointed by tmp */
			 	tmp--;													/* Decrease floor number (value of tmp) by 1; since lift is going DOWN */
			 	liftLEDOn(to_string(pos_leds[tmp]));					/* Turn ON position LED for the floor pointed by tmp. Now tmp is 1 floor DOWN
			 																	than its previous value */
			  	usleep(1000 * 500);										/* sleep for 500 micro-seconds */
			  }
		  }
		  cur_flr = new_flr;											/* Once lift reaches its destination; current floor becomes the destination floor */
		  liftLEDOff(to_string(lift_leds[new_flr]));					/* Turn off the button press indication LED of the destination floor;
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 since lift is at destination now */
		  sleep(1);														/* sleep for 1 second and continue the while loop */
	  }
	  return 0;
}

