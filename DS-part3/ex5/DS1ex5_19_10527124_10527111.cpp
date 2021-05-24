
//  �I�|�z 10527111
//  �����q 10527124 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std ;

int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;
int queue[20][4] ;


void swap( int &a, int &b )        // �洫 
{
	int temp;
	temp = a;
	a = b;
	b= temp;
} // swap

void shellsort()
{
	clock_t start_time, end_time ;
	float total_time = 0 ;
	start_time = clock() ; // �פJ��l�ɶ� 
	int gap, num = 1 ;
	
	while ( queue[num][arrival] != 0 )        //  �p�⦳�X�� job 
		num = num + 1 ;
	
	for ( int h = num / 2 ; h > 0 ; h = h / 2 )
	{
		for ( int unsorted = h ; unsorted < num ; ++unsorted )
		{
			int loc = unsorted;
			int nextItem = queue[unsorted][arrival] ;
			int nextItem2 = queue[unsorted][jobID] ;
			while ( loc >= h )
			{
				if ( queue[ loc-h ][arrival] > nextItem )
				{
					swap( queue[loc][jobID], queue[loc-h][jobID] ) ;
					swap( queue[loc][arrival], queue[loc-h][arrival] ) ;
					swap( queue[loc][duration], queue[loc-h][duration] ) ;
					swap( queue[loc][timeout], queue[loc-h][timeout] ) ;
					
				} // if
				
				else if ( queue[ loc-h ][arrival] == nextItem )
				{
					if ( queue[ loc-h ][jobID] > nextItem2 )
					{
						swap( queue[loc][jobID], queue[loc-h][jobID] ) ;
						swap( queue[loc][arrival], queue[loc-h][arrival] ) ;
						swap( queue[loc][duration], queue[loc-h][duration] ) ;
						swap( queue[loc][timeout], queue[loc-h][timeout] ) ;
						
					} // if
					
					
				} // else if
				
				loc = loc - h ;
			} // while
			
			
				
			
			
		} // for
	} // for	
}

int main()
{
	unsigned __int64 start = 0, input = 0 ;
	int numofjob= 0 ;
	char ch, i = 0 ;
	
	clock_t start_time, end_time ;
	float total_time = 0 ;
	clock_t start_time1, end_time1 ;
	float total_time1 = 0 ;

	
	
	while ( true )
	{
		
		cout << "**** Shell Sort & FIFO Queue ***\n" ;
		cout << "* 0. Quit                      *\n" ;
		cout << "* 1. Sort a file by Shell Sort *\n" ;
		cout << "* 2. Simulate one FIFO queue   *\n" ;
		cout << "********************************\n" ;

		cout << "Input a command(0, 1, 2):" ;
		cin >> start ;
		cout << "\n" ;
	
		while( start < 0 || start > 2 )                    //  �p�G�O�t������ �N�@��Ū 
		{
			cout << "Command does not exist!\n" ;
			cout << "\n" ;
			
			cout << "**** Shell Sort & FIFO Queue ***\n" ;
			cout << "* 0. Quit                      *\n" ;
			cout << "* 1. Sort a file by Shell Sort *\n" ;
			cout << "* 2. Simulate one FIFO queue   *\n" ;
			cout << "********************************\n" ;
	
			cout << "Input a command(0, 1, 2):" ;
			cin >> start ;
			cout << "\n" ;
		
		} // while
	
		if ( start == 0 )                                  // ���� 
			exit(1) ; 
		
		else if ( start == 1 ) {
		
			cout << "Input a file number(ex.501) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
		    if ( input == 501 ) {
		    	
		    start_time = clock() ; // �פJ��l�ɶ� 
			
			FILE * fptr = fopen( "input502.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
				
				
				for( i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%d%d%d%d", &queue[i][jobID], &queue[i][arrival], &queue[i][duration], &queue[i][timeout] ) ;
					fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
					
				} // for
				
				numofjob = i - 1 ;          //  �]�wjob�ƶq 
				
				end_time = clock(); // �פJ�����ɶ� 
				
				
				shellsort() ;            // �Ƨ� 
				
			    for( i = 0 ; i < numofjob ; i++ )
			    {
                   printf( " %d ", queue[i][jobID]) ;
                   printf( " %d ", queue[i][arrival]) ;
                   printf( " %d ", queue[i][duration]) ;
                   printf( " %d \n", queue[i][timeout]) ;
					
		    	} // for

		        start_time1 = clock() ; // �פJ��l�ɶ�   	
				fptr = fopen( "output502.txt", "w" ) ;               //  �}���ɮצ�m 
				for( int i = 0 ; i < numofjob ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h 
				{ 
					fprintf( fptr, " %d ", queue[i][jobID] ) ;
					fprintf( fptr, " %d ", queue[i][arrival] ) ;
					fprintf( fptr, " %d ", queue[i][duration] ) ;
					fprintf( fptr, " %d ", queue[i][timeout] ) ;
					putc( '\n', fptr ) ;
					
					
				} // for
				
				fclose( fptr ) ;
		        end_time1 = clock(); // �פJ�����ɶ� 
			
				
		
			} // if
			

      /* CLOCKS_PER_SEC is defined at time.h */
    total_time = (float) (end_time - start_time)/CLOCKS_PER_SEC ;
      
    total_time = total_time * 1000 ;

    printf("Reading data : %f ms \n", total_time) ;
			
      /* CLOCKS_PER_SEC is defined at time.h */
    total_time1 = (float) (end_time1 - start_time1)/CLOCKS_PER_SEC ;
      
    total_time1 = total_time1 * 1000 ;

    printf("Writing data : %f ms \n", total_time1) ;
		    } // if input = 501 
			
			else
				cout << "Command does not exist!\n" ;	
				
		
		} // else if
		

	} // while
	
} // main

