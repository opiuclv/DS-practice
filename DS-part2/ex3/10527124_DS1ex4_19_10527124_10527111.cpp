// �ѹ����g�c
//  �I�|�z 10527111
//  �����q 10527124 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std ;

int x = 0, y = 0 ;

int for_first_time_to_find_G = 0 ;
int for_first_time_to_find_G2 = 0 ;

class Mouse {
	
	public :
		int out = 0 ;                           // �P�_�X�j�骺���� 
		int line = 0, straight = 0 ;
		int eat = 0;
		int walk = 0 ;
		int RouteLength = 0 ;
		char temp[20][20] ;                        //  �@�ӼȦs���}�C     ********* ���i��@�}�l����l��  


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

void Copymaze ( char maze[][20], char temp[][20] )                // �ƻs�g�c 
{
	for ( int i = 0 ; i < straight ; i++ )                 //   �q�Ĥ@�ӽƻs�L�h 
	{
		for ( int k = 0 ; k < line ; k++ ){
			temp[i][k] = maze[i][k] ;	
	    } // for
	} // for
	
	// printf ( "111" ) ;
	// printf( "%c\n", temp[8][10] ) ;
	// printf ( "222" ) ;	
} // Copymaze 



void HowMuchRRRRRR ( char maze[][20] )                       //   �P�_�s���o�����|���S�������  ( ����u�N��s maze ) 
{
	int num = 0 ;
	
	for ( int i = 0 ; i < straight ; i++ )                 //   �P�_�o�����|���X�� 'R' 
	{
		for ( int k = 0 ; k < line ; k++ )
			if ( maze[i][k] == 'R' )
				num = num + 1 ;
			
	} // for
	
	// printf( "This is num : %d\n", num) ;
	// printf( "This is route : %d\n", RouteLength ) ;
	
	// printf( "666" ) ;
	if ( for_first_time_to_find_G == 0 )     //   �p�G�L�O�Ĥ@���i�Ӫ���( �Ĥ@����� G )       ********************************************************************** 
	{
		// printf( "I'm here'" ) ;
		for_first_time_to_find_G = 1 ;
		RouteLength = num ;              // �]�w���� 
		 // printf( "Here is HowmuchR") ;
		Copymaze( maze, temp ) ;				 // �ƻs�g�c 
		
	} // if
	
	else                                     //  �_�h�N����|������ 
	{
		// printf( "This is num2 : %d\n", num) ;
		// printf( "This is route2 : %d\n", RouteLength ) ;
		// printf( "Here is HowmuchR2") ;
		if ( num < RouteLength )         // �p�G���|��u 
		{
			// printf( "Here is HowmuchR3") ;
			RouteLength = num ;              // �]�w���� 
			Copymaze( maze, temp ) ;				 // �ƻs�g�c 		
			
		} // if
		
		Print2( temp ) ;
	} // else	
	
} // HowMuchRRRRR

void HowMuchRRRRRR2 ( char maze[][20] )                       //   �P�_�s���o�����|���S�������  ( ����u�N��s maze ) 
{
	int num = 0 ;
	
	for ( int i = 0 ; i < straight ; i++ )                 //   �P�_�o�����|���X�� 'R' 
	{
		for ( int k = 0 ; k < line ; k++ )
			if ( maze[i][k] == 'R' )
				num = num + 1 ;
			
	} // for
	
	// printf( "This is num : %d\n", num) ;
	// printf( "This is route : %d\n", RouteLength ) ;
	
	// printf( "666" ) ;
	if ( for_first_time_to_find_G2 == 0 )     //   �p�G�L�O�Ĥ@���i�Ӫ���( �Ĥ@����� G )       ********************************************************************** 
	{
		// printf( "I'm here'" ) ;
		for_first_time_to_find_G2 = 1 ;
		RouteLength = num ;              // �]�w���� 
		 // printf( "Here is HowmuchR") ;
		Copymaze( maze, temp ) ;				 // �ƻs�g�c 
		
	} // if
	
	else                                     //  �_�h�N����|������ 
	{
		// printf( "This is num2 : %d\n", num) ;
		// printf( "This is route2 : %d\n", RouteLength ) ;
		// printf( "Here is HowmuchR2") ;
		if ( num < RouteLength )         // �p�G���|��u 
		{
			// printf( "Here is HowmuchR3") ;
			RouteLength = num ;              // �]�w���� 
			Copymaze( maze, temp ) ;				 // �ƻs�g�c 		
			
		} // if
		
	} // else	
	
} // HowMuchRRRRR2
void Allroute ( char maze[][20], int x, int y, int food )                   // ��X�Ҧ����|  ( 1�ӭ��� ) 
{
	
// if ( out == 1 ) {              //  �Y�쭹���N�����X�j�� 
	
	maze[x][y] = 'V';	                     // �⨫�L�����HV���
	
	// -----------------------------------------------  // 
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // �P�_�|�P���S������ �����ܴN�Y�L  ( �k )
    {
    	if ( out == 1 ) Print( maze ) ;
    	out = 1 ;
 
	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( �U )
    {
    	if ( out == 1 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( �� ) 
    {
    	if ( out == 1 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( �W  ) 
    {
    	if ( out == 1 ) Print( maze ) ;
 		out = 1 ;
	} // if


    // ---------------------------------------------------  //
    
    else
    {

    	if ( maze[x][y+1] == 'E' && y < line   ) {                    // �p�G�k�䤣�O������� �N�V�k�K
    	    // printf( "1" ) ;
	  		Allroute( maze, x, y+1, food ) ;
    	    // printf( "2" ) ;
	    } // if
		
   		if ( maze[x+1][y] == 'E' && x < straight  ) {                     // �V�U 
	   	    // printf( "3" ) ;
	  		Allroute( maze, x+1, y, food ) ;
    	    // printf( "4" ) ;
	    } // if
	  	
		if ( maze[x][y-1] == 'E' && y != 0 ) {                   // �V��
    	    // printf( "5" ) ;
	  		Allroute( maze, x, y-1, food ) ;
    	    // printf( "6" ) ;
	    } // if
		
   		if ( maze[x-1][y] == 'E' && x != 0 ) {                     // �V�W 
    	    // printf( "7" ) ;
	  		Allroute( maze, x-1, y, food );
    	    // printf( "8" ) ;
	    } // if
	
		
		 // if ( maze[x][y] = 'V' ) maze[x][y] = 'E' ;
		
	} // else
	
	
// } // if

	
} // Allroute



void OneRoute ( char maze[][20], int x, int y, int food )   //  ��X�@�����|  ( �H 'R' ��� )    �è��̵u���| 
{
	maze[x][y] = 'R';                      //  ���L�������O�� 'R' 
		
	// -----------------------------------------------  // 
	
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // �P�_�|�P���S������ �����ܴN�Y�L  ( �k )
    {
    	HowMuchRRRRRR ( maze ) ;                       //   �^�� R ���ƶq  ( ���|���� ) 

	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( �U )
    {
    	HowMuchRRRRRR ( maze ) ;
 
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( �� ) 
    {
    	HowMuchRRRRRR ( maze ) ;

	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( �W  ) 
    {
    	HowMuchRRRRRR ( maze ) ;
    	
	} // if


    // ---------------------------------------------------  //
    
    else
    {
    	if ( maze[x][y+1] == 'E' && y < line   )                      // �p�G�k�䤣�O������� �N�V�k�K
	  		OneRoute( maze, x, y+1, food ) ;
		
   		if ( maze[x+1][y] == 'E' && x < straight  )                      // �V�U
	  		OneRoute( maze, x+1, y, food ) ;
	  	
		if ( maze[x][y-1] == 'E' && y != 0 )                      // �V�� 
	  		OneRoute( maze, x, y-1, food ) ;
		
   		if ( maze[x-1][y] == 'E' && x != 0 )                      // �V�W 
	  		OneRoute( maze, x-1, y, food );
	  		
		
		maze[x][y] = 'E';	                     // �p�G�|�� if ���]���F �N��L�O���� ���N�N���令 'E' �קK���즺�� 
    	
    	
	} // else

	
} // OneRoute

void OneRoute2 ( char maze[][20], int x, int y, int food )   //  ��X�@�����|  ( �H 'R' ��� )    �è��̵u���| 
{
	maze[x][y] = 'R';                      //  ���L�������O�� 'R' 
		
	// -----------------------------------------------  // 
	
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // �P�_�|�P���S������ �����ܴN�Y�L  ( �k )
    {
    	HowMuchRRRRRR2 ( maze ) ;                       //   �^�� R ���ƶq  ( ���|���� ) 

	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( �U )
    {
    	HowMuchRRRRRR2 ( maze ) ;
 
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( �� ) 
    {
    	HowMuchRRRRRR2 ( maze ) ;

	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( �W  ) 
    {
    	HowMuchRRRRRR2 ( maze ) ;
    	
	} // if


    // ---------------------------------------------------  //
    
    else
    {
    	if ( maze[x][y+1] == 'E' && y < line   )                      // �p�G�k�䤣�O������� �N�V�k�K
	  		OneRoute2( maze, x, y+1, food ) ;
		
   		if ( maze[x+1][y] == 'E' && x < straight  )                      // �V�U
	  		OneRoute2( maze, x+1, y, food ) ;
	  	
		if ( maze[x][y-1] == 'E' && y != 0 )                      // �V�� 
	  		OneRoute2( maze, x, y-1, food ) ;
		
   		if ( maze[x-1][y] == 'E' && x != 0 )                      // �V�W 
	  		OneRoute2( maze, x-1, y, food );
	  		
		
		maze[x][y] = 'E';	                     // �p�G�|�� if ���]���F �N��L�O���� ���N�N���令 'E' �קK���즺�� 
    	
    	
	} // else

	
} // OneRoute2



//        ������������������������� 





void Allroute2 ( char maze[][20], int x, int y, int food  )                 //  ( �h�ӭ��� )
{	
// if ( out == 1 ) {              //  �Y�쭹���N�����X�j�� 
	
	maze[x][y] = 'V';	                     // �⨫�L�����HV���
	
	// -----------------------------------------------  // 
	
    if ( maze[x][y+1] == 'G' && y < line )                                 // �P�_�|�P���S������ �����ܴN�Y�L  ( �k )
    {
    	// if ( out == 0 ) Print( maze ) ;
    	out = 1 ;
 
	} // if
  	
  	else if ( maze[x+1][y] == 'G' && x < straight )                  //  ( �U )
    {
    	// if ( out == 0 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x][y-1] == 'G' && y != 0 )                           //  ( �� ) 
    {
    	// if ( out == 0 ) Print( maze ) ;
		out = 1 ;
	} // if
  	
  	else if ( maze[x-1][y] == 'G' && x != 0 )                                  //  ( �W  ) 
    {
    	// if ( out == 0 ) Print( maze ) ;
 		out = 1 ;
	} // if


    // ---------------------------------------------------  //
    
    else
    {

    	if ( maze[x][y+1] == 'E' && y < line   ) {                    // �p�G�k�䤣�O������� �N�V�k�K
    	    // printf( "1" ) ;
	  		Allroute2( maze, x, y+1, food ) ;
    	    // printf( "2" ) ;
	    } // if
		
   		if ( maze[x+1][y] == 'E' && x < straight  ) {                     // �V�U 
	   	    // printf( "3" ) ;
	  		Allroute2( maze, x+1, y, food ) ;
    	    // printf( "4" ) ;
	    } // if
	  	
		if ( maze[x][y-1] == 'E' && y != 0 ) {                   // �V��
    	    // printf( "5" ) ;
	  		Allroute2( maze, x, y-1, food ) ;
    	    // printf( "6" ) ;
	    } // if
		
   		if ( maze[x-1][y] == 'E' && x != 0 ) {                     // �V�W 
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
	char ch ;                                     // �Ψ�Ū�J�ťզr�� 
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
			exit(1) ; 
		
		else if ( start == 1 ) {
		
			cout << "Input a file number  (e.g., 411, 412, 413) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			if ( input == 412 ) { // **********************************************************************************
			
			FILE * fptr = fopen( "input412.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // ��e����  '66' Ū��
				fscanf( fptr, "%c", &ch ) ;                            // Ū�J�ťզr��
				
				cout << mouse.straight << " "<< mouse.line << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n"  );
					fscanf( fptr, "%c", &ch ) ;              // Ū�J�ťզr��

				} // for
				
				printf( "\n"  );
				
				food = 1 ;
				mouse.out = 0 ;
				mouse.Allroute( maze, x, y, food ) ;             // �i�h���  ( �Ҧ����| )
				
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 
				mouse.OneRoute( maze, x, y, food ) ;            // �i�h���  ( �������� )    �ç�X�̵u���| 
				
				cout << "�̵u���|���� = " << mouse.RouteLength << "\n" ; 
				
			} // if
			
		} // if
		
			else if ( input == 413 ) { // **********************************************************************************
			
			FILE * fptr = fopen( "input413.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // ��e����  '66' Ū��
				fscanf( fptr, "%c", &ch ) ;                            // Ū�J�ťզr��
				
				cout << mouse.straight << " "<< mouse.line << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n"  );
					fscanf( fptr, "%c", &ch ) ;              // Ū�J�ťզr��

				} // for
				
				printf( "\n"  );
				
				food = 1 ;
				mouse.out = 0 ;
				mouse.Allroute( maze, x, y, food ) ;             // �i�h���  ( �Ҧ����| )
				
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 
				mouse.OneRoute( maze, x, y, food ) ;            // �i�h���  ( �������� )    �ç�X�̵u���| 
				
				cout << "�̵u���|���� = " << mouse.RouteLength << "\n" ; 
				
			} // if
			
		} // else if
			
			else
				cout << "Command does not exist!\n" ;	
		
		} // else if
		
		else if ( start == 2 ) {
		
			cout << "Input a file number (e.g., 421, 422, 423):" ;
			cin >> input ;          // Ū�J�@�ӼƦr
					
			if ( input == 422 ) {
				
			FILE * fptr = fopen( "input422.txt", "rt" ) ;               //  �}���ɮצ�m
			
			if ( fptr )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // ��e����  '662' Ū��
				fscanf( fptr, "%c", &ch ) ;                          // Ū�J�ťզr�� 
				
				cout << mouse.line << " "<< mouse.straight << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n" ) ;
					fscanf( fptr, "%c", &ch ) ;              // Ū�J�ťզr��

				} // for

				printf( "\n" ) ;
				// mouse.ALLroute2( maze, x, y, food ) ;            // �i�h���  ( �Ҧ����| )
	
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 			
				mouse.Allroute2( maze, x, y, food ) ;             // �i�h���  ( �Ҧ����| )	
				mouse.Print( maze ) ;	
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 
				mouse.OneRoute2( maze, x, y, food ) ;            // �i�h���  ( �������� )    �ç�X�̵u���| 
				
				mouse.Print( mouse.temp ) ;
				
			    printf( "The shortest path to the nearest goal is as follows:\n" ) ;
				
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �L�y�� 
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
				
			FILE * fptr = fopen( "input423.txt", "rt" ) ;               //  �}���ɮצ�m
			
			if ( fptr )                  // �d�򥲶��b 311 ~ 313 ���� 
			{
				fscanf( fptr, "%d%d", &mouse.line, &mouse.straight ) ;                    // ��e����  '662' Ū��
				fscanf( fptr, "%c", &ch ) ;                          // Ū�J�ťզr�� 
				
				cout << mouse.line << " "<< mouse.straight << "\n" ; 
					
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h
				{ 
					for( int k = 0 ; k < mouse.line ; k++ ) {
					
						fscanf( fptr, "%c", &maze[i][k] ) ;
						printf( "%c", maze[i][k] ) ;
					} // for
					
					printf( "\n" ) ;
					fscanf( fptr, "%c", &ch ) ;              // Ū�J�ťզr��

				} // for

				printf( "\n" ) ;
				// mouse.ALLroute2( maze, x, y, food ) ;            // �i�h���  ( �Ҧ����| )
	
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 			
				mouse.Allroute2( maze, x, y, food ) ;             // �i�h���  ( �Ҧ����| )		
				mouse.SameMaze( maze ) ;                 		 // ���m�쥻���a�� 
				mouse.OneRoute2( maze, x, y, food ) ;            // �i�h���  ( �������� )    �ç�X�̵u���| 
				
			    printf( "The shortest path to the nearest goal is as follows:\n" ) ;
				
				mouse.Print( mouse.temp ) ;
				
				for( int i = 0 ; i < mouse.straight ; i++ )                      // �L�y�� 
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



