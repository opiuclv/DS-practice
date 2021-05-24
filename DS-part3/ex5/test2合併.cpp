//  施育暘 10527111
//  邱正皓 10527124 


#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>
#define N 100

int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;
int queue[N][4] ;

void createq(int[], int*, int*); 
void showfront(int[], int, int); 
void enqueue(int[], int*, int*, int); 
void dequeue(int[], int*, int*); 
void showqueue(int[], int, int); 

void shellsort(int queue[])
{
    int i, j, gap, n = 1 ;
    
    while ( queue[n] != 0 ) {
	  n = n + 1 ;
    } // while
    
    n = n - 1 ;
    
    for (gap = n / 2; gap > 0; gap /= 2) { //步長 

        i = 1 ;
        for (i = 1; i <= n - gap ; i++)        //直接插入排序
        {
            for (j = i + gap; j <= n; j ++)  {
            
                
                if (queue[j] < queue[i])
                {
                    int temp = queue[j];
                    queue[j] = queue[i];
                    queue[i] = temp ;
                }
            }
        }
    } 
}

int main(void) {  
    int front, rear; 
    int input, select; 
	char ch ;                                     // 用來讀入空白字元 

    createq( &front, &rear ); 
    
    FILE * fptr = fopen( "input412.txt", "rt" ) ;               //  開啟檔案位置 
    
    printf( "*** Shell Sort & FIFO Queue  ***\n" );
    printf( "* 0. Quit                      *\n" );
    printf( "* 1. Sort a file by shell Sort *\n" );
    printf( "* 2. Simulate one FIFO Queue   *\n" );
    printf( "********************************\n" );

		if ( start == 0 )                                  // 結束 
			exit(1) ; 
		
		else if ( start == 1 ) {
		
			cout << "Input a file number :" ;
			cin >> input ;          // 讀入一個數字
			
			
			FILE * fptr = fopen( "input501.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  把最前面的 "標頭 and 換行字元" 讀掉
				
				
				for( i = 1 ; i < 7 ; i++ )
				{
					fscanf( fptr, "%d%d%d%d", &queue[i][jobID], &queue[i][arrival], &queue[i][duration], &queue[i][timeout] ) ;
					fscanf( fptr, "%c", &ch ) ;         //  把空白字元讀掉 
					
					if (  )
					
				} // for
				
				
		
			} // if
			
			else
				cout << "Command does not exist!\n" ;	
		
		} // else if

    while(true) { 
        printf("\n\n請輸入選項(-1結束)："); 
        printf("\n(1)插入值至佇列"); 
        printf("\n(2)顯示佇列前端"); 
        printf("\n(3)刪除前端值"); 
        printf("\n(4)顯示所有內容"); 
        printf("\n\請輸入->"); 
        scanf("%d", &select); 
        
        if(select == -1) 
            break; 

        switch(select) { 
            case 1: 
                printf("\n輸入值："); 
                scanf("%d", &input); 
                enqueue(queue, &front, &rear, input); 
                break; 
            case 2: 
                showfront(queue, front, rear); 
                break; 
            case 3: 
                dequeue(queue, &front, &rear); 
                break; 
            case 4: 
                shellsort( queue ) ;
                showqueue(queue, front, rear); 
                break; 
            default: 
                printf("\n選項錯誤！"); 
        } 
    } 

    printf("\n"); 

    return 0; 
} 

void createq( int* front, int* rear) { 
    int i; 

    for(i = 0; i < N; i++) 
        queue[i] = 0; 

    *front = *rear = 0; 
} 

void showfront( int front, int rear) { 
    if(front == rear) 
        printf("\n佇列為空！"); 
    else 
        printf("%d", queue[(front+1) % N]); 
} 

void enqueue( int* front, int* rear, int data) { 
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

void dequeue( int* front, int* rear) { 
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

void showqueue( int front, int rear) { 
    int i; 

    printf("\n佇列內容："); 
    for(i = (front+1) % N; i <= rear; i++) 
        printf("%d ", queue[i]); 
} 
