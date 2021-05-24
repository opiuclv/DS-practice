//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<string>

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

struct node // �y�Xnode���榡 
{
	int num ;
	node *lnode;
	node *rnode ;
};

void search ( double obj, node *ptr, node *root ){ // �j�M 
	ptr = root ;
	while(1) {
		if( ptr -> num == obj ) {
			cout << "find it in the BST" << "\n" ;
			break ;
		}
		else if(ptr->num < obj && ptr->rnode != NULL )
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr->num <obj && ptr->rnode== NULL )
		{
			cout << "Sorry, the num...." ;
			break ;
		}
		else if( ptr->num > obj && ptr -> lnode != NULL)
		{
			ptr = ptr->lnode ;
		}
		else if ( ptr->num > obj && ptr->lnode == NULL)
		{
			cout << "Sorry, the num...." << "\n" ;
			break ;
		}
	}
}

void insert(double obj, node *ptr, node *root) // ���J 
{
	node *newNode = new node ;
	newNode->num = 0;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ;
	while(1) {
		if(ptr -> num == obj)
		{
			cout << "We have it...." << "\n" ; 
		}
		else if(ptr->num > obj && ptr->lnode != NULL )
		{
			ptr = ptr->lnode ;
		}
		else if ( ptr->num > obj && ptr->lnode == NULL )
		{
			ptr->lnode = newNode ;
			newNode->num=obj ;
			printf("I am here : %d\n", newNode->num );
			break ; 
		} 
		else if (ptr->num <obj && ptr->rnode != NULL)
		{
			ptr = ptr->rnode ;
		}
		else if( ptr->num < obj && ptr->rnode == NULL)
		{
			ptr->rnode = newNode ;
			newNode->num=obj ;
			printf("I am here2 : %d\n", newNode->num );
			break ;
		}
	}
}



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


int main ( int argc, char **argv )
{
	
	unsigned __int64 start = 0 ;
	char ch ;                                      // �Ψ�Ū�J�ťզr��
	bool getin = true ;
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input", temp1[50] ;
	

	while ( true )
	{
		cout << "****   binary search tree   ****\n" ;
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
			
			cout << "****   binary search tree   ****\n" ;
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

    // �ثe�����\insert				
	int num ;
	node *root = new node ;  // �y�X�ڸ`�I 
	root->num = 117 ; // �]�wroot���ȬO�Ĥ@�Ӹ�ƪ����~�H��
	root->lnode = NULL ; // ���k�����ONULL 
	root->rnode = NULL ;
	
	node *ptr ;
	ptr = root ; // �y�Xptr�h�]��,�@�}�l�O�broot����m 
				
			printf( "GG%dGG\n",ptr ) ;	
			for ( int i = 1 ; i < forjob.size() ; i ++ ) { // �٦b���դ� 
			    num = forjob[i].numOfgraduation ;
				insert( num , ptr, root ) ;
			}
			
            int forSearch = 0 ;
		
            printf( "�п�J�n�䪺�� : " );
			cin >> forSearch ;
			search( forSearch, ptr, root ) ;
			
			
			// ------------------------------------------------------------------ //
			
			PrintJob() ;	
			
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
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  ��̫e���� "���Y and ����r��" Ū��
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;
		} // else if (start == 2)
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while

}




