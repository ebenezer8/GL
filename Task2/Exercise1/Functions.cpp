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


struct Book * Resize( struct Book * a, unsigned long newsize, unsigned long oldsize )
{
    struct Book * b = ( struct Book * )malloc( sizeof(struct Book) * newsize );
		
	memcpy( b, a, sizeof(struct Book) * min( oldsize, newsize ) );
 
    free(a);
    
    return b;
}

char ReadDigit( unsigned short & digit )

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


bool ReadStruct( struct Book *book, unsigned long i )
{
	( book + i ) -> autor = new char[20];
	( book + i ) -> title = new char[20];
	( book + i ) -> notes = new char[20];

	if(!ReadAtribute( ( book + i ) -> year, ( book + i ) -> autor, i, "Author", false ) )
		return false;
	if(!ReadAtribute( ( book + i ) -> year, ( book + i ) -> title, i, "Title", false ) )
		return false;
	if(!ReadAtribute( ( book + i ) -> year, ( book + i ) -> notes, i, "Notes", false ) )
		return false;
	if(!ReadAtribute( ( book + i ) -> year, "vbn", i, "Year", true ) )
		return false;


	return true;
}



bool ReadAtribute(unsigned short & digit, char* str, unsigned long & i, char* atribute, bool isDigitt)
{
	char control;
	
	while(1)
		{
			cout << "\n\nEnter the " << atribute << " of the " << i + 1 << " book:  (q - quit)\n\n";
			
			if(isDigitt)
				control = ReadDigit(digit);
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
						cout << "\n\nThe" << atribute << " of the  "<< i + 1 <<" - book, you've entered : " << digit << "\n\n";
					else
						cout << "\n\nThe" << atribute << " of the  "<< i + 1 << " - book, you've entered : " << str << "\n\n";
					break;

			}
			break;
		}
	return true;
}

void PrintStruct( struct Book *st, unsigned long m )
{
	system("cls");

	cout << "\n\n    Autor       Title      Year      Notes\n\n";
	
	for( int i  = 0; i < m; i++ )
		cout << setw(9) << (st + i) -> autor << setw(11) << (st + i) -> title << setw(14) << (st + i) -> year << setw(24) << (st + i) -> notes << "\n\n";
}

void Start()
{
	unsigned long newBook=1;
	
	char question;
	
	bool q;
	

	Book* book = (Book* )malloc(sizeof(Book) * newBook);


	if(!ReadStruct( book, newBook-1 ))
	{
		free(book);
		return;
	}

	Sort( book, newBook );

	Before1970(book, newBook);

	PrintStruct( book, newBook );

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
			++newBook;

			book = Resize(book, newBook, newBook-1);

				if(!ReadStruct(book, newBook-1))
				{
					free(book);
					return;
				}

			Sort(book, newBook);

			Before1970(book, newBook);

			PrintStruct(book,newBook);
		}
		else
			break;
	}

	free(book);
	
	return;
}

void Sort ( struct Book *p, unsigned long m )
{

	struct Book * tmp = ( struct Book * )malloc( sizeof(struct Book) * m );

	memcpy( tmp, p, sizeof(struct Book) * m );

	struct Book * temp = ( struct Book * )malloc( sizeof(struct Book) );

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < m - 1; j++ )
			if( strcmp((tmp + j) -> autor , (tmp + j + 1) -> autor) == 1)
			{
				memcpy(temp, tmp + j, sizeof(struct Book) );
				memcpy( ( tmp + j ), ( tmp + j + 1 ), sizeof(struct Book) );
				memcpy( ( tmp + j + 1 ), temp, sizeof(struct Book) );
			}
	
	free(temp);

	memcpy( p, tmp, sizeof(struct Book) * m );

	free(tmp);
}

void Before1970( struct Book *p, unsigned long m )
{
	bool check = false;
	
	for(int i=0; i<m; i++)
		if((p+i)->year<1970)
			check = true;

	if(check)
	{
		struct Book * tmp = ( struct Book * )malloc( sizeof(struct Book) );

		int count=0;

		for(int i=0; i<m; i++)
		{
			if((p+i)->year < 1970)
			{
				if(count!=0)
					tmp = Resize(tmp, count+1, count);
				memcpy( tmp+count, p+i, sizeof(struct Book) );
				count++;
			}
		}


		PrintStruct(tmp,count);
	}
	else
		cout<<"\n\nThere is no book published before 1970!\n\n";
}