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
#include <math.h>

using namespace std;

fstream file;

stringstream ss;

struct Content {
	string sid1;
	string sid2;
	float weight = 0.0;
} ;

typedef Content content;

struct Body {
	string sid2;
	float weight = -1.0;
	Body * next = NULL;
} ;

typedef Body * body;

struct Head {
	string sid1;
	bool visited = false;
	Body * next = NULL;
} ;

typedef Head * head;

void Hi() {
   	cout << "***************************************" << endl;
   	cout << " On-machine Exercise                  *" << endl;
   	cout << " Mission 1: Build adjacency lists     *" << endl;
   	cout << " Mission 2: Find connected components *" << endl;
  	cout << "***************************************" << endl << endl;
}

class Code {
	vector<content> dataList; // 資料清單 
	vector<head> adjList; // 相鄰陣列 
	vector<string> ccid; // cc表 
	vector<int> ccth; // cc數 
	int quantity = 0; // 資料總數 
public:
	bool ReadBin( string num ) { // 讀bin檔 
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12];
	    content temp;
	    if ( file ) {
            while ( !file.eof() ) {
				file.read((char *) & getS, 10); // 讀學號1
				if ( getS[0] != '\0' ) { 
					temp.sid1 = getS;
					//cout << "sid1:" << temp.sid1;
					file.read((char *) & getS, 10); // 讀學號2
					temp.sid2 = getS;
					//cout << " sid2:" << temp.sid2 << endl;
					file.read((char *) &getF, sizeof(float)); // 讀權重 
		    		temp.weight = getF;
		    		quantity++;
		    		strcpy(getS,"");
			    	dataList.push_back(temp);
				}
			}
		}
		file.close();
		if ( quantity > 0 )
			cout << "<<< " << quantity << " pairs => ";
	    else
	    	return false;
		while ( index < quantity ) { // 反向複製 這樣雙向的資料都有
			temp.sid1 = dataList[index].sid2;
			//cout << "sid1:" << temp.sid1;
			temp.sid2 = dataList[index].sid1;
			//cout << " sid2:" << temp.sid2 << endl;
			temp.weight = dataList[index].weight;
			dataList.push_back(temp);
			index++;
		}
		quantity = quantity + index;
		cout << quantity << " nodes >>>" << endl << endl;
	    return true;
    }
     
    void ShellSort( vector<content> &aList, int x, int begin, int end ) { // Shell排序 
    	int half = end/2, k, j, i;
    	while ( half > begin ) {
    		k = begin;
    		while ( k < half ) {
    			j = k + half;
    			while ( j < end ) {
    				i = j - half;
    				while ( i >= k ) {
    					if ( x == 1 && aList[i].sid1.compare(aList[i+half].sid1) > 0 ) // sid1比較 
	    					swap( aList[i], aList[i+half] );
	    				else if ( x == 2 && dataList[i].weight < dataList[i+half].weight ) // sid2比較 
	    					swap( aList[i], aList[i+half] );
	    				else
	    					break;
    					i = i - half;
					}
					j = j + half;
				}
    			k++;
			}
			half = half / 2;
		}
	}

    body SortedBody( int i, int j ) { // sid2排序並回傳接好的串列 
    	body temp = new Body, temp2;
    	int a = i, b;
    	if ( i == j ) { // 若只有一筆 
    		temp -> sid2 = dataList[i].sid2;
    		temp -> weight = dataList[i].weight;
		}
		else {
			ShellSort( dataList, 2, a, j ); // 排序部分sid2 
    		temp -> sid2 = dataList[i].sid2;
			//cout << " sid2:" << temp -> sid2;
    		temp -> weight = dataList[i].weight;
			//cout << "weight:" << temp -> weight << endl;
    		i++;
			temp2 = temp;
			while ( i <= j ) { // 接指標 
	    		temp2 -> next = new Body;
	    		temp2 = temp2 -> next;
	    		temp2 -> sid2 = dataList[i].sid2;
				//cout << " sid2:" << temp2 -> sid2;
	    		temp2 -> weight = dataList[i].weight;
				//cout << "weight:" << temp2 -> weight << endl;
	    		i++;
			}
		}
		return temp;
	} 
    
	void BuildAdjList() { // 建立adjList 
		head temp;
		int index = 0, i = 0;
		ShellSort( dataList, 1, 0, dataList.size() ); // 排序sid1
		while ( index < dataList.size() ) {
			temp = new Head;
			temp -> sid1 = dataList[index].sid1;
			//cout << "sid1:" << temp -> sid1 << endl;
			i = index;
			index++;
			while ( index < quantity && dataList[index-1].sid1 == dataList[index].sid1 ) // （已排序）計算同sid1的範圍（數量） 
			    index++;
			temp -> next = SortedBody( i, index-1 ); // 取得sid2節點 
			adjList.push_back(temp);
		}
		cout << "Adjacency lists are written into a file..." << endl << endl;
	}
	
	void WriteAdj( string num ) { // 輸出adj檔
		int index = 0, i = 1, j = 0;
		body temp;
		file.open( num.c_str(), ios::out );
		file << endl;
		while ( index < adjList.size() ) {
			file << "[" << setw(3) << index+1 << "] ";
			file << adjList[index] -> sid1 << ":";
			temp = adjList[index] -> next;
			while ( temp != NULL ) {
				for ( ; i > j*5; j++ )
					file << endl;
				file << "\t(" << setw(2) << i << ") ";
				file << temp -> sid2 << ",";
				file << setw(5) << temp -> weight;
				temp = temp -> next;
				i++;
			}
			file << endl;
			index++;
			i = 1;
			j = 0;
		}
		file << endl << "<<< There are " << quantity << " nodes in total. >>>" << endl;
		file.close();
		cout << "<<< There are " << quantity << " nodes in total. >>>" << endl << endl;
	}

	int FindAdjIndex ( string sid ) { // 取得同sid的陣列節點位置 
		for ( int i = 0; i < adjList.size(); i++ )
			if ( adjList[i] -> sid1.compare(sid) == 0 )
				return i;
		return -1;
	}

	bool DFS( int index, int &num ) { // 深度優先搜尋 
		body temp;
		if ( !adjList[index] -> visited ) { // 若此資料未走過 
			adjList[index] -> visited = true; // 第十八組到此一遊 
			ccid.push_back(adjList[index] -> sid1);
			num++; // 此圈連通數+1 
			if ( adjList[index] -> next != NULL ) { // 若還有連通節點(還未走到底) 
				temp = adjList[index] -> next; // 走訪下一個節點 
				while ( temp != NULL ) {
					DFS( FindAdjIndex( temp -> sid2 ), num ); // 以同sid的陣列節點位置進行遞迴 
					temp = temp -> next;
				}
			}
			return true; 
		}
		return false;
	}

	void FindCC() { // 尋找連通成分 
		int num = 0; // 紀錄每個連通圈資料筆數 
		for ( int index = 0; index < adjList.size(); index++ )
			if ( DFS( index, num ) ) { // 新連通圈的開頭  
				ccth.push_back(num);
				num = 0;
			} 
	}
	
	void SortedCCid( int begin, int end ) { // CCid排序(BubbleSort) 
    	int i = begin, j;
    	for ( i = begin; i < end-1; i++ ) {
    		j = i + 1;
    		for ( j = i + 1; j < end; j++ )
				if ( ccid[i] > ccid[j] )
	    			swap( ccid[i], ccid[j] );
		}
	}
	
	void WriteCC( string num ) { // 輸出.cc檔 
		int j = 0, x = 1, z = 0;
		cout << "~~~ Connected Components ~~~" << endl;
		file.open( num.c_str(), ios::out );
		for ( int i = 0; i < ccth.size(); i++ ) {
			file << "{" << std::right << setw(2) << i+1 << "} Connected Component: size = " << ccth[i];
			cout << "{" << std::right << setw(2) << i+1 << "} Connected Component: size = " << ccth[i];
			SortedCCid( j, j+ccth[i] ); // CCid排序 
			while ( x <= ccth[i] ) {
				if ( x == 5*z+1  ) {
					file << endl << " 	";
					cout << endl << "        ";
					z++;
				}
				file << "(" << std::right << setw(3) << x << ") " << std::left << setw(10) << ccid[j];
				cout << "(" << std::right << setw(3) << x << ") " << std::left << setw(10) << ccid[j];
				x++;
				j++;
			}
			x = 1;
			z = 0;
			file << endl << endl;
			cout << endl << endl;
		}
		file.close();
	}

    void InitializeList() { // 初始化資料庫
	    dataList.clear();
	    adjList.clear();
	    ccid.clear();
	    ccth.clear();
	    quantity = 0;
    }

    int GetQuantity() { // 取得資料總數 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	Code code;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		code.InitializeList(); // 將先前的資料清單清空 
		cout << "########################################################" << endl;
		cout << "Mission 1: Build adjacency lists" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 501, 502): [0]Quit" << endl;
        cin >> num;
        fileName = "pairs" + num + ".bin";
	    if ( !code.ReadBin( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	code.BuildAdjList(); // 任務1
        	fileName = "pairs" + num + ".adj";
	    	code.WriteAdj( fileName ); // 輸出.adj檔  
		    cout << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Find connected components" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
		    code.FindCC(); //任務2 
        	fileName = "pairs" + num + ".cc";
		    code.WriteCC( fileName ); // 輸出.cc檔  
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	code.InitializeList();
	return 0;
}
