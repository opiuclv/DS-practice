// 資訊二甲 
// 10527124 
// 邱正皓

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int num[324] ;  // 製作一個Array儲存費氏數列的值 
int i = 1 ;


int FIB( int FibNum ) {
	
	num[i + 1] = num[i] + num[i - 1] ;
    i ++ ;
    
	if( FibNum > 0) {
	  return FIB( FibNum -- ) ;		
	}
	else { 
	  return 0 ;
	}
}


int forRecursion ( int start2, int fornum, int num3 ) {
	
    // /////////////////////////////////////////////////變數宣告 

    num[0] = 1 ; // 令費氏數列的第一個與第一個以前的數都等於1 
    num[1] = 1 ;
    int divide = 1 ; // 從1開始找，整除的就是該因數 
    int forCount[500] ; // 這個Array用於儲存找到的因數 
    forCount[0] = 1 ;
    int count = 0 ;  
    int count2 = 0 ; // 計算innerloop 
    
    int c = fornum ; // 利用c去代換掉fornum做計算 

    FIB( c ) ; // 使用recursion計算費氏數列 


    
    while ( divide <= num[start2]) { // divide一個一個找整除就存起來 
    		
    	if ( num[start2] % divide == 0 ) {
    		forCount[count] = divide ;
    		count ++ ;
    		count2 ++ ;
		}
		divide ++ ;
	} // while
	
	
		
	// 先把該印的資料印出來		
	printf( "[ ") ;
    printf( "%d", num3 ) ;
    printf( "]" ) ;
    printf( "%d", num[start2] ) ;
    printf( "=" ) ;
    // 先把該印的資料印出來	
       	
       	
			
	if( count >= 2 && count % 2 == 0 ){  // 利用除以2來判斷 他的最小因數差是哪2個因數 
		int c = count / 2 ;
		printf( "%d", forCount[c - 1] ) ;
		printf( " * " ) ;
		printf( "%d", forCount[c] ) ;
	}
	else if( count == 1) {
		printf( "%d", forCount[0] ) ;
		printf( " * " ) ;
		printf( "%d", forCount[0] ) ;
	}
	else {  // 沒有整除就是中間的那個因數 
		printf( "%d", forCount[count/2] ) ;
		printf( " * " ) ;
		printf( "%d", forCount[count/2] ) ;
	}
		
	printf( " (Inner recursion :  ") ;
    printf("%d", count2 ) ;
	printf( "times)\n") ;
		
	start2 ++ ;
	count = 0 ; // 每次用完都要把count歸0，再去做下一次計算 
	num3 ++ ; // 印完就要往下一行+1 
	divide = 1 ; // 每次用完要歸0 
	count2 = 1 ;

	
  if ( start2 <= i ) {
  	return forRecursion(start2 ++ , fornum, num3) ;
  }
  else {
	printf( "Outer recursion : " ) ;
	printf( "%d\n", num3 - 1) ;
  }
}



int main(void) 
{
    // /////////////////////////////////////////////////先輸入要哪一個版本 

    int input1 = 1 ; // 先預設1讓它進迴圈 
    
    
    while ( input1 != 0 ){

      printf("Input a command(0, 1, 2): ") ;
      scanf( "%d", &input1) ; 
      
      if ( input1 == 0 ) {
      	break ;
	  }
    
      int num2 = 0 ;      
      printf("Input a number: ") ;  
      scanf( "%d", &num2 ); // 輸入一個值 
    
 
      int start = 1 ; // 用於從[1]跑到最後一個，然後每一個都照順序去找質因數
  	  int num3 = 1 ; // 表示印到第幾個數了 EX. [ 1] [ 2]...etc  
      
    
      // /////////////////////////////////////////////////儲存費氏數列 
      if ( input1 == 1 ){ // 迴圈版本 
    
        // /////////////////////////////////////////////////變數宣告 
        num[0] = 1 ; // 令費氏數列的第一個與第一個以前的數都等於1 
        num[1] = 1 ;
        int divide = 1 ; // 從1開始找，整除的就是該因數 
        int forCount[500] ; // 這個Array用於儲存找到的因數 
        forCount[0] = 1 ;
        int count = 0 ;  
        int count2 = 0 ; // 計算innerloop 

    
        while( num2 > 0 ) { // 使用while迴圈計算費氏數列 

          num[i + 1] = num[i] + num[i - 1] ;
          i ++ ;

          num2 -- ;
          
        } // while 
      
        // /////////////////////////////////////////////////印資料 & 因數分解 
    

        while ( start < i ) { // 這個while在一個一個跑，一個一個送進去找因數 
    
    	  while ( divide <= num[start]) { // divide一個一個找整除就存起來 
    		
    	  	if ( num[start] % divide == 0 ) {
    			forCount[count] = divide ;
    			count ++ ;
    			count2 ++ ;
			}
			divide ++ ;
		} // while
		
		
	  	  // 先把該印的資料印出來		
		  printf( "[ ") ;
          printf( "%d", num3 ) ;
          printf( "]" ) ;
          printf( "%d", num[start] ) ;
          printf( "=" ) ;
          // 先把該印的資料印出來	
       	
       	
			
		  if( count >= 2 && count % 2 == 0 ){  // 利用除以2來判斷 他的最小因數差是哪2個因數 
		      int c = count / 2 ;
			  printf( "%d", forCount[c - 1] ) ;
		  	  printf( " * " ) ;
			  printf( "%d", forCount[c] ) ;
		  }
		  else if( count == 1) {
			  printf( "%d", forCount[0] ) ;
			  printf( " * " ) ;
			  printf( "%d", forCount[0] ) ;
		  }
		  else {  // 沒有整除就是中間的那個因數 
		  	  printf( "%d", forCount[count/2] ) ;
			  printf( " * " ) ;
			  printf( "%d", forCount[count/2] ) ;
		  }
		
		  printf( " (Inner loop :  ") ;
          printf("%d", count2 ) ;
		  printf( "times)\n") ;
		
		  start ++ ;
		  count = 0 ; // 每次用完都要把count歸0，再去做下一次計算 
	  	  num3 ++ ; // 印完就要往下一行+1 
	      divide = 1 ; // 每次用完要歸0 
	  	  count2 = 1 ;
	    } // while
	
	    printf( "Outer loop : " ) ;
	    printf( "%d\n", num3 - 1) ;

      } // if
    
      else { // recursion版本 
    	  forRecursion ( start, num2, num3 ) ;
	  }
	
    } // while
	
} // main

















