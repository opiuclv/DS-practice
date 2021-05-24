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
	node *lnode = NULL ;
	node *rnode = NULL ;
} ;

void InputRoot( node * root )
{
	root -> fornode.schoolcode = forjob[0].schoolcode ;                      // 先把root的值輸入 
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
	
	root->lnode = NULL ; // 左右都先是NULL 
	root->rnode = NULL ;
	
} 



// ------------------------------  //

int H = 1 ;
int HB = 0 ;
int c = 0 ;
int num2 = 0 ;
int printBST( node *ptr )                // 把它印出來 
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
    	H = H + 1 ;
    	if ( H > HB ) HB = H ;  
		H = 0 ;
    }

    if(ptr->rnode)                        //右邊有元素 
    {
        printBST(ptr->rnode);
    	H = H + 1 ;
    	if ( H > HB ) HB = H ;
    }
    
    if ( H > HB ) HB = H ;

  }
}



// -----------------------------------------------------  //



void searchGraduation ( int obj, node *ptr, node *root ){ // 搜尋 
	ptr = root ; // 從根開始找 
	while(1) {
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


void PrintJob( int i )
{
	
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
	char temp[50] = "input", temp1[50] ;
	
	
	char inputschoolname[100] ;
	int num ;
	
	node * ptr ;                          // 用來跑樹 
    node * rootOfgraduation = new node ;  // 造出根節點
	node * rootOfschoolname = new node ;  // 造出根節點
	

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
    			
    			InputRoot( rootOfgraduation ) ;       // 讀入根的值	 
    			InputRoot( rootOfschoolname ) ;
    			
				
				int graduationHeight = 0 ;            // 樹的深度 
				int schoolnameHeight = 0 ;
				
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
			cout << "Input a school name:" ;
			cin >> inputschoolname ;          // 讀入一個學校
			
			for ( i = 0 ; i < forjob.size() ; i++ )
			{
				if( strcmp( forjob[i].schoolname, inputschoolname ) == 0 )       // 如果找到符合條件的 
				{
					forjob.erase(forjob.begin()+i) ;               // 就把它移除掉 並 印出來 
					PrintJob( i ) ;
				}
			
				
			} // for
			
			int graduationHeight = 0 ;            // 樹的深度 
			int schoolnameHeight = 0 ;
				 
    		InputRoot( rootOfschoolname ) ;
    			
			schoolnameHeight = 0 ;
			
			H = 0 ;
			ptr = rootOfschoolname + NULL ;                                                // 從新建造一棵樹 
			for ( int i = 1 ; i < forjob.size() ; i ++ ) 
			{
				H = insertName( forjob[i].schoolname, ptr, rootOfschoolname, i ) ;
				if ( schoolnameHeight < H )
					schoolnameHeight = H ;             // 樹的深度 
			}
				
			printBST(rootOfschoolname) ;	
			printf( "Tree heights: {School name} = %d\n", schoolnameHeight ) ;              // 印出樹高
			printf( "Tree heights: {Number of graduates} = %d\n\n", graduationHeight ) ;              // 印出樹高 
			
			
			
		} // else if 
		
		
		else if ( start == 5 )                 //    5. Removal by Number of Graduates 
		{
			cout << "Input the number of graduates:" ;
			cin >> num ;
			printf( "hi = %d\n", forjob.size() ) ;
			int size = forjob.size() ;
			for ( i = 0 ; i < size ; i++ )
			{
				if( forjob[i].numOfgraduation <= num )       // 如果找到符合條件的 
				{
					int c = i - 1 ;
					forjob.erase(forjob.begin()+c) ;                   // 就把它移除掉  並  印出來 
					PrintJob( i ) ;                       
				}
				
				
			} // for
			
			printf( "%d\n", forjob.size() ) ;
			int graduationHeight = 0 ;            // 樹的深度 
			int schoolnameHeight = 0 ;
			InputRoot( rootOfgraduation ) ;       // 讀入根的值
			graduationHeight = 0 ;            // 樹的深度 
			
			ptr = rootOfgraduation = NULL ;
			int H = 0 ;
			for ( int i = 1 ; i < forjob.size() ; i ++ ) {               // 用畢業人數種樹 
				H = insert( forjob[i].numOfgraduation , ptr, rootOfgraduation, i ) ;
				printf( "GGG2 " ) ;
				if ( graduationHeight < H )
					graduationHeight = H ;             // 樹的深度 
			}
			
			
			printf( "Tree heights: {School name} = %d\n", schoolnameHeight ) ;              // 印出樹高
			printf( "Tree heights: {Number of graduates} = %d\n\n", graduationHeight ) ;              // 印出樹高 
			
		} // else if 
		
		
		
		
		else printf( "請再輸入一次" ) ;
	
	} // while

}




