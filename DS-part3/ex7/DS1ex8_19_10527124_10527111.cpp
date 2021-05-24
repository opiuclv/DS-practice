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
	node *lnode ;
	node *rnode ;
} ;

int H = 1 ;
int HB = 0 ;
int c = 0 ;
int num2 = 0 ;
int printBST( node *ptr ) 
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
    }

    if(ptr->rnode)                        //�k�䦳���� 
    {
        printBST(ptr->rnode);
    }

    H = H + 1 ; 
  }	
}


int height = 0 ;
int TreeHeight( node * ptr, int newH )            // ��� 
{	
	if ( newH > height ) {
		height = newH ; 
	}
	
	if ( ptr != NULL )                      // ���]�@�M 
	{
		TreeHeight( ptr -> lnode, newH+1 ) ;
		TreeHeight( ptr -> rnode, newH+1 ) ;
		
	} // if
	
	return height ;
	
	
} // TreeHeight

void deleteGraduation ( int obj, node *ptr, node *root ){ // �R��

	ptr = root ; // �q�ڶ}�l�� 
	while(1) {
		if( ptr -> fornode.numOfgraduation == obj ) { // �@�˴N��������R 
			ptr->lnode = NULL ;
        	break ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL ) // ��J���ȤӤj�F�٭n���k�� 
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode == NULL ) // ��J���ȤӤj�S��k�A���S��F(�N�O�S���ŦX�����) 
		{
			break ;
		}
		else if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // ��J���ȤӤp�F������ 
		{
			while ( ptr->lnode->fornode.numOfgraduation < obj ) { // ���U���Ȥp���J���ȡA�u�n���ӭȪ��k�U���Ȥ]�p���J�ȴN�i�H�����R�F 
				if ( ptr -> lnode -> rnode && ptr->lnode->rnode->fornode.numOfgraduation > obj ) { // �ܤ����A�k�U���Ȥj��F��J���ȡA�ٻݭn�B�z 
					ptr->lnode = ptr->lnode-> rnode ; // ������ptr�s�쥪�U�A�k�U�����ӼơA���L�̪����s�_�� 
				}
				else {	// �����ŦX����A�����R 
					ptr->lnode = NULL ; 
					break ;
				}
		    }
		    if ( !ptr->lnode ) break ;  
        	if ( ptr -> lnode )ptr = ptr -> lnode ;
		}
		else if( ptr -> fornode.numOfgraduation > obj && ptr->lnode == NULL )
		{

			break ;
		}

	}

} // deleteG 


