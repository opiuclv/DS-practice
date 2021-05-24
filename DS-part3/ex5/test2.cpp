#include <stdio.h> 
#include <stdlib.h> 
#define N 10 

void createq(int[], int*, int*); 
void showfront(int[], int, int); 
void add(int[], int*, int*, int); 
void del(int[], int*, int*); 
void showqueue(int[], int, int); 

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

int main(void) { 
    int queue[N]; 
    int front, rear; 
    int input, select; 

    createq(queue, &front, &rear); 

    while(1) { 
        printf("\n\n�п�J�ﶵ(-1����)�G"); 
        printf("\n(1)���J�Ȧܦ�C"); 
        printf("\n(2)��ܦ�C�e��"); 
        printf("\n(3)�R���e�ݭ�"); 
        printf("\n(4)��ܩҦ����e"); 
        printf("\n$c>"); 
        scanf("%d", &select); 
        
        if(select == -1) 
            break; 

        switch(select) { 
            case 1: 
                printf("\n��J�ȡG"); 
                scanf("%d", &input); 
                add(queue, &front, &rear, input); 
                break; 
            case 2: 
                showfront(queue, front, rear); 
                break; 
            case 3: 
                del(queue, &front, &rear); 
                break; 
            case 4: 
                showqueue(queue, front, rear); 
                break; 
            default: 
                printf("\n�ﶵ���~�I"); 
        } 
    } 

    printf("\n"); 
    
    
    
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

    return 0; 
} 

void createq(int queue[], int* front, int* rear) { 
    int i; 

    for(i = 0; i < N; i++) 
        queue[i] = 0; 

    *front = *rear = 0; 
} 

void showfront(int queue[], int front, int rear) { 
    if(front == rear) 
        printf("\n��C���šI"); 
    else 
        printf("%d", queue[(front+1) % N]); 
} 

void add(int queue[], int* front, int* rear, int data) { 
    int f, r; 
    f = *front; 
    r = *rear; 
    r = (r+1) % N; 

    if(f == r) { 
        printf("\n��C�w���I"); 
        return; 
    } 

    queue[r] = data; 
    *rear = r; 
} 

void del(int queue[], int* front, int* rear) { 
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

void showqueue(int queue[], int front, int rear) { 
    int i; 

    printf("\n��C���e�G"); 
    for(i = (front+1) % N; i <= rear; i++) 
        printf("%d ", queue[i]); 
} 
