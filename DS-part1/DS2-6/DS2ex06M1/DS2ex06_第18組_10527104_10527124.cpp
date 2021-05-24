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

void Hi() {
   	cout << "***********************************" << endl;
   	cout << " On-machine Exercise              *" << endl;
   	cout << " Mission 1: Minimum Spanning Tree *" << endl;
   	cout << " Mission 2: Shortest Distances    *" << endl;
  	cout << "***********************************" << endl << endl;
}

class Code {
	vector<content> dataList; // ��ƲM�� 
	vector<head> adjList; // �۾F�}�C 
	vector<cc> ccList; // cc�� 
	vector<queue> wQ;
	int quantity = 0; // ����`�� 
public:
	bool ReadBin( string num ) { // Ūbin�� 
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12];
	    content temp;
	    if ( file ) {
            while ( !file.eof() ) {
				file.read((char *) & getS, 10); // Ū�Ǹ�1
				if ( getS[0] != '\0' ) { 
					temp.sid1 = getS;
					file.read((char *) & getS, 10); // Ū�Ǹ�2
					temp.sid2 = getS;
					file.read((char *) &getF, sizeof(float)); // Ū�v�� 
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
		while ( index < quantity ) { // �ϦV�ƻs 
			temp.sid1 = dataList[index].sid2;
			temp.sid2 = dataList[index].sid1;
			temp.weight = dataList[index].weight;
			dataList.push_back(temp);
			index++;
		}
		quantity = quantity + index;
	    return true;
    }
     
    void ShellSort( vector<content> &aList, int x, int begin, int end ) { // Shell�Ƨ� 
    	int half = end/2, k, j, i;
    	while ( half > begin ) {
    		k = begin;
    		while ( k < half ) {
    			j = k + half;
    			while ( j < end ) {
    				i = j - half;
    				while ( i >= k ) {
    					if ( x == 1 && aList[i].sid1.compare(aList[i+half].sid1) > 0 ) // sid1��� 
	    					swap( aList[i], aList[i+half] );
	    				else if ( x == 2 && dataList[i].weight < dataList[i+half].weight ) // sid2��� 
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

    body SortedBody( int i, int j ) { // sid2�ƧǨæ^�Ǳ��n����C 
    	body temp = new Body, temp2;
    	int a = i, b;
    	if ( i == j ) { // �Y�u���@�� 
    		temp -> sid2 = dataList[i].sid2;
    		temp -> weight = dataList[i].weight;
		}
		else {
			ShellSort( dataList, 2, a, j ); // �Ƨǳ���sid2 
    		temp -> sid2 = dataList[i].sid2;
    		temp -> weight = dataList[i].weight;
    		i++;
			temp2 = temp;
			while ( i <= j ) { // ������ 
	    		temp2 -> next = new Body;
	    		temp2 = temp2 -> next;
	    		temp2 -> sid2 = dataList[i].sid2;
	    		temp2 -> weight = dataList[i].weight;
	    		i++;
			}
		}
		return temp;
	} 
    
	void BuildAdjList() { // �إ�adjList 
		head temp;
		int index = 0, i = 0;
		ShellSort( dataList, 1, 0, dataList.size() ); // �Ƨ�sid1
		while ( index < dataList.size() ) {
			temp = new Head;
			temp -> sid1 = dataList[index].sid1;
			i = index;
			index++;
			while ( index < quantity && dataList[index-1].sid1 == dataList[index].sid1 ) // �p��Psid1���d�� 
			    index++;
			temp -> next = SortedBody( i, index-1 ); // ���osid2�`�I 
			adjList.push_back(temp);
		}
		cout << endl;
	}

	int FindAdjIndex ( string sid ) { // ���o�Psid���}�C�`�I��m 
		for ( int i = 0; i < adjList.size(); i++ )
			if ( adjList[i] -> sid1.compare(sid) == 0 )
				return i;
		return -1;
	}

	void DFS( int index, int &num ) { // �`���u���j�M 
		body temp;
		if ( adjList[index] -> visited != 1 ) { // �Y����ƥ����L 
			adjList[index] -> visited = 1; // �ĤQ�K�ը즹�@�C 
			ccList[ccList.size()-1].ccid.push_back(adjList[index] -> sid1);
			num++; // ����s�q��+1 
			if ( adjList[index] -> next != NULL ) { // �Y�٦��s�q�`�I(�٥����쩳) 
				temp = adjList[index] -> next; // ���X�U�@�Ӹ`�I 
				while ( temp != NULL ) {
					DFS( FindAdjIndex( temp -> sid2 ), num ); // �H�Psid���}�C�`�I��m�i�滼�j 
					temp = temp -> next;
				}
			}
		}
	}
	
	void FindCC() { // �M��s�q���� 
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
	
	void SortedQueue() {
    	int begin = 0, half = wQ.size()/2, k, j, i;
    	while ( half > begin ) {
    		k = begin;
    		while ( k < half ) {
    			j = k + half;
    			while ( j < wQ.size()) {
    				i = j - half;
    				while ( i >= k ) {
    					if ( wQ[i].weight > wQ[i+half].weight ) // sid1��� 
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
	
    void Prim( int index, int &t ) { // �`���u���j�M 
		body temp;
		queue aQueue;
		int count = 0, i = 0, x= 0, j = 0;
		float num = 0.0;
		if ( adjList[index] -> visited != 2 ) { // �Y����ƥ����L 
			adjList[index] -> visited = 2;
			while ( count < ccList[t-1].ccth-1 ) {
				temp = adjList[index] -> next;
				while ( temp != NULL ) {
					aQueue.place = FindAdjIndex( temp -> sid2 );
					aQueue.weight = temp -> weight;
					wQ.push_back(aQueue);
					temp = temp -> next;
				}
				SortedQueue();
				while ( x == 0 ) {
					if ( adjList[wQ[0].place] -> visited != 2 ) {
						index = wQ[0].place;
						num = num + wQ[0].weight;
						adjList[index] -> visited = 2;
						count++;
						x = 1;
					}
					wQ.erase(wQ.begin()+0);
				}
				x = 0;
			}
			ccList[t-1].minsp = num;
			t++;
			wQ.clear();
		}
	}
		
    void BuildMinST() {
		int t = 1, index;
		float num = 0; // �����C�ӳs�q���Ƶ��� 
		for ( index = 0; index < adjList.size(); index++ )
			Prim( index, t );
	}
	
	void SortedCCList() { // CCList�Ƨ�(BubbleSort) 
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
	
	void Print() {
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

    void InitializeList() { // ��l�Ƹ�Ʈw
	    dataList.clear();
	    adjList.clear();
	    ccList.clear();
	    wQ.clear();
	    quantity = 0;
    }

    int GetQuantity() { // ���o����`�� 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	Code code;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		code.InitializeList(); // �N���e����ƲM��M�� 
	    cout << "Input the file number (e.g., 601, 602): [0]Quit" << endl;
        cin >> num;
        fileName = "pairs" + num + ".bin";
	    if ( !code.ReadBin( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	code.BuildAdjList();
		    code.FindCC(); 
			code.BuildMinST(); // ����1
		    code.Print(); 
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Shortest Distances" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
			//����2 
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	code.InitializeList();
	return 0;
}
