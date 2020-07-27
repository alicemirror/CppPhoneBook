/**
	\file phonebook_const.h
	\brief PhoneBook class constants header file.
	
	This file defines the constants used by the PhoneBook class
	
	\mainpage Notes on the PhoneBook APIs
	This class is provided with a simple terminal main.cpp application showing a
	series of commands designed to test the features of the class. The program is
	very simple and does not aim to be a real application. Many limitations in the
	functionality are imposed by the use of the stdin and stdout as the sole
	ways to input data and send output to the consode.
	
	\section compiling Compiling the test appplication
	The test application, as well as the PhoneBook class sources can be compiled
	with the provided makefile.
	
	This version has been compiled and tested with g++ on Raspberry Pi and BBB
	running Debian versions.
	
	\section perspective The PhoneBook APIs
	
	Full API documentation not yet available.
	
*/

#ifndef _PHONEBOOK_CONST
#define _PHONEBOOK_CONST

//! Select the field Name for the ordering
#define ORDER_NAME 1
//! Select the field Surname for the ordering
#define ORDER_SURNAME 2

#endif
