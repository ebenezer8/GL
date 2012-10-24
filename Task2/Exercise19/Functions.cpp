/*
  file:	    Functions.h
  
  brief:	Realizes functions  for Exerñise 19 from Task 2
 
  autor:	Shalai Markiian
 */

#include "Head.h"
using namespace std;

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


struct Message * Resize( struct Message * a, unsigned long newsize, unsigned long oldsize )
{
    struct Message * b = ( struct Message * )malloc( sizeof(struct Message) * newsize );
		
	memcpy( b, a, sizeof(struct Message) * min( oldsize, newsize ) );
 
    free(a);
    
    return b;

}

char ReadDigit( unsigned short & digit, bool & doubleDigit )

{
 
  char ch;
 
  char*buffer = new char[10];
  
  *(buffer+10)='\0';
  
  char* pBuf = buffer;

  cout<<"buffer length = "<<strlen(buffer)<<"\n\n";

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
	
	if( control >= 5 )
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
  
   if( *buffer == 'q' && *(buffer+1) == '\0' )
   {
	  return '0';
   }
  else if(*buffer == '\0')
	  return '1';
  else if( IsDigit(buffer) )
	  return '2';

  for(int i=0; i<strlen(buffer)-1;i++)
  {
	  if( *( buffer + i ) == *( buffer + ( i + 1 ) ) )
		  doubleDigit = true;
	  else
		  doubleDigit = false;
  }


  digit = ( unsigned short )strtoul( buffer, NULL, 0 );

  if( digit < 0 )
	  return '3';
  else
	  return '4';

}

char ReadChar(  char* str )

{
  char ch;

  char*buffer = new  char[20];

   char* pBuf = buffer;

  *pBuf = (char)1;

   short control = 0, inc = 0;

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
	
	if( control >= strlen(str) )
		return '!';

	if( ch != 8 )
    *pBuf = ch;
	  
	printf("\r%80c\r", ' ');
	for( int i = 0; i < control; i++ )
		std::cout << *( ( pBuf - inc ) + i );
   
	if( ch != 8 )
	{
		inc++;
		++pBuf;
	}

  }
   *pBuf = '\0';
  
   if( *buffer == 'q' && *(buffer+1) == '\0' )
	  return '0';
   else if(*buffer == '\0')
	   return '1';
   
   strcpy(str,buffer);
  
   return '4';


}


bool ReadStruct( struct Message *mess, unsigned long i )
{
	( mess + i ) -> message = new char[20];

	if(!ReadAtribute( ( mess + i ) -> code, ( mess + i ) -> message, i, "Message", false, ( mess + i ) ->doubleDigit ) )
		return false;
	if(!ReadAtribute( ( mess + i ) -> code, "vbn", i, "Code", true, ( mess + i ) -> doubleDigit ) )
		return false;


	return true;

}



bool ReadAtribute(unsigned short & digit, char* str, unsigned long & i, char* atribute, bool isDigitt, bool & doubleDigit)
{
	char control;
	
	while(1)
		{
			cout << "\n\nEnter the " << i + 1 <<"  "<< atribute << ":  (q - quit)\n\n";
			
			if(isDigitt)
				control = ReadDigit(digit, doubleDigit);
			else
			{
				control = ReadChar(str);
			}

			switch(control)
			{
				case '0':
					return false;
				case '1':
					cout << "You didn't enter a thing!\n\n";
					continue;
				case '!':
					cout << "\n\nYou've entered to mach symbols!\n\n";
					continue;
				case '2':
					cout << "One of the symbols you've entered is not digit!\n\n";
					continue;
				case '3':
					cout << "\n\nYou can not enter negative year!\n\n";
					continue;
				default:
					if(isDigitt)
						cout << "\n\nThe" << atribute << " of the  "<< i + 1 <<" - message, you've entered : " << digit << "\n\n";
					else
						cout << "\n\nThe"<< i + 1 <<"  "<< atribute << " you've entered : " << str << "\n\n";
					break;

			}
			break;
		}
	return true;

}

void PrintStruct( struct Message *st, unsigned long m )
{

	cout << "\n\n    Code       Message    \n\n";
	
	for( int i  = 0; i < m; i++ )
		cout << setw(9) << (st + i) -> code << setw(11) << (st + i) -> message << "\n\n";

}

void Start()
{
	unsigned long newMessage=1;
	
	char question;
	
	bool q;
	

	Message* mess = (Message* )malloc(sizeof(Message) * newMessage);


	if(!ReadStruct( mess, newMessage-1 ))
	{
		free(mess);
		return;
	}

	Sort( mess, newMessage );

	DoubleDigit(mess, newMessage);

	PrintStruct( mess, newMessage );

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
			++newMessage;

			mess = Resize(mess, newMessage, newMessage-1);

				if(!ReadStruct(mess, newMessage-1))
				{
					free(mess);
					return;
				}

			Sort(mess, newMessage);

			DoubleDigit(mess, newMessage);

			PrintStruct(mess,newMessage);
		}
		else
			break;
	}

	free(mess);
	
	return;

}

void Sort ( struct Message *p, unsigned long m )
{

	struct Message * tmp = ( struct Message * )malloc( sizeof(struct Message) * m );

	memcpy( tmp, p, sizeof(struct Message) * m );

	struct Message * temp = ( struct Message * )malloc( sizeof(struct Message) );

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < m - 1; j++ )
			if( (tmp + j) -> code < (tmp + j + 1) -> code )
			{
				memcpy(temp, tmp + j, sizeof(struct Message) );
				memcpy( ( tmp + j ), ( tmp + j + 1 ), sizeof(struct Message) );
				memcpy( ( tmp + j + 1 ), temp, sizeof(struct Message) );
			}
	
	free(temp);

	memcpy( p, tmp, sizeof(struct Message) * m );

	free(tmp);

}

void DoubleDigit( struct Message *p, unsigned long m )
{
	bool check = false;
	
	for(int i=0; i<m; i++)
		if( (p+i) -> doubleDigit )
			check = true;

	if(check)
	{
		struct Message * tmp = ( struct Message * )malloc( sizeof(struct Message) );

		int count=0;

		for(int i=0; i<m; i++)
		{
			if( (p+i) -> doubleDigit )
			{
				if(count!=0)
					tmp = Resize(tmp, count+1, count);
				memcpy( tmp+count, p+i, sizeof(struct Message) );
				count++;
			}
		}


		PrintStruct(tmp,count);
	}
	else
		cout<<"\n\nThere is no messages with two side-by-side digits in the code!\n\n";

}