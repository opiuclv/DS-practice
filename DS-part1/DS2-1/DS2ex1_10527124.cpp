//  資訊二甲 邱正皓 10527124 

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

int a = 0 ;
int numofjob = 0 ;
vector<struct Job> forlist ;              // 用 vector 來做 
vector<struct Job> forheap ;
vector<struct Job> fortemp ;
Job joblist ;

int num2 = 0 ;
int bottom = 1 ;
int leftbottom = 1 ; 

// ---------------------------------------------------------  //


void PrintJob( int i ){
	
	printf( "[%d]  ", i+1 ) ;
	printf( "%s  %s  %s  %s  ", &forheap[i].schoolname, &forheap[i].department, &forheap[i].day, &forheap[i].level ) ; 
	cout << forheap[i].numOfstudent << "  " << forheap[i].numOfteacher << "  " << forheap[i].numOfgraduation << "\n"  ;
		
} // print



void Search( char objSN[], char objDP[], char objD[], char objL[] ){
	int c = 0 ;
	for( int i = 0 ; i < numofjob ; i ++ ) {
		if ( strcmp( "*", objSN ) == 0 || strstr( forlist[i].schoolname, objSN ) != NULL ) {
			if ( strcmp( "*", objDP ) == 0 || strstr( forlist[i].department, objDP ) != NULL ) {	
				if ( strcmp( "*", objD ) == 0 || strstr( forlist[i].day, objD ) != NULL ) {
					if ( strcmp( "*", objL ) == 0 || strstr( forlist[i].level, objL ) != NULL ) {
							printf( "[%d]  ", c+1 ) ;
							printf( "%s  %s  %s  %s  ", &forlist[i].schoolname, &forlist[i].department, &forlist[i].day, &forlist[i].level ) ; 
							cout << forlist[i].numOfstudent << "  " << forlist[i].numOfteacher << "  " << forlist[i].numOfgraduation << "\n"  ;
							c ++ ; 
					} // if
				} // if
			} // if
		} // if
	} // for
	
	if ( c == 0 ) printf( "沒有此項目\n" ) ;
} // search

void Swap( int i, int k ) {
	fortemp.push_back( forlist[0] ) ;
	strcpy ( fortemp[0].schoolname, forheap[k].schoolname ) ;
	strcpy ( forheap[k].schoolname, forheap[i].schoolname ) ;
	strcpy ( forheap[i].schoolname, fortemp[0].schoolname ) ;
	
	fortemp[i].numOfgraduation = forheap[0].numOfgraduation ;
	forheap[i].numOfgraduation = forheap[0].numOfgraduation ;
	forheap[i].numOfgraduation = fortemp[0].numOfgraduation ;
	
	strcpy ( fortemp[0].department, forheap[k].department ) ;
	strcpy ( forheap[k].department, forheap[i].department ) ;
	strcpy ( forheap[i].department, fortemp[0].department ) ;
	
	strcpy ( fortemp[0].day, forheap[k].day ) ;
	strcpy ( forheap[k].day, forheap[i].day ) ;
	strcpy ( forheap[i].day, fortemp[0].day ) ;
	
	strcpy ( fortemp[0].level, forheap[k].level ) ;
	strcpy ( forheap[k].level, forheap[i].level ) ;
	strcpy ( forheap[i].level, fortemp[0].level ) ;
} // Swap() 

bool judge( int tempNum ) {
	
	if ( tempNum % 2 == 0 && forheap[tempNum-1].numOfgraduation > forheap[(tempNum-1) / 2].numOfgraduation ) {
		return true ;
	} // if 
	else if( tempNum % 2 != 0 && tempNum != 1 && forheap[tempNum-1].numOfgraduation > forheap[(tempNum-2) / 2].numOfgraduation  ) {
		return true ;
	} // else if
	else if ( forheap[tempNum-1].numOfgraduation > forheap[0].numOfgraduation ) {
		return true ;
	} // if 
	
	return false ;
	
} // judge()

