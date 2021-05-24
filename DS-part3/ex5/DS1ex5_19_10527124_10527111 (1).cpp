
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

void shellsort( float  &total_time2 )
{
	clock_t start_time, end_time ;
	start_time = clock() ; // �פJ��l�ɶ� 
	int gap, num = 1 ;
	
	while ( queue[num][arrival] != 0 )        //  �p�⦳�X�� job 
		num = num + 1 ;
	
	gap = num / 2 ;
	
	while( gap >= 1 )
	{
		for( int i = 0 ; i < num-gap ; i++ )
		{
			if ( queue[i][arrival] > queue[i+gap][arrival] )          // �p�G�e��������j�A�N��p�����L�h 
			{
				swap( queue[i][jobID], queue[i+gap][jobID] ) ;
                swap( queue[i][arrival], queue[i+gap][arrival] ) ;
                swap( queue[i][duration], queue[i+gap][duration] ) ;
                swap( queue[i][timeout], queue[i+gap][timeout] ) ;
                
			} // if
			
			else if ( queue[i][arrival] == queue[i+gap][arrival] )       // �p�G�ۦP���ܡA���N�� "JobID" 
			{
				if ( queue[i][jobID] > queue[i+gap][jobID] )
				{
					swap( queue[i][jobID], queue[i+gap][jobID] ) ;
                	swap( queue[i][arrival], queue[i+gap][arrival] ) ;
                	swap( queue[i][duration], queue[i+gap][duration] ) ;
                	swap( queue[i][timeout], queue[i+gap][timeout] ) ;
					
				} // if
				
			} // else if
			
		} // for
		
		gap = gap / 2 ;
		
	} // while
	
	end_time = clock(); // �פJ�����ɶ� 

      /* CLOCKS_PER_SEC is defined at time.h */
    total_time2 = (float) (end_time - start_time)/CLOCKS_PER_SEC ;
      
    total_time2 = total_time2 * 1000 ;
	
} // shellsort



int main()
{
	clock_t start_time, end_time ;
	float total_time = 0 ;
	clock_t start_time1, end_time1 ;
	float total_time1 = 0 ;
	unsigned __int64 start = 0, input = 0 ;
	int numofjob= 0 ;
	char ch1[100] ; 
	char ch2[100] ; 
    char ch3[100] ; 
	char ch4[100] ; 
	char ch5 ;
	char ch6 ;                                       // �Ψ�Ū�J�ťզr�� 
	int i ;
	float total_time2 ;
	
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
			
			FILE * fptr = fopen( "input501.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch1,&ch2,&ch3,&ch4,&ch5 ) ;     //  ��̫e���� "���Y and ����r��" Ū��
				
				
				for( i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%d%d%d%d", &queue[i][jobID], &queue[i][arrival], &queue[i][duration], &queue[i][timeout] ) ;
					fscanf( fptr, "%c", &ch6 ) ;         //  ��ťզr��Ū�� 
					
				} // for
				
				numofjob = i ;          //  �]�wjob�ƶq 
				
				end_time = clock(); // �פJ�����ɶ� 
				
				
				shellsort( total_time2 ) ;
				
				printf( " %s ", ch1 ) ;
				printf( " %s ", ch2 ) ;
				printf( " %s ", ch3 ) ;
				printf( " %s ", ch4 ) ;
				printf( "\n" ) ;
				
			    for( i = 0 ; i < numofjob - 1 ; i++ )
			    {
			       printf( "[%d]", i ) ;
                   printf( " %d    ", queue[i][jobID]) ;
                   printf( "  %d    ", queue[i][arrival]) ;
                   printf( "  %d    ", queue[i][duration]) ;
                   printf( "     %d \n", queue[i][timeout]) ;
					
		    	} // for

		        start_time1 = clock() ; // �פJ��l�ɶ�   	
				fptr = fopen( "sort501.txt", "w" ) ;               //  �}���ɮצ�m 
				
				fprintf( fptr, "   %s ", ch1 ) ;
				fprintf( fptr, " %s ", ch2 ) ;
			    fprintf( fptr, " %s ", ch3 ) ;
				fprintf( fptr, " %s ", ch4 ) ;
				putc( '\n', fptr ) ;
				for( int i = 0 ; i < numofjob - 1 ; i++ )                      // �N��Ƥ@�Ӥ@��Ū�i�h 
				{ 
				    fprintf( fptr, "[%d]", i ) ; 
					fprintf( fptr, "  %d  ", queue[i][jobID] ) ;
					fprintf( fptr, "  %d  ", queue[i][arrival] ) ;
					fprintf( fptr, "  %d  ", queue[i][duration] ) ;
					fprintf( fptr, "  %d  \n", queue[i][timeout] ) ;
					putc( '\n', fptr ) ;
					

					
				} // for
				
				fclose( fptr ) ;
		        end_time1 = clock(); // �פJ�����ɶ� 


      /* CLOCKS_PER_SEC is defined at time.h */
    total_time = (float) (end_time - start_time)/CLOCKS_PER_SEC ;
      
    total_time = total_time * 1000 ;

    printf("Reading data : %f ms \n", total_time) ;
			
      /* CLOCKS_PER_SEC is defined at time.h */
    total_time1 = (float) (end_time1 - start_time1)/CLOCKS_PER_SEC ;
      
    total_time1 = total_time1 * 1000 ;

    printf("Writing data : %f ms \n", total_time1) ;
	printf("Sorting data : %f ms \n", total_time2) ;			
				
		
			} // if
			

		    } // if input = 501 
			
			else
				cout << "Command does not exist!\n" ;	
				
		
		} // else if
		

	} // while
	
} // main

