//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std; 
#define MAX_SIZE 5  //maximum size of the array that will store Queue. 

int a = 0 ;
float AllD = 0 ; // �Ω�p�⥭������ɶ� 
float AllS = 0 ; // �Ω�p�⥭�����\�v 
int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;
int inputJob[1000][4] ;
int AllTime = 0 ; // �Ω�����@�Ҧ��u�@���`��O�ɶ� 


void forSwap( int &a, int &b )        // �ƺ��ƧǪk 
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
	
	while ( inputJob[num][arrival] != 0 )        //  �p�⦳�X�� job 
		num = num + 1 ;
	
	for ( int h = num / 2 ; h > 0 ; h = h / 2 )
	{
		for ( int unsorted = h ; unsorted < num ; ++unsorted )
		{
			int loc = unsorted;
			int nextItem = inputJob[unsorted][arrival] ;
			int nextItem2 = inputJob[unsorted][jobID] ;
			while ( loc >= h )
			{
				if ( inputJob[ loc-h ][arrival] > nextItem )
				{
					forSwap( inputJob[loc][jobID], inputJob[loc-h][jobID] ) ;
					forSwap( inputJob[loc][arrival], inputJob[loc-h][arrival] ) ;
					forSwap( inputJob[loc][duration], inputJob[loc-h][duration] ) ;
					forSwap( inputJob[loc][timeout], inputJob[loc-h][timeout] ) ;
					
				} // if
				
				else if ( inputJob[ loc-h ][arrival] == nextItem )
				{
					if ( inputJob[ loc-h ][jobID] > nextItem2 )
					{
						forSwap( inputJob[loc][jobID], inputJob[loc-h][jobID] ) ;
						forSwap( inputJob[loc][arrival], inputJob[loc-h][arrival] ) ;
						forSwap( inputJob[loc][duration], inputJob[loc-h][duration] ) ;
						forSwap( inputJob[loc][timeout], inputJob[loc-h][timeout] ) ;
						
					} // if
					
					
				} // else if
				
				loc = loc - h ;
			} // while
			
			
		} // for
	} // for	
}


// Creating a class named Queue.

struct ForQueue { // queue���d�l  �n����Queue 
    int jobID2 ; 
    int arrival2 ;
    int duration2 ;
    int timeout2 ;
} ;

struct Abort { // �˱��d�l �n����vector 
    int jobID2 ; 
    int abort ;
    int delay ;
};

struct Done { // ���檺�d�l �n����vector 
    int jobID2 ; 
    int departure ;
    int delay ;
};
    
class Queue
{


public:
	
	ForQueue W[MAX_SIZE]; // queue�i�H�s�񪺪Ŷ��j�p 
	int front, rear; // �Ω���������}�C��ƪ��Y��� 
    vector<Abort> forAbort; // �s��˱�M�� 
    vector<Done> forDone; // �s�����M�� 
    Abort abandon ;
    Done DoJob ;

	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	// To check wheter Queue is empty or not

	void Done_job(int J, int A, int D, int T ) { // ���ƥ�i����M��Ϊ� 

		DoJob.jobID2 = J ;
		DoJob.departure = AllTime + D ;
		if ( AllTime == 0 ) DoJob.departure = DoJob.departure + A ;
		if ( AllTime == 0 ) DoJob.delay = 0 ;
		else DoJob.delay = AllTime - A ;

        forDone.push_back( DoJob ) ;

	}

	void Abort (int J, int A, int D, int T) {

		abandon.jobID2 = J ;
		if ( a == 1 ) abandon.abort = A ;
		else abandon.abort = AllTime ;
		if ( a == 1 ) abandon.delay = 0 ;
		else abandon.delay = AllTime - A ;
		
		a = 0 ;
		
        forAbort.push_back( abandon ) ;

	}
	
	bool IsEmpty() // �P�_Q���S���� 
	{
		return (front == -1 && rear == -1); 
	}

	// To check whether Queue is full or not
	bool IsFull()// �P�_Q�O���O���� 
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int J, int A, int D, int T) // ���ƥ�iQ 
	{
		if(IsFull())
		{
			cout<<"Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		
		W[rear].jobID2 = J;
		W[rear].arrival2 = A;
		W[rear].duration2 = D;
		W[rear].timeout2 = T;
	}

	// Removes an element in Queue from front end. 
	void Dequeue() // �R��Q����� 
	{
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	/* 
	   Printing the elements in queue from front to rear. 
	   This function is only to test the code. 
	   This is not a standard function for Queue implementation. 
	*/
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout << W[index].jobID2 << " " << W[index].arrival2 << " " << W[index].duration2 << " " << W[index].timeout2 << "\n" ;
		}
		cout<<"\n\n";
	}
};



