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
	maze[x][y] = 'V';                     // 把走過的路以V表示

    if (maze[x][y+1] == 'G' && y != line - 1  ) {     // 如果是食物的話  就印出來八
      printf( "123" ) ;
      Print( maze ) ;
      printf( "667" ) ;
	  return ;
    } // if
    printf( "2" ) ;
    
    if ( maze[x+1][y] == 'G' && x != straight - 1 ) {   // 如果是食物的話  就印出來八
      printf( "123" ) ;
      Print( maze ) ;
      printf( "668" ) ;
	  return ;
    } // if
    printf( "3" ) ;
    
    if ( maze[x][y-1] == 'G' && y != 0 ) { // 如果是食物的話  就印出來八
      printf( "123" ) ;
      Print( maze ) ;
      printf( "669" ) ;
	  return ;
    } // if
    printf( "4" ) ;
    
    if ( maze[x-1][y] == 'G' && x != 0 ) { // 如果是食物的話  就印出來八
      printf( "123" ) ;
      Print( maze ) ;
      printf( "662" ) ;
	  return ;
    } // if
    printf( "5" ) ;

    if ( maze[x][y+1] == 'E' && y != line - 1 )               // 如果右邊不是牆壁的話 就向右八
  	    Allroute ( maze, x, y+1 ) ;

    if ( maze[x+1][y] == 'E' && x != straight - 1 )           // 向下
		Allroute ( maze, x+1, y ) ;
		  
    if ( maze[x][y-1] == 'E' && y != 0 )                      // 向左
	  	Allroute ( maze, x, y-1 ) ;

    if ( maze[x-1][y] == 'E' && x != 0 )                      // 向上
		Allroute ( maze, x-1, y );

} // Allroute


void Allroute2 ( char maze[][7], int x, int y )
{
	
    maze[x][y] = 'V';                     // 把走過的路以V表示

    if (maze[x][y+1] == 'G' && y != line - 1  ) {     // 如果是食物的話  就印出來八
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if                                     
    if ( maze[x+1][y] == 'G' && x != straight - 1 ) {   // 如果是食物的話  就印出來八
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
	if ( maze[x][y-1] == 'G' && y != 0 ) { // 如果是食物的話  就印出來八
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
	if ( maze[x-1][y] == 'G' && x != 0 ) { // 如果是食物的話  就印出來八
      printf( "321" ) ;
      Print( maze ) ;
	  return ;
	} // if
    
	if ( maze[x][y+1] == 'E' && y != line - 1 )               // 如果右邊不是牆壁的話 就向右八
		Allroute2 ( maze, x, y+1 ) ;
		
    if ( maze[x+1][y] == 'E' && x != straight - 1 )           // 向下
		Allroute2 ( maze, x+1, y ) ;
		
	if ( maze[x][y-1] == 'E' && y != 0 )                      // 向左
	  	Allroute2 ( maze, x, y-1 ) ;
		
    if ( maze[x-1][y] == 'E' && x != 0 )                      // 向上
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
	
		if ( start == 0 ) ;                           // 結束 

		else if ( start == 1 ) {                      // 遞迴排列 
		
			cout << "Input a file number (e.g., 311, 312, 313):" ;
			cin >> input ;          // 讀入一個數字
			
			if ( input >= 311 || input <= 313 )                  // 範圍必須在 311 ~ 313 之間 
			{
				if ( input == 311 )
				{
					FILE * fptr = fopen( "input311.txt", "rt" ) ;          //  開啟檔案位置 
					
					fscanf( fptr, "%d%d", &line, &straight ) ;             // 把前面的  '66' 讀掉 
					fscanf( fptr, "%c", &temp ) ;                          // 讀入空白字元 
					
					for( int i = 0 ; i < line ; i++ )                      // 將資料一個一個讀進去 
					{ 
						for( int k = 0 ; k < straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // 讀入空白字元

					} // for 
					
					Allroute ( maze, x, y ) ;

                    for ( int i = 0 ; i <= 5 ; i++ )
	                {
		              for ( int k = 0 ; k <= 5 ; k++ )  if (maze[i][k] == 'V') maze[i][k] = 'E' ;
	                } // for          // 進去找路  ( 所有路徑 )
	            
		            cout << '\n' ;
	        
					Allroute2 ( maze, x, y ) ;
	
				} // if		
				
			} // if
			
			else
				cout << "Command does not exist!\n" ;
			
			
		
		} // else if
	
		else if ( start == 2 ) {                                 // 遞迴排列 
		
			cout << "Input a file number (e.g., 321, 322, 323):" ;
			cin >> input ;          // 讀入一個數字
			
			if ( input >= 321 || input <= 323 )                  // 範圍必須在 311 ~ 313 之間 
			{
				if ( input == 321 )
				{	
					FILE * fptr = fopen( "input321.txt", "rt" ) ;          //  開啟檔案位置 
					
					fscanf( fptr, "%d%d%d", &line, &straight, &numOfG ) ;  // 把前面的  '66' 讀掉 
					fscanf( fptr, "%c", &temp ) ;                          // 讀入空白字元 
					
					for( int i = 0 ; i < line ; i++ )                      // 將資料一個一個讀進去 
					{ 
						for( int k = 0 ; k < straight ; k++ )
							fscanf( fptr, "%c", &maze[i][k] ) ;
						
						fscanf( fptr, "%c", &temp ) ;              // 讀入空白字元

					} // for 	
					
					Allroute ( maze, x, y ) ;

                    for ( int i = 0 ; i <= 5 ; i++ ) {
		              for ( int k = 0 ; k <= 5 ; k++ )  if (maze[i][k] == 'V') maze[i][k] = 'E' ;
	                } // for          進去找路  ( 所有路徑 )
	        
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



