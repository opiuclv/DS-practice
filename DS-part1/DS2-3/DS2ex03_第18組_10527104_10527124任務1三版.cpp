// ��T�G�� �ĤQ�K�� 
//  �G����   �����q 
// 10527104 10527124 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <new>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;

fstream file;

stringstream ss;

struct Content {                                                     // ��Ƶ��c 
	string school;
	string department;
	string training;
	string level;
	string graduate;
	int graduates = -1;
} ;

typedef Content content;

struct Node {                                                     	 // ��Ƶ��c 
	string school;
	int serialNumber;
	int graduates;
} ;

typedef Node node;

struct TreePtr {                                                     // ��Ƶ��c 
	node *key1 = NULL;
	int K1Q = 0;
	node *key2 = NULL;
	int K2Q = 0;
	TreePtr * up = NULL;
	TreePtr * left = NULL;
	TreePtr * down1 = NULL;
	TreePtr * down2 = NULL;
	TreePtr * right = NULL; 
} ;

typedef TreePtr * treePtr;

void Hi() {
   	cout << "*******************************" << endl;
   	cout << " On-machine Exercise          *" << endl;
   	cout << " Mission 1: Build a 2-3 tree  *" << endl;
   	cout << " Mission 2: Search a 2-3 tree *" << endl;
  	cout << "*******************************" << endl << endl;
}

