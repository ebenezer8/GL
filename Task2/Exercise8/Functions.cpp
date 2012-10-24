#include "Head.h"
using namespace std;


void Distance( struct Point *point, unsigned long m )
{
	if(m >= 2)
	{
		unsigned long rez=0;

		for(unsigned long i=m-1;i>=0;i--)
			rez=rez+i;

		float* mass = ( float * )malloc( sizeof(float) * rez );

		float* tempmass = ( float * )malloc( sizeof(float) );

		struct Point * tmp = ( struct Point * )malloc( sizeof(struct Point) * m );

		memcpy( tmp, point, sizeof(struct Point) * m );

		for(int i=0 ;i<m-1; i++ )
			for(int j=i+1; j<m;j++)
				*(mass+j) = pow( ( (float)pow( float( (tmp+i) -> x - (tmp+i) -> x ), 2 ) + 
								   (float)pow( float( (tmp+i) -> y - (tmp+i) -> y ), 2 ) +
								   (float)pow( float( (tmp+i) -> z - (tmp+i) -> z ), 2 ) ), (float)1/2 );

		for ( int i = 0; i < m; i++ )
			for ( int j = 0; j < m - 1; j++ )
				if( *( mass + j ) > *( mass + j + 1 ) )
				{
					memcpy(tempmass, mass + j, sizeof(float) );
					memcpy( ( mass + j ), ( mass + j + 1 ), sizeof(float) );
					memcpy( ( mass + j + 1 ), tempmass, sizeof(float) );
				}

				cout <<"The shortest distance: "<< *mass;
	}
	else
		cout<<"\n\nNot enought points to calculate a distance!\n\n";
}

bool IsDigit ( char* input )
{
	bool isDigit = false;
	
	if( *input == '-' || ( *input >= '0' && *input <= '9' ) )
		isDigit = false;
	else
		isDigit = true;
		
	for( int i = 1; i < strlen(input); i++ )
		if( *(input+i) < '0' || *(input+i) > '9' )
			isDigit = true;
		
	return isDigit;
}


char ReadDigit( signed short & digit )

{
  char ch;

  char buffer[4];

  char* pBuf = buffer;


  *pBuf = (char)1;

  unsigned short control = 0, inc = 0;


  while(1)
  {
	ch = _getch();
	
	if( ch != 8 )
	control++;
    
	if ( ch == 13 )
    {
	  control--;
	  break;  
    }
	
	if ( ch == 8 && *pBuf != (char)1 )
	{
		--inc;
		--control;
		--pBuf;
		if( control == 0 )
			*pBuf = (char)1;
	}
	
	if( control >= sizeof(buffer) )
		return '!';

	if( ch != 8 )
    *pBuf = ch;
	  
	printf("\r%80c\r", ' ');
	for( int i = 0; i < control; i++ )
		cout << *( ( pBuf - inc ) + i );
   
	if( ch != 8 )
	{
		inc++;
		++pBuf;
	}

  }

   *pBuf = '\0';
  
   digit = ( signed short )strtoul( buffer, NULL, 0 );
   
  if( *buffer == 'q' && *(buffer+1) == '\0' )
	  return '0';
  else if( IsDigit(buffer) )
	  return '1';
  else
	  return '2';

}


bool ReadStruct( struct Point *point, unsigned long i )
{
	if(!ReadCoordinate( ( point + i ) -> x, i, 'X' ))
		return false;
	if(!ReadCoordinate( ( point + i ) -> y, i, 'Y' ))
		return false;
	if(!ReadCoordinate( ( point + i ) -> z, i, 'Z' ))
		return false;
	return true;
}


bool ReadCoordinate(signed short & digit, unsigned long & i, char coordinate)
{
	char control;
			
	while(1)
		{
			cout << "\n\nEnter the "<< coordinate <<" - coordinate:  (q - quit)\n\n";
			
			control = ReadDigit(digit);
			
			switch(control)
			{
				case '0':
					return false;
				case '1':
					cout << "One of the symbols you've entered is not digit!\n\n";
					continue;
				case '!':
					cout << "\n\nYou've entered to mach symbols!\n\n";
					continue;
				default:
					cout << "\n\nThe" << coordinate << " - coordinate of the "<<i+1<<" - point: "<<digit<<"\n\n";
					break;

			}
			break;
		}
	return true;
}


void Sort( struct Point *point, unsigned long m )
{

	struct Point * tmp = ( struct Point * )malloc( sizeof(struct Point) * m );

	memcpy( tmp, point, sizeof(struct Point) * m );

	struct Point * temp = ( struct Point * )malloc( sizeof(struct Point) );
	
	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < m - 1; j++ )
			if((tmp + j) -> z < (tmp + j + 1) -> z)
			{
				memcpy( temp, tmp + j, sizeof(struct Point) );
				memcpy( ( tmp + j ), ( tmp + j + 1 ), sizeof(struct Point) );
				memcpy( ( tmp + j + 1 ), temp, sizeof(struct Point) );
			}
	
	free(temp);

	memcpy( point, tmp, sizeof(struct Point) * m );

	free(tmp);
}


struct Point * Resize( struct Point * a, int newsize, int oldsize )
{
    struct Point * b = ( struct Point * )malloc( sizeof(struct Point) * newsize );
		
	memcpy( b, a, sizeof(struct Point) * min( oldsize, newsize ) );
 
    free(a);
    
    return b;
}

void PrintStruct( struct Point *point, unsigned long m )
{
	system("cls");

	cout << "\n\n    X       Y      Z   \n\n";
	
	for( int i  = 0; i < m; i++ )
		cout << setw(11) << (point + i) -> x << setw(14) << (point + i) -> y << setw(24) << (point + i) -> z << "\n\n";
}

void Start()
{
	unsigned long newPoint=1;
	
	char question;
	
	bool q;
	

	Point* point = (Point* )malloc(sizeof(Point) * newPoint);


	if(!ReadStruct( point, newPoint-1 ))
	{
		free(point);
		return;
	}
	
	
	Sort( point, newPoint );


	PrintStruct( point,newPoint );

	while(1)
	{

		while(1)
		{
			cout<<"\n\nDo you want to make new struct? (y - yes, n - no)\n\n";
			
			cin>>question;
			
			if(question=='y')
			{
				q=true;
				break;
			}
			else if(question=='n')
			{
				q=false;
				break;
			}
			else
			{
				cout<<"\n\nEnter correct data!\n\n";
				continue;
			}
		}

		if(q)
		{
			++newPoint;

			point = Resize(point, newPoint, newPoint-1);

				if(!ReadStruct(point, newPoint-1))
				{
					free(point);
					return;
				}

			Sort(point, newPoint);


			PrintStruct(point,newPoint);
		}
		else
			break;
	}

	free(point);
	
	return;
}