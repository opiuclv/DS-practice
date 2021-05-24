#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std ;

/*
class Mouse {
	public :
		int line = 0 ;
		int straight = 0 ;
		int numOfG = 0 ;
  
} // class
*/

int line = 0, straight = 0, numOfG = 0 ;

void Allroute ( char maze [][7], int x, int y ) ;
void Allroute2 ( char maze [][7], int x, int y ) ;
void Print ( char maze [][7] ) ;

void Print ( char maze[][7] )
{
	for ( int i = 0 ; i <= 5 ; i++ )
	{
		for ( int k = 0 ; k <= 5 ; k++ )
			cout << maze[i][k] ;
			
		cout << '\n' ;
			
	} // for
		
	cout << '\n' ;
	
} // Print

void Allroute ( char maze[][7], int x, int y )
{
	maze[x][y] = 'V';                     // �⨫�L�����HV���

    if (maze[x][y+1] == 'G' && y != line - 1  ) {     // �p�G�O��������  �N�L�X�ӤK
      printf( "123" ) ;
      Print( maze ) ;
      printf( "667" ) ;
	  return ;
    } // if
    printf( "2" ) ;
    
    if ( maze[x+1][y] == 'G' && x != straight - 1 ) {   // �p�G�O��������  �N�L�X�ӤK
      printf( "123" ) ;
      Print( maze ) ;
      printf( "668" ) ;
	  return ;
    } // if
    printf( "3" ) ;
    
    if ( maze[x][y-1] == 'G' && y != 0 ) { // �p�G�O��������  �N�L�X�ӤK
      printf( "123" ) ;
      Print( maze ) ;
      printf( "669" ) ;
	  return ;
    } // if
    printf( "4" ) ;
    
    if ( maze[x-1][y] == 'G' && x != 0 ) { // �p�G�O��������  �N�L�X�ӤK
      printf( "123" ) ;
      Print( maze ) ;
      printf( "662" ) ;
	  return ;
    } // if
    printf( "5" ) ;

    if ( maze[x][y+1] == 'E' && y != line - 1 )               // �p�G�k�䤣�O������� �N�V�k�K
  	    Allroute ( maze, x, y+1 ) ;

    if ( maze[x+1][y] == 'E' && x != straight - 1 )           // �V�U
		Allroute ( maze, x+1, y ) ;
		  
    if ( maze[x][y-1] == 'E' && y != 0 )                      // �V��
	  	Allroute ( maze, x, y-1 ) ;

    if ( maze[x-1][y] == 'E' && x != 0 )                      // �V�W
		Allroute ( maze, x-1, y );

} // Allroute


void Allroute2 ( char maze[][7], int x, int y )
{
	
    maze[x][y] = 'V';                     // �⨫�L�����HV���

    if (maze[x][y+1] == 'G' && y != line - 1  ) {     // �p�G�O��������  �N�L�X�ӤK
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if                                     
    if ( maze[x+1][y] == 'G' && x != straight - 1 ) {   // �p�G�O��������  �N�L�X�ӤK
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
	if ( maze[x][y-1] == 'G' && y != 0 ) { // �p�G�O��������  �N�L�X�ӤK
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
	if ( maze[x-1][y] == 'G' && x != 0 ) { // �p�G�O��������  �N�L�X�ӤK
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
    
	if ( maze[x][y+1] == 'E' && y != line - 1 )               // �p�G�k�䤣�O������� �N�V�k�K
		Allroute2 ( maze, x, y+1 ) ;
		
    if ( maze[x+1][y] == 'E' && x != straight - 1 )           // �V�U
		Allroute2 ( maze, x+1, y ) ;
		
	if ( maze[x][y-1] == 'E' && y != 0 )                      // �V��
	  	Allroute2 ( maze, x, y-1 ) ;
		
    if ( maze[x-1][y] == 'E' && x != 0 )                      // �V�W
		Allroute2 ( maze, x-1, y );

     
		
    maze[x][y] = 'E';
		


} // Allroute


int main()
{
	unsigned __int64 start = 0, input = 0 ;
	char maze[7][7] ;
	char temp ;
	int x = 0, y = 0 ;
	
	
	while ( true )
	{
		
		cout << "*** Path Finding ***\n" ;
		cout << "* 0. Quit          *\n" ;
		cout << "* 1. One goal      *\n" ;
		cout << "* 2. More goals    *\n" ;
		cout << "********************\n" ;

		cout << "Input a command(0, 1, 2):" ;
		cin >> start ;
		cout << "\n" ;
	
		while( start < 0 || start > 2 )                    //  �p�G�O�t������ �N�@��Ū 
		{
			cout << "Command does not exist!\n" ;
			cout << "\n" ;
			
			cout << "*** Path Finding ***\n" ;
			cout << "* 0. Quit          *\n" ;
			cout << "* 1. One goal      *\n" ;
			cout << "* 2. More goals    *\n" ;
			cout << "********************\n" ;
	
			cout << "Input a command(0, 1, 2):" ;
			cin >> start ;
			cout << "\n" ;
		
		} // while
	
		if ( start == 0 ) ;                           // ���� 

		else if ( start == 1 ) {                      // ���j�ƦC 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			if ( input >= 311 || input <= 313 )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				if ( input == 311 )
				{
					FILE * fptr = fopen( "input311.txt", "rt" ) ;          //  �}���ɮצ�m 
					
					fscanf( fptr, "%d%d", &line, &straight ) ;             // ��e����  '66' Ū�� 
					fscanf( fptr, "%c", &temp ) ;                          // Ū�J�ťզr�� 
					
					for( int i = 0 ; i < line ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h 
					{ 
						for( int k = 0 ; k < straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // Ū�J�ťզr��

					} // for 
					
					Allroute ( maze, x, y ) ;

                    for ( int i = 0 ; i <= 5 ; i++ )
	                {
		              for ( int k = 0 ; k <= 5 ; k++ )  if (maze[i][k] == 'V') maze[i][k] = 'E' ;
	                } // for          // �i�h���  ( �Ҧ����| )
	            
		            cout << '\n' ;
	        
					Allroute2 ( maze, x, y ) ;
	
				} // if		
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
			
		
		} // else if
	
		else if ( start == 2 ) {                                 // ���j�ƦC 
		
			cout << "Input a file number (e.g., 321, 322, 323):" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			if ( input >= 321 || input <= 323 )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				if ( input == 321 )
				{	
					FILE * fptr = fopen( "input321.txt", "rt" ) ;          //  �}���ɮצ�m 
					
					fscanf( fptr, "%d%d%d", &line, &straight, &numOfG ) ;  // ��e����  '66' Ū�� 
					fscanf( fptr, "%c", &temp ) ;                          // Ū�J�ťզr�� 
					
					for( int i = 0 ; i < line ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h 
					{ 
						for( int k = 0 ; k < straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // Ū�J�ťզr��

					} // for 	
					
					Allroute ( maze, x, y ) ;

                    for ( int i = 0 ; i <= 5 ; i++ ) {
		              for ( int k = 0 ; k <= 5 ; k++ )  if (maze[i][k] == 'V') maze[i][k] = 'E' ;
	                } // for          �i�h���  ( �Ҧ����| )
	        
		            cout << '\n' ;
	        
					Allroute2 ( maze, x, y ) ;			
	
				} // if		
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
		} // else if
	
	
		else
			cout << "Command does not exist!\n" ;
		
		
	} // while
	
	
	
	
	
	
	
	
	
	
	
} // main



