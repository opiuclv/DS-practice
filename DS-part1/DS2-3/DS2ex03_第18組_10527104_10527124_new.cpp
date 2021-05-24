// 資訊二甲 第十八組 
//  鄭智謙   邱正皓 
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

struct Content {                                                     // 資料結構 
	string school;
	string department;
	string training;
	string level;
	string graduate;
	int graduates = -1;
} ;

typedef Content content;

struct Node {                                                     // 資料結構 
	string school;
	int serialNumber;
	int graduates;
} ;

typedef Node node;

struct TreePtr {                                                     // 資料結構 
	node *Keys1 = NULL;
	int K1Q = 0;
	node *Keys2 = NULL;
	int K2Q = 0;
	TreePtr * up = NULL;
	TreePtr * left = NULL;
	TreePtr * down = NULL;
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
	int quantity = 0;                                                // 資料總數 
public:
	bool Readtxt( string num ) {                                     // 讀取文字檔 
		int x = 0, graduates = 0;
		file.open( num.c_str(), ios::in );
	    char getS[255];
	    content temp;
	    if ( !file ) {                                               // 若找不到指定檔案 
	    	file.close();
	    	return false;
		}
		else {
			file.ignore(255,'\n');                                   // 跳過前3行 
			file.ignore(255,'\n');
			file.ignore(255,'\n');
            while ( !file.eof() ) {                                  // 若檔案尚未到結尾 
				x = 0;
				file.getline( getS, 255, '\t');                      // 將到tab為止的字元存進getS陣列 
				file.getline( getS, 255, '\t');
	    		temp.school = getS;                                  // 擷取陣列中的school, department, training, level, graduate等5個欄位 
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
				    x = 1;                                           // 判定此筆資料有誤 
				else {
					temp.graduate = getS; 
					ss << temp.graduate;
					ss >> graduates;
        	    	ss.str("");
                	ss.clear();
					if ( graduates == 0 )
				    	x = 1;
				}
				file.ignore(255,'\n');                               // 跳過剩餘資料直到下一行 
				if ( x == 0 ) {                                      // 若此筆資料無誤 
					temp.graduates = graduates;
    				quantity++;                                      // 資料總數 +1 
	    			aSchoolList.push_back(temp);                     // 新增筆資料於資料清單 
	    		}
			}
		}
		file.close();
	    return true;
    }
    
    void Print() {                                                   // 印出資料清單 
        int index = 0;
    	while ( index < quantity ) {
    		cout << "[" << index + 1 << "] " << aSchoolList[index].school << " " << aSchoolList[index].department;
			cout << "," << aSchoolList[index].training << "," << aSchoolList[index].level << ",";
			cout << aSchoolList[index].graduates << endl;
        	index++;
        }
	}

    void SameKeys( treePtr local, int n, int index ) {
    	if ( n == 1 ) {
    		local -> Keys1[local -> K1Q].school = aSchoolList[index].school;
    		local -> Keys1[local -> K1Q].serialNumber = index + 1;
    		local -> Keys1[local -> K1Q].graduates = aSchoolList[index].graduates;
    		local -> K1Q = local -> K1Q + 1;
		}
		else {
    		local -> Keys2[local -> K2Q].school = aSchoolList[index].school;
    		local -> Keys2[local -> K2Q].serialNumber = index + 1;
    		local -> Keys2[local -> K2Q].graduates = aSchoolList[index].graduates;
    		local -> K2Q = local -> K2Q + 1;
		}
	} 

    void KeysSwap( treePtr local ) {
    	node *temp = local -> Keys1;
    	local -> Keys1 = local -> Keys2;
    	local -> Keys2 = temp;
    	int t = local -> K1Q;
    	local -> K1Q = local -> K2Q;
    	local -> K2Q = t;
	}
	
	int FindData( node *Keys, string school, int index ) {
		int i = 0, t = 0;
		while ( i <= index ) {
			if ( school.compare( aSchoolList[i].school ) == 0 ) {
				Keys[t].school = school;
				Keys[t].serialNumber = i + 1;
				Keys[t].graduates = aSchoolList[i].graduates;
				t++;
			}
			i++;
		}
		return t;
	}
	
