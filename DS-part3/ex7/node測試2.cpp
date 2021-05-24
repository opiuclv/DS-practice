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


/* �{���d��: BSTree.java */
class TreeNode {    // ��`�I���O
   int data;        // �`�I���
   TreeNode left;   // �Ѧҥ��l��
   TreeNode right;  // �Ѧҥk�l��
   // �غc�l
   public TreeNode(int data) {
      this.data = data;
      this.left = this.right = null;
   }
}
public class BSTree {      // �G���j�M�����O
   public TreeNode head;   // �ѦҾ𪺮ڸ`�I
   // �إߪŪ��G���j�M��
   public BSTree() { head = null; }
 
   // ��k: �ˬd�G���j�M��O�_�O�Ū�
   boolean isBSTreeEmpty() {
      if ( head == null ) return true;
      else                return false;
   }
   // ��k: �b�G���j�M�𴡤J�`�I
   public void insertBSTreeNode(int data) {
      if ( head == null ) {  // �إ߮ڸ`�I
         head = new TreeNode(data);
         return;
      }
      // �إߤG���j�M��
      TreeNode current = head;
      while (true) {
         if ( data < current.data ) {  // �b���l��
            if ( current.left == null ) {
               current.left = new TreeNode(data);
               return;
            }
            else  current = current.left;
         }
         else {  // �b�k�l��
            if ( current.right == null ) {
               current.right = new TreeNode(data);
               return;
            }
            else  current = current.right;
         }
      }
   }
   // ��k: ��ܤG���j�M�𪺸`�I���
   public void printBSTree() {
      inOrder(this.head);
      System.out.println();
   }
   // ��k: �e�Ǩ��X�����j��k
   public void preOrder(TreeNode node) {
      if ( node != null ) { 
         // ��ܸ`�I���
         System.out.print("["+node.data+"]"); 
         preOrder(node.left);  // ���X���l��         
         preOrder(node.right); // ���X�k�l��
      }
   }
   // ��k: ���Ǩ��X�����j��k
   public void inOrder(TreeNode node) {
      if ( node != null ) {  
         inOrder(node.left);  // ���X���l��
         // ��ܸ`�I���
         System.out.print("["+node.data+"]");
         inOrder(node.right); // ���X�k�l��
      }
   }
   // ��k: ��Ǩ��X�����j��k
   public void postOrder(TreeNode node) {
      if ( node != null ) {  
         postOrder(node.left);  // ���X���l��
         postOrder(node.right); // ���X�k�l��
         // ��ܸ`�I���
         System.out.print("["+node.data+"]");
      }
   }
	
   public static void main(String args[]){
         int i;         
         int[] array = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
         
         BSTree obj = new BSTree();
      

         System.out.print("Original Array:");
         // �ϥΰj��H���J�覡�إ߾𪬵��c
         for ( i = 0; i < array.length; i++ ) {
              System.out.print("["+array[i]+"]");
              obj.insertBSTreeNode(array[i]);
         }
         System.out.println();

         System.out.print("InOrder:");
         obj.inOrder(obj.head);
         System.out.println();

         System.out.print("PreOrder:");
         obj.preOrder(obj.head);
         System.out.println();

         System.out.print("PostOrder:");
         obj.postOrder(obj.head);
         System.out.println();
   }
}
