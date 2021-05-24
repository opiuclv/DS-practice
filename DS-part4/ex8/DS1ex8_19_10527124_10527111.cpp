//  第19組 
//  施育暘 10527111
//  邱正皓 10527124 

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
    char department[50] ;         // 科系名稱 
    char day[50] ;                 // 日間 / 進修別 
    char level[50] ;              // ( 學士 ) 
    int numOfstudent ;
    int numOfteacher ;
    int numOfgraduation ;
    char city[50] ;
    char system[50] ;             // 體系 
    
} ;

int size = 0 ;
int a = 0 ;
int numofjob = 0 ;
vector<struct Job> forjob ;              // 用 vector 來做 
Job joblist ;

struct node // 造出node的格式 
{
	Job fornode ;
	node *lnode = NULL ;
	node *rnode = NULL ;
} ;

int height = 0 ;
int TreeHeight( node * ptr, int newH ) {         // 找樹高
	if ( newH > height ) {
		height = newH ; 
	}
	
	if ( ptr != NULL )                      // 把樹跑一遍 
	{
		TreeHeight( ptr -> lnode, newH+1 ) ;
		TreeHeight( ptr -> rnode, newH+1 ) ;
		
	} // if
	
	return height ;
	
} // TreeHeight

void InputRoot( node * root, int j ) {
	root -> fornode.schoolcode = forjob[j].schoolcode ;                      // 先把root的值輸入 
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
	
	root->lnode = NULL ; // 左右都先是NULL 
	root->rnode = NULL ;
	
} 

