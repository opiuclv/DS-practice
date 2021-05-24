//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include<vector>
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

int size = 0 ;
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

int height = 0 ;
int TreeHeight( node * ptr, int newH ) {         // ���
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

void InputRoot( node * root, int j ) {
	root -> fornode.schoolcode = forjob[j].schoolcode ;                      // ����root���ȿ�J 
	strcat( root -> fornode.schoolname, forjob[j].schoolname) ;
	root -> fornode.departmentcode = forjob[j].departmentcode ;
	strcat( root -> fornode.department, forjob[j].department) ;  
	strcat( root -> fornode.day, forjob[j].day) ;  
	strcat( root -> fornode.level, forjob[j].level) ; 
	root -> fornode.numOfstudent = forjob[j].numOfstudent ;
	root -> fornode.numOfteacher = forjob[j].numOfteacher ;
	root -> fornode.numOfgraduation = forjob[j].numOfgraduation ;
	strcat( root -> fornode.city, forjob[j].city) ;
	strcat( root -> fornode.system, forjob[j].system) ;
	
	root->lnode = NULL ; // ���k�����ONULL 
	root->rnode = NULL ;
	
} 

// ------------------------------------------  // 
void deleteGraduation ( int obj, node *ptr, node *root ){ // �R�� 

    if( ptr -> fornode.numOfgraduation == obj && ptr == root ) {
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // ���S�� 
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // �u���k�l��
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // �u�����l��
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {
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
		if( ptr -> rnode -> fornode.numOfgraduation == obj ) {
			printf( " %s %s %s", ptr->rnode-> fornode.schoolname, ptr->rnode-> fornode.department, ptr->rnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->rnode-> fornode.level, ptr->rnode-> fornode.numOfstudent, ptr->rnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->rnode-> fornode.numOfgraduation ) ;
			
		}
		if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // �����k�l��
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
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // �u�����l�� 
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // ���S�� 
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // �����𪺥��� 
	{
		if( ptr -> lnode -> fornode.numOfgraduation == obj ) {
			printf( " %s %s %s", ptr->lnode-> fornode.schoolname, ptr->lnode-> fornode.department, ptr->lnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->lnode-> fornode.level, ptr->lnode-> fornode.numOfstudent, ptr->lnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->lnode-> fornode.numOfgraduation ) ;
			
		}

		if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // �����k�l��
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
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // �u�����l�� 
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // ���S��
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
	    	deleteGraduation(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //�k�䦳���� 
        {
            deleteGraduation(obj, ptr->rnode, root );
        }
    }
	
} // deleteG

void deleteSchoolName ( char obj[], node *ptr, node *root ){ // �R�� 

    if( strcmp(ptr -> fornode.schoolname, obj) == 0 && ptr == root ) { // �R����� 
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // ���S�� 
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // �u���k�l��
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // �u�����l��
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {

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
		if( strcmp( ptr -> rnode -> fornode.schoolname, obj ) == 0 ) {
			printf( " %s %s %s", ptr->rnode-> fornode.schoolname, ptr->rnode-> fornode.department, ptr->rnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->rnode-> fornode.level, ptr->rnode-> fornode.numOfstudent, ptr->rnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->rnode-> fornode.numOfgraduation ) ;
			
		}

		if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // �����k�l��

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

			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // �u�����l�� 

			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // ���S�� 

			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( strcmp(ptr -> fornode.schoolname, obj) > 0 && ptr->lnode != NULL ) // �����𪺥��� 
	{
		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 ) {
			printf( " %s %s %s", ptr->lnode-> fornode.schoolname, ptr->lnode-> fornode.department, ptr->lnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->lnode-> fornode.level, ptr->lnode-> fornode.numOfstudent, ptr->lnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->lnode-> fornode.numOfgraduation ) ;
			
		}

		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // �����k�l��

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

			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // �u�����l�� 

			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // ���S��

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

// ------------------------------  //


int writeBSTgraduation( node *ptr,FILE * fptr )  {
	

  if(ptr == NULL)                         //�Y�𬰪Ū� 
    return 0 ;
  else
  { 
          
    if(ptr->lnode)                         //���䦳����
    {
	    writeBSTgraduation(ptr->lnode,  fptr);   
    }

    fprintf( fptr, "%s ",ptr -> fornode.schoolname ) ;  
	fprintf( fptr, "%s ",ptr -> fornode.department ) ; 
	fprintf( fptr, "%s ",ptr -> fornode.day ) ;
	fprintf( fptr, "%s ",ptr -> fornode.level ) ;
	fprintf( fptr, " %d ", ptr->fornode.numOfstudent );
	fprintf( fptr, " %d ", ptr->fornode.numOfteacher );
    fprintf( fptr, " %d \n", ptr->fornode.numOfgraduation );              //���X�쪺�������L�X�� 
    putc( '\n', fptr ) ;
                                

    if(ptr->rnode)                        //�k�䦳���� 
    {
        writeBSTgraduation(ptr->rnode, fptr);
    }

  }
	
}



int writeBSTschoolname( node *ptr,FILE * fptr )  {
	

  if(ptr == NULL)                         //�Y�𬰪Ū� 
    return 0 ;
  else
  { 

    if(ptr->lnode)                         //���䦳����
    {
	    writeBSTschoolname(ptr->lnode,  fptr);   
    }
    
    fprintf( fptr, "%s ",ptr -> fornode.schoolname ) ;  
	fprintf( fptr, "%s ",ptr -> fornode.department ) ; 
	fprintf( fptr, "%s ",ptr -> fornode.day ) ;
	fprintf( fptr, "%s ",ptr -> fornode.level ) ;
	fprintf( fptr, " %d ", ptr->fornode.numOfstudent );
	fprintf( fptr, " %d ", ptr->fornode.numOfteacher );
    fprintf( fptr, " %d \n", ptr->fornode.numOfgraduation );              //���X�쪺�������L�X�� 
    putc( '\n', fptr ) ;
                                


    if(ptr->rnode)                        //�k�䦳���� 
    {
        writeBSTschoolname(ptr->rnode, fptr);
    }

  }
	
}


int num2 = 0 ;
int printBST( node *ptr ) {               // �⥦�L�X�� 
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
    if(ptr->lnode)                         //���䦳����
    {
	    printBST(ptr->lnode);   
    }

    if(ptr->rnode)                        //�k�䦳���� 
    {
        printBST(ptr->rnode);
    }


  }
}


// -----------------------------------------------------  //

int num3 = 0 ; 
void searchGraduation ( int obj, node *ptr, node *root ){ // �j�M 
	ptr = root ; // �q�ڶ}�l�� 
	while(1) {
		num3 = num3 + 1 ;
		printf( "%d\n", num3) ;
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


void PrintJob( int i ){
	
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
	char temp[50] = "input" ;
	
	int graduationHeight = 1 ;            // �𪺰��� 
	int schoolnameHeight = 1 ;
	char inputschoolname[100] ;
	int num ;
	
	node * ptr ;                          // �ΨӶ]�� 
	node * temp11 ;
    node * rootOfgraduation = new node ;  // �y�X�ڸ`�I
	node * rootOfschoolname = new node ;  // �y�X�ڸ`�I
	

	while ( true )
	{
		forjob.clear() ;
		
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
			cout << "Input a file number(ex.801,802,803) :" ;
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
    			
    			InputRoot( rootOfgraduation, 0 ) ;       // Ū�J�ڪ���	 
    			InputRoot( rootOfschoolname, 0 ) ;
				
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
				
				size = forjob.size() ;
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
			char scN2[50] ;
			cout << "Input a school name:" ;
			cin >> scN2 ;
			deleteSchoolName( scN2, ptr, rootOfschoolname ) ; 
			
			for ( int i = 0 ; i < size ; i ++ ) {
				if( strcmp( forjob[i].schoolname, scN2 ) == 0 ) 
					deleteSchoolName( forjob[i].schoolname, ptr, rootOfschoolname ) ; 
			}
			
			int J = 0 ;
			height = TreeHeight( rootOfschoolname, J ) ;
			printf( "Tree Height : %d\n", height ) ;          // �p��� 
			
		} // else if 
		
		
		else if ( start == 5 )                 //    5. Removal by Number of Graduates 
		{
			cout << "Input the number of graduates:" ;
			cin >> num ;
			
			ptr = rootOfgraduation ;
			for ( int i = 0 ; i < size ; i ++ ) {
				if( forjob[i].numOfgraduation < num ) 
					deleteGraduation( forjob[i].numOfgraduation,ptr , rootOfgraduation ) ;
			}
			
			ptr = rootOfgraduation ;
			int J = 0 ;
			height = TreeHeight( rootOfgraduation, J ) ;
			printf( "Tree Height : %d\n", height ) ;

			
		} // else if 
		
		else if ( start == 6 )                 //    6. save 
		{
			FILE * fptr = fopen( "tree701num.txt", "w" ) ;               //  �}���ɮצ�m
			writeBSTgraduation( rootOfgraduation, fptr ) ;
			fclose( fptr ) ;
			
			fptr = fopen( "tree701name.txt", "w" ) ;               //  �}���ɮצ�m
			writeBSTschoolname( rootOfschoolname, fptr ) ;
			fclose( fptr ) ;
			
		} // else if 
		
		else if ( start == 7 )                 //    7. load
		{
			forjob.clear() ;
			
			FILE * fptr = fopen( "tree701num.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{             
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%s%s", &joblist.schoolname, &joblist.department ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;

					forjob.push_back( joblist ) ;              // �N�u�@����̫�@��
						
					fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
					numofjob = i ;          //  �]�wjob�ƶq 
					
				} // for
				
				fclose( fptr ) ;
			}

    		InputRoot( rootOfgraduation, forjob.size() / 2 ) ;       // Ū�J�ڪ���	                         // �n�令������ 

			graduationHeight = 0 ;
			height = 0 ;
   			ptr = rootOfgraduation ;
			int H = 0 ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // �β��~�H�ƺؾ� 
				if ( i == forjob.size() / 2 ) i ++ ;
				H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
				if ( graduationHeight < H )
					graduationHeight = H ;             // �𪺲`�� 
			}
				
			// ---------------------------------------------------------------------------------------------- //
			
			forjob.clear() ;
			
			fptr = fopen( "tree701name.txt", "rt" ) ;               //  �}���ɮצ�m 
			if ( fptr )
			{             
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  Ū�J 
				{
					fscanf( fptr, "%s%s", &joblist.schoolname, &joblist.department ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;

					forjob.push_back( joblist ) ;              // �N�u�@����̫�@��
						
					fscanf( fptr, "%c", &ch ) ;         //  ��ťզr��Ū�� 
					numofjob = i ;          //  �]�wjob�ƶq 
					
				} // for
				
				fclose( fptr ) ;
			}
			
    		InputRoot( rootOfschoolname, forjob.size() / 2 ) ;    // �n�令������
			
			height = 0 ;
			schoolnameHeight = 0 ;
			
			H = 0 ;
			ptr = rootOfschoolname ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {
				if ( i == forjob.size() / 2 ) i ++ ;
				H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
				if ( schoolnameHeight < H )
					schoolnameHeight = H ;             // �𪺲`�� 
			}
			
			// ---------------------------------------------------------------------------------------------- //
			
			printf( "Tree heights:\n" ) ;
			printf( "{School name} = %d\n", schoolnameHeight ) ;              // �L�X��
			printf( "{Number of graduates} = %d\n\n", graduationHeight ) ;              // �L�X�� 
				 
		} // else if 
		
		
		else printf( "�ЦA��J�@��" ) ;
	
	} // while

}




