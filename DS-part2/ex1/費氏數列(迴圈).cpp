// ��T�G�� 
// 10527124 
// �����q

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void) 
{
    // /////////////////////////////////////////////////�x�s�O��ƦC 
    int i = 1 ;
    int num2 = 0 ;

    scanf( "%d", &num2 ); // ��J�@�ӭ� 

    int num[324] ;  // �s�@�@��Array�x�s�O��ƦC���� 

    num[0] = 1 ; // �O�O��ƦC���Ĥ@�ӻP�Ĥ@�ӥH�e���Ƴ�����1 
    num[1] = 1 ;

    while( num2 > 0 ) { // �ϥ�while�j��p��O��ƦC 

      num[i + 1] = num[i] + num[i - 1] ;
      i ++ ;

      num2 -- ;
    } // while 
    
    // /////////////////////////////////////////////////�L��� & �]�Ƥ��� 
    int start = 1 ; // �Ω�q[1]�]��̫�@�ӡA�M��C�@�ӳ��Ӷ��ǥh���]�� 
    int divide = 1 ; // �q1�}�l��A�㰣���N�O�Ӧ]�� 
    int forCount[500] ; // �o��Array�Ω��x�s��쪺�]�� 
    forCount[0] = 1 ;
    int count = 0 ;  
    int count2 = 0 ; // �p��innerloop 
    int num3 = 1 ; // ��ܦL��ĴX�ӼƤF EX. [ 1] [ 2]...etc 
    

    while ( start <= i ) { // �o��while�b�@�Ӥ@�Ӷ]�A�@�Ӥ@�Ӱe�i�h��]�� 
    
    	while ( divide <= num[start]) { // divide�@�Ӥ@�ӧ�㰣�N�s�_�� 
    		
    		if ( num[start] % divide == 0 ) {
    			forCount[count] = divide ;
    			count ++ ;
    			count2 ++ ;
			}
			divide ++ ;
		} // while
		
		
		// ����ӦL����ƦL�X��		
		printf( "[ ") ;
        printf( "%d", num3 ) ;
        printf( "]" ) ;
        printf( "%d", num[start] ) ;
        printf( "=" ) ;
       	// ����ӦL����ƦL�X��	
       	
       	
			
		if( count >= 2 && count % 2 == 0 ){  // �Q�ΰ��H2�ӧP�_ �L���̤p�]�Ʈt�O��2�Ӧ]�� 
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
		else {  // �S���㰣�N�O���������Ӧ]�� 
			printf( "%d", forCount[count/2] ) ;
			printf( " * " ) ;
			printf( "%d", forCount[count/2] ) ;
		}
		
		printf( " (Inner loop :  ") ;
        printf("%d", count2 ) ;
		printf( "times)\n") ;
		
		start ++ ;
		count = 0 ; // �C���Χ����n��count�k0�A�A�h���U�@���p�� 
		num3 ++ ; // �L���N�n���U�@��+1 
		divide = 1 ; // �C���Χ��n�k0 
		count2 = 1 ;
	} // while
	
	printf( "outer loop : " ) ;
	printf( "%d", num3 - 2) ;

	
    
} // main













