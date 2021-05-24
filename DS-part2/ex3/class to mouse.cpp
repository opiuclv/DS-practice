#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std ;

void Allroute ( char maze [][7], int x, int y ) ;
void Allroute2 ( char maze [][7], int x, int y ) ;
void Print ( char maze [][7] ) ;




class ForMouse {
	public :
	  int line = 0 ;
	  int straight = 0 ;
	  int numOfG = 0 ;
	  int x = 0 ;
	  int y = 0 ;
};



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

void Allroute ( char maze[][7] )
{
	ForMouse mouse ;
	maze[mouse.x][mouse.y] = 'V';                     // �⨫�L�����HV���

  if (maze[mouse.x][mouse.y+1] == 'G' && mouse.y != mouse.line - 1  ) {     // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
  if ( maze[mouse.x+1][mouse.y] == 'G' && mouse.x != mouse.straight - 1 ) {   // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x][mouse.y-1] == 'G' && mouse.y != 0 ) { // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x-1][mouse.y] == 'G' && mouse.x != 0 ) { // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if

	  if ( maze[mouse.x][mouse.y+1] == 'E' && mouse.y != mouse.line - 1 )                      // �p�G�k�䤣�O������� �N�V�k�K
		Allroute ( maze ) ;

    if ( maze[mouse.x+1][mouse.y] == 'E' && mouse.x != mouse.straight - 1 )                      // �V�U
		  Allroute ( maze ) ;
	  if ( maze[mouse.x][mouse.y-1] == 'E' && mouse.y != 0 )                      // �V��
	  	Allroute ( maze ) ;

    if ( maze[mouse.x-1][mouse.y] == 'E' && mouse.x != 0 )                      // �V�W
		Allroute ( maze );




} // Allroute


void Allroute2 ( char maze[][7] )
{
	ForMouse mouse ;
	maze[mouse.x][mouse.y] = 'V';                     // �⨫�L�����HV���

  if (maze[mouse.x][mouse.y+1] == 'G' && mouse.y != mouse.line - 1  ) {     // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if                                     
  if ( maze[mouse.x+1][mouse.y] == 'G' && mouse.x != mouse.straight - 1 ) {   // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x][mouse.y-1] == 'G' && mouse.y != 0 ) { // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x-1][mouse.y] == 'G' && mouse.x != 0 ) { // �p�G�O��������  �N�L�X�ӤK
    Print( maze ) ;
		return ;
	} // if
    
	  if ( maze[mouse.x][mouse.y+1] == 'E' && mouse.y != mouse.line - 1 )                      // �p�G�k�䤣�O������� �N�V�k�K
		Allroute2 ( maze ) ;
		
    if ( maze[mouse.x+1][mouse.y] == 'E' && mouse.x != mouse.straight - 1 )                      // �V�U
		  Allroute2 ( maze ) ;
	  if ( maze[mouse.x][mouse.y-1] == 'E' && mouse.y != 0 )                      // �V��
	  	Allroute2 ( maze ) ;
		
    if ( maze[mouse.x-1][mouse.y] == 'E' && mouse.x != 0 )                      // �V�W
		Allroute2 ( maze );

     
		
    maze[mouse.x][mouse.y] = 'E';
		


} // Allroute


int main()
{
	unsigned __int64 start = 0, input = 0 ;
	char maze[7][7] ;
	char temp ;
	
	ForMouse mouse ;
	
	
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
	
		if ( start == 0 )                                  // ���� 
            ; 
		
		else if ( start == 1 ) {                                 // ���j�ƦC 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			if ( input >= 311 || input <= 313 )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				if ( input == 311 )
				{
					FILE * fptr = fopen( "input311.txt", "rt" ) ;               //  �}���ɮצ�m 
					
					fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // ��e����  '66' Ū�� 
					fscanf( fptr, "%c", &temp ) ;                          // Ū�J�ťզr�� 
					
					for( int i = 0 ; i < mouse.line ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h 
					{ 
						for( int k = 0 ; k < mouse.straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // Ū�J�ťզr��

					} // for 
					
					
					Allroute ( maze ) ;

                    for ( int i = 0 ; i <= 5 ; i++ )
	                {
		              for ( int k = 0 ; k <= 5 ; k++ )

			             if (maze[i][k] == 'V') maze[i][k] = 'E' ;


	                } // for          // �i�h���  ( �Ҧ����| )
	        
	        		cout << '\n' ;
					Allroute2 ( maze ) ;

					
					
					
				} // if
				
				
				
				
				
				
				
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
			
		
		} // else if
	
		else if ( start == 2 ) {                                 // ���j�ƦC 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			if ( input >= 311 || input <= 313 )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				if ( input == 311 )
				{
					
					
					Print( maze ) ;
					
					
				} // if
				
				
				
				
				
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
			
			
			
			
		} // else if
	
	
		else
			cout << "Command does not exist!\n" ;
		
		
	} // while
	
	
	
	
	
	
	
	
	
	
	
} // main



