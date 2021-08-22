# include <cstdlib>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>

using namespace std;

static int num = 0;

void printnum( int max, int & num, int ans[10] ) {
	for ( int i = 0 ; i < max ; i++  )
	  for ( int j = i + 1 ; j < max ; j++ )
	    if ( ans[i] == ans[j] || ans[i] >= 10 ) return;
	    
    cout << "[ " << ++num << " ] " ;
    for( int h = 0 ; h < max ; h++ ) cout << ans[h] << " ";
    cout << "\n";
}

void holyfuck( int max, int & num, int ans[10], int now ){
	for( ; ans[0] != 10 ; ans[max - 1]++ ) {
		printnum( max, num, ans );
	    for( int i = max - 1 ; i > -1 ; i-- ) {
	  	 if ( ans[i] == 9 && i != 0 ) {
	  	  ans[i] = 0;
	   	  ans[i - 1] = ans[i - 1] + 1;
	     }
    	}
   }
}

void holyshit( int max, int & num, int ans[10], int now ) {
	if ( now == max ) {
      printnum( max, num, ans );
	  return;
    }
	for( int i = 0 ; i < 10 ; i++ ) {
	  ans[now] = i; 
	  holyshit( max, num, ans, now + 1 );
	  //for ( int i = now ; i < 10 ; i++ ) ans[i] = 0;
	  ans[now + 1] = 0;
    }
}

int main() {
	int ans[10];

	for( int i = 0 ; i < 10 ; i++ ) ans[i] = 0;
	int max;
	cin >> max;
	for( int i = 0 ; i < 10 ; i++ ) ans[i] = 0;
	//holyfuck( max, num, ans, 0 );
	num = 0;
	holyshit( max, num, ans, 0 );
}
