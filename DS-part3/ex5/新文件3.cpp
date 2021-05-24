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
    int dempartmentcode ;
    char dempartment[50] ;         // 科系名稱 
    char day[50] ;                 // 日間 / 進修別 
    char level[50] ;              // ( 學士 ) 
    int numOfstudent ;
    int numOfteacher ;
    int numOfgraduation ;
    char city[50] ;
    char system[50] ;             // 體系 
    
} ;

int numofjob = 0 ;
vector<struct Job> forjob;              // 用 vector 來做 
Job joblist ;

struct node // 造出node的格式 
{
	int num ;
	node *lnode;
	node *rnode ;
};

void search ( double obj, node *ptr, node *root ){ // 搜尋 
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

void insert(double obj, node *ptr, node *root) // 插入 
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
	cout << "大專校院各校科系別概況\n" ; 
	cout << "105 學年度 SY2016-2017\n" ;
	cout << "	學校名稱	科系名稱	日間∕進修別	等級別	學生數	教師數	上學年度畢業生數\n" ;
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
	char ch ;                                      // 用來讀入空白字元
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
	
		while( start < 0 || start > 2 )                    //  如果是負號的話 就一直讀 
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
	
		if ( start == 0 )                                  // 結束 
			exit(1) ; 
		
		else if ( start == 1 ) 
		{
			cout << "Input a file number(ex.701,702,703) :" ;
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
					fscanf( fptr, "%d%s%d%s", &joblist.schoolcode, &joblist.schoolname, &joblist.dempartmentcode, &joblist.dempartment ) ;
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

    // 目前有成功insert				
	int num ;
	node *root = new node ;  // 造出根節點 
	root->num = 117 ; // 設定root的值是第一個資料的畢業人數
	root->lnode = NULL ; // 左右都先是NULL 
	root->rnode = NULL ;
	
	node *ptr ;
	ptr = root ; // 造出ptr去跑樹,一開始是在root的位置 
				
			printf( "GG%dGG\n",ptr ) ;	
			for ( int i = 1 ; i < forjob.size() ; i ++ ) { // 還在測試中 
			    num = forjob[i].numOfgraduation ;
				insert( num , ptr, root ) ;
			}
			
            int forSearch = 0 ;
		
            printf( "請輸入要找的數 : " );
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
			cin >> input ;          // 讀入一個數字
			
		    sprintf( temp1, "%d", input ) ;     // 數字轉字串
			strcat( temp, temp1 ) ;
			strcat( temp, ".txt" ) ;
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  把最前面的 "標頭 and 換行字元" 讀掉
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;
		} // else if (start == 2)
		
		else printf( "請再輸入一次" ) ;
	
	} // while

}




