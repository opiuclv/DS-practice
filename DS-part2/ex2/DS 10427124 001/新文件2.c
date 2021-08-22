 /* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 2016年9月21日, 下午 8:44
 */

# include<stdlib.h>
# include<stdio.h>
# include<iostream>

using namespace std;

void arrangement ( int count, int number, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10 ) ;
int main(int argc, char** argv) {
  int number = 0 ;
  int count = 1 ;
  int a1 = 0 ;
  int a2 = 0 ;
  int a3 = 0 ;
  int a4 = 0 ;
  int a5 = 0 ;
  int a6 = 0 ;
  int a7 = 0 ;
  int a8 = 0 ;
  int a9 = 0 ;
  int a10 = 0 ;
  cin >> number ;
  arrangement ( count, number, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
}

void arrangement ( int count, int number, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10 ) {
  if ( number  == 1 ) {
    if ( a1 <= 9 ) {
      cout << "[" << count << "]" << a1 << endl ;
      count++ ;
      arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    } // if  
  } // if  
  else if ( number == 2 ) {
      if ( a1 <= 9 && a2 <= 9 && a1 != a2 ) {
        cout << "[" << count << "]" << a2 << a1 << endl ;
        count++ ;
      } // if      
      if ( a1 < 9 )
        arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
      else if ( a1 == 9 ) {
        a1 = 0 ;
        arrangement ( count, number, a1, a2 + 1, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else if
  } // else if
  else if ( number == 3 ) {
    if ( a1 <= 9 && a2 <= 9 && a3 <= 9 && a1 != a2 && a2 != a3 && a1 != a3 ) {
      cout << "[" << count << "]" << a3 << a2 << a1 << endl ;
      count++ ;
    } // if 
    if ( a1 < 9 )
      arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    else if ( a1 == 9 ) {
      if ( a2 == 9 ) {
        a1 = 0 ;
        a2 = 0 ;
        arrangement ( count, number, a1, a2, a3 + 1, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // if
      else {
        a1 = 0 ;
        arrangement ( count, number, a1, a2 + 1, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else  
    } // else if   
  } // else if   
  else if ( number == 4 ) {
    if ( a4 <= 9 && a1 != a2 && a1 != a3 && a1 != a4 && a2 != a3 && a2 != a4 && a3 != a4 ) {
      cout << "[" << count << "]" << a4 << a3 << a2 << a1 << endl ;
      count++ ;
    } // if  
    if ( a1 < 9 )
      arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    else if ( a1 == 9 ) {
      if ( a3 == 9 ) {
        a1 = a2 = a3 = 0 ;
        arrangement ( count, number, a1, a2, a3, a4 + 1, a5, a6, a7, a8, a9, a10 ) ;
      }// if  
      else if ( a2 == 9 ) {
        a1 = 0 ;
        a2 = 0 ;
        arrangement ( count, number, a1, a2, a3 + 1, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else if
      else {
        a1 = 0 ;
        arrangement ( count, number, a1, a2 + 1, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else  
    } // else if     
  } // else if    
      
  else if ( number == 5 ) {
    if ( a5 <= 9 && a1 != a2 && a1 != a3 && a1 != a4 && a1 != a5 && a2 != a3 && a2 != a4 && a2 != a5
                        && a3 != a4 && a3 != a5 && a4 != a5 ) {
      cout << "[" << count << "]" << a5 << a4 << a3 << a2 << a1 << endl ;
      count++ ;
    } // if 
    if ( a1 < 9 )
      arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    else if ( a1 == 9 ) {
      
      if ( a3 == 9 ) 
        arrangement ( count, number, 0, 0, 0, a4 + 1, a5, a6, a7, a8, a9, a10 ) ;
   
      else if ( a4 == 9 ) 
        arrangement ( count, number, 0, 0, 0, 0, a5 + 1, a6, a7, a8, a9, a10 ) ;
    
      else if ( a2 == 9 ) 
        arrangement ( count, number, 0, 0, a3 + 1, a4, a5, a6, a7, a8, a9, a10 ) ;
      else
        arrangement ( count, number, 0, a2 + 1, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    } // else if    
  } // else if  
  else if ( number == 6 ) {
    if ( a1 <= 9 && a2 <= 9 && a3 <= 9 && a4 <= 9 && a5 <= 9 && a6 <= 9 && a1 != a2 && a1 != a3 && a1 != a4 && a1 != a5 && a1 != a6 && a2 != a3 && a2 != a4 && a2 != a5 && a2 != a6
            && a3 != a4 && a3 != a5 && a3 != a6 && a4 != a5 && a4 != a6 && a5 != a6 ) {
      cout << "[" << count << "]" << a6 << a5 << a4 << a3 << a2 << a1 << endl ;
      count++ ;
    } // if  
    if ( a1 < 9 )
      arrangement ( count, number, a1 + 1 , a2, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
    else if ( a1 == 9 ) {
      if ( a5 == 9 )
        arrangement ( count, number, 0, 0, 0, 0, 0, a6 + 1, a7, a8, a9, a10 ) ;
      else if ( a4 == 9 ) 
        arrangement ( count, number, 0, 0, 0, 0, a5 + 1, a6, a7, a8, a9, a10 ) ;
      if ( a3 == 9 ) {
        arrangement ( count, number, 0, 0, 0, a4 + 1, a5, a6, a7, a8, a9, a10 ) ;
      }// if  
      else if ( a2 == 9 ) {
        a1 = 0 ;
        a2 = 0 ;
        arrangement ( count, number, a1, a2, a3 + 1, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else if
      else {
        a1 = 0 ;
        arrangement ( count, number, a1, a2 + 1, a3, a4, a5, a6, a7, a8, a9, a10 ) ;
      } // else  
    } // else if     
  } // else if

  else if ( number == 7 ) 
    if ( a1 != a2 )
      cout << a7 << a6 << a5 << a4 << a3 << a2 << a1 ;
  else if ( number == 8 ) 
    if ( a1 != a2 )
      cout << a2 << a1 ;
  else if ( number == 9 ) 
    if ( a1 != a2 )
      cout << a2 << a1 ;
  else if ( number == 10 ) 
    if ( a1 != a2 )
      cout << a2 << a1 ;


} // arrangement()
