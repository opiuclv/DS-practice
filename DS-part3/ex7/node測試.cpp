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

struct Node { /* 二元樹的節點宣告 */
    int data; /* 儲存節點資料 */
    struct Node *left; /* 指向左子樹的指標 */
    struct Node *right; /* 指向右子樹的指標 */
};
typedef struct Node TNode; /* 二元樹節點的新型態 */
typedef TNode *BTree; /* 二元樹鏈結的新型態 */
BTree head = NULL; /* 二元樹根節點的指標 */
Btree ptr = NULL ; /* 不確定是不是這樣宣告ptr */ 
ptr = head ; /* 不確定 */ 


int main() {
	
	if ( d > node ) { // 嘗試建構二元搜尋數ing 
	    while ( ptr->right != null) {
	    	if ( d > ptr->right )
	    	    ptr = ptr -> right ;
	    	else
	    	    ptr = ptr -> left ;
		} 
		if ( ptr -> right == null ) 
		    ptr->right = d ;
	}
	else ( d < node ) {
		if ( ptr -> right == null ) 
		    ptr->right = d ;  
    }
    
    
    

while ( ptr != NULL ) { // 搜尋 
    if ( ptr->data == d ) // d是要尋找的資料 
        return ptr;
    else
        if ( ptr->data > d ) ptr = ptr->left;
        else ptr = ptr->right;
}




if ( parent if ( parent->left == ptr ) >left == ptr ) // 刪除 
    parent->left = NULL; >left = NULL;
else
    parent->right = NULL;
    
    
} // main
