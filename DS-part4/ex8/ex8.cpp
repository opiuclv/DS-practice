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
    int departmentcode ;
    char department[50] ;         // ��t�W�� 
    char day[50] ;                 // �鶡 / �i�קO 
    char level[50] ;              // ( �Ǥh ) 
    int numOfstudent ;
    int numOfteacher ;
    int numOfgraduation ;
    char city[50] ;
    char system[50] ;             // ��t 
    
} ;


int a = 0 ;
int numofjob = 0 ;
vector<struct Job> forjob ;              // �� vector �Ӱ� 
Job joblist ;

struct node // �y�Xnode���榡 
{
	Job fornode ;
	node *lnode = NULL ;
	node *rnode = NULL ;
} ;

void InputRoot( node * root )
{
	root -> fornode.schoolcode = forjob[0].schoolcode ;                      // ����root���ȿ�J 
	strcat( root -> fornode.schoolname, forjob[0].schoolname) ;
	root -> fornode.departmentcode = forjob[0].departmentcode ;
	strcat( root -> fornode.department, forjob[0].department) ;  
	strcat( root -> fornode.day, forjob[0].day) ;  
	strcat( root -> fornode.level, forjob[0].level) ; 
	root -> fornode.numOfstudent = forjob[0].numOfstudent ;
	root -> fornode.numOfteacher = forjob[0].numOfteacher ;
	root -> fornode.numOfgraduation = forjob[0].numOfgraduation ;
	strcat( root -> fornode.city, forjob[0].city) ;
	strcat( root -> fornode.system, forjob[0].system) ;
	
	root->lnode = NULL ; // ���k�����ONULL 
	root->rnode = NULL ;
	
} 



// ------------------------------  //

int H = 1 ;
int HB = 0 ;
int c = 0 ;
int num2 = 0 ;
int printBST( node *ptr )                // �⥦�L�X�� 
{
  num2 = num2 + 1 ;
  if(ptr == NULL)                         //�Y�𬰪Ū� 
    return 0 ;
  else
  { 
    printf( "[ %d]", num2 ) ;
    printf( "%s ",ptr -> fornode.schoolname ) ;  
	printf( "%s ",ptr -> fornode.department ) ; 
	printf( "%s ",ptr -> fornode.day ) ;
	printf( "%s ",ptr -> fornode.level ) ;
	printf(" %d ", ptr->fornode.numOfstudent );
	printf(" %d ", ptr->fornode.numOfteacher );
    printf(" %d \n", ptr->fornode.numOfgraduation );              //���X�쪺�������L�X�� 
                                          //�A�̷ӫe�Ǩ��X���覡�[�W�A���M�r��
                                          
    if(!ptr->lnode && !ptr->rnode) H = 0 ;
    if(ptr->lnode)                         //���䦳����
    {
	    printBST(ptr->lnode);   
    	H = H + 1 ;
    	if ( H > HB ) HB = H ;  
		H = 0 ;
    }

    if(ptr->rnode)                        //�k�䦳���� 
    {
        printBST(ptr->rnode);
    	H = H + 1 ;
    	if ( H > HB ) HB = H ;
    }
    
    if ( H > HB ) HB = H ;

  }
}



// -----------------------------------------------------  //



void searchGraduation ( int obj, node *ptr, node *root ){ // �j�M 
	ptr = root ; // �q�ڶ}�l�� 
	while(1) {
		if( ptr -> fornode.numOfgraduation == obj ) {                        // �p�G���@�˪��A�N�L�X�ӤK 
    		printf( "%s ",ptr -> fornode.schoolname ) ;  
			printf( "%s ",ptr -> fornode.department ) ; 
			printf( "%s ",ptr -> fornode.day ) ;
			printf( "%s ",ptr -> fornode.level ) ;
			printf(" %d ", ptr->fornode.numOfstudent );
			printf(" %d ", ptr->fornode.numOfteacher );
    		printf(" %d \n", ptr->fornode.numOfgraduation );              //���X�쪺�������L�X�� 
			ptr = ptr-> rnode ;
        	printBST(ptr) ;
        	num2 = 0 ;
        	if ( !ptr -> rnode )break ;                                //      ????????????????????????
			ptr = ptr -> rnode ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL )         // ���k�� 
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode== NULL )         // ���k����� 
		{
			printf( "�S���񦹭Ȥj����" ) ;
			break ;
		}
		else if( ptr -> fornode.numOfgraduation > obj )
		{
		   	
		    node *newNode = new node ;
			newNode = ptr->lnode ;
			if ( newNode -> fornode.numOfgraduation > obj || ptr -> lnode == NULL ) {
			    printBST(ptr) ; 
			    num2 = 0 ;
			    break ;
        	}
        	else {
			    printf( "%s ",ptr -> fornode.schoolname ) ;  
				printf( "%s ",ptr -> fornode.department ) ; 
				printf( "%s ",ptr -> fornode.day ) ;
				printf( "%s ",ptr -> fornode.level ) ;
				printf(" %d ", ptr->fornode.numOfstudent );
				printf(" %d ", ptr->fornode.numOfteacher );
   				printf(" %d \n", ptr->fornode.numOfgraduation );              //���X�쪺�������L�X�� 
			}
        	ptr = ptr -> lnode ;
		}

	}
}

