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
	int visited = 0;
	Body * next = NULL;
} ;

typedef Head * head;

struct CC {
	vector<string> ccid;
	int ccth = 0;
	float minsp = 0.0;
} ;

typedef CC cc;

struct Queue {
	int place = -1;
	float weight = -1.0;
} ;

typedef Queue queue;

struct Distances {
	string sid = "\0";
	bool visited = false;
	float dw = 0.0;
} ;

typedef Distances distances;

void Hi() {
   	cout << "***********************************" << endl;
   	cout << " On-machine Exercise              *" << endl;
   	cout << " Mission 1: Minimum Spanning Tree *" << endl;
   	cout << " Mission 2: Shortest Distances    *" << endl;
  	cout << "***********************************" << endl << endl;
}

class Code {
	vector<content> dataList; // 資料清單 
	vector<head> adjList; // 相鄰陣列 
	vector<cc> ccList; // cc表 
	vector<queue> wQ; // 權重優先佇列 
	int quantity = 0; // 資料總數 
public:

// ================================= 上週讀檔 ＆ AdjList =================================================

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
					file.read((char *) & getS, 10); // 讀學號2
					temp.sid2 = getS;
					file.read((char *) &getF, sizeof(float)); // 讀權重 
		    		temp.weight = getF;
		    		quantity++;
		    		strcpy(getS,"");
			    	dataList.push_back(temp);
				}
			}
		}
		file.close();
		if ( quantity == 0 )
	    	return false;
		while ( index < quantity ) { // 反向複製 
			temp.sid1 = dataList[index].sid2;
			temp.sid2 = dataList[index].sid1;
			temp.weight = dataList[index].weight;
			dataList.push_back(temp);
			index++;
		}
		quantity = quantity + index;
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
    		temp -> weight = dataList[i].weight;
    		i++;
			temp2 = temp;
			while ( i <= j ) { // 接指標 
	    		temp2 -> next = new Body;
	    		temp2 = temp2 -> next;
	    		temp2 -> sid2 = dataList[i].sid2;
	    		temp2 -> weight = dataList[i].weight;
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
			i = index;
			index++;
			while ( index < quantity && dataList[index-1].sid1 == dataList[index].sid1 ) // 計算同sid1的範圍 
			    index++;
			temp -> next = SortedBody( i, index-1 ); // 取得sid2節點 
			adjList.push_back(temp);
		}
		cout << endl;
	}

// ================================= 上週DFS ==========================================================

	void FindCC() { // 尋找連通成分 
    	int num = 0;
    	cc temp;
		for ( int index = 0; index < adjList.size(); index++ )
			if ( adjList[index] -> visited != 1 ) {
				ccList.push_back(temp);
				DFS( index, num );
				ccList[ccList.size()-1].ccth = num;
				num = 0;
			}
	}

	void DFS( int index, int &num ) { // 深度優先搜尋 
		body temp;
		if ( adjList[index] -> visited != 1 ) { // 若此資料未走過 
			adjList[index] -> visited = 1; // 第十八組到此一遊 
			ccList[ccList.size()-1].ccid.push_back(adjList[index] -> sid1);
			num++; // 此成分連通數+1 
			if ( adjList[index] -> next != NULL ) { // 若還有連通節點(還未走到底) 
				temp = adjList[index] -> next; // 走訪下一個節點 
				while ( temp != NULL ) {
					DFS( FindAdjIndex( temp -> sid2 ), num ); // 以同sid的陣列節點位置進行遞迴 
					temp = temp -> next;
				}
			}
		}
	}

