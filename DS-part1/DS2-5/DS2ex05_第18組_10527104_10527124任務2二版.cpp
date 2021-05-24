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
	vector<content> dataList; // ��ƲM�� 
	vector<head> adjList; // �۾F�}�C 
	vector<string> ccid; // cc�� 
	vector<int> ccth; // cc�� 
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
					//cout << "sid1:" << temp.sid1;
					file.read((char *) & getS, 10); // Ū�Ǹ�2
					temp.sid2 = getS;
					//cout << " sid2:" << temp.sid2 << endl;
					file.read((char *) &getF, sizeof(float)); // Ū�v�� 
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
		while ( index < quantity ) { // �ϦV�ƻs �o�����V����Ƴ���
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
			//cout << " sid2:" << temp -> sid2;
    		temp -> weight = dataList[i].weight;
			//cout << "weight:" << temp -> weight << endl;
    		i++;
			temp2 = temp;
			while ( i <= j ) { // ������ 
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
    
	void BuildAdjList() { // �إ�adjList 
		head temp;
		int index = 0, i = 0;
		ShellSort( dataList, 1, 0, dataList.size() ); // �Ƨ�sid1
		while ( index < dataList.size() ) {
			temp = new Head;
			temp -> sid1 = dataList[index].sid1;
			//cout << "sid1:" << temp -> sid1 << endl;
			i = index;
			index++;
			while ( index < quantity && dataList[index-1].sid1 == dataList[index].sid1 ) // �]�w�Ƨǡ^�p��Psid1���d��]�ƶq�^ 
			    index++;
			temp -> next = SortedBody( i, index-1 ); // ���osid2�`�I 
			adjList.push_back(temp);
		}
		cout << "Adjacency lists are written into a file..." << endl << endl;
	}
	
	void WriteAdj( string num ) { // ��Xadj��
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

	int FindAdjIndex ( string sid ) { // ���o�Psid���}�C�`�I��m 
		for ( int i = 0; i < adjList.size(); i++ )
			if ( adjList[i] -> sid1.compare(sid) == 0 )
				return i;
		return -1;
	}

	bool DFS( int index, int &num ) { // �`���u���j�M 
		body temp;
		if ( !adjList[index] -> visited ) { // �Y����ƥ����L 
			adjList[index] -> visited = true; // �ĤQ�K�ը즹�@�C 
			ccid.push_back(adjList[index] -> sid1);
			num++; // ����s�q��+1 
			if ( adjList[index] -> next != NULL ) { // �Y�٦��s�q�`�I(�٥����쩳) 
				temp = adjList[index] -> next; // ���X�U�@�Ӹ`�I 
				while ( temp != NULL ) {
					DFS( FindAdjIndex( temp -> sid2 ), num ); // �H�Psid���}�C�`�I��m�i�滼�j 
					temp = temp -> next;
				}
			}
			return true; 
		}
		return false;
	}

	void FindCC() { // �M��s�q���� 
		int num = 0; // �����C�ӳs�q���Ƶ��� 
		for ( int index = 0; index < adjList.size(); index++ )
			if ( DFS( index, num ) ) { // �s�s�q�骺�}�Y  
				ccth.push_back(num);
				num = 0;
			} 
	}
	
	void SortedCCid( int begin, int end ) { // CCid�Ƨ�(BubbleSort) 
    	int i = begin, j;
    	for ( i = begin; i < end-1; i++ ) {
    		j = i + 1;
    		for ( j = i + 1; j < end; j++ )
				if ( ccid[i] > ccid[j] )
	    			swap( ccid[i], ccid[j] );
		}
	}
	
	void WriteCC( string num ) { // ��X.cc�� 
		int j = 0, x = 1, z = 0;
		cout << "~~~ Connected Components ~~~" << endl;
		file.open( num.c_str(), ios::out );
		for ( int i = 0; i < ccth.size(); i++ ) {
			file << "{" << std::right << setw(2) << i+1 << "} Connected Component: size = " << ccth[i];
			cout << "{" << std::right << setw(2) << i+1 << "} Connected Component: size = " << ccth[i];
			SortedCCid( j, j+ccth[i] ); // CCid�Ƨ� 
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

    void InitializeList() { // ��l�Ƹ�Ʈw
	    dataList.clear();
	    adjList.clear();
	    ccid.clear();
	    ccth.clear();
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
		cout << "########################################################" << endl;
		cout << "Mission 1: Build adjacency lists" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 501, 502): [0]Quit" << endl;
        cin >> num;
        fileName = "pairs" + num + ".bin";
	    if ( !code.ReadBin( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	code.BuildAdjList(); // ����1
        	fileName = "pairs" + num + ".adj";
	    	code.WriteAdj( fileName ); // ��X.adj��  
		    cout << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Find connected components" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
		    code.FindCC(); //����2 
        	fileName = "pairs" + num + ".cc";
		    code.WriteCC( fileName ); // ��X.cc��  
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	code.InitializeList();
	return 0;
}
