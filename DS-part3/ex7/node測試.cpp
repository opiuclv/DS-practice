//  ��19�� 
//  �I�|�z 10527111
//  �����q 10527124 

#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string.h>

using namespace std; 

struct Node { /* �G���𪺸`�I�ŧi */
    int data; /* �x�s�`�I��� */
    struct Node *left; /* ���V���l�𪺫��� */
    struct Node *right; /* ���V�k�l�𪺫��� */
};
typedef struct Node TNode; /* �G����`�I���s���A */
typedef TNode *BTree; /* �G�����쵲���s���A */
BTree head = NULL; /* �G����ڸ`�I������ */
Btree ptr = NULL ; /* ���T�w�O���O�o�˫ŧiptr */ 
ptr = head ; /* ���T�w */ 


int main() {
	
	if ( d > node ) { // ���իغc�G���j�M��ing 
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
    
    
    

while ( ptr != NULL ) { // �j�M 
    if ( ptr->data == d ) // d�O�n�M�䪺��� 
        return ptr;
    else
        if ( ptr->data > d ) ptr = ptr->left;
        else ptr = ptr->right;
}




if ( parent if ( parent->left == ptr ) >left == ptr ) // �R�� 
    parent->left = NULL; >left = NULL;
else
    parent->right = NULL;
    
    
} // main
