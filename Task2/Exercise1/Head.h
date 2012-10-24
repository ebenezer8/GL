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

struct Book 
{
	 char* autor;
	
	 char* title;
	
	 char* notes;
	
	unsigned short year;
};



bool IsDigit ( char* input ); // function: returns false in case string it takes is digit, and true otherwise  

char ReadDigit( unsigned short & digit ); // function that reads (and convert to digit) symbols from keyboard

bool ReadStruct( struct Book *book, unsigned long i ); // fill the struct's fields with some values

void PrintStruct( struct Book *st, unsigned long m ); // prints the fild's values of the structs

struct Book * Resize( struct Book * a, unsigned long newsize, unsigned long oldsize ); // changes  size of the massive of the structs

void Sort ( struct Book *p, unsigned long m ); // sorts the structs according some ruel

bool ReadAtribute(unsigned short & digit, char* str, unsigned long & i, char* atribute, bool isDigit); // chacks correction of the struct's fild's values entered by user

char ReadChar(  char* str ); // reads and handles char symbols entered from keyboard

void Start(void); // lanches main functions

void Before1970( struct Book *p, unsigned long m ); // print the list of the structs with year-field low than 1970

#endif