// ================================= 本週任務一 Prim最小生成樹 =================================================

    void BuildMinST() { // 建立最小生成樹 
		int t = 1, index;
		float num = 0; // 紀錄每個連通成分的資料筆數 
		for ( index = 0; index < adjList.size(); index++ )
			Prim( index, t );
	}

    void Prim( int index, int &t ) { // Prim演算法 
		body temp;
		queue aQueue;
		int count = 0, i = 0, x= 0, j = 0;
		float num = 0.0;
		if ( adjList[index] -> visited != 2 ) { // 若此資料未走過 
			adjList[index] -> visited = 2;
			while ( count < ccList[t-1].ccth-1 ) { // 邊數不足 
				temp = adjList[index] -> next;
				while ( temp != NULL ) { // 將可選擇的邊放進佇列 
					aQueue.place = FindAdjIndex( temp -> sid2 );
					aQueue.weight = temp -> weight;
					wQ.push_back(aQueue);
					temp = temp -> next;
				}
				SortedQueue(); // 佇列內部排序(小->大) 
				while ( x == 0 ) { // 取出未走訪且最小者(第一個未走訪者)
					if ( adjList[wQ[0].place] -> visited != 2 ) { // 未走訪 
						index = wQ[0].place;
						num = num + wQ[0].weight;
						adjList[index] -> visited = 2;
						count++;
						x = 1;
					}
					wQ.erase(wQ.begin()+0); // 自佇列中刪除 
				}
				x = 0;
			}
			ccList[t-1].minsp = num; // 紀錄生成樹值 
			t++;
			wQ.clear();
		}
	}

	void SortedQueue() {
    	int begin = 0, half = wQ.size()/2, k, j, i;
    	while ( half > begin ) {
    		k = begin;
    		while ( k < half ) {
    			j = k + half;
    			while ( j < wQ.size()) {
    				i = j - half;
    				while ( i >= k ) {
    					if ( wQ[i].weight > wQ[i+half].weight ) // sid1比較 
	    					swap( wQ[i], wQ[i+half] );
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
		
	int FindAdjIndex ( string sid ) { // 取得同sid的陣列節點位置 
		for ( int i = 0; i < adjList.size(); i++ )
			if ( adjList[i] -> sid1.compare(sid) == 0 )
				return i;
		return -1;
	}

// ================================= 本週任務二 Dijkstra Shortest Distance =================================

	void FindSD( string fileName ) { // 尋找最短路徑 
		int begin, z;
		string num = "1";
		while ( num.compare("0") != 0 ) {
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Shortest Distances" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			z = 0;
			for ( int i = 0; i < adjList.size(); i++ ) { // 印出所有的id 
				if ( i == 5*z  ) {
					cout << endl;
					z++;
				}
				cout << std::right << setw(10) << adjList[i] -> sid1;
			}
			cout << endl << endl << "Input a student id from the above:" << endl;
			cin >> num;
			begin = FindAdjIndex( num );
			if ( begin != -1 ) // id存在 
				Dijkstra( begin, num, fileName );
			else
				cout << endl << num << " does not exist!!!" << endl << endl;
			cout << "[0]Quit or [Any other key]continue?" << endl; 
			cin >> num;
		}
	}	

	void Dijkstra( int begin, string num, string fileName ) { // Dijkstra演算法 
		vector<distances> sdList; // 最小生成樹陣列 
		distances t;
		body temp;
		int i = 0, j = begin, index = 0, finished = 1, sdth = GetCCth( num ), last = 0;
		for ( index = 0; index < sdth; index++ ) // sd陣列初始化 
			sdList.push_back(t);
		sdList[0].sid = num; // 填入原點 
		sdList[0].visited = true;
		while ( finished < sdth ) { // 若還有點未走訪 
			temp = adjList[j] -> next;
			index = 1;
			while ( temp != NULL ) { // 檢查相鄰節點 
				if ( temp -> sid2.compare( num ) == 0 ) // 同原點者跳過 
					temp = temp -> next;
				else {
					if ( sdList[index].sid.compare("\0") == 0 ) { // 初次走訪 
						sdList[index].sid = temp -> sid2;
						sdList[index].dw = temp -> weight + sdList[last].dw; // 路徑長累加 
						temp = temp -> next;
						index = 1;
					}
					else if ( temp -> sid2.compare( sdList[index].sid ) == 0 ) { // 二次走訪 
						if ( ( sdList[last].dw + temp -> weight ) < sdList[index].dw ) // 路長比較 
							sdList[index].dw = sdList[last].dw + temp -> weight; // 更新路徑長 
						temp = temp -> next;
						index = 1;
					}
					else // 檢查sd陣列其他節點 
						index++;
				}
			}
			last = 0;
			for ( index = 1; index < sdth; index++ ) // 尋找距離最短且未走訪者 
				if ( sdList[index].visited == false && sdList[index].sid.compare("\0") != 0 )
					if ( last == 0 || sdList[last].dw > sdList[index].dw )
						last = index;
			sdList[last].visited = true; // 標記此點 
			j = FindAdjIndex( sdList[last].sid ); // 取得其在adj陣列的位置 
			finished++;	// 完成數+1 
		}
	    for ( i = 1; i < sdList.size()-1; i++ ) // 排序路徑sid(BubbleSort) 
	    	for ( j = i + 1; j < sdList.size(); j++ )
				if ( sdList[i].sid.compare( sdList[j].sid ) > 0 )
		    		swap( sdList[i], sdList[j] );
		WriteDis( sdList, fileName ); // 輸出dis檔 
		sdList.clear();
	}
	
	int GetCCth( string num ) { // 取得此id所屬連通成分的大小 
		for ( int i = 0; i < ccList.size(); i++ )
			for ( int j = 0; j < ccList[i].ccid.size(); j++ )
				if ( num.compare( ccList[i].ccid[j] ) == 0 )
					return ccList[i].ccth;
		return -1;
	}	
	
	void WriteDis( vector<distances> sdList, string fileName ) { // 輸出dis檔 
		int z = 0;
		file.open( fileName.c_str(), ios::app );
		file << endl << "origin: " << sdList[0].sid;
		for ( int index = 1; index < sdList.size(); index++ ) {
			if ( index == 5*z + 1 ) {
				file << endl;
				z++;
			}
			file << "(" << std::right << setw(2) << index << ") 	" << sdList[index].sid << ", " << fixed << setprecision(2) << sdList[index].dw << "	";
		}
		file << endl;
		file.close();
		cout << endl << "~~~ Shortest Distances are computed! ~~~" << endl << endl;
	}
	


// ============================================== 排序並印出資料 =============================================

	void SortedCCList() { // CCList排序(BubbleSort) 
    	int i = 0, j, k;
    	for ( k = 0; k < ccList.size(); k++ )
	    	for ( i = 0; i < ccList[k].ccid.size()-1; i++ )
	    		for ( j = i + 1; j < ccList[k].ccid.size(); j++ )
					if ( ccList[k].ccid[i] >ccList[k].ccid[j] )
		    			swap( ccList[k].ccid[i], ccList[k].ccid[j] );
	    for ( i = 0; i < ccList.size()-1; i++ )
	    	for ( j = i + 1; j < ccList.size(); j++ )
				if ( ccList[i].ccth <= ccList[j].ccth )
		   			swap( ccList[i], ccList[j] );
	}
	
	void Print() { // 印出相鄰串列和最小生成樹值 
		int i = 0, j = 0, x = 1, z = 0;
		cout << "~~~ Connected Components ~~~" << endl;
		SortedCCList();
		for ( i = 0; i < ccList.size(); i++ ) {
			cout << "{" << std::right << setw(2) << i+1 << "} Connected Component: size = " << ccList[i].ccth;
			while ( x <= ccList[i].ccth ) {
				if ( x == 5*z+1  ) {
					cout << endl << "        ";
					z++;
				}
				cout << "(" << std::right << setw(3) << x << ") " << std::left << setw(10) << ccList[i].ccid[j];
				x++;
				j++;
			}
			x = 1;
			z = 0;
			j = 0;
			cout << endl << endl;
		}
		cout << "########################################################" << endl;
		cout << "Mission 1: Minimum Spanning Trees" << endl;
		cout << "########################################################" << endl << endl;
		for ( i = 0; i < ccList.size(); i++ )
			cout << "The MST cost of connected component {" << std::right << setw(2) << i+1 << "} = " << fixed << setprecision(4) << ccList[i].minsp << endl << endl;
	}

// ============================================== 其他函式 =============================================
    void InitializeList() { // 初始化資料庫
	    dataList.clear();
	    adjList.clear();
	    ccList.clear();
	    wQ.clear();
	    quantity = 0;
    }

    int GetQuantity() { // 取得資料總數 
	    return quantity;
	}
};

int main(int argc, char** argv) {
	Code code;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
    	Hi();
		code.InitializeList(); // 將先前的資料清單清空 
	    cout << "Input the file number (e.g., 601, 602): [0]Quit" << endl;
        cin >> num;
        fileName = "pairs" + num + ".bin";
	    if ( !code.ReadBin( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	code.BuildAdjList();
		    code.FindCC(); 
			code.BuildMinST(); // 任務1
		    code.Print();
		    fileName = "pairs" + num + ".dis";
			code.FindSD( fileName ); //任務2
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
		}
    }
	code.InitializeList();
	return 0;
}
