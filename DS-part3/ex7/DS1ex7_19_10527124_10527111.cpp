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
	node *lnode;
	node *rnode ;
};

int printBST( node *ptr )
{

  if(ptr == NULL)                         //若樹為空的 
    return 0;
  else
  { 
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
	else if(ptr->lnode == NULL)            //左邊走到底了,再往右邊走 
    {
        ;
    }
    if(ptr->rnode)                        //右邊有元素 
    {
      printBST(ptr->rnode);
    }
    else if(ptr->rnode == NULL)           //右邊走到底了, 再往左邊走 
    {
    	;
    }
  }	
}

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
   			printf(" %d \n", ptr->fornode.numOfgraduation ); 
			break ;
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) < 0 && ptr->rnode != NULL )
		{
			ptr = ptr->rnode ; 
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) < 0 && ptr->rnode== NULL )
		{
			break ;
		}
		else if( strcmp ( ptr -> fornode.schoolname, obj) > 0 && ptr -> lnode != NULL)
		{
			ptr = ptr->lnode ;
		}
		else if ( strcmp ( ptr -> fornode.schoolname, obj) > 0 && ptr->lnode == NULL)
		{
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
		if(ptr -> fornode.numOfgraduation == obj)
		{
			break ; 
		}
		else if(ptr -> fornode.numOfgraduation > obj && ptr->lnode != NULL )
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
		else if (ptr -> fornode.numOfgraduation <obj && ptr->rnode != NULL)
		{
			ptr = ptr->rnode ;
		}
		else if( ptr -> fornode.numOfgraduation < obj && ptr->rnode == NULL)
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
	cout << "	學校名稱	科系名稱	日間∕進修別	等級別	學生數	教師數	上學年度畢業生數\n" ;
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

    		// ---------------------------------------這裡以下是二元樹------------------------------ //
			
			 			
				int num ;
				node *root = new node ;  // 造出根節點 
				root -> fornode.numOfgraduation = forjob[0].numOfgraduation ; // 設定root的值是第一個資料的畢業人數    這裡還要改要改成第一筆資料 
				root->lnode = NULL ; // 左右都先是NULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // 造出ptr去跑樹,一開始是在root的位置 

					
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 
				    num = forjob[i].numOfgraduation ;
					insert( num , ptr, root, i ) ;
				}
			
            	int forSearch = 0 ;

    	        printf( "請輸入要找的數 : " );
				cin >> forSearch ;
				searchGraduation( forSearch, ptr, root ) ;
				
			
			
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

    		// ---------------------------------------這裡以下是二元樹------------------------------ //
			
			 			
				char num[10000] ;
				node *root = new node ;  // 造出根節點 
				strcat( root -> fornode.schoolname, forjob[0].schoolname) ; // 設定root的值 
				root->lnode = NULL ; // 左右都先是NULL 
				root->rnode = NULL ;
				node *ptr ;
				ptr = root ; // 造出ptr去跑樹,一開始是在root的位置 

					
				for ( int i = 1 ; i < forjob.size() ; i ++ ) { 

				    strcpy( num, forjob[i].schoolname ) ;
					insertName( num, ptr, root, i ) ;
				}
				
				char scN[50] ;
		
				printf( "請輸入要找的學校名稱 : " );
				cin >> scN ;
				searchSchoolName( scN, ptr, root ) ;

	    	} // if
		} // else if (start == 2)
		
		else printf( "請再輸入一次" ) ;
	
	} // while

}