void searchSchoolName ( char obj[], node *ptr, node *root ){ // �j�M 
	ptr = root ; // �q�ڶ}�l��
 
	while(1) {
		if( strcmp ( ptr -> fornode.schoolname, obj) == 0  ) {
		    printf( "%s ",ptr -> fornode.schoolname ) ;  
			printf( "%s ",ptr -> fornode.department ) ; 
			printf( "%s ",ptr -> fornode.day ) ;
			printf( "%s ",ptr -> fornode.level ) ;
			printf(" %d ", ptr->fornode.numOfstudent );
			printf(" %d ", ptr->fornode.numOfteacher );
   			printf(" %d \n ", ptr->fornode.numOfgraduation ); 
			if ( !ptr -> rnode )break ;                                //      ????????????????????????
			ptr = ptr -> rnode ;
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) < 0 && ptr->rnode != NULL )
		{
			ptr = ptr->rnode ; 
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) < 0 && ptr->rnode== NULL )
		{
			cout << "Sorry, the num...." ;
			break ;
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) > 0 && ptr -> lnode != NULL)
		{
			ptr = ptr->lnode ;
		}
		else if ( strcmp ( ptr -> fornode.schoolname, obj) > 0 && ptr->lnode == NULL)
		{
			cout << "Sorry, the num...." << "\n" ;
			break ;
		}
	}
}

int insert(int obj, node *ptr, node * root, int i) {          // ���J 
	node *newNode = new node ; // �y�@�ӷs���`�I �A�ǥѥH�U�P�_�⥦��i��̭� 
	newNode->fornode.numOfgraduation = 0 ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // �q�ڶ}�l�� 
	int height = 1 ;
	
	while(1) {
		
		if(ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL )                      // �������A���O�٤��O�� 
		{
			ptr = ptr->lnode ;
			height++ ;
		}
		else if ( ptr -> fornode.numOfgraduation > obj && ptr->lnode == NULL )                      // ��������� 
		{
			ptr->lnode = newNode ;
			newNode -> fornode.schoolcode = forjob[i].schoolcode ;
			strcpy ( newNode -> fornode.schoolname, forjob[i].schoolname ) ;
			newNode -> fornode.departmentcode = forjob[i].departmentcode ;
			strcpy ( newNode -> fornode.department, forjob[i].department ) ;
			strcpy ( newNode -> fornode.day, forjob[i].day ) ;
			strcpy ( newNode -> fornode.level, forjob[i].level ) ;
			newNode -> fornode.numOfstudent = forjob[i].numOfstudent ;
			newNode -> fornode.numOfteacher = forjob[i].numOfteacher ;
			newNode -> fornode.numOfgraduation = forjob[i].numOfgraduation ;
			strcpy ( newNode -> fornode.city, forjob[i].city ) ;
			strcpy ( newNode -> fornode.system, forjob[i].system ) ;
			return height+1 ;
		} 
		else if (ptr -> fornode.numOfgraduation <= obj && ptr->rnode != NULL)                      // ���k���A���O�٤��O�� 
		{
			ptr = ptr->rnode ;
			height++ ;
		}
		else if( ptr -> fornode.numOfgraduation <= obj && ptr->rnode == NULL)                      // ���k����� 
		{
			ptr->rnode = newNode ;
			newNode -> fornode.schoolcode = forjob[i].schoolcode ;
			strcpy ( newNode -> fornode.schoolname, forjob[i].schoolname ) ;
			newNode -> fornode.departmentcode = forjob[i].departmentcode ;
			strcpy ( newNode -> fornode.department, forjob[i].department ) ;
			strcpy ( newNode -> fornode.day, forjob[i].day ) ;
			strcpy ( newNode -> fornode.level, forjob[i].level ) ;
			newNode -> fornode.numOfstudent = forjob[i].numOfstudent ;
			newNode -> fornode.numOfteacher = forjob[i].numOfteacher ;
			newNode -> fornode.numOfgraduation = forjob[i].numOfgraduation ;
			strcpy ( newNode -> fornode.city, forjob[i].city ) ;
			strcpy ( newNode -> fornode.system, forjob[i].system ) ;
			return height+1 ;
		}
	}
}