    void NodeSplit( treePtr local, int n, treePtr aRoot ) { // 分拆分拆
    	treePtr temp = NULL;
        if ( local -> left != NULL && local -> right != NULL ) {
	    	if ( n == 1 ) { // 左->中 
    			if ( local -> right -> K2Q == 0 ) {
    				if ( local -> left -> K2Q > 0 ) {
	    				aRoot -> right = local -> right;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> left = local -> down;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				local -> right = new TreePtr;
	    				local -> right -> K1Q = local -> left -> K2Q;
	    				local -> right -> Keys1 = local -> left -> Keys2;
	    				local -> left -> Keys2 = NULL;
	    				local -> left -> K2Q = 0;
	    				local -> down = NULL;
	    			
	    				NodeSplit( local -> left, n, local -> right );
	    			}
	    			else {
	    				aRoot -> right = local -> right;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				local -> right = local -> down;
	    				local -> down = NULL;
	    				
	    				aRoot -> left = new TreePtr;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				aRoot -> left -> K1Q = local -> right -> K2Q;
	    				aRoot -> left -> Keys1 = local -> right -> Keys2;
	    				local -> right -> Keys2 = NULL;
	    				local -> right -> K2Q = 0;
	    			
	    				NodeSplit( local -> right, n, aRoot -> left );
					}
	    	    }
	    	    else {
	    			if ( local -> left -> K2Q == 0 ) {
	    				aRoot -> left = local -> right;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> right = new TreePtr;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				aRoot -> right -> K1Q = aRoot -> left -> K2Q;
	    				aRoot -> right -> Keys1 = aRoot -> left -> Keys2;
	    				aRoot -> left -> Keys2 = NULL;
	    				aRoot -> left -> K2Q = 0;
	    				
	    				local -> right = local -> down;
	    				local -> down = NULL;
	    				NodeSplit( aRoot -> left, n, aRoot -> right );
					}
					else {
	    				aRoot -> right = local -> right;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> left = local -> down;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				local -> right = new TreePtr;
	    				temp = local -> right;
	    				temp -> up = local;
	    				local -> right -> K1Q = local -> left -> K2Q;
	    				local -> right -> Keys1 = local -> left -> Keys2;
	    				local -> left -> Keys2 = NULL;
	    				local -> left -> K2Q = 0;
	    				local -> down = NULL;
	    				
	    				NodeSplit( local -> left, n, local -> right );
					}
				}
			} 
    		else { // 右->中 
    			if ( local -> left -> K2Q == 0 ) {
    				if ( local -> right -> K2Q > 0 ) {
	    				aRoot -> left = local -> left;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> right = local -> down;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				local -> left = new TreePtr;
	    				local -> left -> K1Q = local -> right -> K1Q;
	    				local -> left -> Keys1 = local -> right -> Keys1;
	    				local -> right -> Keys1 = NULL;
	    				local -> right -> K1Q = 0;
	    				local -> down = NULL;
	    				KeysSwap( local -> right );
	    			
	    				NodeSplit( local -> right, n, local -> left );
	    			}
	    			else {
	    				aRoot -> left = local -> left;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				local -> left = local -> down;
	    				local -> down = NULL;
	    				
	    				aRoot -> right = new TreePtr;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				aRoot -> right -> K1Q = local -> left -> K1Q;
	    				aRoot -> right -> Keys1 = local -> left -> Keys1;
	    				local -> left -> Keys1 = NULL;
	    				local -> left -> K1Q = 0;
	    				KeysSwap( local -> left );
	    			
	    				NodeSplit( local -> left, n, aRoot -> right );
					}
	    	    }
	    	    else {
	    			if ( local -> right -> K2Q == 0 ) {
	    				aRoot -> right = local -> left;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> left = new TreePtr;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				aRoot -> left -> K1Q = aRoot -> right -> K1Q;
	    				aRoot -> left -> Keys1 = aRoot -> right -> Keys1;
	    				aRoot -> right -> Keys1 = NULL;
	    				aRoot -> right -> K1Q = 0;
	    				KeysSwap( aRoot -> right );
	    				
	    				local -> left = local -> down;
	    				local -> down = NULL;
	    				NodeSplit( aRoot -> right, n, aRoot -> left );
					}
					else {
	    				aRoot -> left = local -> left;
	    				temp = aRoot -> left;
	    				temp -> up = aRoot;
	    				
	    				aRoot -> right = local -> down;
	    				temp = aRoot -> right;
	    				temp -> up = aRoot;
	    				
	    				local -> left = new TreePtr;
	    				temp = local -> left;
	    				temp -> up = local;
	    				local -> left -> K1Q = local -> right -> K1Q;
	    				local -> left -> Keys1 = local -> right -> Keys1;
	    				local -> right -> Keys1 = NULL;
	    				local -> right -> K1Q = 0;
	    				local -> down = NULL;
	    				KeysSwap( local -> right );
	    				
	    				NodeSplit( local -> right, n, local -> left );
					}
				}
			}
		}
	}
	
