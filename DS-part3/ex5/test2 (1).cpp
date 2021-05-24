
//  �I�|�z 10527111
//  �����q 10527124 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#define N = 6 

using namespace std ;

int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;
int inputJob[20][4] ;
int queue[N][4] ;

void createq(int*, int*); 
void enqueue(int*, int*, int); 
void dequeue(int*, int*); 

typedef struct Queue {
  int jobID2 ;
  int arrival2 ;
  int duration2 ;
  int timeout2 ;
} ;

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
	
	while ( inputJob[num][arrival] != 0 )        //  �p�⦳�X�� job 
		num = num + 1 ;
	
	gap = num / 2 ;
	
	while( gap >= 1 )
	{
		for( int i = 0 ; i < num-gap ; i++ )
		{
			if ( inputJob[i][arrival] > inputJob[i+gap][arrival] )          // �p�G�e��������j�A�N��p�����L�h 
			{
				swap( inputJob[i][jobID], inputJob[i+gap][jobID] ) ;
                swap( inputJob[i][arrival], inputJob[i+gap][arrival] ) ;
                swap( inputJob[i][duration], inputJob[i+gap][duration] ) ;
                swap( inputJob[i][timeout], inputJob[i+gap][timeout] ) ;
                
			} // if
			
			else if ( inputJob[i][arrival] == inputJob[i+gap][arrival] )       // �p�G�ۦP���ܡA���N�� "JobID" 
			{
				if ( inputJob[i][jobID] > inputJob[i+gap][jobID] )
				{
					swap( inputJob[i][jobID], inputJob[i+gap][jobID] ) ;
                	swap( inputJob[i][arrival], inputJob[i+gap][arrival] ) ;
                	swap( inputJob[i][duration], inputJob[i+gap][duration] ) ;
                	swap( inputJob[i][timeout], inputJob[i+gap][timeout] ) ;
					
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


bool abort( queue, n ) { // �P�_�n���n�ᱼ��job
    int sum = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) {
    	sum = sum + queue[i-1].arrival2 + queue[i-1].duration2 ;
	}
	
	if ( sum <= queue[i].timeout2 )
	    return true ;
	else
	    return false ;
} // abort()
 


int main(void) {  
    int front, rear; 
    int input, select; 
    Queue queue[] ;

    createq( queue, &front, &rear ); 

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
					fscanf( fptr, "%d%d%d%d", &inputJob[i][jobID], &inputJob[i][arrival], &inputJob[i][duration], &inputJob[i][timeout] ) ;
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
                   printf( " %d    ", inputJob[i][jobID]) ;
                   printf( "  %d    ", inputJob[i][arrival]) ;
                   printf( "  %d    ", inputJob[i][duration]) ;
                   printf( "     %d \n", inputJob[i][timeout]) ;
					
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
					fprintf( fptr, "  %d  ", inputJob[i][jobID] ) ;
					fprintf( fptr, "  %d  ", inputJob[i][arrival] ) ;
					fprintf( fptr, "  %d  ", inputJob[i][duration] ) ;
					fprintf( fptr, "  %d  \n", inputJob[i][timeout] ) ;
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
		
		
		else if ( start == 2 ) {	
		
		    if ( input == 501 ) {
		
			    FILE * fptr = fopen( "sort501.txt", "rt" ) ;               //  �}���ɮצ�m 	    
		    
		        if ( fptr )
	            {
		           fscanf( fptr, "%s%s%s%s%c", &ch1,&ch2,&ch3,&ch4,&ch5 ) ;     //  ��̫e���� "���Y and ����r��" Ū��
		        } // if
		        
		        inputSort( queue ) ; // ����Ū�i��
		        
				for( i = 0 ; !feof(fptr) && abort( queue, i ); i++ )            //  Ū�J 
				{
		            inputSort( queue ) ; // ����Ū�i��	
				} // for
		      
		        else
			        cout << "Command does not exist!\n" ;
		    } // if
		    
		    
		} // else if (start == 2)
		
		
		

	} // while

    return 0; 
} 

void createq(int* front, int* rear) { 
    int i; 

    for(i = 0; i < N; i++) 
        queue[i] = 0 ; 

    *front = *rear = 0; 
} 


void enqueue(int* front, int* rear, int data) { 
    int f, r; 
    f = *front; 
    r = *rear; 
    r = (r+1) % N; 

    if(f == r) { 
        printf("\n��C�w���I"); 
        return; 
    } 
    
    char ch ;			
	fscanf( fptr, "%d%d%d%d", &queue[r].jobID2, &queue[r].arrival2, &queue[r].duration2, &queue[r].timeout2 ) ;
	fscanf( fptr, "%c", &ch ) ;  //  ��ťզr��Ū�� 
    *rear = r; 
		
} 

void dequeue(int* front, int* rear) { 
    int f, r; 
    f = *front; 
    r = *rear; 

    if(f == r) { 
        printf("\n��C���šI"); 
        return; 
    } 

    f = (f+1) % N; 
    *front = f; 
} 

