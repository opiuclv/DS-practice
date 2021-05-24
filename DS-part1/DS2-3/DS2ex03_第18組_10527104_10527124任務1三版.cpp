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

struct Node {                                                     	 // 資料結構 
	string school;
	int serialNumber;
	int graduates;
} ;

typedef Node node;

struct TreePtr {                                                     // 資料結構 
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
	int quantity = 0;                                                // 資料總數 
public:
	bool Readtxt( string num ) {                                     // 讀取文字檔 
		int x = 0, graduates = 0;
		file.open( num.c_str(), ios::in );
	    char getS[255];
	    content temp;
	    if ( file ) {                                                // 若找不到指定檔案 
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
					if ( graduates == 0 )                            // 畢業人數必須>0 
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
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
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

    void Samekey( treePtr local, int n, int index ) {                // 堆疊同校名的key 
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

    void keySwap( treePtr local ) {                                  // 交換兩key的位置 
    	node *temp = local -> key1;
    	local -> key1 = local -> key2;
    	local -> key2 = temp;
    	int t = local -> K1Q;
    	local -> K1Q = local -> K2Q;
    	local -> K2Q = t;
	}
	
	int FindData( node *key, string school, int index ) {            // 從資料清單裡尋找同名資料 
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

   	void NodeSplit( treePtr local, node *newkey, int index ) {		 // 節點分裂 
   	    treePtr newNode = NULL, parents = NULL, temp = NULL;
	   	node *strs = NULL; 
        if ( local -> K2Q == 0 ) {                                   // 若key2為空 
        	local -> key2 = new Node[100];
			local -> K2Q = FindData( local -> key2, newkey[0].school, index );
    		newkey = NULL;
    		if ( local -> key2[0].school.compare( local -> key1[0].school ) < 0 ) 
    		    keySwap( local );
    	}
    	else {
   	    	strs = new Node[3];                                		 // 比大小用陣列(0,1,2=小,中,大)
	   	    strs[0] = local -> key1[0];                              // 舊key1 
	   	    strs[1] = local -> key2[0];                              // 舊key2
	   	    strs[2] = newkey[0];                              		 // 新key
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
			if ( local -> up == NULL ) {                             // 樹根分裂 
				parents = new TreePtr;								 // 新增樹根 
				parents -> key1 = new Node[100];
				parents -> K1Q = FindData( parents -> key1, strs[1].school, index ); // 資料補齊 
				parents -> left = local;
				a23tree = parents;
				parents -> right = new TreePtr; 					 // 新增兄弟節點 
				newNode = parents -> right;
				newNode -> up = a23tree;
				newNode -> key1 = new Node[100];
				newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
				local -> K1Q = FindData( local -> key1, strs[0].school, index ); // 更新舊節點 
				local -> key2 = NULL;
				local -> K2Q = 0;
				local -> up = a23tree;
				if ( local -> down2 != NULL ) {						 // 樹葉分配 
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
				if ( parents -> left == local ) {                    // 上來的方向為"/" 
					local -> K1Q = FindData( local -> key1, strs[0].school, index );
					if ( parents -> down1 != NULL )
						parents -> down2 = parents -> down1;
					parents -> down1 = new TreePtr; 				 // 新增兄弟節點
					newNode = parents -> down1;
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
					if ( local -> down2 != NULL ) {					 // 樹葉分配	  
						newNode -> right = local -> right;
						temp = newNode -> right;
						temp -> up = newNode;
						newNode -> left = local -> down2;
						temp = newNode -> left;
						temp -> up = newNode;
						local -> right = local -> down1;
					}
				}
				else if ( parents -> down1 == local ) {              // 上來的方向為"|" 
					local -> K1Q = FindData( local -> key1, strs[0].school, index );
					parents -> down2 = new TreePtr; 				 // 新增兄弟節點
					newNode = parents -> down2;
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[2].school, index );
					if ( local -> down2 != NULL ) {					 // 樹葉分配
						newNode -> right = local -> right;
						temp = newNode -> right;
						temp -> up = newNode;
						newNode -> left = local -> down2;
						temp = newNode -> left;
						temp -> up = newNode;
						local -> right = local -> down1;
					}
				}
				else {                    							 // 上來的方向為"\" 
					local -> K1Q = FindData( local -> key1, strs[2].school, index );
					if ( parents -> down1 == NULL ) { 				 // 新增兄弟節點
						parents -> down1 = new TreePtr;
						newNode = parents -> down1;
					}
					else {
						parents -> down2 = new TreePtr;
						newNode = parents -> down2;
					}
					newNode -> key1 = new Node[100];
					newNode -> K1Q = FindData( newNode -> key1, strs[0].school, index );
					if ( local -> down2 != NULL ) {					 // 樹葉分配
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
				local -> key2 = NULL;								 // 更新舊節點 
				local -> K2Q = 0;
				local -> down1 = NULL;
				local -> down2 = NULL;
				FindData( newkey, strs[1].school, index );           // 更新新key(中間值) 
				NodeSplit( parents, newkey, index );       			 // 繼續向上遞迴 
			}
		}
	}

    void Build23tree() {                                             // 建立2-3樹 
    	treePtr local;
    	node *newkey = NULL;
    	int index = 1, done = 0;
    	if ( a23tree == NULL ) {                                     // 新增第一筆資料為樹根 
    		a23tree = new TreePtr;
    		a23tree -> key1 = new Node[100];
    		a23tree -> key1[0].serialNumber = 1;
    		a23tree -> key1[0].graduates = aSchoolList[0].graduates;
    		a23tree -> key1[0].school = aSchoolList[0].school;
    		a23tree -> K1Q = 1;
    	}
		local = a23tree;
		while ( index < quantity ) {
			while ( done == 0 ) {                                    // 若此筆資料尚未就定位 
				if ( aSchoolList[index].school.compare( local -> key1[0].school ) < 0 ) { // <key1 
					if( local -> left != NULL )
					    local = local -> left;
					else
					    done = 3;
				}
				else if ( aSchoolList[index].school.compare( local -> key1[0].school ) == 0 ) // 同key1 
					done = 1;
				else {
					if ( local -> key2 != NULL) {                    // 若key2存在 
			   	 		if ( aSchoolList[index].school.compare( local -> key2[0].school ) < 0 ) { // 在兩key之間 
						   	if ( local -> down1 != NULL )
			    		    	local = local -> down1;
							else
					   			done = 3;
						}
						else if ( aSchoolList[index].school.compare( local -> key2[0].school ) == 0 ) // 同key2 
							done = 2;
						else {                                       // >key2 
					    	if ( local -> right != NULL )
    				     		local = local -> right;
							else
					    		done = 3;
						}
					}
					else {                                           // >key1且key2不存在 
					    if ( local -> right != NULL )
    				     	local = local -> right;
						else
					    	done = 3;
				    }
				}
				if ( done == 1 )                                     // 與key1同名 
				    Samekey( local, 1, index );
				if ( done == 2 )                                     // 與key2同名  
				    Samekey( local, 2, index );
				if ( done == 3 ) {                                   // 新key 
        			newkey = new Node[100];
    				newkey[0].school = aSchoolList[index].school;
    				newkey[0].serialNumber = index + 1;
    				newkey[0].graduates = aSchoolList[index].graduates;
				    NodeSplit( local, newkey, index );               // 節點分裂 
				}
			}
			done = 0;
		    index++;
		    local = a23tree;
		}
	}
	
	void PrintTheData( int aNumber ) {                               // 印出key的內容 
		int index = aNumber - 1;
		cout << aSchoolList[index].school << ", " << aSchoolList[index].department << ", ";
		cout  << aSchoolList[index].training << ", " << aSchoolList[index].level << ", ";
		cout << aSchoolList[index].graduates << endl;
	}
	
	void PrintPreOrder( treePtr root, int level ) {                  // 印出樹的所有節點(前序) 
		int index = 0, n = 1;
		if ( level > 0 )
			cout << "^^^^^^ Level = " << level << endl;
		while ( index < root -> K1Q ) {                              // 印出key1  
			cout << setw(3) << n << ": [" << root -> key1[index].serialNumber << "] ";
			PrintTheData( root -> key1[index].serialNumber );
			index++;
			n++;
		}
		if ( root -> K2Q > 0 ) {                                     // 印出key2 
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
		if ( level > 0 ) {                                           // 前序遞迴 
			cout << "~~~~~~~~~~" << endl;
			if ( root -> left != NULL )
			    PrintPreOrder( root -> left, level + 1 );
			if ( root -> down1 != NULL )
			    PrintPreOrder( root -> down1, level + 1 );
			if ( root -> right != NULL )
			    PrintPreOrder( root -> right, level + 1 );
		}
		else
			PrintPreOrder( root, level + 1 );                        // 開始印出完整的樹 
	}
	
    void InitializeList() {                                          // 初始化資料庫
	    aSchoolList.clear();
	    delete a23tree;
	    a23tree = NULL;
	    quantity = 0;
    }

    treePtr GetRoot() {                                              // 取得樹根
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

void Mission1( List &aList ) {                                       // 任務1 
    aList.Print();
	cout << "########################################################" << endl;
	cout << "Mission 1: Build a 2-3 tree" << endl;
	cout << "########################################################" << endl;
	aList.Build23tree();                                             // 建立2-3樹 
	treePtr root = aList.GetRoot();
	aList.PrintPreOrder( root, 0 );                                  // 印出2-3樹 
}

int main(int argc, char** argv) {
    Hi();
	List aList;
    int num = 1;
	while ( num != 0 ) {
		aList.InitializeList();                                      // 將先前的資料清單清空 
        cout << "Input the file number: 301, 302, ... [0]Quit" << endl << endl;
        cin >> num;
	    if ( !ReadFile( aList, num ) )                               // 若讀檔失敗 
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
