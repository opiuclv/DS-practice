// �ѹ����g�c
//  �I�|�z 10527111
//  �����q 10527124 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std ;

int jobID = 0;
int arrival = 1 ;
int duration = 2;
int timeout = 3;

void shell_sort(int arr[], int len) {
 int gap, i, j;
 int temp;
 for (gap = len >> 1; gap > 0; gap >>= 1)
  for (i = gap; i < len; i++) {
   temp = arr[i];
   for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
    arr[j + gap] = arr[j];
   arr[j + gap] = temp;
  }
}


class Queue 
{
	public :
		
		bool isEmpty() ;
		void enqueue(  ) ;                // �s�W 
		void dequeue(  ) ;                // ���� 
		void getFront(  ) ; 
		
		void Read() ;                    // Ū�J 
		void Print() ; 					 // �L�X 
		
		char front ;
		char back ;
		
		
		
	
	
	
	
	
	
	
} // class


int main()
{
	unsigned __int64 start = 0, input = 0 ;
	char ch ;                                     // �Ψ�Ū�J�ťզr�� 
	int numofjob = 0 ;
	
	
	
	Quene quene ;
	
	
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
		
			cout << "Input a file number :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			
			FILE * fptr = fopen( "input501.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
				
				
				for( i = 0 ; !fptr.eof() ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%d%d%d%d", &a[i][jobID], &a[i][arrival], &a[i][duration], &a[i][timeout] ) ;
					fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
					
				} // for
				
				numofjob = i ;          //  �]�wjob�ƶq 
				
				
				
				
		
			} // if
			
			else
				cout << "Command does not exist!\n" ;	
		
		} // else if
		
		
		
		
	} // while
} // main



