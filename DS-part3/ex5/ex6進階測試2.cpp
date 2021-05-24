//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std; 

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////�o�̥������OQ1//////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define MAX_SIZE 3  //maximum size of the array that will store Queue. 

int a = 0 ;
float AllD = 0 ;
float AllS = 0 ;
int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;
int inputJob[1000][4] ;
int AllTime = 0 ; // �Ω�����@�Ҧ��u�@���`��O�ɶ� 
int AllTime2 = 0 ; // �Ω�����@�Ҧ��u�@���`��O�ɶ� 
int judgefordone = 0 ; // �Ω�P�_Q2�i�JDone_job 


void forSwap( int &a, int &b )        // �洫 
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

struct ForQueue {
    int jobID2 ; 
    int arrival2 ;
    int duration2 ;
    int timeout2 ;
} ;

struct Abort {
    int jobID2 ;
	int cpu ; 
    int abort ;
    int delay ;
};

struct Done {
    int jobID2 ; 
    int cpu ;
    int departure ;
    int delay ;
};
    
class Queue
{


public:
	
	ForQueue W[MAX_SIZE];
	int front, rear; 
    vector<Abort> forAbort;
    vector<Done> forDone;
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

	void Done_job(int J, int C , int A, int D, int T ) {
		
		DoJob.jobID2 = 0 ;
		DoJob.departure = 0 ;
		DoJob.delay = 0 ;
		
		DoJob.jobID2 = J ;
		DoJob.cpu = C ;
		
		if ( AllTime == 0 ) DoJob.departure = A + D ;
		if ( AllTime == 0 ) DoJob.delay = 0 ;
		else {
		    DoJob.delay = AllTime - A ; // (�ݦA�]�pAllTime2�����p)  
		    DoJob.departure = AllTime + D ;
	    }	
		
		if ( judgefordone = 1 && AllTime2 == 0 ) DoJob.departure = A + D ;
		if ( judgefordone = 1 && AllTime2 == 0 ) DoJob.delay = 0 ;
		if ( judgefordone = 1 && AllTime2 != 0 ) {
		    DoJob.delay = AllTime2 - A ; // (�ݦA�]�pAllTime2�����p) 
		    DoJob.departure = AllTime2 + D ;
	    }
		
		judgefordone = 0 ;

        forDone.push_back( DoJob ) ;

	}

	void Abort (int J, int C, int A, int D, int T) { // �٨S��!!!!!!!!!!!!!!!!!!! 

		abandon.jobID2 = J ;
		abandon.cpu = C ;
		abandon.abort = 0 ;
		abandon.delay = 0 ;
		
		if ( a == 1 ) abandon.abort = A ;
		else abandon.abort = AllTime ;
		if ( a == 1 ) abandon.delay = 0 ;
		else abandon.delay = AllTime - A ;
		
		a = 0 ;
		
        forAbort.push_back( abandon ) ;

	}
	
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int J, int A, int D, int T)
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
	void Dequeue()
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



// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////�o�̥������OQ2//////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#define MAX_SIZE2 3  //maximum size of the array that will store Queue. 


// Creating a class named Queue.

struct ForQueue2 {
    int jobID2 ; 
    int arrival2 ;
    int duration2 ;
    int timeout2 ;
} ;
    
class Queue2
{


public:
	
	ForQueue2 W[MAX_SIZE2];
	int front, rear; 

	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	
	Queue2()
	{
		front = -1; 
		rear = -1;
	}

