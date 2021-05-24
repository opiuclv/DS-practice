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

    for (gap = n / 2; gap > 0; gap /= 2) //gap�O�ƺ��Ƨǥثe�n�ƪ���m 
        for (i = 0; i < gap; i++)        //�������J�Ƨ�
        {
            for (j = i + gap; j < n; j += gap) 
                if (queue[j] < queue[j - gap]) // �p�G���ݭn�� �N���U�C�Ʊ� 
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
                shellsort(queue, N) ;
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
