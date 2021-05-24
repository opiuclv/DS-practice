#include <stdio.h> 
#include <stdlib.h> 
#define N 100

typedef struct Queue {
	int jobID ;
	int arrival ;
	int duration ;
	int timeOut ;
} ;


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
    
    /*
    
    printf( "GG%dGG\n", n ) ;
    
    for ( int c = 1 ; c <= 7 ; c++ )
      printf ( "%d\n", queue[c] ) ;
    */
    for (gap = n / 2; gap > 0; gap /= 2) { //�B�� 
    /*
        printf( "HH%dHH\n", gap ) ;
        printf( "NN%dNN\n", n - gap ) ;
        for ( int c = 1 ; c <= 7 ; c++ )
          printf ( "%d\n", queue[c] ) ;
    */
        i = 1 ;
        for (i = 1; i <= n - gap ; i++)        //�������J�Ƨ�
        {
            for (j = i + gap; j <= n; j ++)  {
			
                // printf( "BB%dBB\n", queue[i] );
                // printf( "AA%dAA\n", queue[j] ) ;
            
                
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
    struct Queue queue[N]; 
    int front, rear; 
    int input, select; 
    
    createq( struct Queue queue[], &front, &rear); 
    
    FILE * fptr = fopen( "input412.txt", "rt" ) ;               //  �}���ɮצ�m 
    
    printf( "*** Shell Sort & FIFO Queue  ***\n" );
    printf( "* 0. Quit                      *\n" );
    printf( "* 1. Sort a file by shell Sort *\n" );
    printf( "* 2. Simulate one FIFO Queue   *\n" );
    printf( "********************************\n" );


    while(true) { 
        printf("\n\n�п�J�ﶵ(-1����)�G"); 
        printf("\n(1)���J�Ȧܦ�C"); 
        printf("\n(2)��ܦ�C�e��"); 
        printf("\n(3)�R���e�ݭ�"); 
        printf("\n(4)��ܩҦ����e"); 
        printf("\n\�п�J->"); 
        scanf("%d", &select); 
        
        if(select == -1) 
            break; 

        switch(select) { 
            case 1: 
                printf("\n��J�ȡG"); 
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
                printf("\n�ﶵ���~�I"); 
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
        printf("\n��C���šI"); 
    else 
        printf("%d", queue[(front+1) % N]); 
} 

void enqueue(int queue[], int* front, int* rear, int data) { 
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

void dequeue(int queue[], int* front, int* rear) { 
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