   	void NodeRotate( treePtr local, node *aKey, int index ) {
   	    treePtr aRoot = NULL, temp = NULL;
   	    node *strs = new Node[3];
   	    int kqs[3];
   	    strs[0] = local -> Keys1[0];
   	    strs[1] = local -> Keys2[0];
   	    strs[2] = aKey[0];
		int i = 0, j = 0;
   	    while ( i < 2 ) {
   	    	while ( j < 3 ) {
   	    		if ( strs[i].school.compare( strs[j].school ) > 0 ) {
   	    			swap( strs[i], strs[j] );
   	    			swap( kqs[i], kqs[j] );
				}
   	    		j++;
		    }
		    i++;
		    j = i + 1;
		}
		if ( local -> up == NULL ) {
			aRoot = new TreePtr;
			aRoot -> Keys1 = new Node[100];
			aRoot -> K1Q = FindData( aRoot -> Keys1, strs[1].school, index );
			aRoot -> left = local;
			aRoot -> right = new TreePtr;
			a23tree = aRoot;
			aRoot = aRoot -> right;
			aRoot -> up = a23tree;
			aRoot -> Keys1 = new Node[100];
			aRoot -> K1Q = FindData( aRoot -> Keys1, strs[2].school, index );
			local -> K1Q = FindData( local -> Keys1, strs[0].school, index );
			local -> Keys2 = NULL;
			local -> K2Q = 0;
			local -> up = a23tree;
			NodeSplit( local, 1, aRoot );
		}
		else {
			aRoot = local -> up;
			if ( aRoot -> K2Q == 0 ) {
				aRoot -> Keys2 = new Node[100];
				aRoot -> K2Q = FindData( aRoot -> Keys2, strs[1].school, index );
				if ( aRoot -> Keys2[0].school.compare( aRoot -> Keys1[0].school ) < 0 )
    		        KeysSwap( aRoot );
				aRoot -> down = new TreePtr;
				temp = aRoot;
				aRoot = aRoot -> down;
				aRoot -> up = temp;
				aRoot -> Keys1 = new Node[100];
				local -> Keys2 = NULL;
				local -> K2Q = 0;
				if ( temp -> left == local ) {
					aRoot -> K1Q = FindData( aRoot -> Keys1, strs[2].school, index );
					local -> K1Q = FindData( local -> Keys1, strs[0].school, index );
					NodeSplit( local, 1, aRoot );
				}
				else {
					aRoot -> K1Q = FindData( aRoot -> Keys1, strs[0].school, index );
					local -> K1Q = FindData( local -> Keys1, strs[2].school, index );
					NodeSplit( local, 2, aRoot );
				}
			}
			else {
				local -> K1Q = FindData( local -> Keys1, strs[0].school, index );
				local -> K2Q = FindData( local -> Keys2, strs[2].school, index );
				FindData( aKey, strs[1].school, index );
				NodeRotate( aRoot, aKey, index );
			}
		}
	}
	 
    void AddtoNode( treePtr local, node *aKey, int index ) {
        if ( local -> K2Q == 0 ) {
        	local -> Keys2 = aKey;
    		local -> K2Q = 1;
    		aKey = NULL;
    		if ( local -> Keys2[0].school.compare( local -> Keys1[0].school ) < 0 )
    		    KeysSwap( local );
		}
		else
			NodeRotate( local, aKey, index );
	} 