int Maxheapify() {
	int num = 0 ;
	int num2 = 0 ;
	int size = forlist.size() - 1 ;  
	int root = 1 ; // 紀錄樹根位置 
	int tempNum ;
	fortemp.push_back( forlist[0] ) ;
	for ( num = 0 ; num < size ; num ++ ) { // 照順序一個一個丟進堆積中 ( 平衡樹排列 ) 
		// printf("GG") ;
		forheap.push_back( forlist[num] ) ; // 搜尋到的值丟入vector去排序
		tempNum = num + 1 ;
		
		for( num2 = 0 ; judge( tempNum ) ; num2 ++ ) { // 如果有需要更換排列結構就換 
			if ( tempNum % 2 == 0 ) {
				strcpy ( fortemp[0].schoolname, forheap[tempNum-1].schoolname ) ;
				strcpy ( forheap[tempNum-1].schoolname, forheap[(tempNum-1) / 2].schoolname ) ;
				strcpy ( forheap[(tempNum-1) / 2].schoolname, fortemp[0].schoolname ) ;
				
				fortemp[0].numOfgraduation = forheap[tempNum-1].numOfgraduation ;
				forheap[tempNum-1].numOfgraduation = forheap[(tempNum-1) / 2].numOfgraduation ;
				forheap[(tempNum-1) / 2].numOfgraduation = fortemp[0].numOfgraduation ;
				
				fortemp[0].numOfteacher = forheap[tempNum-1].numOfteacher ;
				forheap[tempNum-1].numOfteacher = forheap[(tempNum-1) / 2].numOfteacher ;
				forheap[(tempNum-1) / 2].numOfteacher = fortemp[0].numOfteacher ;

				fortemp[0].numOfstudent = forheap[tempNum-1].numOfstudent ;
				forheap[tempNum-1].numOfstudent = forheap[(tempNum-1) / 2].numOfstudent ;
				forheap[(tempNum-1) / 2].numOfstudent = fortemp[0].numOfstudent ;
				
				strcpy ( fortemp[0].department, forheap[tempNum-1].department ) ;
				strcpy ( forheap[tempNum-1].department, forheap[(tempNum-1) / 2].department ) ;
				strcpy ( forheap[(tempNum-1) / 2].department, fortemp[0].department ) ;
	
				strcpy ( fortemp[0].day, forheap[tempNum-1].day ) ;
				strcpy ( forheap[tempNum-1].day, forheap[(tempNum-1) / 2].day ) ;
				strcpy ( forheap[(tempNum-1) / 2].day, fortemp[0].day ) ;
	
				strcpy ( fortemp[0].level, forheap[tempNum-1].level ) ;
				strcpy ( forheap[tempNum-1].level, forheap[(tempNum-1) / 2].level ) ;
				strcpy ( forheap[(tempNum-1) / 2].level, fortemp[0].level ) ;
				tempNum = tempNum / 2 ;
			} // if 
			else if( tempNum % 2 != 0 && tempNum != 1 ) {
				strcpy ( fortemp[0].schoolname, forheap[tempNum-1].schoolname ) ;
				strcpy ( forheap[tempNum-1].schoolname, forheap[(tempNum-2) / 2].schoolname ) ;
				strcpy ( forheap[(tempNum-2) / 2].schoolname, fortemp[0].schoolname ) ;
				
				fortemp[0].numOfgraduation = forheap[tempNum-1].numOfgraduation ;
				forheap[tempNum-1].numOfgraduation = forheap[(tempNum-2) / 2].numOfgraduation ;
				forheap[(tempNum-2) / 2].numOfgraduation = fortemp[0].numOfgraduation ;
				
				fortemp[0].numOfteacher = forheap[tempNum-1].numOfteacher ;
				forheap[tempNum-1].numOfteacher = forheap[(tempNum-2) / 2].numOfteacher ;
				forheap[(tempNum-2) / 2].numOfteacher = fortemp[0].numOfteacher ;

				fortemp[0].numOfstudent = forheap[tempNum-1].numOfstudent ;
				forheap[tempNum-1].numOfstudent = forheap[(tempNum-2) / 2].numOfstudent ;
				forheap[(tempNum-2) / 2].numOfstudent = fortemp[0].numOfstudent ;
	
				strcpy ( fortemp[0].department, forheap[tempNum-1].department ) ;
				strcpy ( forheap[tempNum-1].department, forheap[(tempNum-2) / 2].department ) ;
				strcpy ( forheap[(tempNum-2) / 2].department, fortemp[0].department ) ;
	
				strcpy ( fortemp[0].day, forheap[tempNum-1].day ) ;
				strcpy ( forheap[tempNum-1].day, forheap[(tempNum-2) / 2].day ) ;
				strcpy ( forheap[(tempNum-2) / 2].day, fortemp[0].day ) ;
	
				strcpy ( fortemp[0].level, forheap[tempNum-1].level ) ;
				strcpy ( forheap[tempNum-1].level, forheap[(tempNum-2) / 2].level ) ;
				strcpy ( forheap[(tempNum-2) / 2].level, fortemp[0].level ) ;
				tempNum = (tempNum-1) / 2 ;
			} // else if
			if ( tempNum == 1 ) {
				root = num + 1 ; // 如果換到樹根就記錄其原來位置 
			} // if
			
		} // for
		
	} // for
	
	return root ; 
	
} // Maxheapify() 


