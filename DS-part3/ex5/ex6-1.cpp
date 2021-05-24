//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std; 
#define MAX_SIZE 3  //maximum size of the array that will store Queue. 

int JobID = 0;
int Arrival = 1 ;
int Duration = 2;
int Timeout = 3;
int inputJob[1000][4] ;
int numofjob= 0 ;
int numofDone_job = 0 ;
int numofabort = 0 ;
float AllD = 0 ;
float AllS = 0 ;


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
	
	while ( inputJob[num][Arrival] != 0 )        //  �p�⦳�X�� job 
		num = num + 1 ;
	
	for ( int h = num / 2 ; h > 0 ; h = h / 2 )
	{
		for ( int unsorted = h ; unsorted < num ; ++unsorted )
		{
			int loc = unsorted;
			int nextItem = inputJob[unsorted][Arrival] ;
			int nextItem2 = inputJob[unsorted][JobID] ;
			while ( loc >= h )
			{
				if ( inputJob[ loc-h ][Arrival] > nextItem )
				{
					forSwap( inputJob[loc][JobID], inputJob[loc-h][JobID] ) ;
					forSwap( inputJob[loc][Arrival], inputJob[loc-h][Arrival] ) ;
					forSwap( inputJob[loc][Duration], inputJob[loc-h][Duration] ) ;
					forSwap( inputJob[loc][Timeout], inputJob[loc-h][Timeout] ) ;
					
				} // if
				
				else if ( inputJob[ loc-h ][Arrival] == nextItem )
				{
					if ( inputJob[ loc-h ][JobID] > nextItem2 )
					{
						forSwap( inputJob[loc][JobID], inputJob[loc-h][JobID] ) ;
						forSwap( inputJob[loc][Arrival], inputJob[loc-h][Arrival] ) ;
						forSwap( inputJob[loc][Duration], inputJob[loc-h][Duration] ) ;
						forSwap( inputJob[loc][Timeout], inputJob[loc-h][Timeout] ) ;
						
					} // if
					
					
				} // else if
				
				loc = loc - h ;
			} // while
			
			
		} // for
	} // for	
}




// Creating a class named Queue.

struct ForQueue {
    int jobID ; 
    int arrival ;
    int duration ;
    int timeout ;
    int cpu ;
} ;

struct Abort {
    int jobID ;
	int cpu ; 
    int abort ;
    int delay ;
};

struct Done {
    int jobID ; 
    int cpu ;
    int departure ;
    int delay ;
};

vector<struct Abort> forabort;              // �� vector �Ӱ� 
vector<struct Done> fordone;
Abort abortlist ;
Done donelist ;


// ---------------------------------------------------------  //

void Done_job( int J,int cpu, int depart, int delay ) 
{
	int i = numofDone_job ;              // �� DoJob ���j�p   �Ψӱƶ���
	
	donelist.jobID = J ;
	donelist.cpu = cpu ;
	donelist.departure = depart ;
	donelist.delay = delay ;
		
	fordone.push_back( donelist ) ;              // �N�u�@����̫�@�� 
		
	numofDone_job++ ;
}

void Abort (int J,int cpu, int A, int D)             // �˱�M�� 
{
	int i = numofabort ;               // �� abort ���j�p   �Ψӱƶ��� 

	abortlist.jobID = J ;
	abortlist.cpu = cpu ;
	abortlist.abort = A ;
	abortlist.delay =  D ;
	
	forabort.push_back( abortlist ) ;              // �N�u�@����̫�@�� 
	
	numofabort++ ;
}

void PrintAbort()
{
	cout << "        �u�˱�u�@�M��v\n" ; 
	cout << "    jobID    CPU    Abort    Delay\n" ;
	for( int i = 0 ; i < forabort.size() ; i++ )
	{
		printf( "[%d]  ", i+1 ) ;
		printf( "%d  %d  %d  %d\n", forabort[i].jobID, forabort[i].cpu, forabort[i].abort, forabort[i].delay ) ; 	
	} // for
		
} // print
	
