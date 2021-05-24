//  第19組 
//  施育暘 10527111
//  邱正皓 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>

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


int main()
{
	clock_t start_time, end_time ;
	float total_time = 0 ;
	clock_t start_time1, end_time1 ;
	float total_time1 = 0 ;
	unsigned __int64 start = 0 ;
	char ch ;                                      // 用來讀入空白字元
	float total_time2 ;
	bool getin = true ;
	int i = 0 ;
	char input[50] ;
	char temp[50] = "input", temp1[50] ;
	

	while ( true )
	{
		cout << "**** Shell Sort & FIFO Queue ***\n" ;
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
			
			cout << "**** Shell Sort & FIFO Queue ***\n" ;
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
		
		 	start_time = clock() ; // 匯入初始時間 
			
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
				
				end_time = clock(); // 匯入結束時間 
				
				
			// ------------------------------------------------------------------ //
			
			PrintJob() ;
		
		
		
			// ----------------------------------------------------------------  //
					
			
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
			
		 	start_time = clock() ; // 匯入初始時間 
			
			FILE * fptr = fopen( temp, "rt" ) ;               //  開啟檔案位置 
			if ( fptr )
			{
				fscanf( fptr, "%s%s%s%s%c", &ch,&ch,&ch,&ch,&ch ) ;     //  把最前面的 "標頭 and 換行字元" 讀掉
			
			
				end_time = clock(); // 匯入結束時間 
				
					
				
			} // if
			
		    else
			  cout << "Command does not exist!\n" ;
		} // else if (start == 2)
		
		else printf( "請再輸入一次" ) ;
	
	} // while
 
} // main