	// To check wheter Queue is empty or not

	
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int J, int A, int D, int T)
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
	void Dequeue()
	{
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty2\n";
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


bool SQF1( int A ) { // ��� CPU ���O�ߧY�i�Ϊ��]�u�i�ήɨ�v�����B��C�O�Ū��^�G�� 1 �� CPU�A�ߧY����α˱�o�@���s�u�@�C
    Queue Q ;
    Queue2 Q2 ;
	if (Q.rear == 0 && Q2.rear == 0 || AllTime == 0 || AllTime2 == 0 && AllTime <= A && AllTime2 <= A ) return true ;
	else return false ;
}
bool SQF2( int A ) { // �u���@�� CPU �O�ߧY�i�Ϊ��G��ߧY�i�Ϊ� CPU�A�ߧY����α˱�o�@���s�u�@�C
    Queue Q ;
    Queue2 Q2 ;
	if (Q.rear == 0 && Q2.rear != 0 || Q.rear != 0 && Q2.rear == 0 ) return true ;
	else return false ;
}
bool SQF3() { // ��� CPU �����O�ߧY�i�Ϊ��A�B�ܤ֤@�Ӧ�C�ëD�����G
              // ���C���ס]�s��u�@���ơ^2�̵u�� CPU�F�Y��̵����A�h�� 1 �� CPU�A�N�s�u�@��J���C�C
    Queue Q ;
    Queue2 Q2 ;
	if ( !Q.IsFull() || !Q2.IsFull() ) return true ;
	else return false ;	
}
bool SQF4() { // ��� CPU �����O�ߧY�i�Ϊ��A�ӥB��Ӧ�C�����G�ߧY�˱�s�u�@�A�y�˱�u�@�M��z���uCPU �s���v�]�w�� 0 ���C
    Queue Q ;
    Queue2 Q2 ;
	if (Q.rear == 2 && Q2.rear == 2 ) return true ;
	else return false ;	
}


// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	/*
	  Driver Code to test the implementation
	  Printing the elements in Queue after each Enqueue or Dequeue 
	*/
	int i ;
    Queue Q; // creating an instance of Queue. 
    Queue2 Q2;
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
	int  forcount2 = 0 ;

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
		
			cout << "Input a file number(ex.601) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
		    if ( input == 601 ) {
		    	
		    start_time = clock() ; // �פJ��l�ɶ� 
			
			FILE * fptr = fopen( "input601.txt", "rt" ) ;               //  �}���ɮצ�m 
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
		
		
		
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		
		else if ( start == 2 ) {
			
			for ( int i = 0 ; AllTime == 0 || AllTime <= inputJob[i][arrival] ; i ++ ) { // �p�G���槹�F�i�O�ĤG���u�@�٨S��arrival�N�A��iQ1�@�� 
				Q.Done_job(inputJob[0][jobID],1 , inputJob[0][arrival], inputJob[0][duration], inputJob[0][timeout]) ; // �Ĥ@�Ӥ@�w�O��iQ1 
				AllTime = AllTime + inputJob[0][arrival] + inputJob[0][duration] ;
				Q.Dequeue() ;
		    } // for
			
			judgefordone = 1 ;
			Q.Done_job(inputJob[1][jobID],2 , inputJob[1][arrival], inputJob[1][duration], inputJob[1][timeout]) ; // ��2�ӥ�Q2 (�ݦA�ҶqQ1�٨S���槹butQ2�w���槹!!!!!!!!!!)
			AllTime2 = AllTime2 + inputJob[1][arrival] + inputJob[1][duration] ;
			Q.Dequeue() ;
			
		
	        for( int num = 2 ; num < numofjob - 1 ; num++ )  {          //  �P�_�n�����Q s
	        
	            printf("PP  ") ;

				if ( inputJob[num][arrival] >= AllTime || inputJob[num][arrival] >= AllTime2 ) { // �ˬd�e�� 
				
				    for( int forcount = Q.front ; forcount <= Q.rear ; forcount ++ ) {
						printf(" �}�} \n")  ;
	
						if ( AllTime <= AllTime2 && Q.W[Q.front].arrival2 != 0 ) {
		
							printf("�~�~�ڬO�i�Ӫ�id = %d \n", Q.W[forcount].jobID2 ) ;

						    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
						    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// ��iDoneJob
								if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
								else AllTime = Q.W[forcount].arrival2 + Q.W[forcount].duration2 ;
						    	Q.Dequeue() ;
							}
							else {
								Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // ��iAbort 
								Q.Dequeue() ;
							}
		
						}
						if ( AllTime2 < AllTime && Q2.W[Q2.front].arrival2 != 0 ) {
							printf("�����ڬO�i�Ӫ�id = %d \n", Q2.W[forcount].jobID2 ) ;

			 			    if ( AllTime2 + Q2.W[forcount].duration2 <= Q2.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			 			        printf("�����ڬO�i�Ӫ�id2 = %d \n", Q2.W[forcount].jobID2 ) ;
			 			        judgefordone = 1 ;
						    	Q.Done_job(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ;// ��iDoneJob
								if ( AllTime2 >= Q2.W[forcount].arrival2 ) AllTime2 = AllTime + Q2.W[forcount].duration2 ;
								else AllTime2 = Q2.W[forcount].arrival2 + Q2.W[forcount].duration2 ;
						    	Q2.Dequeue() ;
							}
							else {
								printf("�����ڬO�i�Ӫ�id3 = %d \n", Q2.W[forcount].jobID2 ) ;
								Q.Abort(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ; // ��iAbort 
								Q2.Dequeue() ;
							}
						}		
			    	} // for
				}
	        
	            if ( SQF1( inputJob[num][arrival] ) ){ // ��� CPU ���O�ߧY�i�Ϊ��]�u�i�ήɨ�v�����B��C�O�Ū��^�G�� 1 �� CPU�A�ߧY����α˱�o�@���s�u�@�C
	            printf("  hihi1 = %d \n", inputJob[num][jobID] ) ;
	            	Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else if ( SQF2( inputJob[num][arrival] ) ){ // �u���@�� CPU �O�ߧY�i�Ϊ��G��ߧY�i�Ϊ� CPU�A�ߧY����α˱�o�@���s�u�@�C 
	            printf("  hihi2 = %d \n", inputJob[num][jobID] ) ;
	            	if ( Q.rear == 0 ) Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
	            	else Q2.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else if ( SQF3() ){ // ��� CPU �����O�ߧY�i�Ϊ��A�B�ܤ֤@�Ӧ�C�ëD�����G
                // ���C���ס]�s��u�@���ơ^2�̵u�� CPU�F�Y��̵����A�h�� 1 �� CPU�A�N�s�u�@��J���C�C
                printf("  hihi3 = %d \n", inputJob[num][jobID] ) ; // 104�S���i 
	            	if ( Q.rear <= Q2.rear ) Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
	            	else Q2.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else{ // ��� CPU �����O�ߧY�i�Ϊ��A�ӥB��Ӧ�C�����G�ߧY�˱�s�u�@�A�y�˱�u�@�M��z���uCPU �s���v�]�w�� 0 ���C
	            	Q.Abort(inputJob[num][jobID],0 , inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
				
			
			} // for


for ( int num = Q.front ; num <= Q.rear ; num ++ ){

printf("Q1 ID = %d\n", Q.W[num].jobID2 ) ;
printf("Q1 A = %d\n\n", Q.W[num].arrival2 ) ;

} // for

for ( int num2 = Q2.front ; num2 <= Q2.rear ; num2 ++ ){

printf("Q2 ID = %d\n", Q2.W[num2].jobID2 ) ;
printf("Q2 A = %d\n\n", Q2.W[num2].arrival2 ) ;

} // for
			
	int forcount = Q.front ;
    int forcount2 = Q2.front ;			
			
	while ( !Q.IsEmpty() || !Q2.IsEmpty() && forcount <= Q.rear && forcount2 <= Q2.rear ) {
	
		if ( AllTime <= AllTime2 && Q.W[forcount].arrival2 <= Q2.W[forcount].arrival2 || forcount2 == Q2.rear ) {
  	            printf(" WWEE ") ;
			    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			        judgefordone = 0 ;
			    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// ��iDoneJob
					if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
					else AllTime = Q.W[forcount].arrival2 - AllTime + Q.W[forcount].duration2 ;
			    	Q.Dequeue() ;
				}
				else {
					Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // ��iAbort 
					Q.Dequeue() ;
				}
						
                if (!Q.IsEmpty()) forcount = forcount + 1 ;
		    
		}
		    
		else {
		
		        printf( "GG\n" ) ;	
			    if ( AllTime2 + Q2.W[forcount2].duration2 <= Q2.W[forcount2].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			        judgefordone = 0 ;
			    	Q.Done_job(Q2.W[forcount2].jobID2,2 , Q2.W[forcount2].arrival2, Q2.W[forcount2].duration2, Q2.W[forcount2].timeout2) ;// ��iDoneJob
					if ( AllTime2 >= Q2.W[forcount2].arrival2 ) AllTime2 = AllTime2 + Q2.W[forcount2].duration2 ;
					else AllTime2 = Q2.W[forcount2].arrival2 - AllTime2 + Q2.W[forcount2].duration2 ;
			    	Q2.Dequeue() ;
				}
				else {
					Q.Abort(Q2.W[forcount2].jobID2,2 , Q2.W[forcount2].arrival2, Q2.W[forcount2].duration2, Q2.W[forcount2].timeout2) ; // ��iAbort 
					Q2.Dequeue() ;
				}
				
				if (!Q.IsEmpty()) forcount2 = forcount2 + 1 ;
						
		    
	    }
	
    } // while
    
    
			for ( int forcount = Q.front ; !Q.IsEmpty() && forcount < Q.rear ; forcount ++ ) {
			    printf("   HHHEEELLO  ") ;
			    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			        judgefordone = 0 ;
			    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// ��iDoneJob
					if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
					else AllTime = Q.W[forcount].arrival2 + Q.W[forcount].duration2 ;
			    	Q.Dequeue() ;
				}
				else {
					Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // ��iAbort 
					Q.Dequeue() ;
				}
						
		    } // for
		    
			for ( int forcount = Q2.front ; !Q2.IsEmpty() && forcount < Q2.rear ; forcount ++ ) {
			    printf("   HHHEEELLO2  ") ;  	
			    if ( AllTime2 + Q2.W[forcount].duration2 <= Q2.W[forcount].timeout2 ) { // �bqueue���u�@�ǦC�����Ĥ@��P�_���L�O�� 
			        judgefordone = 0 ;
			    	Q.Done_job(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ;// ��iDoneJob
					if ( AllTime2 >= Q2.W[forcount].arrival2 ) AllTime2 = AllTime2 + Q2.W[forcount].duration2 ;
					else AllTime2 = Q2.W[forcount].arrival2 + Q2.W[forcount].duration2 ;
			    	Q2.Dequeue() ;
				}
				else {
					Q.Abort(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ; // ��iAbort 
					Q2.Dequeue() ;
				}
						
		    } // for
		    
		    
		    
		    printf("      [�˱�u�@�M��]\n") ;
			printf( " JobID  CPU  Abort  Delay\n") ;
			for ( int b = 0 ; b < Q.forAbort.size() ; b ++ ) {
		    	printf( "[%d]", b + 1 ) ;
		    	printf( "%d ", Q.forAbort[b].jobID2 ) ;
		    	printf( " %d", Q.forAbort[b].cpu ) ;
		    	printf( "   %d", Q.forAbort[b].abort ) ;
		    	printf( "   %d\n", Q.forAbort[b].delay ) ;
		    	AllD = AllD + Q.forAbort[b].delay ;
			}

		    printf("      [����u�@�M��]\n") ; 
			printf( " JobID  CPU  Departure  Delay\n") ;
		    for ( int a = 0 ; a < Q.forDone.size() ; a ++ ) {
		    	printf( "[%d]", a + 1 ) ;
		    	printf( "%d ", Q.forDone[a].jobID2 ) ;
		    	printf( " %d", Q.forDone[a].cpu ) ;
		    	printf( "   %d", Q.forDone[a].departure ) ;
		    	printf( "   %d\n", Q.forDone[a].delay ) ;
		    	AllD = AllD + Q.forDone[a].delay ;
		    	AllS += 1 ;
			}
			
			 
			
			printf("����������� : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			printf("���槹����� : %f ",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
			printf( "%\n" ) ;
			
			
			
			
			
			    FILE * fptr = fopen( "SQF601.txt", "W" ) ;               //  �}���ɮצ�m 
				
		        fprintf( fptr, "      [�˱�u�@�M��]\n") ;
			    fprintf( fptr, " JobID  CPU  Abort  Delay\n") ;
			    
				for ( int b = 0 ; b < Q.forAbort.size() ; b ++ ) {
		    		fprintf( fptr, "[%d]", b + 1 ) ;
		    		fprintf( fptr, "%d ", Q.forAbort[b].jobID2 ) ;
		    		fprintf( fptr, " %d", Q.forAbort[b].cpu ) ;
		    		fprintf( fptr, "   %d", Q.forAbort[b].abort ) ;
		    		fprintf( fptr, "   %d\n", Q.forAbort[b].delay ) ;
		    		AllD = AllD + Q.forAbort[b].delay ;
				}
				
		        fprintf( fptr, "      [����u�@�M��]\n") ; 
		    	fprintf( fptr, " JobID  CPU  Departure  Delay\n") ;
				
		        for ( int a = 0 ; a < Q.forDone.size() ; a ++ ) {
		    	    fprintf( fptr, "[%d]", a + 1 ) ;
		    	    fprintf( fptr, "%d ", Q.forDone[a].jobID2 ) ;
		    	    fprintf( fptr, " %d", Q.forDone[a].cpu ) ;
		    	    fprintf( fptr, "   %d", Q.forDone[a].departure ) ;
		    	    fprintf( fptr, "   %d\n", Q.forDone[a].delay ) ;
		    	    AllD = AllD + Q.forDone[a].delay ;
		    	    AllS += 1 ;
					putc( '\n', fptr ) ;
			    }
			    
			    fprintf( fptr, "����������� : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			    fprintf( fptr, "���槹����� : %f ",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
			    fprintf( fptr, "%\n" ) ;

				fclose( fptr ) ;
		} // else if (start == 2)
	
	} // while

    return 0; 
} 
