// 資訊二甲 
// 10527124 
// 邱正皓


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int num = 1 ;


void play(char *pc, char *ans, int sz, int lv, int mx, int*cntP){ 
  int i; 
  if(0 > sz) return; 
  
  if(lv >= mx) { 
      printf( "[ ") ;
      printf( "%d", num ) ;
      printf( "]" ) ;
      printf("%s\n",ans); 
	  *cntP ++ ; 
	  num = num + 1 ;
	  return ;
  } // for
  
  for(i = 0 ; sz > i && *pc ; i ++ , pc ++ ) { 
    ans[ lv ] = *pc; 
    ans[ 1+lv ]='\0'; 
    play( 1+pc, ans, sz-i-1, 1+lv, mx, cntP); 
    ans[ lv ]='\0';     
  } // for
  

  return; 
}  

int main(void){ 

  clock_t start_time, end_time ;
  float total_time = 0 ;
  int iNum = 0 ;

  start_time = clock() ; // 匯入初始時間 

  int input = 1 ;

  printf("Input a command(0, 1, 2): ") ;  
  scanf( "%d", &input) ; 
  
  while ( input != 0 ) {

    char*a = "0123456789" ,  // 9不會跑 
    b[64] = {'\0'} ; 
    int c, d, cnt ; 
    c = 10 ;
  
    for( ;printf("IIInput a numberrr!!! : ") && (9*2) >= c && scanf("%d",&d) && c >= d && d > 0; ) { 

      play(a, b, c, 0, d, &cnt) ; 
      end_time = clock(); // 匯入結束時間 

      /* CLOCKS_PER_SEC is defined at time.h */
      total_time = (float) (end_time - start_time)/CLOCKS_PER_SEC ;
      
      total_time = total_time * 10 ;

      printf("Recursion : %f ms \n", total_time) ;
    
    
    }  // for 
    
    
    printf("Input a command(0, 1, 2): ") ; 
    scanf( "%d", &input) ;
    
    
  } // while


  
  return 0 ; 
  
} // main()






