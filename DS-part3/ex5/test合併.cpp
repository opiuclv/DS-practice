#include <stdio.h> 
#include <stdlib.h> 
#define N 10 

void createq(int[], int*, int*); 
void showfront(int[], int, int); 
void add(int[], int*, int*, int); 
void del(int[], int*, int*); 
void showqueue(int[], int, int); 

void shellsort(int queue[], int n)
{
    int i, j, gap;
    printf( "%d\n", queue[0] ) ;
    printf( "%d\n", queue[1] ) ;
    printf( "%d\n", queue[2] ) ;
    printf( "%d\n", queue[3] ) ;
    printf( "%d\n", queue[4] ) ;

    for (gap = n / 2; gap > 0; gap /= 2) //gap是希爾排序目前要排的位置 
        for (i = 0; i < gap; i++)        //直接插入排序
        {
            for (j = i + gap; j < n; j += gap) 
                if (queue[j] < queue[j - gap]) // 如果有需要換 就做下列事情 
                {
                    int temp = queue[j];
                    int k = j - gap;
                    while (k >= 0 && queue[k] > temp)
                    {
                        queue[k + gap] = queue[k];
                        k -= gap;
                    }
                    queue[k + gap] = temp;
                }
        }
}

int main(void) { 
    int queue[N]; 
    int front, rear; 
    int input, select; 

    createq(queue, &front, &rear); 
    
    printf( "*** Shell Sort & FIFO Queue  ***\n" );
    printf( "* 0. Quit                      *\n" );
    printf( "* 1. Sort a file by shell Sort *\n" );
    printf( "* 2. Simulate one FIFO Queue   *\n" );
    printf( "********************************\n" );

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
                shellsort(queue, N) ;
                showqueue(queue, front, rear); 
                break; 
            default: 
                printf("\n選項錯誤！"); 
        } 
    } 

    printf("\n"); 

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
