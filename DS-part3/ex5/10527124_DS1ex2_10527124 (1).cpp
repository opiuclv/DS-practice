// 資訊二甲 
// 10527124 
// 邱正皓


# include <cstdlib>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>

using namespace std;

static int num = 1;
static int input = 1 ;

void printnum( int max, int & num, int ans[10] ) {
	for ( int i = 0 ; i < max ; i++  )
	    for ( int j = i + 1 ; j < max ; j++ ) {
	      if ( input == 2 && ans[i] == ans[j] || ans[i] >= 10 ) return ;
	      if ( input == 1 && ans[i] >= ans[j] || ans[i] >= 10 ) return ;
	} // for
	    
    cout << "[ " << num++ << "] " ;
    for( int h = 0 ; h < max ; h++ ) cout << ans[h] << " ";
    cout << "\n";
}


void permutation( int max, int & num, int ans[10], int now ) {
	if ( now == max ) {
      printnum( max, num, ans );
	  return;
    }
	for( int i = 0 ; i < 10 ; i++ ) {
	  ans[now] = i; 
	  permutation( max, num, ans, now + 1 );
	  //for ( int i = now ; i < 10 ; i++ ) ans[i] = 0;
	  // ans[now + 1] = 0; 以防萬一 
    }
}

int main() {

  
  clock_t start_time, end_time ;
  float total_time = 0 ;

  start_time = clock() ; // 匯入初始時間 

  printf("Input a command(0, 1, 2): ") ;  
  scanf( "%d", &input) ; 
  
  while ( input != 0 ) {
	
	int ans[10];

	for( int i = 0 ; i < 10 ; i++ ) ans[i] = 0;
	int max;
	cout << "IIInput a numberrr!!! : " ;
	cin >> max;
	for( int i = 0 ; i < 10 ; i++ ) ans[i] = 0;
	num = 1;
	permutation( max, num, ans, 0 );
	
	
    end_time = clock(); // 匯入結束時間 

      /* CLOCKS_PER_SEC is defined at time.h */
    total_time = (float) (end_time - start_time) ;


    printf("Recursion : %f ms \n", total_time) ;
      
    printf("Input a command(0, 1, 2): ") ; 
    scanf( "%d", &input) ;
    
    
  } // while


  
  return 0 ; 
}