void PrintDone()
{
	cout << "        �u����u�@�M��v\n" ; 
	cout << "    jobID    CPU    Departure    Delay\n" ;
	for( int i = 0 ; i < numofDone_job ; i++ )
	{
		printf( "[%d]  ", i+1 ) ;
		printf( "%d  %d  %d  %d\n", fordone[i].jobID, fordone[i].cpu, fordone[i].departure, fordone[i].delay ) ; 
	} // for
		
} // print


class Queue
{
	
public:
	
	int front , rear ;
	int cputime ;
	int num ;                  // ������C�`�@���X�� 
	
	ForQueue queue[MAX_SIZE] ;            // �o�O��C 
    
    
	Queue()
	{
		front = -1; 
		rear = -1;
		cputime = 0 ;
		num = 0 ;
	}
	 
	
	//  -----------------------------------------------  //
	
	 
	void CleanQueue( int C )                         //  �����C 
	{
		if ( IsEmpty() )     // �p�G�O�Ū�  ���N�����Ʃ� 
			;
		else 
		{
			for( int i = 0 ; i < num ; i++ )
			{
				if ( cputime + queue[i].duration <= queue[i].timeout )           // ���|�O�ɴN���� 
				{
					Done_job( queue[i].jobID, C , cputime + queue[i].duration , cputime - queue[i].arrival ) ;
					cputime = cputime + queue[i].duration ;     // �]�w�s��cputime 
					
				} // else if
				else
					Abort( queue[i].jobID, C , cputime, cputime - queue[i].arrival ) ;                              // �_�h�˱�
					
			} // for
			
			num = 0 ;             // �M�� 
			front = -1 ;
			rear = -1 ;
		} // else
	} // CleanQueue
	
	
	// --------------------------------  // 
	

	
	
	
	bool IsEmpty()
	{
		if ( front == -1 && rear == -1 )
			return true ; 
		else 
			return false ;
	}

	// To check whether Queue is full or not
	bool IsFull()
	{	
		if ( front == -1 && rear == -1 )                 // �p�G�Ĥ@�����  " front rear = -1 " 
			return false ;
		else if ( (rear+1)%MAX_SIZE == front )             //  �N��O���� 
			return true ;
		else 
			return false ;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int J, int A, int D, int T, int cpu )
	{		
		if ( front == -1 && rear == -1 )                     // �p�G�O�Ū�   �N��Ĥ@�� 
		{ 
			front = rear = 0 ; 
			queue[rear].jobID = J;
			queue[rear].cpu = cpu ;
			queue[rear].arrival = A;
			queue[rear].duration = D;
			queue[rear].timeout = T;
			num++ ;
		}
		else if ( rear == MAX_SIZE )                       //  �p�G���F�A�q0�}�l�C �� 5 �ܦ� 1 
		{
		    rear = (rear+1) % 5 ;
		    queue[rear].jobID = J;
			queue[rear].cpu = cpu ;
			queue[rear].arrival = A;
			queue[rear].duration = D;
			queue[rear].timeout = T;
			num++ ;
		}
		
		else                            //  �s�Jqueue 
		{
			rear = rear + 1 ;
			queue[rear].jobID = J;
			queue[rear].cpu = cpu ;
			queue[rear].arrival = A;
			queue[rear].duration = D;
			queue[rear].timeout = T;
			num++ ;
		} // else
	
	} // Enqueue

	void Dequeue( int cpu )
	{
		if( IsEmpty() )
		{
			cout<<"Error: Queue is Empty\n";	
		}
		
		else 
		{
			queue[rear].jobID = -1;                     // �M�Ũ�}�C 
			queue[rear].cpu = 0 ;
			queue[rear].arrival = -1;
			queue[rear].duration = -1;
			queue[rear].timeout = -1;
			
			rear = rear - 1 ;
			
		} // else
		
	}
	
};  // class Queue