int insertName(char obj[], node *ptr, node *root, int i) // ���J 
{
	node *newNode = new node ; // �y�@�ӷs���`�I �A�ǥѥH�U�P�_�⥦��i��̭� 
	// newNode->fornode.schoolname = NULL ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // �q�ڶ}�l�� 
	int height = 1 ;
	
	while(1) {
		
		if( strcmp( ptr -> fornode.schoolname ,  obj ) > 0 && ptr->lnode != NULL )
		{
			ptr = ptr->lnode ;
			height++ ;
		}
		else if (  strcmp( ptr -> fornode.schoolname ,  obj ) > 0  && ptr->lnode == NULL )
		{
			ptr->lnode = newNode ;
			newNode -> fornode.schoolcode = forjob[i].schoolcode ;
			strcpy ( newNode -> fornode.schoolname, forjob[i].schoolname ) ;
			newNode -> fornode.departmentcode = forjob[i].departmentcode ;
			strcpy ( newNode -> fornode.department, forjob[i].department ) ;
			strcpy ( newNode -> fornode.day, forjob[i].day ) ;
			strcpy ( newNode -> fornode.level, forjob[i].level ) ;
			newNode -> fornode.numOfstudent = forjob[i].numOfstudent ;
			newNode -> fornode.numOfteacher = forjob[i].numOfteacher ;
			newNode -> fornode.numOfgraduation = forjob[i].numOfgraduation ;
			strcpy ( newNode -> fornode.city, forjob[i].city ) ;
			strcpy ( newNode -> fornode.system, forjob[i].system ) ;
			return height+1 ; 
		} 
		else if ( strcmp( ptr -> fornode.schoolname ,  obj ) <= 0  && ptr->rnode != NULL)
		{
			ptr = ptr->rnode ;
			height++ ;
		}
		else if(  strcmp( ptr -> fornode.schoolname ,  obj ) <= 0  && ptr->rnode == NULL)
		{
			ptr->rnode = newNode ;
			newNode -> fornode.schoolcode = forjob[i].schoolcode ;
			strcpy ( newNode -> fornode.schoolname, forjob[i].schoolname ) ;
			newNode -> fornode.departmentcode = forjob[i].departmentcode ;
			strcpy ( newNode -> fornode.department, forjob[i].department ) ;
			strcpy ( newNode -> fornode.day, forjob[i].day ) ;
			strcpy ( newNode -> fornode.level, forjob[i].level ) ;
			newNode -> fornode.numOfstudent = forjob[i].numOfstudent ;
			newNode -> fornode.numOfteacher = forjob[i].numOfteacher ;
			newNode -> fornode.numOfgraduation = forjob[i].numOfgraduation ;
			strcpy ( newNode -> fornode.city, forjob[i].city ) ;
			strcpy ( newNode -> fornode.system, forjob[i].system ) ;
			return height+1 ;
		}
	}
}



// ---------------------------------------------------------  //


void PrintJob( int i )
{
	
	printf( "[%d]  ", i+1 ) ;
	printf( "%s  %s  %s  %s  ", &forjob[i].schoolname, &forjob[i].department, &forjob[i].day, &forjob[i].level ) ; 
	cout << forjob[i].numOfstudent << "  " << forjob[i].numOfteacher << "  " << forjob[i].numOfgraduation << "\n"  ;
		
} // print


