/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 19 from Task 2
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <memory.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct Message 
{
	 char* message;
	
	 unsigned short code;

	 bool doubleDigit;
};



bool IsDigit ( char* input ); // function: returns false in case string it takes is digit, and true otherwise   

char ReadDigit( unsigned short & digit, bool & doubleDigit ); // function that reads (and convert to digit) symbols from keyboard

bool ReadStruct( struct Message *mess, unsigned long i ); // fill the struct's fields with some values

void PrintStruct( struct Message *st, unsigned long m ); // prints the fild's values of the structs

struct Message * Resize( struct Message * a, unsigned long newsize, unsigned long oldsize ); // changes  size of the massive of the structs

void Sort ( struct Message *p, unsigned long m ); // sorts the structs according some ruel

bool ReadAtribute( unsigned short & digit, char* str, unsigned long & i, char* atribute, bool isDigitt, bool & doubleDigit ); // chacks correction of the struct's fild's values entered by user

char ReadChar(  char* str ); // reads and handles char symbols entered from keyboard

void Start(void); // lanches main functions

void DoubleDigit( struct Message *p, unsigned long m ); // chacks: is there, in the code of the message, two equal side-by-side digits  

#endif