#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <memory.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>


struct Point
{
	signed short x;
	
	signed short y;
	
	signed short z;
};




void Sort( struct Point *p, unsigned long m );

bool IsDigit( char* input );

char ReadDigit( signed short & digit );

bool ReadStruct( struct Point *point, unsigned long i );

bool ReadCoordinate(signed short & digit, unsigned long & i, char coordinate);

void PrintStruct( struct Point *point, unsigned long m );

struct Point * Resize( struct Point * a, int newsize, int oldsize );

void Start();

#endif