// ------------------------------------------  // 
void deleteGraduation ( int obj, node *ptr, node *root ){ // 刪除 

    if( ptr -> fornode.numOfgraduation == obj && ptr == root ) {
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // 都沒有 
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // 只有右子樹
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // 只有左子樹
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {
			ptr->rnode = root ;
			ptr->lnode = root ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = ptr->lnode->rnode ; // newNode2就是要刪的右下 
			ptr->lnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // 交換 
			root = ptr->lnode ;
			return ;
		}

    	
	}

	if( ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL ) // 整顆樹的右邊 
	{
		if( ptr -> rnode -> fornode.numOfgraduation == obj ) {
			printf( " %s %s %s", ptr->rnode-> fornode.schoolname, ptr->rnode-> fornode.department, ptr->rnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->rnode-> fornode.level, ptr->rnode-> fornode.numOfstudent, ptr->rnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->rnode-> fornode.numOfgraduation ) ;
			
		}
		if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // 有左右子樹
		    node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ;
			newNode2 = NULL ; 
			if( ptr->rnode->rnode ) newNode2 = ptr->rnode->rnode ; // newNode2就是要刪的右下 
			ptr->rnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->rnode->lnode ;
			ptr->rnode = newNode ; // 交換 
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode && ptr -> rnode->rnode != NULL ) { // 只有右子樹 
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // 只有左子樹 
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // 都沒有 
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // 整顆樹的左邊 
	{
		if( ptr -> lnode -> fornode.numOfgraduation == obj ) {
			printf( " %s %s %s", ptr->lnode-> fornode.schoolname, ptr->lnode-> fornode.department, ptr->lnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->lnode-> fornode.level, ptr->lnode-> fornode.numOfstudent, ptr->lnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->lnode-> fornode.numOfgraduation ) ;
			
		}

		if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // 有左右子樹
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = NULL ;
			if( ptr->lnode->rnode ) newNode2 = ptr->lnode->rnode ; // newNode2就是要刪的右下 
			ptr->lnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // 交換 
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode != NULL ) { // 只有右子樹 
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // 只有左子樹 
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // 都沒有
			ptr->lnode = NULL ;
			return ;
		}
	}
	
    if(ptr == NULL)                         //若樹為空的 
      return ;
    else
    { 

        if(ptr->lnode)                         //左邊有元素
        {
	    	deleteGraduation(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //右邊有元素 
        {
            deleteGraduation(obj, ptr->rnode, root );
        }
    }
	
} // deleteG

void deleteSchoolName ( char obj[], node *ptr, node *root ){ // 刪除 

    if( strcmp(ptr -> fornode.schoolname, obj) == 0 && ptr == root ) { // 刪除樹根 
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // 都沒有 
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // 只有右子樹
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // 只有左子樹
		 	root = ptr->lnode ;
			ptr = NULL ;
			ptr = root ;	
			return ;
		}
		else {

			ptr->rnode = root ;
			ptr->lnode = root ;
		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = ptr->lnode->rnode ; // newNode2就是要刪的右下 
			ptr->lnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // 交換 
			root = ptr->lnode ;
			return ;
		}

    	
	}

	if( strcmp(ptr -> fornode.schoolname, obj) < 0 && ptr->rnode != NULL ) // 整顆樹的右邊 
	{
		if( strcmp( ptr -> rnode -> fornode.schoolname, obj ) == 0 ) {
			printf( " %s %s %s", ptr->rnode-> fornode.schoolname, ptr->rnode-> fornode.department, ptr->rnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->rnode-> fornode.level, ptr->rnode-> fornode.numOfstudent, ptr->rnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->rnode-> fornode.numOfgraduation ) ;
			
		}

		if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // 有左右子樹

		    node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ;
			newNode2 = NULL ; 
			if( ptr->rnode->rnode ) newNode2 = ptr->rnode->rnode ; // newNode2就是要刪的右下 
			ptr->rnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->rnode->lnode ;
			ptr->rnode = newNode ; // 交換 
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode && ptr -> rnode->rnode != NULL ) { // 只有右子樹 

			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // 只有左子樹 

			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // 都沒有 

			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( strcmp(ptr -> fornode.schoolname, obj) > 0 && ptr->lnode != NULL ) // 整顆樹的左邊 
	{
		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 ) {
			printf( " %s %s %s", ptr->lnode-> fornode.schoolname, ptr->lnode-> fornode.department, ptr->lnode-> fornode.day ) ;
			printf( " %s %d %d", ptr->lnode-> fornode.level, ptr->lnode-> fornode.numOfstudent, ptr->lnode->fornode.numOfteacher ) ;
			printf( " %d \n ", ptr->lnode-> fornode.numOfgraduation ) ;
			
		}

		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // 有左右子樹

		    node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; // 先等於左子樹的第一個 
			while( newNode->rnode ) { // 經過這個while ， newNode會指向要刪的那個左子樹裡面最大的 
				newNode = newNode->rnode ;
			}
			node *newNode2 = new node ; 
			newNode2 = NULL ;
			if( ptr->lnode->rnode ) newNode2 = ptr->lnode->rnode ; // newNode2就是要刪的右下 
			ptr->lnode->lnode->rnode = newNode->lnode ; // 要刪的左子樹的右下 = 左子樹最大的左下 
			newNode->rnode = newNode2 ; // 設定交換前的左右腳 
			newNode->lnode = ptr->lnode->lnode ;
			ptr->lnode = newNode ; // 交換 
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode != NULL ) { // 只有右子樹 

			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // 只有左子樹 

			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // 都沒有

			ptr->lnode = NULL ;
			return ;
		}
	}
	
    if(ptr == NULL)                         //若樹為空的 
      return ;
    else
    { 

        if(ptr->lnode)                         //左邊有元素
        {
	    	deleteSchoolName(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //右邊有元素 
        {
            deleteSchoolName(obj, ptr->rnode, root );
        }
    }
} // deleteSN

// ------------------------------  //


int writeBSTgraduation( node *ptr,FILE * fptr )  {
	

  if(ptr == NULL)                         //若樹為空的 
    return 0 ;
  else
  { 
          
    if(ptr->lnode)                         //左邊有元素
    {
	    writeBSTgraduation(ptr->lnode,  fptr);   
    }

    fprintf( fptr, "%s ",ptr -> fornode.schoolname ) ;  
	fprintf( fptr, "%s ",ptr -> fornode.department ) ; 
	fprintf( fptr, "%s ",ptr -> fornode.day ) ;
	fprintf( fptr, "%s ",ptr -> fornode.level ) ;
	fprintf( fptr, " %d ", ptr->fornode.numOfstudent );
	fprintf( fptr, " %d ", ptr->fornode.numOfteacher );
    fprintf( fptr, " %d \n", ptr->fornode.numOfgraduation );              //走訪到的元素先印出來 
    putc( '\n', fptr ) ;
                                

    if(ptr->rnode)                        //右邊有元素 
    {
        writeBSTgraduation(ptr->rnode, fptr);
    }

  }
	
}



int writeBSTschoolname( node *ptr,FILE * fptr )  {
	

  if(ptr == NULL)                         //若樹為空的 
    return 0 ;
  else
  { 

    if(ptr->lnode)                         //左邊有元素
    {
	    writeBSTschoolname(ptr->lnode,  fptr);   
    }
    
    fprintf( fptr, "%s ",ptr -> fornode.schoolname ) ;  
	fprintf( fptr, "%s ",ptr -> fornode.department ) ; 
	fprintf( fptr, "%s ",ptr -> fornode.day ) ;
	fprintf( fptr, "%s ",ptr -> fornode.level ) ;
	fprintf( fptr, " %d ", ptr->fornode.numOfstudent );
	fprintf( fptr, " %d ", ptr->fornode.numOfteacher );
    fprintf( fptr, " %d \n", ptr->fornode.numOfgraduation );              //走訪到的元素先印出來 
    putc( '\n', fptr ) ;
                                


    if(ptr->rnode)                        //右邊有元素 
    {
        writeBSTschoolname(ptr->rnode, fptr);
    }

  }
	
}


int num2 = 0 ;
int printBST( node *ptr ) {               // 把它印出來 
  num2 = num2 + 1 ;
  if(ptr == NULL)                         //若樹為空的 
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
    printf(" %d \n", ptr->fornode.numOfgraduation );              //走訪到的元素先印出來 
                                          //再依照前序走訪的方式加上括號和逗號
    if(ptr->lnode)                         //左邊有元素
    {
	    printBST(ptr->lnode);   
    }

    if(ptr->rnode)                        //右邊有元素 
    {
        printBST(ptr->rnode);
    }


  }
}


// -----------------------------------------------------  //

int num3 = 0 ; 
void searchGraduation ( int obj, node *ptr, node *root ){ // 搜尋 
	ptr = root ; // 從根開始找 
	while(1) {
		num3 = num3 + 1 ;
		printf( "%d\n", num3) ;
		if( ptr -> fornode.numOfgraduation == obj ) {                        // 如果找到一樣的，就印出來八 
    		printf( "%s ",ptr -> fornode.schoolname ) ;  
			printf( "%s ",ptr -> fornode.department ) ; 
			printf( "%s ",ptr -> fornode.day ) ;
			printf( "%s ",ptr -> fornode.level ) ;
			printf(" %d ", ptr->fornode.numOfstudent );
			printf(" %d ", ptr->fornode.numOfteacher );
    		printf(" %d \n", ptr->fornode.numOfgraduation );              //走訪到的元素先印出來 
			ptr = ptr-> rnode ;
        	printBST(ptr) ;
        	num2 = 0 ;
        	if ( !ptr -> rnode )break ;                                //      ????????????????????????
			ptr = ptr -> rnode ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL )         // 往右走 
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode== NULL )         // 往右走到樹底 
		{
			printf( "沒有比此值大的數" ) ;
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
   				printf(" %d \n", ptr->fornode.numOfgraduation );              //走訪到的元素先印出來 
			}
        	ptr = ptr -> lnode ;
		}

	}
}


