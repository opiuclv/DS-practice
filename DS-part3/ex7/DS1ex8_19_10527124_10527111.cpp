//  第19組 
//  施育暘 10527111
//  邱正皓 10527124 

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
    char department[50] ;         // 科系名稱 
    char day[50] ;                 // 日間 / 進修別 
    char level[50] ;              // ( 學士 ) 
    int numOfstudent ;
    int numOfteacher ;
    int numOfgraduation ;
    char city[50] ;
    char system[50] ;             // 體系 
    
} ;


int a = 0 ;
int numofjob = 0 ;
vector<struct Job> forjob ;              // 用 vector 來做 
Job joblist ;

struct node // 造出node的格式 
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
                                          
    if(!ptr->lnode && !ptr->rnode) H = 0 ;
    if(ptr->lnode)                         //左邊有元素
    {
	    printBST(ptr->lnode); 
    }

    if(ptr->rnode)                        //右邊有元素 
    {
        printBST(ptr->rnode);
    }

    H = H + 1 ; 
  }	
}


int height = 0 ;
int TreeHeight( node * ptr, int newH )            // 找樹高 
{	
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

void deleteGraduation ( int obj, node *ptr, node *root ){ // 刪除

	ptr = root ; // 從根開始找 
	while(1) {
		if( ptr -> fornode.numOfgraduation == obj ) { // 一樣就左邊全部刪 
			ptr->lnode = NULL ;
        	break ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL ) // 輸入的值太大了還要往右找 
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode == NULL ) // 輸入的值太大沒辦法再往又找了(就是沒找到符合的資料) 
		{
			break ;
		}
		else if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // 輸入的值太小了往左找 
		{
			while ( ptr->lnode->fornode.numOfgraduation < obj ) { // 左下的值小於輸入的值，只要那個值的右下的值也小於輸入值就可以直接刪了 
				if ( ptr -> lnode -> rnode && ptr->lnode->rnode->fornode.numOfgraduation > obj ) { // 很不巧，右下的值大於了輸入的值，還需要處理 
					ptr->lnode = ptr->lnode-> rnode ; // 直接把ptr連到左下再右下的那個數，讓他們直接連起來 
				}
				else {	// 完全符合條件，直接刪 
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


void deleteSchoolName ( char obj[], node *ptr, node *root ){ // 刪除 

    if( strcmp(ptr -> fornode.schoolname, obj) == 0 && ptr == root ) { // 刪除樹根 
    	printf( "3" ) ;
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // 都沒有 
    		printf( "3-1" ) ;
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // 只有右子樹
    		printf( "3-2" ) ;
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // 只有左子樹
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
		printf( "1" ) ;
		if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // 有左右子樹
			printf( " 1-1 ") ;
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
			printf( " 1-2 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // 只有左子樹 
			printf( " 1-3 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( strcmp(ptr ->rnode-> fornode.schoolname, obj) == 0 && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // 都沒有 
			printf( " 1-4 ") ;
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( strcmp(ptr -> fornode.schoolname, obj) > 0 && ptr->lnode != NULL ) // 整顆樹的左邊 
	{
		printf( "2" ) ;
		if( strcmp( ptr -> lnode -> fornode.schoolname, obj ) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // 有左右子樹
			printf( "2-1" ) ;
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
		    printf( "2-2" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // 只有左子樹 
			printf( "2-3" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( strcmp( ptr -> lnode -> fornode.schoolname, obj) == 0 && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // 都沒有
			printf( "2-4" ) ; 
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


void deleteGraduation2 ( int obj, node *ptr, node *root ){ // 刪除 

    if( ptr -> fornode.numOfgraduation == obj && ptr == root ) {
    	printf( "3" ) ;
    	
    	if( ptr->rnode == NULL && ptr->lnode == NULL ) { // 都沒有 
    		printf( "3-1" ) ;
		 	root = NULL ;
			return ;	
		}	
    	
    	if( ptr->rnode != NULL && ptr->lnode == NULL ) { // 只有右子樹
    		printf( "3-2" ) ;
		 	root = ptr->rnode ;
			ptr = NULL ;
			ptr = root ;
			return ;	
		}
    	if( ptr->rnode == NULL && ptr->lnode != NULL ) { // 只有左子樹
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
		printf( "1" ) ;
		if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode != NULL ) { // 有左右子樹
			printf( " 1-1 ") ;
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
			printf( " 1-2 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode != NULL && ptr -> rnode->rnode == NULL ) { // 只有左子樹 
			printf( " 1-3 ") ;
			node *newNode = new node ; 
			newNode = ptr->rnode->lnode ; 
			ptr->rnode = NULL ;
			ptr->rnode = newNode ;
			return ;
		}
		
		else if( ptr -> rnode -> fornode.numOfgraduation == obj && ptr -> rnode->lnode == NULL && ptr -> rnode->rnode == NULL ) { // 都沒有 
			printf( " 1-4 ") ;
			ptr->rnode = NULL ;
			return ;
		}
	}	
	
	
	if( ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL ) // 整顆樹的左邊 
	{
		printf( "2" ) ;
		if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode != NULL ) { // 有左右子樹
			printf( "2-1" ) ;
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
		    printf( "2-2" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->rnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode != NULL && ptr -> lnode->rnode == NULL ) { // 只有左子樹 
			printf( "2-3" ) ;
			node *newNode = new node ; 
			newNode = ptr->lnode->lnode ; 
			ptr->lnode = NULL ;
			ptr->lnode = newNode ;
			return ;
		}
		else if( ptr -> lnode -> fornode.numOfgraduation == obj && ptr -> lnode->lnode == NULL && ptr -> lnode->rnode == NULL ) { // 都沒有
			printf( "2-4" ) ; 
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
	    	deleteGraduation2(obj, ptr->lnode, root ); 
        }

        if(ptr->rnode)                        //右邊有元素 
        {
            deleteGraduation2(obj, ptr->rnode, root );
        }
    }
	
} // deleteSN


void searchGraduation ( int obj, node *ptr, node *root ){ // 搜尋 
	ptr = root ; // 從根開始找 
	while(1) {
		if( ptr -> fornode.numOfgraduation == obj ) {
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
        	break ;
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode != NULL )
		{
			ptr = ptr->rnode ; 
		}
		else if(ptr -> fornode.numOfgraduation < obj && ptr->rnode== NULL )
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

void insert(int obj, node *ptr, node *root, int i) // 插入 
{
	node *newNode = new node ; // 造一個新的節點 再藉由以下判斷把它塞進樹裡面 
	newNode->fornode.numOfgraduation = 0 ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // 從根開始找 
	
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


void insertName(char obj[], node *ptr, node *root, int i) // 插入 
{
	node *newNode = new node ; // 造一個新的節點 再藉由以下判斷把它塞進樹裡面 
	// newNode->fornode.schoolname = NULL ;
	newNode->rnode=NULL ;
	newNode->lnode=NULL ;
	ptr = root ; // 從根開始找 
	
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
	cout << "大專校院各校科系別概況\n" ; 
	cout << "105 學年度 SY2016-2017\n" ;
	cout << "	學校名稱	科系名稱	日間／進修別	等級別	學生數	教師數	上學年度畢業生數\n" ;
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
	char ch ;                                      // 用來讀入空白字元
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
	
		while( start < 0 || start > 2 )                    //  如果是負號的話 就一直讀 
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
	
		if ( start == 0 )                                  // 結束 
			exit(1) ; 
		
		else if ( start == 1 ) 
		{
			cout << "Input a file number(ex.701,702,703) :" ;
			cin >> input ;          // 讀入一個數字
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			if ( start == 1 && fptr )
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
			
			 			
				int num ;
				node *root = new node ;  // 造出根節點 
				
				root -> fornode.schoolcode = forjob[0].schoolcode ;
				strcat( root -> fornode.schoolname, forjob[0].schoolname) ; // 設定root的值 
				root -> fornode.departmentcode = forjob[0].departmentcode ;
				strcat( root -> fornode.department, forjob[0].department) ; // 設定root的值 
				strcat( root -> fornode.day, forjob[0].day) ; // 設定root的值 
				strcat( root -> fornode.level, forjob[0].level) ; // 設定root的值 
				root -> fornode.numOfstudent = forjob[0].numOfstudent ;
				root -> fornode.numOfteacher = forjob[0].numOfteacher ;
				root -> fornode.numOfgraduation = forjob[0].numOfgraduation ; // 設定root的值是第一個資料的畢業人數
				strcat( root -> fornode.city, forjob[0].city) ; // 設定root的值 
				strcat( root -> fornode.system, forjob[0].system) ; // 設定root的值  
				 
				root->lnode = NULL ; // 左右都先是NULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // 造出ptr去跑樹,一開始是在root的位置 

			
		
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 
				    num = forjob[i].numOfgraduation ;
					insert( num , ptr, root, i ) ;
				}
			
            	int forSearch = 0 ;
            	
            	printBST( root ) ;
            	num2 = 0 ;
            	printf( "I'm HB = %d \n" , HB ) ;

    	        printf( "請輸入要找的數 : " );
				cin >> forSearch ;
				searchGraduation( forSearch, ptr, root ) ;
				
	    	    printf( "請輸入要刪除的數 : " );
				cin >> forSearch ;
				// deleteGraduation( forSearch, ptr, root ) ;
				deleteGraduation2( forSearch, ptr, root ) ;
				printBST( root ) ; 
		
				
				int J = 0 ;
				height = TreeHeight( root, J ) ;
				printf( "Tree Height : %d\n", height ) ;
			
			// -------------------------------二元樹一直到這裡----------------------------------- //	
			
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else if
		
		
		else if ( start == 2 ) {
		
			cout << "Input a file number(ex.701,702,703) :" ;
			cin >> input ;          // 讀入一個數字
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			if ( start == 2 && fptr )
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
			
			 			
				char num[10000] ;
				node *root = new node ;  // 造出根節點 
				root -> fornode.schoolcode = forjob[0].schoolcode ;
				strcat( root -> fornode.schoolname, forjob[0].schoolname) ; // 設定root的值 
				root -> fornode.departmentcode = forjob[0].departmentcode ;
				strcat( root -> fornode.department, forjob[0].department) ; // 設定root的值 
				strcat( root -> fornode.day, forjob[0].day) ; // 設定root的值 
				strcat( root -> fornode.level, forjob[0].level) ; // 設定root的值 
				root -> fornode.numOfstudent = forjob[0].numOfstudent ;
				root -> fornode.numOfteacher = forjob[0].numOfteacher ;
				root -> fornode.numOfgraduation = forjob[0].numOfgraduation ; // 設定root的值是第一個資料的畢業人數
				strcat( root -> fornode.city, forjob[0].city) ; // 設定root的值 
				strcat( root -> fornode.system, forjob[0].system) ; // 設定root的值  
				root->lnode = NULL ; // 左右都先是NULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // 造出ptr去跑樹,一開始是在root的位置 

					
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 

				    strcpy( num, forjob[i].schoolname ) ;
					insertName( num, ptr, root, i ) ;
				}
				
				printBST( root ) ;
				num2 = 0 ;
				
				char scN[50] ;
		
				printf( "請輸入要找的學校名稱 : " );
				cin >> scN ;
				searchSchoolName( scN, ptr, root ) ;
				
				
				char scN2[50] ;
				printf( "請輸入要刪除的學校名稱 : " );
				cin >> scN2 ;
				deleteSchoolName( scN2, ptr, root ) ;
				
				printBST( root ) ;
				


	    	} // if
		} // else if (start == 2)
		
		else printf( "請再輸入一次" ) ;
	
	} // while

}




