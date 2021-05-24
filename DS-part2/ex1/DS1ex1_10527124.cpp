// 資訊二甲 
// 10527124 
// 邱正皓

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

unsigned long long int num[92] ;  // 製作一個Array儲存費氏數列的值 
unsigned long long int i = 1 ; // 用於計算費氏數列 
unsigned long long int count = 0 ; // 計算找到幾個因數 
unsigned long long int forCount[1500] ; // 這個Array用於儲存找到的因數 
unsigned long long int num2 = 0 ; // 使用者輸入 
unsigned long long int divide = 1 ;
unsigned long long int start2 = 1 ;
unsigned long long int CountInnerRecursion = 0 ;


unsigned long long int forDivide( unsigned long long int sum, unsigned long long int divide, unsigned long long int start2 ) {
    CountInnerRecursion = CountInnerRecursion + 1 ;
    // 找因數  
    if( num[start2] >= divide ){
	
    while ( num[start2] % divide != 0  ) {
 
        divide ++ ;	
//	printf ( "%lluRRRRRRRRRRRRRR\n", divide ) ;   	
	} // while
}
    
    if ( divide * divide <= num[start2] ) {
 
    	sum = divide ;  
    	return forDivide(sum, divide+1 , start2 ) ;
	} // if
	else {
		return sum ;
	}
}


unsigned long long int FIB( int FibNum ){ // 製作費氏數列  
	
	if( FibNum == 1) {
       return 1 ;
	}
	
	if( FibNum == 2) {
       return 2 ;
	}
	
	return ( FIB( FibNum - 1 ) + FIB( FibNum - 2 ) );		

}


unsigned long long int forRecursion ( unsigned long long int start2, unsigned long long int fornum
                   , unsigned long long int num3 ) {
	// fornum的值與使用者輸入相同 
    // /////////////////////////////////////////////////變數宣告  
    num[0] = 1 ; // 令費氏數列的第一個與第一個以前的數都等於1 
    num[1] = 1 ;
    unsigned long long int divide = 1 ; // 從1開始找，整除的就是該因數 
    forCount[0] = 1 ; 
    int count = 1 ;
    unsigned long long int count2 = 0 ; // 計算innerloop     
    unsigned long long int sum = 0 ;  
	forCount[count] = forDivide(sum, divide, start2 ) ;

		
	// 先把該印的資料印出來		
	printf( "[ ") ;
    printf( "%llu", num3 ) ;
    printf( "]" ) ;
    printf( "%llu", num[start2] ) ;
    printf( "=" ) ;
    // 先把該印的資料印出來	
    unsigned long long int b = num[start2] / forCount[count] ;
			
	if( forCount[count] != 1 && forCount[count] * forCount[count] != num[start2] ){  // 利用除以2來判斷 他的最小因數差是哪2個因數 

        printf( "%llu", forCount[count] ) ;
		printf( " * " ) ;
		printf( "%llu", b ) ;
	}
	else if( forCount[count] * forCount[count] == num[start2] ){

	    printf( "%llu", forCount[count] ) ;
	    printf( " * " ) ;
		printf( "%llu", forCount[count] ) ;
	}
		  
	else  {

	    printf( "%llu", forCount[0] ) ;
		printf( " * " ) ;
		printf( "%llu", num[start2] ) ;
	}
	
	printf( " (Inner recursion :  ") ;
    printf("%llu", CountInnerRecursion ) ;
	printf( "times)\n") ;
	
    if ( start2 < fornum ) { // 把數字一個一個帶入判斷
  	    return forRecursion(start2+1 , fornum, num3+1) ;
    }
    else {
	    printf( "Outer recursion : " ) ;
	    printf( "%d\n", num3) ;
    }
}