void deleteSchoolName ( char obj[], node *ptr, node *root ){ // �R�� 

    if( strcmp(ptr -> fornode.schoolname, obj) == 0 && ptr == root ) { // �R����� 
    	printf( "3" ) ;
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // ���S�� 
    		printf( "3-1" ) ;
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // �u���k�l��
    		printf( "3-2" ) ;
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // �u�����l��
    		printf( "3-3" ) ;
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {
			printf( "3-4" ) ;
			ptr->rnode = root ;
			ptr->lnode = root ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = ptr->lnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->lnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // �洫 
			root = ptr->lnode ;
			return ;
		}

    	
	}

	if( strcmp(ptr -> fornode.schoolname, obj) < 0 && ptr->rnode != NULL ) // �����𪺥k�� 
	{
		printf( "1" ) ;
		if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // �����k�l��
			printf( " 1-1 ") ;
		    node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ;
			newNode2 = NULL ; 
			if( ptr->rnode->rnode ) newNode2 = ptr->rnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->rnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->rnode->lnode ;
			ptr->rnode = newNode ; // �洫 
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode && ptr -> rnode->rnode != NULL ) { // �u���k�l�� 
			printf( " 1-2 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // �u�����l�� 
			printf( " 1-3 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // ���S�� 
			printf( " 1-4 ") ;
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( strcmp(ptr -> fornode.schoolname, obj) > 0 && ptr->lnode != NULL ) // �����𪺥��� 
	{
		printf( "2" ) ;
		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // �����k�l��
			printf( "2-1" ) ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = NULL ;
			if( ptr->lnode->rnode ) newNode2 = ptr->lnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->lnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // �洫 
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode != NULL ) { // �u���k�l�� 
		    printf( "2-2" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // �u�����l�� 
			printf( "2-3" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // ���S��
			printf( "2-4" ) ; 
			ptr->lnode = NULL ;
			return ;
		}
	}
	
    if(ptr == NULL)                         //�Y�𬰪Ū� 
      return ;
    else
    { 

        if(ptr->lnode)                         //���䦳����
        {
	    	deleteSchoolName(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //�k�䦳���� 
        {
            deleteSchoolName(obj, ptr->rnode, root );
        }
    }
} // deleteSN


void deleteGraduation2 ( int obj, node *ptr, node *root ){ // �R�� 

    if( ptr -> fornode.numOfgraduation == obj && ptr == root ) {
    	printf( "3" ) ;
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // ���S�� 
    		printf( "3-1" ) ;
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // �u���k�l��
    		printf( "3-2" ) ;
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // �u�����l��
    		printf( "3-3" ) ;
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {
			printf( "3-4" ) ;
			ptr->rnode = root ;
			ptr->lnode = root ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = ptr->lnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->lnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // �洫 
			root = ptr->lnode ;
			return ;
		}

    	
	}

	if( ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL ) // �����𪺥k�� 
	{
		printf( "1" ) ;
		if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // �����k�l��
			printf( " 1-1 ") ;
		    node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ;
			newNode2 = NULL ; 
			if( ptr->rnode->rnode ) newNode2 = ptr->rnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->rnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->rnode->lnode ;
			ptr->rnode = newNode ; // �洫 
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode && ptr -> rnode->rnode != NULL ) { // �u���k�l�� 
			printf( " 1-2 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // �u�����l�� 
			printf( " 1-3 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // ���S�� 
			printf( " 1-4 ") ;
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // �����𪺥��� 
	{
		printf( "2" ) ;
		if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // �����k�l��
			printf( "2-1" ) ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // �����󥪤l�𪺲Ĥ@�� 
			while( newNode->rnode ) { // �g�L�o��while �A newNode�|���V�n�R�����ӥ��l��̭��̤j�� 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = NULL ;
			if( ptr->lnode->rnode ) newNode2 = ptr->lnode->rnode ; // newNode2�N�O�n�R���k�U 
			ptr->lnode->lnode->rnode = newNode->lnode ; // �n�R�����l�𪺥k�U = ���l��̤j�����U 
			newNode->rnode = newNode2 ; // �]�w�洫�e�����k�} 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // �洫 
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode != NULL ) { // �u���k�l�� 
		    printf( "2-2" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // �u�����l�� 
			printf( "2-3" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // ���S��
			printf( "2-4" ) ; 
			ptr->lnode = NULL ;
			return ;
		}
	}
	
    if(ptr == NULL)                         //�Y�𬰪Ū� 
      return ;
    else
    { 

        if(ptr->lnode)                         //���䦳����
        {
	    	deleteGraduation2(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //�k�䦳���� 
        {
            deleteGraduation2(obj, ptr->rnode, root );
        }
    }
	
} // deleteSN


void searchGraduation ( int obj, node *ptr, node *root ){ // �j�M 
	ptr = root ; // �q�ڶ}�l�� 
	while(1) {
		if( ptr -> fornode.numOfgraduation == obj ) {
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
        	break ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL )
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode== NULL )
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
			break ;
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

void insert(int obj, node *ptr, node *root, int i) // ���J 
{
	node *newNode = new node ; // �y�@�ӷs���`�I �A�ǥѥH�U�P�_�⥦��i��̭� 
	newNode->fornode.numOfgraduation = 0 ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // �q�ڶ}�l�� 
	
	while(1) {

		if(ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL )
		{
			ptr = ptr->lnode ;
		}
		else if ( ptr -> fornode.numOfgraduation > obj && ptr->lnode == NULL )
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
			break ; 
		} 
		else if (ptr -> fornode.numOfgraduation <= obj && ptr->rnode != NULL)
		{
			ptr = ptr->rnode ;
		}
		else if( ptr -> fornode.numOfgraduation <= obj && ptr->rnode == NULL)
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
			break ;
		}
	}
}


void insertName(char obj[], node *ptr, node *root, int i) // ���J 
{
	node *newNode = new node ; // �y�@�ӷs���`�I �A�ǥѥH�U�P�_�⥦��i��̭� 
	// newNode->fornode.schoolname = NULL ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // �q�ڶ}�l�� 
	
	while(1) {
		if( strcmp( ptr -> fornode.schoolname ,  obj ) == 0 )
		{
			break ; 
		}
		else if( strcmp( ptr -> fornode.schoolname ,  obj ) > 0 && ptr->lnode != NULL )
		{
			ptr = ptr->lnode ;
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
			break ; 
		} 
		else if ( strcmp( ptr -> fornode.schoolname ,  obj ) < 0  && ptr->rnode != NULL)
		{
			ptr = ptr->rnode ;
		}
		else if(  strcmp( ptr -> fornode.schoolname ,  obj ) < 0  && ptr->rnode == NULL)
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
		printf( "%s  %s  %s  %s  ", &forjob[i].schoolname, &forjob[i].department, &forjob[i].day, &forjob[i].level ) ; 
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
		forjob.clear() ;
		
		cout << "****   binary search tree   ****\n" ;
		cout << "* 0. Quit                      *\n" ;
		cout << "* 1. search by school name     *\n" ;
		cout << "* 2. search by school gradu    *\n" ;
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
			cout << "* 1. search by school name     *\n" ;
			cout << "* 2. search by school gradu    *\n" ;
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
			if ( start == 1 && fptr )
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
			
			 			
				int num ;
				node *root = new node ;  // �y�X�ڸ`�I 
				
				root -> fornode.schoolcode = forjob[0].schoolcode ;
				strcat( root -> fornode.schoolname, forjob[0].schoolname) ; // �]�wroot���� 
				root -> fornode.departmentcode = forjob[0].departmentcode ;
				strcat( root -> fornode.department, forjob[0].department) ; // �]�wroot���� 
				strcat( root -> fornode.day, forjob[0].day) ; // �]�wroot���� 
				strcat( root -> fornode.level, forjob[0].level) ; // �]�wroot���� 
				root -> fornode.numOfstudent = forjob[0].numOfstudent ;
				root -> fornode.numOfteacher = forjob[0].numOfteacher ;
				root -> fornode.numOfgraduation = forjob[0].numOfgraduation ; // �]�wroot���ȬO�Ĥ@�Ӹ�ƪ����~�H��
				strcat( root -> fornode.city, forjob[0].city) ; // �]�wroot���� 
				strcat( root -> fornode.system, forjob[0].system) ; // �]�wroot����  
				 
				root->lnode = NULL ; // ���k�����ONULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // �y�Xptr�h�]��,�@�}�l�O�broot����m 

			
		
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 
				    num = forjob[i].numOfgraduation ;
					insert( num , ptr, root, i ) ;
				}
			
            	int forSearch = 0 ;
            	
            	printBST( root ) ;
            	num2 = 0 ;
            	printf( "I'm HB = %d \n" , HB ) ;

    	        printf( "�п�J�n�䪺�� : " );
				cin >> forSearch ;
				searchGraduation( forSearch, ptr, root ) ;
				
	    	    printf( "�п�J�n�R������ : " );
				cin >> forSearch ;
				// deleteGraduation( forSearch, ptr, root ) ;
				deleteGraduation2( forSearch, ptr, root ) ;
				printBST( root ) ; 
		
				
				int J = 0 ;
				height = TreeHeight( root, J ) ;
				printf( "Tree Height : %d\n", height ) ;
			
			// -------------------------------�G����@����o��----------------------------------- //	
			
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
			cout << "Input a file number(ex.701,702,703) :" ;
			cin >> input ;          // Ū�J�@�ӼƦr
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  �}���ɮצ�m 
			if ( start == 2 && fptr )
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
			
			 			
				char num[10000] ;
				node *root = new node ;  // �y�X�ڸ`�I 
				root -> fornode.schoolcode = forjob[0].schoolcode ;
				strcat( root -> fornode.schoolname, forjob[0].schoolname) ; // �]�wroot���� 
				root -> fornode.departmentcode = forjob[0].departmentcode ;
				strcat( root -> fornode.department, forjob[0].department) ; // �]�wroot���� 
				strcat( root -> fornode.day, forjob[0].day) ; // �]�wroot���� 
				strcat( root -> fornode.level, forjob[0].level) ; // �]�wroot���� 
				root -> fornode.numOfstudent = forjob[0].numOfstudent ;
				root -> fornode.numOfteacher = forjob[0].numOfteacher ;
				root -> fornode.numOfgraduation = forjob[0].numOfgraduation ; // �]�wroot���ȬO�Ĥ@�Ӹ�ƪ����~�H��
				strcat( root -> fornode.city, forjob[0].city) ; // �]�wroot���� 
				strcat( root -> fornode.system, forjob[0].system) ; // �]�wroot����  
				root->lnode = NULL ; // ���k�����ONULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // �y�Xptr�h�]��,�@�}�l�O�broot����m 

					
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 

				    strcpy( num, forjob[i].schoolname ) ;
					insertName( num, ptr, root, i ) ;
				}
				
				printBST( root ) ;
				num2 = 0 ;
				
				char scN[50] ;
		
				printf( "�п�J�n�䪺�ǮզW�� : " );
				cin >> scN ;
				searchSchoolName( scN, ptr, root ) ;
				
				
				char scN2[50] ;
				printf( "�п�J�n�R�����ǮզW�� : " );
				cin >> scN2 ;
				deleteSchoolName( scN2, ptr, root ) ;
				
				printBST( root ) ;
				


	    	} // if
		} // else if (start == 2)
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while

}