int main()
{
	/*Driver Code to test the implementation
	  Printing the elements in Queue after each Enqueue or Dequeue 
	*/
	int i ;
    Queue Q; // creating an instance of Queue. 
    int front, rear;  
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
	float total_time2 ;
	int  forcount = 0 ;

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
				
				
				shellsort() ;
				
				printf( " %s ", ch1 ) ;
				printf( " %s ", ch2 ) ;
				printf( " %s ", ch3 ) ;
				printf( " %s ", ch4 ) ;
				printf( "\n" ) ;
				
			    for( int numP = 0 ; numP < numofjob - 1 ; numP ++ )
			    {
			       printf( "[%d]", numP ) ;
                   printf( " %d    ", inputJob[numP][jobID]) ;
                   printf( "  %d    ", inputJob[numP][arrival]) ;
                   printf( "  %d    ", inputJob[numP][duration]) ;
                   printf( "     %d \n", inputJob[numP][timeout]) ;
					
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
			
			Q.Done_job(inputJob[0][jobID], inputJob[0][arrival], inputJob[0][duration], inputJob[0][timeout]) ; // ��iDoneJob vector
			AllTime = AllTime + inputJob[0][arrival] + inputJob[0][duration] ;
			Q.Dequeue() ;
			
		
	        for( int i = 1 ; i < 6 && i < numofjob ; i++ )  {          //  �q1�}�l�A�M��̧�Ū�J5��job 
			    Q.Enqueue(inputJob[i][jobID], inputJob[i][arrival], inputJob[i][duration], inputJob[i][timeout]) ;
			} // for

	        for( int i = 6 ; i < numofjob ; i ++ )  {          //  ��5����ƶ}�l �n�P�_�n�Τ��n 
						
			    if ( AllTime <= Q.W[Q.front].arrival2 ) { // ���槹���b���檺�u�@�F
			        forcount = 0 ;
			        
			        for ( forcount = Q.front ; forcount <= Q.rear ; forcount ++ ) {
			    		if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			    			Q.Done_job(Q.W[forcount].jobID2, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// ��iDoneJob
							if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
							else AllTime = Q.W[forcount].arrival2 - AllTime + Q.W[forcount].duration2 ;
			    			Q.Dequeue() ;
						}
						else {
							Q.Abort(Q.W[forcount].jobID2, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // ��iAbort 
							Q.Dequeue() ;
						}
						
				    } // for
				    
				} // if(true)
				
			    if ( !Q.IsFull() && Q.rear!= 4 ) {
			    	// Q.Enqueue(inputJob[i][jobID], inputJob[i][arrival], inputJob[i][duration], inputJob[i][timeout]) ;
				}
				else {
					a = 1 ;
					Q.Abort(inputJob[i][jobID], inputJob[i][arrival], inputJob[i][duration], inputJob[i][timeout]) ; // ��iAbort
				}
			} // for
			
			
			for ( forcount = Q.front ; forcount <= Q.rear ; forcount ++ ) {
			        	
			    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			    	Q.Done_job(Q.W[forcount].jobID2, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// ��iDoneJob
					if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
					else AllTime = Q.W[forcount].arrival2 - AllTime + Q.W[forcount].duration2 ;
			    	Q.Dequeue() ;
				}
				else {
					Q.Abort(Q.W[forcount].jobID2, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // ��iAbort 
					Q.Dequeue() ;
				}
						
		    } // for
		    
		    printf("      [�˱�u�@�M��]\n") ;
			printf( "JobID  Abort  Delay\n") ;
			for ( int b = 0 ; b < Q.forAbort.size() ; b ++ ) {
		    	printf( "[%d] ", b + 1 ) ;
		    	printf( " %d", Q.forAbort[b].jobID2 ) ;
		    	printf( "     %d", Q.forAbort[b].abort ) ;
		    	printf( "     %d\n", Q.forAbort[b].delay ) ;
		    	AllD = AllD + Q.forAbort[b].delay ;
			}

		    printf("      [����u�@�M��]\n") ; 
			printf( "JobID  Departure  Delay\n") ;
		    for ( int a = 0 ; a < Q.forDone.size() ; a ++ ) {
		    	printf( "[%d] ", a + 1 ) ;
		    	printf( " %d", Q.forDone[a].jobID2 ) ;
		    	printf( "     %d", Q.forDone[a].departure ) ;
		    	printf( "     %d\n", Q.forDone[a].delay ) ;
		    	AllD = AllD + Q.forDone[a].delay ;
		    	AllS += 1 ;
			}
			
			 
			
			printf("����������� : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			printf("���\������ : %f %\n",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
		} // else if (start == 2)
	
	} // while

    return 0; 
} 