int main ( int argc, char **argv )
{
	
	unsigned __int64 start = 0 ;
	char ch ;                                      // �Ψ�Ū�J�ťզr��
	bool getin = true ;
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input", temp1[50] ;
	
	
	char inputschoolname[100] ;
	int num ;
	
	node * ptr ;                          // �ΨӶ]�� 
    node * rootOfgraduation = new node ;  // �y�X�ڸ`�I
	node * rootOfschoolname = new node ;  // �y�X�ڸ`�I
	

	while ( true )
	{

		
		cout << "*** University Graduate Information System ***\n" ;
		cout << "* 0. Quit                                    *\n" ;
		cout << "* 1. search by school name                   *\n" ;
		cout << "* 2. search by school gradu                  *\n" ;
		cout << "* 3. Search by Number of Graduates           *\n" ;
		cout << "* 4. Removal by School Name                  *\n" ;
		cout << "* 5. Removal by Number of Graduates          *\n" ;
		cout << "* 6. Save BST                                *\n" ;
		cout << "* 7. Load BST                                *\n" ;
		cout << "**********************************************\n" ;

		cout << "Input a command(0, 1~7 ):" ;
		cin >> start ;
		cout << "\n" ;
	
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
					fscanf( fptr, "%d%s%d%s", &joblist.schoolcode, &joblist.schoolname, &joblist.departmentcode, &joblist.department ) ;
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
				
				fclose( fptr ) ;

    		// ---------------------------------------�o�̥H�U�O�G����------------------------------ //
    			
    			InputRoot( rootOfgraduation ) ;       // Ū�J�ڪ���	 
    			InputRoot( rootOfschoolname ) ;
    			
				
				int graduationHeight = 0 ;            // �𪺲`�� 
				int schoolnameHeight = 0 ;
				
   				ptr = rootOfgraduation ;
				int H = 0 ;
				for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // �β��~�H�ƺؾ� 
					H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
					if ( graduationHeight < H )
						graduationHeight = H ;             // �𪺲`�� 
				}
			
				H = 0 ;
				ptr = rootOfschoolname ;
				for ( int i = 1 ; i < forjob.size() ; i ++ ) {
					H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
					if ( schoolnameHeight < H )
						schoolnameHeight = H ;             // �𪺲`�� 
				}
				
				
				
				printf( "Tree heights:\n" ) ;
				printf( "{School name} = %d\n", schoolnameHeight ) ;              // �L�X��
				printf( "{Number of graduates} = %d\n\n", graduationHeight ) ;              // �L�X�� 
				 
				
				
				
				
			
			// -------------------------------�G����@����o��----------------------------------- //	
			
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
			cout << "Input a school name:" ;
			cin >> inputschoolname ;          // Ū�J�@�ӾǮ� 
			
			searchSchoolName ( inputschoolname, ptr, rootOfschoolname ) ; 
			
		} // else if (start == 2)
		
		else if ( start == 3 )                //      3. Search by Number of Graduates
		{			
			cout << "Input the number of graduates:" ;
			cin >> num ;
			
			searchGraduation ( num, ptr, rootOfgraduation ) ;
			
		} // else if 
		
		else if ( start == 4 )                 //   4. Removal by School Name
		{
			cout << "Input a school name:" ;
			cin >> inputschoolname ;          // Ū�J�@�ӾǮ�
			
			for ( i = 0 ; i < forjob.size() ; i++ )
			{
				if( strcmp( forjob[i].schoolname, inputschoolname ) == 0 )       // �p�G���ŦX���� 
				{
					forjob.erase(forjob.begin()+i) ;               // �N�⥦������ �� �L�X�� 
					PrintJob( i ) ;
				}
			
				
			} // for
			
			int graduationHeight = 0 ;            // �𪺲`�� 
			int schoolnameHeight = 0 ;
				 
    		InputRoot( rootOfschoolname ) ;
    			
			schoolnameHeight = 0 ;
			
			H = 0 ;
			ptr = rootOfschoolname + NULL ;                                                // �q�s�سy�@�ʾ� 
			for ( int i = 1 ; i < forjob.size() ; i ++ ) 
			{
				H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
				if ( schoolnameHeight < H )
					schoolnameHeight = H ;             // �𪺲`�� 
			}
				
			printBST(rootOfschoolname) ;	
			printf( "Tree heights: {School name} = %d\n", schoolnameHeight ) ;              // �L�X��
			printf( "Tree heights: {Number of graduates} = %d\n\n", graduationHeight ) ;              // �L�X�� 
			
			
			
		} // else if 
		
		
		else if ( start == 5 )                 //    5. Removal by Number of Graduates 
		{
			cout << "Input the number of graduates:" ;
			cin >> num ;
			printf( "hi = %d\n", forjob.size() ) ;
			int size = forjob.size() ;
			for ( i = 0 ; i < size ; i++ )
			{
				if( forjob[i].numOfgraduation <= num )       // �p�G���ŦX���� 
				{
					int c = i - 1 ;
					forjob.erase(forjob.begin()+c) ;                   // �N�⥦������  ��  �L�X�� 
					PrintJob( i ) ;                       
				}
				
				
			} // for
			
			printf( "%d\n", forjob.size() ) ;
			int graduationHeight = 0 ;            // �𪺲`�� 
			int schoolnameHeight = 0 ;
			InputRoot( rootOfgraduation ) ;       // Ū�J�ڪ���
			graduationHeight = 0 ;            // �𪺲`�� 
			
			ptr = rootOfgraduation = NULL ;
			int H = 0 ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // �β��~�H�ƺؾ� 
				H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
				printf( "GGG2 " ) ;
				if ( graduationHeight < H )
					graduationHeight = H ;             // �𪺲`�� 
			}
			
			
			printf( "Tree heights: {School name} = %d\n", schoolnameHeight ) ;              // �L�X��
			printf( "Tree heights: {Number of graduates} = %d\n\n", graduationHeight ) ;              // �L�X�� 
			
		} // else if 
		
		
		
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while

}