void searchSchoolName ( char obj[], node *ptr, node *root ){ // 搜尋 

	ptr = root ; // 從根開始找
 
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

int insert(int obj, node *ptr, node * root, int i) {          // 插入 
	node *newNode = new node ; // 造一個新的節點 再藉由以下判斷把它塞進樹裡面 
	newNode->fornode.numOfgraduation = 0 ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // 從根開始找 
	int height = 1 ;
	
	while(1) {
		
		if(ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL )                      // 往左走，但是還不是樹底 
		{
			ptr = ptr->lnode ;
			height++ ;
		}
		else if ( ptr -> fornode.numOfgraduation > obj && ptr->lnode == NULL )                      // 往左走到樹底 
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
		else if (ptr -> fornode.numOfgraduation <= obj && ptr->rnode != NULL)                      // 往右走，但是還不是樹底 
		{
			ptr = ptr->rnode ;
			height++ ;
		}
		else if( ptr -> fornode.numOfgraduation <= obj && ptr->rnode == NULL)                      // 往右走到樹底 
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

int insertName(char obj[], node *ptr, node *root, int i) // 插入 
{
	node *newNode = new node ; // 造一個新的節點 再藉由以下判斷把它塞進樹裡面 
	// newNode->fornode.schoolname = NULL ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // 從根開始找 
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
	char ch ;                                      // 用來讀入空白字元
	bool getin = true ;
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input" ;
	
	int graduationHeight = 1 ;            // 樹的高度 
	int schoolnameHeight = 1 ;
	char inputschoolname[100] ;
	int num ;
	
	node * ptr ;                          // 用來跑樹 
	node * temp11 ;
    node * rootOfgraduation = new node ;  // 造出根節點
	node * rootOfschoolname = new node ;  // 造出根節點
	

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
	
		if ( start == 0 )                                  // 結束 
			exit(1) ; 
		
		else if ( start == 1 ) 
		{
			cout << "Input a file number(ex.801,802,803) :" ;
			cin >> input ;          // 讀入一個數字
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%c", &ch ) ;             // 第一行讀掉 
				while ( ch != '\n' )
					fscanf( fptr, "%c", &ch ) ;
					
				fscanf( fptr, "%c", &ch ) ;             // 第二行讀掉 
				while ( ch != '\n' )
					fscanf( fptr, "%c", &ch ) ;

				
				for ( int k = 0 ; k < 11 ; k++ )
				{
					fscanf( fptr, "%s", &ch ) ;
				} // for
				fscanf( fptr, "%c", &ch ) ;                    
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  讀入 
				{
					fscanf( fptr, "%d%s%d%s", &joblist.schoolcode, &joblist.schoolname, &joblist.departmentcode, &joblist.department ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;
						
					fscanf( fptr, "%s%s", &joblist.city, &temp ) ;          // 城市 
					strcat( joblist.day, " " ) ;
					strcat( joblist.city, temp ) ;
						
					fscanf( fptr, "%s%s", &joblist.system, &temp ) ;       //  體系 
					strcat( joblist.day, " " ) ;
					strcat( joblist.system, temp ) ;

					forjob.push_back( joblist ) ;              // 將工作移到最後一個
						
					fscanf( fptr, "%c", &ch ) ;         //  把空白字元讀掉 
					numofjob = i ;          //  設定job數量 
				} // for
				
				fclose( fptr ) ;

    		// ---------------------------------------這裡以下是二元樹------------------------------ //
    			
    			InputRoot( rootOfgraduation, 0 ) ;       // 讀入根的值	 
    			InputRoot( rootOfschoolname, 0 ) ;
				
   				ptr = rootOfgraduation ;
				int H = 0 ;
				for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // 用畢業人數種樹 
					H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
					if ( graduationHeight < H )
						graduationHeight = H ;             // 樹的深度 
				}
			
				H = 0 ;
				ptr = rootOfschoolname ;
				for ( int i = 1 ; i < forjob.size() ; i ++ ) {
					H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
					if ( schoolnameHeight < H )
						schoolnameHeight = H ;             // 樹的深度 
				}
				
				size = forjob.size() ;
				printf( "Tree heights:\n" ) ;
				printf( "{School name} = %d\n", schoolnameHeight ) ;              // 印出樹高
				printf( "{Number of graduates} = %d\n\n", graduationHeight ) ;              // 印出樹高 
				 
				
				
				
				
			
			// -------------------------------二元樹一直到這裡----------------------------------- //	
			
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
			cout << "Input a school name:" ;
			cin >> inputschoolname ;          // 讀入一個學校 
			
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
			printf( "Tree Height : %d\n", height ) ;          // 計算樹高 
			
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
			FILE * fptr = fopen( "tree701num.txt", "w" ) ;               //  開啟檔案位置
			writeBSTgraduation( rootOfgraduation, fptr ) ;
			fclose( fptr ) ;
			
			fptr = fopen( "tree701name.txt", "w" ) ;               //  開啟檔案位置
			writeBSTschoolname( rootOfschoolname, fptr ) ;
			fclose( fptr ) ;
			
		} // else if 
		
		else if ( start == 7 )                 //    7. load
		{
			forjob.clear() ;
			
			FILE * fptr = fopen( "tree701num.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{             
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  讀入 
				{
					fscanf( fptr, "%s%s", &joblist.schoolname, &joblist.department ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;

					forjob.push_back( joblist ) ;              // 將工作移到最後一個
						
					fscanf( fptr, "%c", &ch ) ;         //  把空白字元讀掉 
					numofjob = i ;          //  設定job數量 
					
				} // for
				
				fclose( fptr ) ;
			}

    		InputRoot( rootOfgraduation, forjob.size() / 2 ) ;       // 讀入根的值	                         // 要改成中間值 

			graduationHeight = 0 ;
			height = 0 ;
   			ptr = rootOfgraduation ;
			int H = 0 ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // 用畢業人數種樹 
				if ( i == forjob.size() / 2 ) i ++ ;
				H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
				if ( graduationHeight < H )
					graduationHeight = H ;             // 樹的深度 
			}
				
			// ---------------------------------------------------------------------------------------------- //
			
			forjob.clear() ;
			
			fptr = fopen( "tree701name.txt", "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{             
				
				for( int i = 0 ; !feof(fptr) ; i++ )            //  讀入 
				{
					fscanf( fptr, "%s%s", &joblist.schoolname, &joblist.department ) ;
					fscanf( fptr, "%s%s", &joblist.day, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.day, temp ) ;
					
					fscanf( fptr, "%s%s", &joblist.level, &temp ) ;
					strcat( joblist.day, " " ) ;
					strcat( joblist.level, temp ) ;
					
					fscanf( fptr, "%d%d%d", &joblist.numOfstudent, &joblist.numOfteacher, &joblist.numOfgraduation ) ;

					forjob.push_back( joblist ) ;              // 將工作移到最後一個
						
					fscanf( fptr, "%c", &ch ) ;         //  把空白字元讀掉 
					numofjob = i ;          //  設定job數量 
					
				} // for
				
				fclose( fptr ) ;
			}
			
    		InputRoot( rootOfschoolname, forjob.size() / 2 ) ;    // 要改成中間值
			
			height = 0 ;
			schoolnameHeight = 0 ;
			
			H = 0 ;
			ptr = rootOfschoolname ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {
				if ( i == forjob.size() / 2 ) i ++ ;
				H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
				if ( schoolnameHeight < H )
					schoolnameHeight = H ;             // 樹的深度 
			}
			
			// ---------------------------------------------------------------------------------------------- //
			
			printf( "Tree heights:\n" ) ;
			printf( "{School name} = %d\n", schoolnameHeight ) ;              // 印出樹高
			printf( "{Number of graduates} = %d\n\n", graduationHeight ) ;              // 印出樹高 
				 
		} // else if 
		
		
		else printf( "請再輸入一次" ) ;
	
	} // while

}




