// ��T�G�� 
// 10527124 
// �����q

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

unsigned long long int num[92] ;  // �s�@�@��Array�x�s�O��ƦC���� 
unsigned long long int i = 1 ; // �Ω�p��O��ƦC 
unsigned long long int count = 0 ; // �p����X�Ӧ]�� 
unsigned long long int forCount[1500] ; // �o��Array�Ω��x�s��쪺�]�� 
unsigned long long int num2 = 0 ; // �ϥΪ̿�J 
unsigned long long int divide = 1 ;
unsigned long long int start2 = 1 ;
unsigned long long int CountInnerRecursion = 0 ;


unsigned long long int forDivide( unsigned long long int sum, unsigned long long int divide, unsigned long long int start2 ) {
    CountInnerRecursion = CountInnerRecursion + 1 ;
    // ��]��  
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


unsigned long long int FIB( int FibNum ){ // �s�@�O��ƦC  
	
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
	// fornum���ȻP�ϥΪ̿�J�ۦP 
    // /////////////////////////////////////////////////�ܼƫŧi  
    num[0] = 1 ; // �O�O��ƦC���Ĥ@�ӻP�Ĥ@�ӥH�e���Ƴ�����1 
    num[1] = 1 ;
    unsigned long long int divide = 1 ; // �q1�}�l��A�㰣���N�O�Ӧ]�� 
    forCount[0] = 1 ; 
    int count = 1 ;
    unsigned long long int count2 = 0 ; // �p��innerloop     
    unsigned long long int sum = 0 ;  
	forCount[count] = forDivide(sum, divide, start2 ) ;

		
	// ����ӦL����ƦL�X��		
	printf( "[ ") ;
    printf( "%llu", num3 ) ;
    printf( "]" ) ;
    printf( "%llu", num[start2] ) ;
    printf( "=" ) ;
    // ����ӦL����ƦL�X��	
    unsigned long long int b = num[start2] / forCount[count] ;
			
	if( forCount[count] != 1 && forCount[count] * forCount[count] != num[start2] ){  // �Q�ΰ��H2�ӧP�_ �L���̤p�]�Ʈt�O��2�Ӧ]�� 

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
	
    if ( start2 < fornum ) { // ��Ʀr�@�Ӥ@�ӱa�J�P�_
  	    return forRecursion(start2+1 , fornum, num3+1) ;
    }
    else {
	    printf( "Outer recursion : " ) ;
	    printf( "%d\n", num3) ;
    }
}



int main(void) {
    // /////////////////////////////////////////////////����J�n���@�Ӫ��� 

    unsigned long long int input1 = 1 ; // ���w�]1�����i�j�� 
    
    
    while ( input1 != 0 ){

      printf("Input a command(0, 1, 2): ") ;
      scanf( "%d", &input1) ; 
      
      if ( input1 == 0 ) {
      	break ;
	  }
          
      printf("Input a number: ") ;  
      scanf( "%d", &num2 ); // ��J�@�ӭ� 
    
 
      unsigned long long int start = 1 ; // �Ω�q[1]�]��̫�@�ӡA�M��C�@�ӳ��Ӷ��ǥh���]��
  	  unsigned long long int num3 = 1 ; // ��ܦL��ĴX�ӼƤF EX. [ 1] [ 2]...etc  
      
    
      // /////////////////////////////////////////////////�x�s�O��ƦC 
      if ( input1 == 1 ){ // �j�骩�� 
    
        // /////////////////////////////////////////////////�ܼƫŧi 

        num[0] = 1 ; // �O�O��ƦC����0�ӻP��1�Ӫ��Ƴ�����1 
        num[1] = 1 ;
        unsigned long long int divide = 1 ; // �q1�}�l��A�㰣���N�O�Ӧ]��  
        forCount[0] = 1 ;
        unsigned long long int count = 0 ;  // �p��ӼƦ��X�Ӧ]��
        unsigned long long int count2 = 0 ; // �p��innerloop 

    
        while( num2 > 0 ) { // �ϥ�while�j��p��O��ƦC 

          num[i + 1] = num[i] + num[i - 1] ;
          i ++ ;

          num2 -- ;
          
        } // while 
      
        // /////////////////////////////////////////////////�L��� & �]�Ƥ��� 
    

        while ( start < i ) { // �o��while�b�@�Ӥ@�Ӷ]�A�@�Ӥ@�Ӱe�i�h��]�� 
    
    	  while ( divide * divide <= num[start]) { // divide�@�Ӥ@�ӧ�㰣�N�s�_�� 
    		
    	  	if ( num[start] % divide == 0 ) {
    			forCount[count] = divide ;
    			count ++ ;
			}
			count2 ++ ;
			divide ++ ;
	   } // while
		
		
	  // ����ӦL����ƦL�X��		
	      printf( "[ ") ;
          printf( "%llu", num3 ) ;
          printf( "]" ) ;
          printf( "%llu", num[start] ) ;
          printf( "=" ) ;
          // ����ӦL����ƦL�X��	
       	
       	  unsigned long long int c = num[start] / forCount[count - 1 ] ;
			
		  if( count >= 2 && forCount[count] * forCount[count] != num[start] ){  // �Q�ΰ��H2�ӧP�_ �L���̤p�]�Ʈt�O��2�Ӧ]�� 

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
		  count = 0 ; // �C���Χ����n��count�k0�A�A�h���U�@���p�� 
	  	  num3 = num3 + 1 ; // �L���N�n���U�@��+1 
	      divide = 1 ; // �C���Χ��n�k0 
	  	  count2 = 1 ;
	    
	    } // while
	    printf( "Outer loop : " ) ;
	    printf( "%llu\n", num3 - 1) ;

      } // if
    
      else { // recursion����                  *num2�S���Dbut FIB�|�i�J�L�a�j��*
	    num[0] = 1 ;
   	    num[1] = 1 ;
	    int number = 2 ;
	    int i = 2 ;

	    while( number <= num2 ) { // ��p��n���O��ƦC�s�i�}�C 
	      num[i] = FIB( number ) ;
	      number ++ ;
	      i ++ ;
        }
    	  forRecursion ( start, num2, num3 ) ;
	  }
	
    } // while
	
} // main
















