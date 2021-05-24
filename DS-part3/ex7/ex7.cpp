//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>

using namespace std; 


struct Job {
	int schoolcode ;
    char schoolname[50] ; 
    int dempartmentcode ;
    char dempartment[50] ;         // ��t�W�� 
    char day[50] ;                 // �鶡 / �i�קO 
    char level[50] ;              // ( �Ǥh ) 
    int numOfstudent ;
    int numOfteacher ;
    int numOfgraduation ;
    char city[50] ;
    char system[50] ;             // ��t 
    
} ;

int numofjob = 0 ;
vector<struct Job> forjob;              // �� vector �Ӱ� 
Job joblist ;

// ---------------------------------------------------------  //


void PrintJob()
{
	cout << "�j�M�հ|�U�լ�t�O���p\n" ; 
	cout << "105 �Ǧ~�� SY2016-2017\n" ;
	cout << "	�ǮզW��	��t�W��	�鶡�A�i�קO	���ŧO	�ǥͼ�	�Юv��	�W�Ǧ~�ײ��~�ͼ�\n" ;
	for( int i = 0 ; i < forjob.size() ; i++ )
	{
		printf( "[%d]  ", i+1 ) ;
		printf( "%s  %s  %s  %s  ", &forjob[i].schoolname, &forjob[i].dempartment, &forjob[i].day, &forjob[i].level ) ; 
		cout << forjob[i].numOfstudent << "  " << forjob[i].numOfteacher << "  " << forjob[i].numOfgraduation << "\n"  ;
	
	} // for
		
} // print


int main()
{
	clock_t start_time, end_time ;
	float total_time = 0 ;
	clock_t start_time1, end_time1 ;
	float total_time1 = 0 ;
	unsigned __int64 start = 0 ;
	char ch ;                                      // �Ψ�Ū�J�ťզr��
	float total_time2 ;
	bool getin = true ;
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input", temp1[50] ;
	

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
			cout << "Input a file number(ex.701,702,703) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;
		
		 	start_time = clock() ; // �פJ��l�ɶ� 
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%c", &ch ) ;             // �Ĥ@��Ū�� 
				while ( ch != '\n' )
					fscanf( fptr, "%c", &ch ) ;
					
				fscanf( fptr, "%c", &ch ) ;             // �ĤG��Ū�� 
				while ( ch != '\n' )
					fscanf( fptr, "%c", &ch ) ;

				
				for ( int k = 0 ; k < 11 ; k++ )
				{
					fscanf( fptr, "%s", &ch ) ;
				} // for
				fscanf( fptr, "%c", &ch ) ;                    
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%d%s%d%s", &joblist.schoolcode, &joblist.schoolname, &joblist.dempartmentcode, &joblist.dempartment ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;
						
					fscanf( fptr, "%s%s", &joblist.city, &temp ) ;          // ���� 
					strcat( joblist.day, " " ) ;
					strcat( joblist.city, temp ) ;
						
					fscanf( fptr, "%s%s", &joblist.system, &temp ) ;       //  ��t 
					strcat( joblist.day, " " ) ;
					strcat( joblist.system, temp ) ;

					forjob.push_back( joblist ) ;              // �N�u�@����̫�@��
						
					fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
					numofjob = i ;          //  �]�wjob�ƶq 
				} // for
				
				end_time = clock(); // �פJ�����ɶ� 
				
				
			// ------------------------------------------------------------------ //
			
			PrintJob() ;
		
		
		
			// ----------------------------------------------------------------  //
					
			
			} // if
				

			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
	        cout << "Input a file number(ex.701,702,703) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
		    sprintf( temp1, "%d", input ) ;     // �Ʀr��r��
			strcat( temp, temp1 ) ;
			strcat( temp, ".txt" ) ;
			
		 	start_time = clock() ; // �פJ��l�ɶ� 
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
			
			
				end_time = clock(); // �פJ�����ɶ� 
				
					
				
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;
		} // else if (start == 2)
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while
 
} // main