int main()
{
    Queue cpu1 ;
	Queue cpu2 ;
	clock_t start_time, end_time ;
	float total_time = 0 ;
	clock_t start_time1, end_time1 ;
	float total_time1 = 0 ;
	unsigned __int64 start = 0, input = 0 ;
	char ch ;                                      // �Ψ�Ū�J�ťզr�� 
	float total_time2 ;
	bool getin = true ;
	int i = 0 ;
	

	

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
		
		else if ( start == 1 ) 
		{
			cout << "Input a file number(ex.601) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
		    if ( input == 601 ) 
			{	
		 	   start_time = clock() ; // �פJ��l�ɶ� 
			
				FILE * fptr = fopen( "input604.txt", "rt" ) ;               //  �}���ɮצ�m 
				if ( fptr )
				{
					fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
				
					for( int i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
					{
						fscanf( fptr, "%d%d%d%d", &inputJob[i][JobID], &inputJob[i][Arrival], &inputJob[i][Duration], &inputJob[i][Timeout] ) ;
						fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
						numofjob = i ;          //  �]�wjob�ƶq 
					} // for
				
					end_time = clock(); // �פJ�����ɶ� 
				
				
			// ------------------------------------------------------------------ //
			
			while ( i < numofjob +1 )
			{
				if ( inputJob[i][Arrival] >= cpu1.cputime )    // �����C 
				{
					cpu1.CleanQueue( 1 ) ; 
					
				} // if 
		
				if ( inputJob[i][Arrival] >= cpu2.cputime )    // �����C
				{
					cpu2.CleanQueue( 2 ) ;
					
				} // if
		
		// ----------------------   �P�_    -------------------------------------  //
		
				if ( inputJob[i][Arrival] < cpu1.cputime && inputJob[i][Arrival] < cpu2.cputime && i < numofjob +1 ) 
				{   // �p�G���p��cpu1 cpu2 ������ɶ�  �N���CPU�K 
					if ( cpu1.IsFull() == 1 && cpu2.IsFull() == 1 )                  // ���P�_�O�_���F �p�G���F�N�˱� 
						Abort( inputJob[i][JobID], 0 , inputJob[i][Arrival] , 0 ) ;
	
					else if ( cpu1.IsEmpty() == 1 && cpu2.IsEmpty() == 1 )          // �p�G��ӳ��O�Ū��� �N��cpu1 
						cpu1.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 1 ) ;
	
					else if ( cpu1.rear < cpu2.rear )
						cpu1.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 1 ) ;
		
					else if ( cpu1.rear > cpu2.rear )
						cpu2.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 2 ) ;
		
					else if ( cpu1.rear == cpu2.rear )
						cpu1.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 1 ) ; 
				} // if
		

				else if ( inputJob[i][Arrival] >= cpu1.cputime )           // �p�G�j��N���� 
				{
					if ( inputJob[i][Arrival] + inputJob[i][Duration] <= inputJob[i][Timeout] )              //  �p�G�A���|�O�� 
					{
						Done_job( inputJob[i][JobID], 1 , inputJob[i][Arrival] + inputJob[i][Duration], 0 ) ;      //  ���N����K 
						cpu1.cputime = inputJob[i][Arrival] + inputJob[i][Duration] ;      // �]�wcputime 
					} // if
				
					else
						Abort( inputJob[i][JobID], 1 , inputJob[i][Arrival], 0 ) ;                              // �_�h�˱�    *******************************
			
			
				} // else if
			
				else if ( inputJob[i][Arrival] >= cpu2.cputime ) 
				{
					if ( inputJob[i][Arrival] + inputJob[i][Duration] <= inputJob[i][Timeout] )              //  �p�G�A���|�O�� 
					{
						Done_job( inputJob[i][JobID], 2 , inputJob[i][Arrival] + inputJob[i][Duration], 0 ) ;      //  ���N����K 
						cpu2.cputime = inputJob[i][Arrival] + inputJob[i][Duration] ;      // �]�wcputime 
				
					} // if
				
					else
						Abort( inputJob[i][JobID], 2 , inputJob[i][Arrival], 0 ) ;                              // �_�h�˱�
			
				} // else if
			
				i++ ;
				getin = true ;
			} // while
			
			printf( "cpu1 = %d\n " , cpu1.num ) ;
			printf( "cpu2 = %d\n " , cpu2.num ) ;
			cpu1.CleanQueue( 1 ) ; 
			cpu2.CleanQueue( 2 ) ; 
	// ------------------------   ����  ---------------------------// 
			 
					PrintAbort() ;
					PrintDone() ; 
				
			    FILE * fptr = fopen( "SQF604.txt", "W" ) ;               //  �}���ɮצ�m 
				
		        fprintf( fptr, "      [�˱�u�@�M��]\n") ;
			    fprintf( fptr, " JobID  CPU  Abort  Delay\n") ;
			    
				for ( int b = 0 ; b < forabort.size() ; b ++ ) {
		    		fprintf( fptr, "[%d]", b + 1 ) ;
		    		fprintf( fptr, "%d ", forabort[b].jobID ) ;
		    		fprintf( fptr, " %d", forabort[b].cpu ) ;
		    		fprintf( fptr, "   %d", forabort[b].abort ) ;
		    		fprintf( fptr, "   %d\n", forabort[b].delay ) ;
		    		AllD = AllD + forabort[b].delay ;
				}
				
		        fprintf( fptr, "      [����u�@�M��]\n") ; 
		    	fprintf( fptr, " JobID  CPU  Departure  Delay\n") ;
				
		        for ( int a = 0 ; a < fordone.size() ; a ++ ) {
		    	    fprintf( fptr, "[%d]", a + 1 ) ;
		    	    fprintf( fptr, "%d ", fordone[a].jobID ) ;
		    	    fprintf( fptr, " %d", fordone[a].cpu ) ;
		    	    fprintf( fptr, "   %d", fordone[a].departure ) ;
		    	    fprintf( fptr, "   %d\n", fordone[a].delay ) ;
		    	    AllD = AllD + fordone[a].delay ;
		    	    AllS += 1 ;
					putc( '\n', fptr ) ;
			    }
			    
			    AllD = 0 ;
			    AllS = 0 ;
			    
			    fprintf( fptr, "����������� : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			    fprintf( fptr, "���槹����� : %f ",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
			    fprintf( fptr, "%\n" ) ;					
					
			// ---------------------------------------------  //
					
			AllD = 0 ;
			AllS = 0 ;


			for ( int b = 0 ; b < forabort.size() ; b ++ ) {
				
		    	AllD = AllD + forabort[b].delay ;
			}

		    for ( int a = 0 ; a < fordone.size() ; a ++ ) {
		    	AllD = AllD + fordone[a].delay ;
		    	AllS += 1 ;
			}
			
			printf("����������� : %f\n", (double)((int)(AllD / (numofjob + 1)*100)*0.01)) ;
			printf("���槹����� : %f ",  (double)((int)(AllS / (numofjob + 1) * 100*100)*0.01)) ;
			printf( "%\n" ) ;
			
		
				} // if
				
			} // if 
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
	        cout << "Input a file number(ex.601) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
		    if ( input == 601 ) 
			{	
		 	   start_time = clock() ; // �פJ��l�ɶ� 
			
				FILE * fptr = fopen( "input601.txt", "rt" ) ;               //  �}���ɮצ�m 
				if ( fptr )
				{
					fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
				
					for( int i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
					{
						fscanf( fptr, "%d%d%d%d", &inputJob[i][JobID], &inputJob[i][Arrival], &inputJob[i][Duration], &inputJob[i][Timeout] ) ;
						fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
						numofjob = i ;          //  �]�wjob�ƶq 
					} // for
				
					end_time = clock(); // �פJ�����ɶ� 
				
				
			// ------------------------------------------------------------------ //
			
			while ( i < numofjob +1 )
			{
				if ( inputJob[i][Arrival] >= cpu1.cputime )    // �����C 
				{
					cpu1.CleanQueue( 1 ) ; 
					
				} // if 
		
				if ( inputJob[i][Arrival] >= cpu2.cputime )    // �����C
				{
					cpu2.CleanQueue( 2 ) ;
					
				} // if
		
		// ----------------------   �P�_    -------------------------------------  //
		
				if ( inputJob[i][Arrival] < cpu1.cputime && inputJob[i][Arrival] < cpu2.cputime && i < numofjob +1 ) 
				{   // �p�G���p��cpu1 cpu2 ������ɶ�  �N���CPU�K 
					if ( cpu1.cputime < cpu2.cputime && cpu1.IsFull() == 1 )                  // ���P�_�O�_���F �p�G���F�N�˱� 
						Abort( inputJob[i][JobID], 1 , inputJob[i][Arrival] , 0 ) ;
					else if ( cpu1.cputime > cpu2.cputime && cpu2.IsFull() == 1 )
						Abort( inputJob[i][JobID], 2 , inputJob[i][Arrival] , 0 ) ;
					else if ( cpu1.cputime == cpu2.cputime && cpu1.IsFull() == 1 )
						Abort( inputJob[i][JobID], 1 , inputJob[i][Arrival] , 0 ) ;
						
						
	
					else if ( cpu1.cputime < cpu2.cputime )
						cpu1.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 1 ) ;
		
					else if ( cpu1.cputime > cpu2.cputime )
						cpu2.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 2 ) ;
		
					else if ( cpu1.cputime == cpu2.cputime )
						cpu1.Enqueue( inputJob[i][JobID],inputJob[i][Arrival],inputJob[i][Duration],inputJob[i][Timeout], 1 ) ; 
				} // if
		

				else if ( inputJob[i][Arrival] >= cpu1.cputime )           // �p�G�j��N���� 
				{
					if ( inputJob[i][Arrival] + inputJob[i][Duration] <= inputJob[i][Timeout] )              //  �p�G�A���|�O�� 
					{
						Done_job( inputJob[i][JobID], 1 , inputJob[i][Arrival] + inputJob[i][Duration], 0 ) ;      //  ���N����K 
						cpu1.cputime = inputJob[i][Arrival] + inputJob[i][Duration] ;      // �]�wcputime 
					} // if
				
					else
						Abort( inputJob[i][JobID], 1 , inputJob[i][Arrival], 0 ) ;                              // �_�h�˱�    *******************************
			
			
				} // else if
			
				else if ( inputJob[i][Arrival] >= cpu2.cputime ) 
				{
					if ( inputJob[i][Arrival] + inputJob[i][Duration] <= inputJob[i][Timeout] )              //  �p�G�A���|�O�� 
					{
						Done_job( inputJob[i][JobID], 2 , inputJob[i][Arrival] + inputJob[i][Duration], 0 ) ;      //  ���N����K 
						cpu2.cputime = inputJob[i][Arrival] + inputJob[i][Duration] ;      // �]�wcputime 
				
					} // if
				
					else
						Abort( inputJob[i][JobID], 2 , inputJob[i][Arrival], 0 ) ;                              // �_�h�˱�
			
				} // else if
			
				i++ ;
				getin = true ;
			} // while
			
			cpu1.CleanQueue( 1 ) ; 
			cpu2.CleanQueue( 2 ) ; 
	// ------------------------   ����  ---------------------------// 
			 
					PrintAbort() ;
					PrintDone() ; 
				
					fclose( fptr ) ;
					
			AllD = 0 ;
			AllS = 0 ;


			for ( int b = 0 ; b < forabort.size() ; b ++ ) {
				
		    	AllD = AllD + forabort[b].delay ;
			}

		    for ( int a = 0 ; a < fordone.size() ; a ++ ) {
		    	AllD = AllD + fordone[a].delay ;
		    	AllS += 1 ;
			}
			
			printf("����������� : %f\n", (double)((int)(AllD / (numofjob + 1)*100)*0.01)) ;
			printf("���槹����� : %f ",  (double)((int)(AllS / (numofjob + 1) * 100*100)*0.01)) ;
			printf( "%\n" ) ;			
				
		
				} // if
				
			} // if 
			
		    else
			  cout << "Command does not exist!\n" ;
		} // else if (start == 2)
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while
 
} // main


