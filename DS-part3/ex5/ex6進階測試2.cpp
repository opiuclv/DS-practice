//  第19組 
//  施育暘 10527111
//  邱正皓 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std; 

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////這裡全部都是Q1//////////////////////////////////////////////////////////////////
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
int AllTime = 0 ; // 用於紀錄作所有工作的總花費時間 
int AllTime2 = 0 ; // 用於紀錄作所有工作的總花費時間 
int judgefordone = 0 ; // 用於判斷Q2進入Done_job 


void forSwap( int &a, int &b )        // 交換 
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
	start_time = clock() ; // 匯入初始時間 
	int gap, num = 1 ;
	
	while ( inputJob[num][arrival] != 0 )        //  計算有幾個 job 
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
		    DoJob.delay = AllTime - A ; // (需再設計AllTime2的情況)  
		    DoJob.departure = AllTime + D ;
	    }	
		
		if ( judgefordone = 1 && AllTime2 == 0 ) DoJob.departure = A + D ;
		if ( judgefordone = 1 && AllTime2 == 0 ) DoJob.delay = 0 ;
		if ( judgefordone = 1 && AllTime2 != 0 ) {
		    DoJob.delay = AllTime2 - A ; // (需再設計AllTime2的情況) 
		    DoJob.departure = AllTime2 + D ;
	    }
		
		judgefordone = 0 ;

        forDone.push_back( DoJob ) ;

	}

	void Abort (int J, int C, int A, int D, int T) { // 還沒改!!!!!!!!!!!!!!!!!!! 

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
// ////////////////////////////////////////////////這裡全部都是Q2//////////////////////////////////////////////////////////////////
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


bool SQF1( int A ) { // 兩個 CPU 都是立即可用的（「可用時刻」較早且佇列是空的）：選 1 號 CPU，立即執行或捨棄這一筆新工作。
    Queue Q ;
    Queue2 Q2 ;
	if (Q.rear == 0 && Q2.rear == 0 || AllTime == 0 || AllTime2 == 0 && AllTime <= A && AllTime2 <= A ) return true ;
	else return false ;
}
bool SQF2( int A ) { // 只有一個 CPU 是立即可用的：選立即可用的 CPU，立即執行或捨棄這一筆新工作。
    Queue Q ;
    Queue2 Q2 ;
	if (Q.rear == 0 && Q2.rear != 0 || Q.rear != 0 && Q2.rear == 0 ) return true ;
	else return false ;
}
bool SQF3() { // 兩個 CPU 都不是立即可用的，且至少一個佇列並非全滿：
              // 選佇列長度（存放工作筆數）2最短的 CPU；若兩者等長，則選 1 號 CPU，將新工作放入其佇列。
    Queue Q ;
    Queue2 Q2 ;
	if ( !Q.IsFull() || !Q2.IsFull() ) return true ;
	else return false ;	
}
bool SQF4() { // 兩個 CPU 都不是立即可用的，而且兩個佇列全滿：立即捨棄新工作，『捨棄工作清單』的「CPU 編號」設定為 0 號。
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
	char ch6 ;                                       // 用來讀入空白字元 
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
	
		while( start < 0 || start > 2 )                    //  如果是負號的話 就一直讀 
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
	
		if ( start == 0 )                                  // 結束 
			exit(1) ; 
		
		else if ( start == 1 ) {
		
			cout << "Input a file number(ex.601) :" ;
			cin >> input ;          // 讀入一個數字
			
		    if ( input == 601 ) {
		    	
		    start_time = clock() ; // 匯入初始時間 
			
			FILE * fptr = fopen( "input601.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch1,&ch2,&ch3,&ch4,&ch5 ) ;     //  把最前面的 "標頭 and 換行字元" 讀掉
				
				
				for( i = 0 ; !feof(fptr) ; i++ )            //  讀入 
				{
					fscanf( fptr, "%d%d%d%d", &inputJob[i][jobID], &inputJob[i][arrival], &inputJob[i][duration], &inputJob[i][timeout] ) ;
					fscanf( fptr, "%c", &ch6 ) ;         //  把空白字元讀掉 
					
				} // for
				
				numofjob = i ;          //  設定job數量 
				
				end_time = clock(); // 匯入結束時間 
				
				
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

		        start_time1 = clock() ; // 匯入初始時間   	
				fptr = fopen( "sort501.txt", "w" ) ;               //  開啟檔案位置 
				
				fprintf( fptr, "   %s ", ch1 ) ;
				fprintf( fptr, " %s ", ch2 ) ;
			    fprintf( fptr, " %s ", ch3 ) ;
				fprintf( fptr, " %s ", ch4 ) ;
				putc( '\n', fptr ) ;
				for( int i = 0 ; i < numofjob - 1 ; i++ )                      // 將資料一個一個讀進去 
				{ 
				    fprintf( fptr, "[%d]", i ) ; 
					fprintf( fptr, "  %d  ", inputJob[i][jobID] ) ;
					fprintf( fptr, "  %d  ", inputJob[i][arrival] ) ;
					fprintf( fptr, "  %d  ", inputJob[i][duration] ) ;
					fprintf( fptr, "  %d  \n", inputJob[i][timeout] ) ;
					putc( '\n', fptr ) ;
					

					
				} // for
				
				fclose( fptr ) ;
		        end_time1 = clock(); // 匯入結束時間 


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
			
			for ( int i = 0 ; AllTime == 0 || AllTime <= inputJob[i][arrival] ; i ++ ) { // 如果執行完了可是第二筆工作還沒到arrival就再丟進Q1一次 
				Q.Done_job(inputJob[0][jobID],1 , inputJob[0][arrival], inputJob[0][duration], inputJob[0][timeout]) ; // 第一個一定是丟進Q1 
				AllTime = AllTime + inputJob[0][arrival] + inputJob[0][duration] ;
				Q.Dequeue() ;
		    } // for
			
			judgefordone = 1 ;
			Q.Done_job(inputJob[1][jobID],2 , inputJob[1][arrival], inputJob[1][duration], inputJob[1][timeout]) ; // 第2個丟Q2 (需再考量Q1還沒執行完butQ2已執行完!!!!!!!!!!)
			AllTime2 = AllTime2 + inputJob[1][arrival] + inputJob[1][duration] ;
			Q.Dequeue() ;
			
		
	        for( int num = 2 ; num < numofjob - 1 ; num++ )  {          //  判斷要放哪個Q s
	        
	            printf("PP  ") ;

				if ( inputJob[num][arrival] >= AllTime || inputJob[num][arrival] >= AllTime2 ) { // 檢查前面 
				
				    for( int forcount = Q.front ; forcount <= Q.rear ; forcount ++ ) {
						printf(" ㄎㄎ \n")  ;
	
						if ( AllTime <= AllTime2 && Q.W[Q.front].arrival2 != 0 ) {
		
							printf("ㄏㄏ我是進來的id = %d \n", Q.W[forcount].jobID2 ) ;

						    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
						    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// 丟進DoneJob
								if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
								else AllTime = Q.W[forcount].arrival2 + Q.W[forcount].duration2 ;
						    	Q.Dequeue() ;
							}
							else {
								Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // 丟進Abort 
								Q.Dequeue() ;
							}
		
						}
						if ( AllTime2 < AllTime && Q2.W[Q2.front].arrival2 != 0 ) {
							printf("ㄤㄤ我是進來的id = %d \n", Q2.W[forcount].jobID2 ) ;

			 			    if ( AllTime2 + Q2.W[forcount].duration2 <= Q2.W[forcount].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
			 			        printf("ㄤㄤ我是進來的id2 = %d \n", Q2.W[forcount].jobID2 ) ;
			 			        judgefordone = 1 ;
						    	Q.Done_job(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ;// 丟進DoneJob
								if ( AllTime2 >= Q2.W[forcount].arrival2 ) AllTime2 = AllTime + Q2.W[forcount].duration2 ;
								else AllTime2 = Q2.W[forcount].arrival2 + Q2.W[forcount].duration2 ;
						    	Q2.Dequeue() ;
							}
							else {
								printf("ㄤㄤ我是進來的id3 = %d \n", Q2.W[forcount].jobID2 ) ;
								Q.Abort(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ; // 丟進Abort 
								Q2.Dequeue() ;
							}
						}		
			    	} // for
				}
	        
	            if ( SQF1( inputJob[num][arrival] ) ){ // 兩個 CPU 都是立即可用的（「可用時刻」較早且佇列是空的）：選 1 號 CPU，立即執行或捨棄這一筆新工作。
	            printf("  hihi1 = %d \n", inputJob[num][jobID] ) ;
	            	Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else if ( SQF2( inputJob[num][arrival] ) ){ // 只有一個 CPU 是立即可用的：選立即可用的 CPU，立即執行或捨棄這一筆新工作。 
	            printf("  hihi2 = %d \n", inputJob[num][jobID] ) ;
	            	if ( Q.rear == 0 ) Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
	            	else Q2.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else if ( SQF3() ){ // 兩個 CPU 都不是立即可用的，且至少一個佇列並非全滿：
                // 選佇列長度（存放工作筆數）2最短的 CPU；若兩者等長，則選 1 號 CPU，將新工作放入其佇列。
                printf("  hihi3 = %d \n", inputJob[num][jobID] ) ; // 104沒有進 
	            	if ( Q.rear <= Q2.rear ) Q.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
	            	else Q2.Enqueue(inputJob[num][jobID], inputJob[num][arrival], inputJob[num][duration], inputJob[num][timeout]) ;
				}
	            else{ // 兩個 CPU 都不是立即可用的，而且兩個佇列全滿：立即捨棄新工作，『捨棄工作清單』的「CPU 編號」設定為 0 號。
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
			    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
			        judgefordone = 0 ;
			    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// 丟進DoneJob
					if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
					else AllTime = Q.W[forcount].arrival2 - AllTime + Q.W[forcount].duration2 ;
			    	Q.Dequeue() ;
				}
				else {
					Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // 丟進Abort 
					Q.Dequeue() ;
				}
						
                if (!Q.IsEmpty()) forcount = forcount + 1 ;
		    
		}
		    
		else {
		
		        printf( "GG\n" ) ;	
			    if ( AllTime2 + Q2.W[forcount2].duration2 <= Q2.W[forcount2].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
			        judgefordone = 0 ;
			    	Q.Done_job(Q2.W[forcount2].jobID2,2 , Q2.W[forcount2].arrival2, Q2.W[forcount2].duration2, Q2.W[forcount2].timeout2) ;// 丟進DoneJob
					if ( AllTime2 >= Q2.W[forcount2].arrival2 ) AllTime2 = AllTime2 + Q2.W[forcount2].duration2 ;
					else AllTime2 = Q2.W[forcount2].arrival2 - AllTime2 + Q2.W[forcount2].duration2 ;
			    	Q2.Dequeue() ;
				}
				else {
					Q.Abort(Q2.W[forcount2].jobID2,2 , Q2.W[forcount2].arrival2, Q2.W[forcount2].duration2, Q2.W[forcount2].timeout2) ; // 丟進Abort 
					Q2.Dequeue() ;
				}
				
				if (!Q.IsEmpty()) forcount2 = forcount2 + 1 ;
						
		    
	    }
	
    } // while
    
    
			for ( int forcount = Q.front ; !Q.IsEmpty() && forcount < Q.rear ; forcount ++ ) {
			    printf("   HHHEEELLO  ") ;
			    if ( AllTime + Q.W[forcount].duration2 <= Q.W[forcount].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
			        judgefordone = 0 ;
			    	Q.Done_job(Q.W[forcount].jobID2, 1, Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ;// 丟進DoneJob
					if ( AllTime >= Q.W[forcount].arrival2 ) AllTime = AllTime + Q.W[forcount].duration2 ;
					else AllTime = Q.W[forcount].arrival2 + Q.W[forcount].duration2 ;
			    	Q.Dequeue() ;
				}
				else {
					Q.Abort(Q.W[forcount].jobID2,1 , Q.W[forcount].arrival2, Q.W[forcount].duration2, Q.W[forcount].timeout2) ; // 丟進Abort 
					Q.Dequeue() ;
				}
						
		    } // for
		    
			for ( int forcount = Q2.front ; !Q2.IsEmpty() && forcount < Q2.rear ; forcount ++ ) {
			    printf("   HHHEEELLO2  ") ;  	
			    if ( AllTime2 + Q2.W[forcount].duration2 <= Q2.W[forcount].timeout2 ) { // 在queue的工作序列中的第一位判斷有無逾時 
			        judgefordone = 0 ;
			    	Q.Done_job(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ;// 丟進DoneJob
					if ( AllTime2 >= Q2.W[forcount].arrival2 ) AllTime2 = AllTime2 + Q2.W[forcount].duration2 ;
					else AllTime2 = Q2.W[forcount].arrival2 + Q2.W[forcount].duration2 ;
			    	Q2.Dequeue() ;
				}
				else {
					Q.Abort(Q2.W[forcount].jobID2,2 , Q2.W[forcount].arrival2, Q2.W[forcount].duration2, Q2.W[forcount].timeout2) ; // 丟進Abort 
					Q2.Dequeue() ;
				}
						
		    } // for
		    
		    
		    
		    printf("      [捨棄工作清單]\n") ;
			printf( " JobID  CPU  Abort  Delay\n") ;
			for ( int b = 0 ; b < Q.forAbort.size() ; b ++ ) {
		    	printf( "[%d]", b + 1 ) ;
		    	printf( "%d ", Q.forAbort[b].jobID2 ) ;
		    	printf( " %d", Q.forAbort[b].cpu ) ;
		    	printf( "   %d", Q.forAbort[b].abort ) ;
		    	printf( "   %d\n", Q.forAbort[b].delay ) ;
		    	AllD = AllD + Q.forAbort[b].delay ;
			}

		    printf("      [執行工作清單]\n") ; 
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
			
			 
			
			printf("平均延遲長度 : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			printf("執行完成比例 : %f ",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
			printf( "%\n" ) ;
			
			
			
			
			
			    FILE * fptr = fopen( "SQF601.txt", "W" ) ;               //  開啟檔案位置 
				
		        fprintf( fptr, "      [捨棄工作清單]\n") ;
			    fprintf( fptr, " JobID  CPU  Abort  Delay\n") ;
			    
				for ( int b = 0 ; b < Q.forAbort.size() ; b ++ ) {
		    		fprintf( fptr, "[%d]", b + 1 ) ;
		    		fprintf( fptr, "%d ", Q.forAbort[b].jobID2 ) ;
		    		fprintf( fptr, " %d", Q.forAbort[b].cpu ) ;
		    		fprintf( fptr, "   %d", Q.forAbort[b].abort ) ;
		    		fprintf( fptr, "   %d\n", Q.forAbort[b].delay ) ;
		    		AllD = AllD + Q.forAbort[b].delay ;
				}
				
		        fprintf( fptr, "      [執行工作清單]\n") ; 
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
			    
			    fprintf( fptr, "平均延遲長度 : %f\n", (double)((int)(AllD / (numofjob - 1)*100)*0.01)) ;
			    fprintf( fptr, "執行完成比例 : %f ",  (double)((int)(AllS / (numofjob - 1) * 100*100)*0.01)) ;
			    fprintf( fptr, "%\n" ) ;

				fclose( fptr ) ;
		} // else if (start == 2)
	
	} // while

    return 0; 
} 