int main(void) {
    // /////////////////////////////////////////////////先輸入要哪一個版本 

    unsigned long long int input1 = 1 ; // 先預設1讓它進迴圈 
    
    
    while ( input1 != 0 ){

      printf("Input a command(0, 1, 2): ") ;
      scanf( "%d", &input1) ; 
      
      if ( input1 == 0 ) {
      	break ;
	  }
          
      printf("Input a number: ") ;  
      scanf( "%d", &num2 ); // 輸入一個值 
    
 
      unsigned long long int start = 1 ; // 用於從[1]跑到最後一個，然後每一個都照順序去找質因數
  	  unsigned long long int num3 = 1 ; // 表示印到第幾個數了 EX. [ 1] [ 2]...etc  
      
    
      // /////////////////////////////////////////////////儲存費氏數列 
      if ( input1 == 1 ){ // 迴圈版本 
    
        // /////////////////////////////////////////////////變數宣告 

        num[0] = 1 ; // 令費氏數列的第0個與第1個的數都等於1 
        num[1] = 1 ;
        unsigned long long int divide = 1 ; // 從1開始找，整除的就是該因數  
        forCount[0] = 1 ;
        unsigned long long int count = 0 ;  // 計算該數有幾個因數
        unsigned long long int count2 = 0 ; // 計算innerloop 

    
        while( num2 > 0 ) { // 使用while迴圈計算費氏數列 

          num[i + 1] = num[i] + num[i - 1] ;
          i ++ ;

          num2 -- ;
          
        } // while 
      
        // /////////////////////////////////////////////////印資料 & 因數分解 
    

        while ( start < i ) { // 這個while在一個一個跑，一個一個送進去找因數 
    
    	  while ( divide * divide <= num[start]) { // divide一個一個找整除就存起來 
    		
    	  	if ( num[start] % divide == 0 ) {
    			forCount[count] = divide ;
    			count ++ ;
			}
			count2 ++ ;
			divide ++ ;
	   } // while
		
		
	  // 先把該印的資料印出來		
	      printf( "[ ") ;
          printf( "%llu", num3 ) ;
          printf( "]" ) ;
          printf( "%llu", num[start] ) ;
          printf( "=" ) ;
          // 先把該印的資料印出來	
       	
       	  unsigned long long int c = num[start] / forCount[count - 1 ] ;
			
		  if( count >= 2 && forCount[count] * forCount[count] != num[start] ){  // 利用除以2來判斷 他的最小因數差是哪2個因數 

			  printf( "%llu", forCount[count - 1] ) ;
		  	  printf( " * " ) ;
			  printf( "%llu", c ) ;
		  }
		  else if( forCount[count] * forCount[count] == num[start] ){
			  printf( "%llu", forCount[count] ) ;
		  	  printf( " * " ) ;
			  printf( "%llu", forCount[count] ) ;
		  }
		  
		  else  {
			  printf( "%llu", forCount[0] ) ;
			  printf( " * " ) ;
			  printf( "%llu", num[start] ) ;
		  }

		
		  printf( " (Inner loop :  ") ;
          printf("%llu", count2 ) ;
		  printf( "times)\n") ;
		
		  start = start + 1 ;
		  count = 0 ; // 每次用完都要把count歸0，再去做下一次計算 
	  	  num3 = num3 + 1 ; // 印完就要往下一行+1 
	      divide = 1 ; // 每次用完要歸0 
	  	  count2 = 1 ;
	    
	    } // while
	    printf( "Outer loop : " ) ;
	    printf( "%llu\n", num3 - 1) ;

      } // if
    
      else { // recursion版本                  *num2沒問題but FIB會進入無窮迴圈*
	    num[0] = 1 ;
   	    num[1] = 1 ;
	    int number = 2 ;
	    int i = 2 ;

	    while( number <= num2 ) { // 把計算好的費氏數列存進陣列 
	      num[i] = FIB( number ) ;
	      number ++ ;
	      i ++ ;
        }
    	  forRecursion ( start, num2, num3 ) ;
	  }
	
    } // while
	
} // main
