class List {
	vector<content> aSchoolList;
	treePtr a23tree = NULL;
	int quantity = 0;                                                // ����`�� 
public:
	bool Readtxt( string num ) {                                     // Ū����r�� 
		int x = 0, graduates = 0;
		file.open( num.c_str(), ios::in );
	    char getS[255];
	    content temp;
	    if ( file ) {                                                // �Y�䤣����w�ɮ� 
			file.ignore(255,'\n');                                   // ���L�e3�� 
			file.ignore(255,'\n');
			file.ignore(255,'\n');
            while ( !file.eof() ) {                                  // �Y�ɮש|���쵲�� 
				x = 0;
				file.getline( getS, 255, '\t');                      // �N��tab����r���s�igetS�}�C 
				file.getline( getS, 255, '\t');
	    		temp.school = getS;                                  // �^���}�C����school, department, training, level, graduate��5����� 
				file.getline( getS, 255, '\t');
				file.getline( getS, 255, '\t');
	    		temp.department = getS;
				file.getline( getS, 255, '\t');
	    		temp.training = getS;
				file.getline( getS, 255, '\t');
	    		temp.level = getS;
				file.getline( getS, 255, '\t');
				file.getline( getS, 255, '\t');
				file.getline( getS, 255, '\t');
                if ( !isdigit(getS[0]) )
				    x = 1;                                           // �P�w������Ʀ��~ 
				else {
					temp.graduate = getS; 
					ss << temp.graduate;
					ss >> graduates;
        	    	ss.str("");
                	ss.clear();
					if ( graduates == 0 )                            // ���~�H�ƥ���>0 
				    	x = 1;
				}
				file.ignore(255,'\n');                               // ���L�Ѿl��ƪ���U�@�� 
				if ( x == 0 ) {                                      // �Y������ƵL�~ 
					temp.graduates = graduates;
    				quantity++;                                      // ����`�� +1 
	    			aSchoolList.push_back(temp);                     // �s�W����Ʃ��ƲM�� 
	    		}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
    
    void Print() {                                                   // �L�X��ƲM�� 
        int index = 0;
    	while ( index < quantity ) {
    		cout << "[" << index + 1 << "] " << aSchoolList[index].school << " " << aSchoolList[index].department;
			cout << "," << aSchoolList[index].training << "," << aSchoolList[index].level << ",";
			cout << aSchoolList[index].graduates << endl;
        	index++;
        }
	}

    void Samekey( treePtr local, int n, int index ) {                // ���|�P�զW��key 
    	if ( n == 1 ) {
    		local -> key1[local -> K1Q].school = aSchoolList[index].school;
    		local -> key1[local -> K1Q].serialNumber = index + 1;
    		local -> key1[local -> K1Q].graduates = aSchoolList[index].graduates;
    		local -> K1Q = local -> K1Q + 1;
		}
		else {
    		local -> key2[local -> K2Q].school = aSchoolList[index].school;
    		local -> key2[local -> K2Q].serialNumber = index + 1;
    		local -> key2[local -> K2Q].graduates = aSchoolList[index].graduates;
    		local -> K2Q = local -> K2Q + 1;
		}
	} 

    void keySwap( treePtr local ) {                                  // �洫��key����m 
    	node *temp = local -> key1;
    	local -> key1 = local -> key2;
    	local -> key2 = temp;
    	int t = local -> K1Q;
    	local -> K1Q = local -> K2Q;
    	local -> K2Q = t;
	}
	
	int FindData( node *key, string school, int index ) {            // �q��ƲM��̴M��P�W��� 
		int i = 0, t = 0;
		while ( i <= index ) {
			if ( school.compare( aSchoolList[i].school ) == 0 ) {
				key[t].school = school;
				key[t].serialNumber = i + 1;
				key[t].graduates = aSchoolList[i].graduates;
				t++;
			}
			i++;
		}
		return t;
	}

   	void NodeSplit( treePtr local, node *newkey, int index ) {		 // �`�I���� 
   	    treePtr newNode = NULL, parents = NULL, temp = NULL;
	   	node *strs = NULL; 
        if ( local -> K2Q == 0 ) {                                   // �Ykey2���� 
        	local -> key2 = new Node[100];
			local -> K2Q = FindData( local -> key2, newkey[0].school, index );
    		newkey = NULL;
    		if ( local -> key2[0].school.compare( local -> key1[0].school ) < 0 ) 
    		    keySwap( local );
    	}
    	else {
   	    	strs = new Node[3];                                		 // ��j�p�ΰ}�C(0,1,2=�p,��,�j)
	   	    strs[0] = local -> key1[0];                              // ��key1 
	   	    strs[1] = local -> key2[0];                              // ��key2
	   	    strs[2] = newkey[0];                              		 // �skey
			int i = 0, j = 0;
	   	    while ( i < 2 ) {
	   	    	while ( j < 3 ) {
	   	    		if ( strs[i].school.compare( strs[j].school ) > 0 )
	   	    			swap( strs[i], strs[j] );
	   	    		j++;
			    }
			    i++;
			    j = i + 1;
			}
			if ( local -> up == NULL ) {                             // ��ڤ��� 
				parents = new TreePtr;								 // �s�W��� 
				parents -> key1 = new Node[100];
				parents -> K1Q = FindData( parents -> key1, strs[1].school, index ); // ��Ƹɻ� 
				parents -> left = local;
				a23tree = parents;
				parents -> right = new TreePtr; 					 // �s�W�S�̸`�I 
				newNode = parents -> right;
				newNode -> up = a23tree;
				newNode -> key1 = new Node[100];
				newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
				local -> K1Q = FindData( local -> key1, strs[0].school, index ); // ��s�¸`�I 
				local -> key2 = NULL;
				local -> K2Q = 0;
				local -> up = a23tree;
				if ( local -> down2 != NULL ) {						 // �𸭤��t 
					newNode -> right = local -> right;
					temp = newNode -> right;
					temp -> up = newNode;
					
					newNode -> left = local -> down2;
					temp = newNode -> left;
					temp -> up = newNode;
					
					local -> right = local -> down1;
					local -> down1 = NULL;
					local -> down2 = NULL;
				}
			}
			else {
				parents = local -> up;
				if ( parents -> left == local ) {                    // �W�Ӫ���V��"/" 
					local -> K1Q = FindData( local -> key1, strs[0].school, index );
					if ( parents -> down1 != NULL )
						parents -> down2 = parents -> down1;
					parents -> down1 = new TreePtr; 				 // �s�W�S�̸`�I
					newNode = parents -> down1;
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
					if ( local -> down2 != NULL ) {					 // �𸭤��t	  
						newNode -> right = local -> right;
						temp = newNode -> right;
						temp -> up = newNode;
						newNode -> left = local -> down2;
						temp = newNode -> left;
						temp -> up = newNode;
						local -> right = local -> down1;
					}
				}
				else if ( parents -> down1 == local ) {              // �W�Ӫ���V��"|" 
					local -> K1Q = FindData( local -> key1, strs[0].school, index );
					parents -> down2 = new TreePtr; 				 // �s�W�S�̸`�I
					newNode = parents -> down2;
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
					if ( local -> down2 != NULL ) {					 // �𸭤��t
						newNode -> right = local -> right;
						temp = newNode -> right;
						temp -> up = newNode;
						newNode -> left = local -> down2;
						temp = newNode -> left;
						temp -> up = newNode;
						local -> right = local -> down1;
					}
				}
				else {                    							 // �W�Ӫ���V��"\" 
					local -> K1Q = FindData( local -> key1, strs[2].school, index );
					if ( parents -> down1 == NULL ) { 				 // �s�W�S�̸`�I
						parents -> down1 = new TreePtr;
						newNode = parents -> down1;
					}
					else {
						parents -> down2 = new TreePtr;
						newNode = parents -> down2;
					}
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[0].school, index );
					if ( local -> down2 != NULL ) {					 // �𸭤��t
						newNode -> left = local -> left;
						temp = newNode -> left;
						temp -> up = newNode;
						newNode -> right = local -> down1;
						temp = newNode -> right;
						temp -> up = newNode;
						local -> left = local -> down2;
					}
				}
				newNode -> up = parents;
				local -> key2 = NULL;								 // ��s�¸`�I 
				local -> K2Q = 0;
				local -> down1 = NULL;
				local -> down2 = NULL;
				FindData( newkey, strs[1].school, index );           // ��s�skey(������) 
				NodeSplit( parents, newkey, index );       			 // �~��V�W���j 
			}
		}
	}

    void Build23tree() {                                             // �إ�2-3�� 
    	treePtr local;
    	node *newkey = NULL;
    	int index = 1, done = 0;
    	if ( a23tree == NULL ) {                                     // �s�W�Ĥ@����Ƭ���� 
    		a23tree = new TreePtr;
    		a23tree -> key1 = new Node[100];
    		a23tree -> key1[0].serialNumber = 1;
    		a23tree -> key1[0].graduates = aSchoolList[0].graduates;
    		a23tree -> key1[0].school = aSchoolList[0].school;
    		a23tree -> K1Q = 1;
    	}
		local = a23tree;
		while ( index < quantity ) {
			while ( done == 0 ) {                                    // �Y������Ʃ|���N�w�� 
				if ( aSchoolList[index].school.compare( local -> key1[0].school ) < 0 ) { // <key1 
					if( local -> left != NULL )
					    local = local -> left;
					else
					    done = 3;
				}
				else if ( aSchoolList[index].school.compare( local -> key1[0].school ) == 0 ) // �Pkey1 
					done = 1;
				else {
					if ( local -> key2 != NULL) {                    // �Ykey2�s�b 
			   	 		if ( aSchoolList[index].school.compare( local -> key2[0].school ) < 0 ) { // �b��key���� 
						   	if ( local -> down1 != NULL )
			    		    	local = local -> down1;
							else
					   			done = 3;
						}
						else if ( aSchoolList[index].school.compare( local -> key2[0].school ) == 0 ) // �Pkey2 
							done = 2;
						else {                                       // >key2 
					    	if ( local -> right != NULL )
    				     		local = local -> right;
							else
					    		done = 3;
						}
					}
					else {                                           // >key1�Bkey2���s�b 
					    if ( local -> right != NULL )
    				     	local = local -> right;
						else
					    	done = 3;
				    }
				}
				if ( done == 1 )                                     // �Pkey1�P�W 
				    Samekey( local, 1, index );
				if ( done == 2 )                                     // �Pkey2�P�W  
				    Samekey( local, 2, index );
				if ( done == 3 ) {                                   // �skey 
        			newkey = new Node[100];
    				newkey[0].school = aSchoolList[index].school;
    				newkey[0].serialNumber = index + 1;
    				newkey[0].graduates = aSchoolList[index].graduates;
				    NodeSplit( local, newkey, index );               // �`�I���� 
				}
			}
			done = 0;
		    index++;
		    local = a23tree;
		}
	}
	
	void PrintTheData( int aNumber ) {                               // �L�Xkey�����e 
		int index = aNumber - 1;
		cout << aSchoolList[index].school << ", " << aSchoolList[index].department << ", ";
		cout  << aSchoolList[index].training << ", " << aSchoolList[index].level << ", ";
		cout << aSchoolList[index].graduates << endl;
	}
	
	void PrintPreOrder( treePtr root, int level ) {                  // �L�X�𪺩Ҧ��`�I(�e��) 
		int index = 0, n = 1;
		if ( level > 0 )
			cout << "^^^^^^ Level = " << level << endl;
		while ( index < root -> K1Q ) {                              // �L�Xkey1  
			cout << setw(3) << n << ": [" << root -> key1[index].serialNumber << "] ";
			PrintTheData( root -> key1[index].serialNumber );
			index++;
			n++;
		}
		if ( root -> K2Q > 0 ) {                                     // �L�Xkey2 
		    if ( level > 0 ) 
				cout << "~~~~~~~~~~" << endl;
			index = 0;
			while ( index < root -> K2Q ) {
				cout << setw(3) << n << ": [" << root -> key2[index].serialNumber << "] ";
				PrintTheData( root -> key2[index].serialNumber );
				index++;
				n++;
			}
		}
		if ( level > 0 ) {                                           // �e�ǻ��j 
			cout << "~~~~~~~~~~" << endl;
			if ( root -> left != NULL )
			    PrintPreOrder( root -> left, level + 1 );
			if ( root -> down1 != NULL )
			    PrintPreOrder( root -> down1, level + 1 );
			if ( root -> right != NULL )
			    PrintPreOrder( root -> right, level + 1 );
		}
		else
			PrintPreOrder( root, level + 1 );                        // �}�l�L�X���㪺�� 
	}
	
    void InitializeList() {                                          // ��l�Ƹ�Ʈw
	    aSchoolList.clear();
	    delete a23tree;
	    a23tree = NULL;
	    quantity = 0;
    }

    treePtr GetRoot() {                                              // ���o���
	    return a23tree;
	}
	
    int GetQuantity() {                                              // ���o����`�� 
	    return quantity;
	}
};

bool ReadFile( List &aList, int num ) {                              // �ǳ�Ū����r�� 
    string fileName, temp;
	ss << num;
	ss >> temp;
	fileName = "input" + temp + ".txt";
    ss.str("");
    ss.clear();
	if ( aList.Readtxt( fileName ) )                                 // �Y���\Ū���ɮ�
	    return true;
    return false;
}

void Mission1( List &aList ) {                                       // ����1 
    aList.Print();
	cout << "########################################################" << endl;
	cout << "Mission 1: Build a 2-3 tree" << endl;
	cout << "########################################################" << endl;
	aList.Build23tree();                                             // �إ�2-3�� 
	treePtr root = aList.GetRoot();
	aList.PrintPreOrder( root, 0 );                                  // �L�X2-3�� 
}

int main(int argc, char** argv) {
    Hi();
	List aList;
    int num = 1;
	while ( num != 0 ) {
		aList.InitializeList();                                      // �N���e����ƲM��M�� 
        cout << "Input the file number: 301, 302, ... [0]Quit" << endl << endl;
        cin >> num;
	    if ( !ReadFile( aList, num ) )                               // �YŪ�ɥ��� 
		    cout << endl << "### input" << num << ".txt does not exist! ###" << endl << endl;
        else {
            Mission1( aList );
            cout << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