    void Build23tree() {
    	treePtr local;
    	node *aKey = NULL;
    	int index = 1, done = 0;
    	if ( a23tree == NULL ) {
    		a23tree = new TreePtr;
    		a23tree -> Keys1 = new Node[100];
    		a23tree -> Keys1[0].serialNumber = 1;
    		a23tree -> Keys1[0].graduates = aSchoolList[0].graduates;
    		a23tree -> Keys1[0].school = aSchoolList[0].school;
    		a23tree -> K1Q = 1;
    	}
		local = a23tree;
		while ( index < quantity ) {
			while ( done == 0 ) {
				if ( aSchoolList[index].school.compare( local -> Keys1[0].school ) < 0 ) {
					if( local -> left != NULL )
					    local = local -> left;
					else
					    done = 3;
				}
				else if ( aSchoolList[index].school.compare( local -> Keys1[0].school ) == 0 ) 
					done = 1;
				else {
					if ( local -> Keys2 != NULL) {
			   	 		if ( aSchoolList[index].school.compare( local -> Keys2[0].school ) < 0 ) {
						   	if ( local -> down != NULL )
			    		    	local = local -> down;
			    		    else
			    		        done = 3;
						}
						else if ( aSchoolList[index].school.compare( local -> Keys2[0].school ) == 0 )
							done = 2;
						else {
					    	if ( local -> right != NULL )
    				     		local = local -> right;
    				    	else
    				    		done = 3;
						}
					}
					else {
					    if ( local -> right != NULL )
    				     	local = local -> right;
    				    else
    				    	done = 3;
				    }
				}
				if ( done == 1 )
				    SameKeys( local, 1, index );
				if ( done == 2 )
				    SameKeys( local, 2, index );
				if ( done == 3 ) {
        			aKey = new Node[100];
    				aKey[0].school = aSchoolList[index].school;
    				aKey[0].serialNumber = index + 1;
    				aKey[0].graduates = aSchoolList[index].graduates;
				    AddtoNode( local, aKey, index );
				}
			}
			done = 0;
		    index++;
		    local = a23tree;
		}
	}
	
	void PrintTheData( int aNumber ) { 
		int index = aNumber - 1;
		cout << aSchoolList[index].school << ", " << aSchoolList[index].department << ", ";
		cout  << aSchoolList[index].training << ", " << aSchoolList[index].level << ", ";
		cout << aSchoolList[index].graduates << endl;
	}
	
	void PrintPreOrder( treePtr root, int level ) {
		int index = 0, n = 1;
		cout << "^^^^^^ Level = " << level << endl;
		while ( index < root -> K1Q ) {
			cout << setw(3) << n << ": [" << root -> Keys1[index].serialNumber << "] ";
			PrintTheData( root -> Keys1[index].serialNumber );
			index++;
			n++;
		}
		if ( root -> K2Q > 0 ) {		
			cout << "~~~~~~~~~~" << endl;
			index = 0;
			while ( index < root -> K2Q ) {
				cout << setw(3) << n << ": [" << root -> Keys2[index].serialNumber << "] ";
				PrintTheData( root -> Keys2[index].serialNumber );
				index++;
				n++;
			}
		}
		cout << "~~~~~~~~~~" << endl;
		if ( root -> left != NULL )
		    PrintPreOrder( root -> left, level + 1 );
		if ( root -> down != NULL )
		    PrintPreOrder( root -> down, level + 1 );
		if ( root -> right != NULL )
		    PrintPreOrder( root -> right, level + 1 );
	}
	
    void InitializeList() {                                          // 清空資料清單 
	    aSchoolList.clear();
	    delete a23tree;
	    a23tree = NULL;
	    quantity = 0;
    }

    treePtr GetRoot() {                                              // 取得資料總數 
	    return a23tree;
	}
	
    int GetQuantity() {                                              // 取得資料總數 
	    return quantity;
	}
};

bool ReadFile( List &aList, int num ) {                              // 準備讀取文字檔 
    string fileName, temp;
	ss << num;
	ss >> temp;
	fileName = "input" + temp + ".txt";
    ss.str("");
    ss.clear();
	if ( aList.Readtxt( fileName ) )                                 // 若成功讀取檔案
	    return true;
    return false;
}

void Mission1( List &aList ) {
    aList.Print();
	cout << "########################################################" << endl;
	cout << "Mission 1: Build a 2-3 tree" << endl;
	cout << "########################################################" << endl << endl;
	aList.Build23tree();
	treePtr root = aList.GetRoot();
	aList.PrintPreOrder( root, 1 );
}

int main(int argc, char** argv) {
    Hi();
	List aList;
    int num = 1;
	while ( num != 0 ) {
		aList.InitializeList();                                      // 將先前的資料清單清空 
        cout << "Input the file number: 301, 302, ... [0]Quit" << endl << endl;
        cin >> num;
	    if ( !ReadFile( aList, num ) )
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
