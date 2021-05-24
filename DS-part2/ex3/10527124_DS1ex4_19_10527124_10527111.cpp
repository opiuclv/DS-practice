// 老鼠走迷宮
//  施育暘 10527111
//  邱正皓 10527124 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std ;

int x = 0, y = 0 ;

int for_first_time_to_find_G = 0 ;
int for_first_time_to_find_G2 = 0 ;

class Mouse {
	
	public :
		int out = 0 ;                           // 判斷出迴圈的條件 
		int line = 0, straight = 0 ;
		int eat = 0;
		int walk = 0 ;
		int RouteLength = 0 ;
		char temp[20][20] ;                        //  一個暫存的陣列     ********* 有可能一開始有初始值  


void Print ( char maze[][20] )
{
	for ( int i = 0 ; i < straight ; i++ )
	{
		for ( int k = 0 ; k < line ; k++ )
			cout << maze[i][k] ;
			
		cout << '\n' ;
			
	} // for
		
	cout << '\n' ;
	
} // Print

void Print2 ( char temp[][20] )
{
	for ( int i = 0 ; i < straight ; i++ )
	{
		for ( int k = 0 ; k < line ; k++ )
			cout << temp[i][k] ;
			
		cout << '\n' ;
			
	} // for
		
	cout << '\n' ;
	
} // Print

void SameMaze( char maze[][20] )
{
	for ( int i = 0 ; i < straight ; i++ )
		for ( int k = 0 ; k < line ; k++ )
		{
			if ( maze[i][k] == 'V' )
				maze[i][k] = 'E' ;
			
		} // for

} // SameMaze

void Copymaze ( char maze[][20], char temp[][20] )                // 複製迷宮 
{
	for ( int i = 0 ; i < straight ; i++ )                 //   從第一個複製過去 
	{
		for ( int k = 0 ; k < line ; k++ ){
			temp[i][k] = maze[i][k] ;	
	    } // for
	} // for
	
	// printf ( "111" ) ;
	// printf( "%c\n", temp[8][10] ) ;
	// printf ( "222" ) ;	
} // Copymaze 



void HowMuchRRRRRR ( char maze[][20] )                       //   判斷新的這條路徑有沒有比較長  ( 比較短就更新 maze ) 
{
	int num = 0 ;
	
	for ( int i = 0 ; i < straight ; i++ )                 //   判斷這條路徑有幾個 'R' 
	{
		for ( int k = 0 ; k < line ; k++ )
			if ( maze[i][k] == 'R' )
				num = num + 1 ;
			
	} // for
	
	// printf( "This is num : %d\n", num) ;
	// printf( "This is route : %d\n", RouteLength ) ;
	
	// printf( "666" ) ;
	if ( for_first_time_to_find_G == 0 )     //   如果他是第一次進來的話( 第一次找到 G )       ********************************************************************** 
	{
		// printf( "I'm here'" ) ;
		for_first_time_to_find_G = 1 ;
		RouteLength = num ;              // 設定長度 
		 // printf( "Here is HowmuchR") ;
		Copymaze( maze, temp ) ;				 // 複製迷宮 
		
	} // if
	
	else                                     //  否則就比路徑的長度 
	{
		// printf( "This is num2 : %d\n", num) ;
		// printf( "This is route2 : %d\n", RouteLength ) ;
		// printf( "Here is HowmuchR2") ;
		if ( num < RouteLength )         // 如果路徑更短 
		{
			// printf( "Here is HowmuchR3") ;
			RouteLength = num ;              // 設定長度 
			Copymaze( maze, temp ) ;				 // 複製迷宮 		
			
		} // if
		
		Print2( temp ) ;
	} // else	
	
} // HowMuchRRRRR

void HowMuchRRRRRR2 ( char maze[][20] )                       //   判斷新的這條路徑有沒有比較長  ( 比較短就更新 maze ) 
{
	int num = 0 ;
	
	for ( int i = 0 ; i < straight ; i++ )                 //   判斷這條路徑有幾個 'R' 
	{
		for ( int k = 0 ; k < line ; k++ )
			if ( maze[i][k] == 'R' )
				num = num + 1 ;
			
	} // for
	
	// printf( "This is num : %d\n", num) ;
	// printf( "This is route : %d\n", RouteLength ) ;
	
	// printf( "666" ) ;
	if ( for_first_time_to_find_G2 == 0 )     //   如果他是第一次進來的話( 第一次找到 G )       ********************************************************************** 
	{
		// printf( "I'm here'" ) ;
		for_first_time_to_find_G2 = 1 ;
		RouteLength = num ;              // 設定長度 
		 // printf( "Here is HowmuchR") ;
		Copymaze( maze, temp ) ;				 // 複製迷宮 
		
	} // if
	
	else                                     //  否則就比路徑的長度 
	{
		// printf( "This is num2 : %d\n", num) ;
		// printf( "This is route2 : %d\n", RouteLength ) ;
		// printf( "Here is HowmuchR2") ;
		if ( num < RouteLength )         // 如果路徑更短 
		{
			// printf( "Here is HowmuchR3") ;
			RouteLength = num ;              // 設定長度 
			Copymaze( maze, temp ) ;				 // 複製迷宮 		
			
		} // if
		
	} // else	
	
} // HowMuchRRRRR2
void Allroute ( char maze[][20], int x, int y, int food )                   // 找出所有路徑  ( 1個食物 ) 
{
	
// if ( out == 1 ) {              //  吃到食物就讓它出迴圈 
	
	maze[x][y] = 'V';	                     // 把走過的路以V表示
	
	// -----------------------------------------------  // 
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // 判斷四周有沒有食物 有的話就吃他  ( 右 )
    {
    	if ( out == 1 ) Print( maze ) ;
    	out = 1 ;
 
	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( 下 )
    {
    	if ( out == 1 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( 左 ) 
    {
    	if ( out == 1 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( 上  ) 
    {
    	if ( out == 1 ) Print( maze ) ;
 		out = 1 ;
	} // if


    // ---------------------------------------------------  //
    
    else
    {

    	if ( maze[x][y+1] == 'E' && y < line   ) {                    // 如果右邊不是牆壁的話 就向右八
    	    // printf( "1" ) ;
	  		Allroute( maze, x, y+1, food ) ;
    	    // printf( "2" ) ;
	    } // if
		
   		if ( maze[x+1][y] == 'E' && x < straight  ) {                     // 向下 
	   	    // printf( "3" ) ;
	  		Allroute( maze, x+1, y, food ) ;
    	    // printf( "4" ) ;
	    } // if
	  	
		if ( maze[x][y-1] == 'E' && y != 0 ) {                   // 向左
    	    // printf( "5" ) ;
	  		Allroute( maze, x, y-1, food ) ;
    	    // printf( "6" ) ;
	    } // if
		
   		if ( maze[x-1][y] == 'E' && x != 0 ) {                     // 向上 
    	    // printf( "7" ) ;
	  		Allroute( maze, x-1, y, food );
    	    // printf( "8" ) ;
	    } // if
	
		
		 // if ( maze[x][y] = 'V' ) maze[x][y] = 'E' ;
		
	} // else
	
	
// } // if

	
} // Allroute



void OneRoute ( char maze[][20], int x, int y, int food )   //  找出一條路徑  ( 以 'R' 表示 )    並取最短路徑 
{
	maze[x][y] = 'R';                      //  走過的路先記成 'R' 
		
	// -----------------------------------------------  // 
	
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // 判斷四周有沒有食物 有的話就吃他  ( 右 )
    {
    	HowMuchRRRRRR ( maze ) ;                       //   回傳 R 的數量  ( 路徑長度 ) 

	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( 下 )
    {
    	HowMuchRRRRRR ( maze ) ;
 
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( 左 ) 
    {
    	HowMuchRRRRRR ( maze ) ;

	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( 上  ) 
    {
    	HowMuchRRRRRR ( maze ) ;
    	
	} // if


    // ---------------------------------------------------  //
    
    else
    {
    	if ( maze[x][y+1] == 'E' && y < line   )                      // 如果右邊不是牆壁的話 就向右八
	  		OneRoute( maze, x, y+1, food ) ;
		
   		if ( maze[x+1][y] == 'E' && x < straight  )                      // 向下
	  		OneRoute( maze, x+1, y, food ) ;
	  	
		if ( maze[x][y-1] == 'E' && y != 0 )                      // 向左 
	  		OneRoute( maze, x, y-1, food ) ;
		
   		if ( maze[x-1][y] == 'E' && x != 0 )                      // 向上 
	  		OneRoute( maze, x-1, y, food );
	  		
		
		maze[x][y] = 'E';	                     // 如果四個 if 都跑完了 代表他是死路 那就將它改成 'E' 避免走到死路 
    	
    	
	} // else

	
} // OneRoute

void OneRoute2 ( char maze[][20], int x, int y, int food )   //  找出一條路徑  ( 以 'R' 表示 )    並取最短路徑 
{
	maze[x][y] = 'R';                      //  走過的路先記成 'R' 
		
	// -----------------------------------------------  // 
	
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // 判斷四周有沒有食物 有的話就吃他  ( 右 )
    {
    	HowMuchRRRRRR2 ( maze ) ;                       //   回傳 R 的數量  ( 路徑長度 ) 

	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( 下 )
    {
    	HowMuchRRRRRR2 ( maze ) ;
 
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( 左 ) 
    {
    	HowMuchRRRRRR2 ( maze ) ;

	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( 上  ) 
    {
    	HowMuchRRRRRR2 ( maze ) ;
    	
	} // if


    // ---------------------------------------------------  //
    
    else
    {
    	if ( maze[x][y+1] == 'E' && y < line   )                      // 如果右邊不是牆壁的話 就向右八
	  		OneRoute2( maze, x, y+1, food ) ;
		
   		if ( maze[x+1][y] == 'E' && x < straight  )                      // 向下
	  		OneRoute2( maze, x+1, y, food ) ;
	  	
		if ( maze[x][y-1] == 'E' && y != 0 )                      // 向左 
	  		OneRoute2( maze, x, y-1, food ) ;
		
   		if ( maze[x-1][y] == 'E' && x != 0 )                      // 向上 
	  		OneRoute2( maze, x-1, y, food );
	  		
		
		maze[x][y] = 'E';	                     // 如果四個 if 都跑完了 代表他是死路 那就將它改成 'E' 避免走到死路 
    	
    	
	} // else

	
} // OneRoute2



//        改改改改改改改改改改改改改改改改改改改改改改改改 





void Allroute2 ( char maze[][20], int x, int y, int food  )                 //  ( 多個食物 )
{	
// if ( out == 1 ) {              //  吃到食物就讓它出迴圈 
	
	maze[x][y] = 'V';	                     // 把走過的路以V表示
	
	// -----------------------------------------------  // 
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // 判斷四周有沒有食物 有的話就吃他  ( 右 )
    {
    	// if ( out == 0 ) Print( maze ) ;
    	out = 1 ;
 
	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( 下 )
    {
    	// if ( out == 0 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( 左 ) 
    {
    	// if ( out == 0 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( 上  ) 
    {
    	// if ( out == 0 ) Print( maze ) ;
 		out = 1 ;
	} // if


    // ---------------------------------------------------  //
    
    else
    {

    	if ( maze[x][y+1] == 'E' && y < line   ) {                    // 如果右邊不是牆壁的話 就向右八
    	    // printf( "1" ) ;
	  		Allroute2( maze, x, y+1, food ) ;
    	    // printf( "2" ) ;
	    } // if
		
   		if ( maze[x+1][y] == 'E' && x < straight  ) {                     // 向下 
	   	    // printf( "3" ) ;
	  		Allroute2( maze, x+1, y, food ) ;
    	    // printf( "4" ) ;
	    } // if
	  	
		if ( maze[x][y-1] == 'E' && y != 0 ) {                   // 向左
    	    // printf( "5" ) ;
	  		Allroute2( maze, x, y-1, food ) ;
    	    // printf( "6" ) ;
	    } // if
		
   		if ( maze[x-1][y] == 'E' && x != 0 ) {                     // 向上 
    	    // printf( "7" ) ;
	  		Allroute2( maze, x-1, y, food );
    	    // printf( "8" ) ;
	    } // if
	
		
		 // if ( maze[x][y] = 'V' ) maze[x][y] = 'E' ;
		
	} // else
	
	
// } // if
} // ALLroute2 





} ; // class 



int main()
{
	unsigned __int64 start = 0, input = 0 ;
	char maze[20][20] ;
	char ch ;                                     // 用來讀入空白字元 
	int x = 0, y = 0 ;
	int food = 0 ;
	int kkk = 0 ;
	
	int forCountCo = 0 ;
	
	
	Mouse mouse ;
	
	
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
			exit(1) ; 
		
		else if ( start == 1 ) {
		
			cout << "Input a file number  (e.g., 411, 412, 413) :" ;
			cin >> input ;          // 讀入一個數字
			
			if ( input == 412 ) { // **********************************************************************************
			
			FILE * fptr = fopen( "input412.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // 把前面的  '66' 讀掉
				fscanf( fptr, "%c", &ch ) ;                            // 讀入空白字元
				
				cout << mouse.straight << " "<< mouse.line << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 將資料一個一個讀進去
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n"  );
					fscanf( fptr, "%c", &ch ) ;              // 讀入空白字元

				} // for
				
				printf( "\n"  );
				
				food = 1 ;
				mouse.out = 0 ;
				mouse.Allroute( maze, x, y, food ) ;             // 進去找路  ( 所有路徑 )
				
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 
				mouse.OneRoute( maze, x, y, food ) ;            // 進去找路  ( 扣除死路 )    並找出最短路徑 
				
				cout << "最短路徑長度 = " << mouse.RouteLength << "\n" ; 
				
			} // if
			
		} // if
		
			else if ( input == 413 ) { // **********************************************************************************
			
			FILE * fptr = fopen( "input413.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // 把前面的  '66' 讀掉
				fscanf( fptr, "%c", &ch ) ;                            // 讀入空白字元
				
				cout << mouse.straight << " "<< mouse.line << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 將資料一個一個讀進去
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n"  );
					fscanf( fptr, "%c", &ch ) ;              // 讀入空白字元

				} // for
				
				printf( "\n"  );
				
				food = 1 ;
				mouse.out = 0 ;
				mouse.Allroute( maze, x, y, food ) ;             // 進去找路  ( 所有路徑 )
				
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 
				mouse.OneRoute( maze, x, y, food ) ;            // 進去找路  ( 扣除死路 )    並找出最短路徑 
				
				cout << "最短路徑長度 = " << mouse.RouteLength << "\n" ; 
				
			} // if
			
		} // else if
			
			else
				cout << "Command does not exist!\n" ;	
		
		} // else if
		
		else if ( start == 2 ) {
		
			cout << "Input a file number (e.g., 421, 422, 423):" ;
			cin >> input ;          // 讀入一個數字
					
			if ( input == 422 ) {
				
			FILE * fptr = fopen( "input422.txt", "rt" ) ;               //  開啟檔案位置
			
			if ( fptr )                  // 範圍必須在 311 ~ 313 之間 
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // 把前面的  '662' 讀掉
				fscanf( fptr, "%c", &ch ) ;                          // 讀入空白字元 
				
				cout << mouse.line << " "<< mouse.straight << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 將資料一個一個讀進去
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n" ) ;
					fscanf( fptr, "%c", &ch ) ;              // 讀入空白字元

				} // for

				printf( "\n" ) ;
				// mouse.ALLroute2( maze, x, y, food ) ;            // 進去找路  ( 所有路徑 )
	
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 			
				mouse.Allroute2( maze, x, y, food ) ;             // 進去找路  ( 所有路徑 )	
				mouse.Print( maze ) ;	
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 
				mouse.OneRoute2( maze, x, y, food ) ;            // 進去找路  ( 扣除死路 )    並找出最短路徑 
				
				mouse.Print( mouse.temp ) ;
				
			    printf( "The shortest path to the nearest goal is as follows:\n" ) ;
				
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 印座標 
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						if ( mouse.temp[i][k] == 'R' ) {
							forCountCo ++ ;
							printf( "[" ) ;
							printf( "%d", forCountCo ) ;
							printf( "] " ) ;
							printf( "( " ) ;
							printf( "%d", i ) ;
							printf( ", ") ;
							printf( "%d", k ) ;
							printf( " )\n" ) ;
						}
					} // for

				} // for
				
				forCountCo = 0 ;
				
					
			} // if
			
		} // if 
		
			else if ( input == 423 ) {
				
			FILE * fptr = fopen( "input423.txt", "rt" ) ;               //  開啟檔案位置
			
			if ( fptr )                  // 範圍必須在 311 ~ 313 之間 
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // 把前面的  '662' 讀掉
				fscanf( fptr, "%c", &ch ) ;                          // 讀入空白字元 
				
				cout << mouse.line << " "<< mouse.straight << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 將資料一個一個讀進去
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n" ) ;
					fscanf( fptr, "%c", &ch ) ;              // 讀入空白字元

				} // for

				printf( "\n" ) ;
				// mouse.ALLroute2( maze, x, y, food ) ;            // 進去找路  ( 所有路徑 )
	
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 			
				mouse.Allroute2( maze, x, y, food ) ;             // 進去找路  ( 所有路徑 )		
				mouse.SameMaze( maze ) ;                 		 // 重置原本的地圖 
				mouse.OneRoute2( maze, x, y, food ) ;            // 進去找路  ( 扣除死路 )    並找出最短路徑 
				
			    printf( "The shortest path to the nearest goal is as follows:\n" ) ;
				
				mouse.Print( mouse.temp ) ;
				
				for( int i = 0 ; i < mouse.straight ; i++ )                      // 印座標 
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						if ( mouse.temp[i][k] == 'R' ) {
							forCountCo ++ ;
							printf( "[" ) ;
							printf( "%d", forCountCo ) ;
							printf( "] " ) ;
							printf( "( " ) ;
							printf( "%d", i ) ;
							printf( ", ") ;
							printf( "%d", k ) ;
							printf( " )\n" ) ;
						}
					} // for

				} // for
				
				forCountCo = 0 ;
				
					
			} // if
			
		} // else if 
			
			else
				cout << "Command does not exist!\n" ;
			
		} // else if
	
	
		else
			cout << "Command does not exist!\n" ;
		
		
	} // while
} // main



