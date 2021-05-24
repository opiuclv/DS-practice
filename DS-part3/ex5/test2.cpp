#include <stdio.h> 
#include <stdlib.h> 
#define N 10 

void createq(int[], int*, int*); 
void showfront(int[], int, int); 
void add(int[], int*, int*, int); 
void del(int[], int*, int*); 
void showqueue(int[], int, int); 

void swap( int &a, int &b )        // 交換 
{
	int temp;
	temp = a;
	a = b;
	b= temp;
} // swap

void shellsort( float  &total_time2 )
{
	clock_t start_time, end_time ;
	start_time = clock() ; // 匯入初始時間 
	int gap, num = 1 ;
	
	while ( queue[num][arrival] != 0 )        //  計算有幾個 job 
		num = num + 1 ;
	
	gap = num / 2 ;
	
	while( gap >= 1 )
	{
		for( int i = 0 ; i < num-gap ; i++ )
		{
			if ( queue[i][arrival] > queue[i+gap][arrival] )          // 如果前面的比較大，就把小的換過去 
			{
				swap( queue[i][jobID], queue[i+gap][jobID] ) ;
                swap( queue[i][arrival], queue[i+gap][arrival] ) ;
                swap( queue[i][duration], queue[i+gap][duration] ) ;
                swap( queue[i][timeout], queue[i+gap][timeout] ) ;
                
			} // if
			
			else if ( queue[i][arrival] == queue[i+gap][arrival] )       // 如果相同的話，那就比 "JobID" 
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
	
	end_time = clock(); // 匯入結束時間 

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
        printf("\n\n請輸入選項(-1結束)："); 
        printf("\n(1)插入值至佇列"); 
        printf("\n(2)顯示佇列前端"); 
        printf("\n(3)刪除前端值"); 
        printf("\n(4)顯示所有內容"); 
        printf("\n$c>"); 
        scanf("%d", &select); 
        
        if(select == -1) 
            break; 

        switch(select) { 
            case 1: 
                printf("\n輸入值："); 
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
                printf("\n選項錯誤！"); 
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
	char ch6 ;                                       // 用來讀入空白字元 
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
		
			cout << "Input a file number(ex.501) :" ;
			cin >> input ;          // 讀入一個數字
			
		    if ( input == 501 ) {
		    	
		    start_time = clock() ; // 匯入初始時間 
			
			FILE * fptr = fopen( "input501.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch1,&ch2,&ch3,&ch4,&ch5 ) ;     //  把最前面的 "標頭 and 換行字元" 讀掉
				
				
				for( i = 0 ; !feof(fptr) ; i++ )            //  讀入 
				{
					fscanf( fptr, "%d%d%d%d", &queue[i][jobID], &queue[i][arrival], &queue[i][duration], &queue[i][timeout] ) ;
					fscanf( fptr, "%c", &ch6 ) ;         //  把空白字元讀掉 
					
				} // for
				
				numofjob = i ;          //  設定job數量 
				
				end_time = clock(); // 匯入結束時間 
				
				
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
					fprintf( fptr, "  %d  ", queue[i][jobID] ) ;
					fprintf( fptr, "  %d  ", queue[i][arrival] ) ;
					fprintf( fptr, "  %d  ", queue[i][duration] ) ;
					fprintf( fptr, "  %d  \n", queue[i][timeout] ) ;
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
        printf("\n佇列為空！"); 
    else 
        printf("%d", queue[(front+1) % N]); 
} 

void add(int queue[], int* front, int* rear, int data) { 
    int f, r; 
    f = *front; 
    r = *rear; 
    r = (r+1) % N; 

    if(f == r) { 
        printf("\n佇列已滿！"); 
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
        printf("\n佇列為空！"); 
        return; 
    } 

    f = (f+1) % N; 
    *front = f; 
} 

void showqueue(int queue[], int front, int rear) { 
    int i; 

    printf("\n佇列內容："); 
    for(i = (front+1) % N; i <= rear; i++) 
        printf("%d ", queue[i]); 
} 