int main ( int argc, char **argv )
{
	
	unsigned __int64 start = 0 ;
	char ch ;                                      // 用來讀入空白字元
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input" ;
	char tempD[50] ;
	char forsearchSN[100] ;
	char forsearchDP[100] ;
	char forsearchD[100] ;
	char forsearchL[100] ;
	int root ;

	while ( true )
	{
		forlist.clear() ;
		
		cout << "************************************************************\n" ;
		cout << "*** Mission One: Select Matched Records from a Text File ***\n" ;
		cout << "************************************************************\n" ;

		cout << "\n" ;
		
		if ( true )
		{
			cout << "Input the file number: 101, 102, ... [0]Quit : " ;
			cin >> input ;          // 讀入一個數字

			if ( input[0] == '0' ) { // 如果輸入0就結束 
				printf( "\n感謝您的使用。\n" ) ; 
				exit(0) ;
			} // if
			
			strcat( temp, input ) ;
			strcat( temp, ".txt" ) ;

			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			
			if ( fptr )
			{
				for ( int num = 0 ; num < 3 ; num ++ ) {
					fscanf( fptr, "%c", &ch ) ;             // 第一行讀掉 
					while ( ch != '\n' )
						fscanf( fptr, "%c", &ch ) ;
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

					forlist.push_back( joblist ) ;              // 將工作移到最後一個
						
					fscanf( fptr, "%c", &ch ) ;         //  把空白字元讀掉 
					numofjob = i ;          //  設定job數量 
				} // for
				
				fclose( fptr ) ;
				
				//for( int k = 0 ; k < numofjob ; k ++ )   印出所有資料 
				//    PrintJob( k ) ;

				cout << "Enter a keyword of 學校名稱: [*]for all : " ;
				cin >> forsearchSN ;
				cout << "Enter a keyword of 科系名稱: [*]for all : " ;
				cin >> forsearchDP ;
				cout << "Enter a keyword of 日夜別: [*]for all : " ;
				cin >> forsearchD ;
				if ( forsearchD[0] != '*' ) { // 為了避免空白輸入 
					cin >> tempD ;
					strcat ( forsearchD, " " ) ;
					strcat ( forsearchD, tempD ) ; 
			    } // if
				cout << "Enter a keyword of 等級別: [*]for all : " ;
				cin >> forsearchL ;
				
				Search(forsearchSN, forsearchDP, forsearchD, forsearchL) ;
				
				memset( temp, 0, strlen(temp) );                // fill with zero.
				strcat( temp, "input" ) ;
				
				root = Maxheapify() ; // 以最大堆積排序搜尋到的資料 
				
				////////////////////////////////////////////  這段單純只是為了找出最左下的位置 
				int count = 1 ;
				int count2 = -1 ;
				for ( count = 1 ; count < forheap.size() - 1 ; count = count * 2 ) {
					count2 ++ ;
				} // for
			
				int leftbottom2 ;
				for ( leftbottom2 = 2 ; count2 > 1 ; count2 -- ) {
					leftbottom2 = leftbottom2 * 2 ;
				} // for
				///////////////////////////////////////////
				
				
				for( int h = 0 ; h < forheap.size() - 1 ; h ++ ) {
					if ( forlist[h].numOfgraduation == forheap[forheap.size() - 1].numOfgraduation ) {
						bottom = h ;
					} // if
				} // for
				
				bottom ++ ;
				
				for( int h2 = 0 ; h2 < forheap.size() - 1 ; h2 ++ ) {
					if ( forlist[h2].numOfgraduation == forheap[leftbottom2-1].numOfgraduation ) {
						leftbottom = h2 ;
					} // if
				} // for
				
				leftbottom ++ ;
				
				printf( "root = [%d] %d\n" , root, forheap[0].numOfgraduation ) ;
				printf( "bottom = [%d] %d\n" , bottom, forheap[forheap.size() - 1].numOfgraduation ) ;
				printf( "leftmost bottom = [%d] %d\n" , leftbottom, forheap[leftbottom2-1].numOfgraduation ) ;
				
				// for( int k = 0 ; k < forheap.size() ; k ++ ) PrintJob( k ) ; // 印出所有 Maxheapify 
				
				printf( "\n請輸入0來結束此程式，或輸入其他按鍵以繼續搜尋。\n" ) ; 
				
				cin >> input ;          // 讀入一個數字

				if ( input[0] == '0' ) { // 如果輸入0就結束 
					printf( "\n感謝您的使用。\n" ) ; 
					exit(0) ;
				} // if
				
			
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;	
				
		} // else 
	
	} // while

}




