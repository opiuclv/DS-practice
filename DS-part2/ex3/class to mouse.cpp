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
	maze[mouse.x][mouse.y] = 'V';                     // 把走過的路以V表示

  if (maze[mouse.x][mouse.y+1] == 'G' && mouse.y != mouse.line - 1  ) {     // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
  if ( maze[mouse.x+1][mouse.y] == 'G' && mouse.x != mouse.straight - 1 ) {   // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x][mouse.y-1] == 'G' && mouse.y != 0 ) { // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x-1][mouse.y] == 'G' && mouse.x != 0 ) { // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if

	  if ( maze[mouse.x][mouse.y+1] == 'E' && mouse.y != mouse.line - 1 )                      // 如果右邊不是牆壁的話 就向右八
		Allroute ( maze ) ;

    if ( maze[mouse.x+1][mouse.y] == 'E' && mouse.x != mouse.straight - 1 )                      // 向下
		  Allroute ( maze ) ;
	  if ( maze[mouse.x][mouse.y-1] == 'E' && mouse.y != 0 )                      // 向左
	  	Allroute ( maze ) ;

    if ( maze[mouse.x-1][mouse.y] == 'E' && mouse.x != 0 )                      // 向上
		Allroute ( maze );




} // Allroute


void Allroute2 ( char maze[][7] )
{
	ForMouse mouse ;
	maze[mouse.x][mouse.y] = 'V';                     // 把走過的路以V表示

  if (maze[mouse.x][mouse.y+1] == 'G' && mouse.y != mouse.line - 1  ) {     // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if                                     
  if ( maze[mouse.x+1][mouse.y] == 'G' && mouse.x != mouse.straight - 1 ) {   // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x][mouse.y-1] == 'G' && mouse.y != 0 ) { // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
	if ( maze[mouse.x-1][mouse.y] == 'G' && mouse.x != 0 ) { // 如果是食物的話  就印出來八
    Print( maze ) ;
		return ;
	} // if
    
	  if ( maze[mouse.x][mouse.y+1] == 'E' && mouse.y != mouse.line - 1 )                      // 如果右邊不是牆壁的話 就向右八
		Allroute2 ( maze ) ;
		
    if ( maze[mouse.x+1][mouse.y] == 'E' && mouse.x != mouse.straight - 1 )                      // 向下
		  Allroute2 ( maze ) ;
	  if ( maze[mouse.x][mouse.y-1] == 'E' && mouse.y != 0 )                      // 向左
	  	Allroute2 ( maze ) ;
		
    if ( maze[mouse.x-1][mouse.y] == 'E' && mouse.x != 0 )                      // 向上
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
	
		while( start < 0 || start > 2 )                    //  如果是負號的話 就一直讀 
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
	
		if ( start == 0 )                                  // 結束 
            ; 
		
		else if ( start == 1 ) {                                 // 遞迴排列 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // 讀入一個數字
			
			if ( input >= 311 || input <= 313 )                  // 範圍必須在 311 ~ 313 之間 
			{
				if ( input == 311 )
				{
					FILE * fptr = fopen( "input311.txt", "rt" ) ;               //  開啟檔案位置 
					
					fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // 把前面的  '66' 讀掉 
					fscanf( fptr, "%c", &temp ) ;                          // 讀入空白字元 
					
					for( int i = 0 ; i < mouse.line ; i++ )                      // 將資料一個一個讀進去 
					{ 
						for( int k = 0 ; k < mouse.straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // 讀入空白字元

					} // for 
					
					
					Allroute ( maze ) ;

                    for ( int i = 0 ; i <= 5 ; i++ )
	                {
		              for ( int k = 0 ; k <= 5 ; k++ )

			             if (maze[i][k] == 'V') maze[i][k] = 'E' ;


	                } // for          // 進去找路  ( 所有路徑 )
	        
	        		cout << '\n' ;
					Allroute2 ( maze ) ;

					
					
					
				} // if
				
				
				
				
				
				
				
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
			
		
		} // else if
	
		else if ( start == 2 ) {                                 // 遞迴排列 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // 讀入一個數字
			
			if ( input >= 311 || input <= 313 )                  // 範圍必須在 311 ~ 313 之間 
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



