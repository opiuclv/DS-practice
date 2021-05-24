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

struct Content {                                                     // ��Ƶ��c 
	int number = 0;
	char sid[10] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }; // ��l�ư}�C 
	char sname[10] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }; 
	unsigned char score[6] = { '\0', '\0', '\0', '\0', '\0', '\0' };
	float average = 0.0;
} ;

typedef Content content;

void Hi() {
   	cout << "*****************************************" << endl;
   	cout << " On-machine Exercise                    *" << endl;
   	cout << " Mission 1: Make a binary file          *" << endl;
   	cout << " Mission 2: Hashing with Linear probing *" << endl;
  	cout << "*****************************************" << endl << endl;
}

class List {
	vector<content> aDataList;
	content * hashList = NULL;
	int quantity = 0, hashSize = 0;                                  // ����`��, hash�}�C�j�p 
public:
	bool Readtxt( string num ) {                                     // Ū����r�� 
		int getI = 0, index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in );
	    char getS[12] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }, getC;
	    content temp;
	    if ( file ) {                                                // �Y�䤣����w�ɮ� 
	    	cout << endl << "~~ A binary file has been successfully created! ~~" << endl;
            while ( !file.eof() ) {                                  // �Y�ɮש|���쵲�� 
				file.getline( getS, 12, '\t');                       // �N��tab����r���s�igetS�}�C 
				if ( getS[0] != '\0' ) {
		    		cout << "[" << quantity + 1 << "] " << getS << ", ";  
					while ( index < 10 ) {
						temp.sid[index] = getS[index];
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) ); 			 // �}�C��l�� 
					file.getline( getS, 12, '\t');
		    		cout << getS << ", "; 
		    		
					while ( index < 10 ) {
						temp.sname[index] = getS[index];
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) );
			    	while ( index < 6 )	{
	        			file.getline( getS, 12, '\t');
	        			cout << getS << " ";
						ss << getS;
						ss >> getI;
	        	    	ss.str("");
	                	ss.clear(); 
						temp.score[index] = getI;
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) );
					file.getline( getS, 12, '\n');
					cout << getS << endl;
					getF = atof(getS);
		    		temp.average = getF;
		    		quantity++;                                      // ����`�� +1 
		    		temp.number = quantity;
		    		memset( getS, '\0', strlen(getS) );
			    	aDataList.push_back(temp);                       // �s�W����Ʃ��ƲM��
				}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
	
    void SetHashRange() {											 // �]�whash�}�C�j�p 
    	int i = 2, j = quantity, x = 0;
    	while ( x == 0 ) {											 // ���̱������`�ƪ���� 
    		while ( i <= sqrt( j ) && x == 0 ) {
    			if ( j % i == 0 )
    				x = 1;
    			i++;
			}
    		if ( x == 1 ) {
    			x = 0;
    			i = 2;
    			j++;
			}
			else
				x = 1;
		}
		hashSize = j;
		hashList = new Content[hashSize];
	}

	int Sumofsid ( char num[] ) {									 // �[�`�Ǹ� 
		int i = 0, sum = 0;
		while ( i < 8 ) {
			sum = sum + num[i] - 48;
			i++;
		}
		//cout << endl << "sum:" << sum << endl;
		return sum;
	}

    void BuildHash() {												 // �إ�hash�}�C 
    	if ( hashList == NULL )										 // �]�w�}�C�j�p 
			SetHashRange();
		int index = 0, i = 0, t = 0, done = 0;
		while ( index < quantity ) {
			t = Sumofsid ( aDataList[index].sid ) % hashSize;		 // ���o�ؼ�index 
			while ( done == 0 ) {
				if ( hashList[t].sid[0] == '\0' ) {				 //  �Y��쬰�� 
					hashList[t].number = aDataList[index].number;
					strcpy( hashList[t].sid, aDataList[index].sid );
					//cout << "sid:" << hashList[t].sid << endl;
					strcpy( hashList[t].sname, aDataList[index].sname );
					//cout << "sname:" << hashList[t].sname<< endl;
					while ( i < 6 ) {
						hashList[t].score[i] = aDataList[index].score[i];
						//cout << "score:" << (int) hashList[t].score[i] << endl;
						i++;
					}
					hashList[t].average = aDataList[index].average;
					//cout << "average:" << hashList[t].average << endl;
					//cout << "final : " << key << endl; 
					done = 1;
				}
				else {												 // �w���h���U�@����� 
					t++;
					if ( t == hashSize )
						t = 0;
				}
			}
			i = 0;
			done = 0;
			index++;
		}
		aDataList.clear();
		quantity = 0;
	}
	    
    void Check() {                                                   // �ˬd��ƲM�� 
        int index = 0, i = 0;
        cout << endl << "###Check###" << endl;
    	while ( index < quantity ) {
    		cout << "[" << index + 1 << "] " << aDataList[index].sid << ", " << aDataList[index].sname << ", ";
			while ( i < 6 ) {
				cout << aDataList[index].score[i] << " ";
				i++;
			}
			i = 0;
			cout << aDataList[index].average << endl;
        	index++;
        }
	}

	void WriteBinary( string num ) {								 // ��Xbin��
		int index = 0, i = 0;
		char temp[6];
		string filename = "input" + num + ".bin";
		file.open( filename.c_str(), ios::out|ios::binary );
		while ( index < quantity ) {
			file.write( aDataList[index].sid, 10 );					 // �g�Ǹ� 
			file.write( aDataList[index].sname, 10 );				 // �g�m�W 
			for( i = 0; i < 6; i++ )
				temp[i] = aDataList[index].score[i];
			file.write( temp, 6 );								 	 // �g6�Ӥ��� 
			file.put('\0'); 
			file.put('\0'); 
			file.write( (char *) &aDataList[index].average, sizeof(float) ); // �g���� 
			index++;
		}
		file.close();
	}
	
	bool Readbin( string num ) {                                     // Ū��bin��(���) 
		InitializeList();
		int getI = 0, index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }, getC;
	    content temp;
	    if ( file ) {
	    	cout << endl << "~~ A binary file has been successfully created! ~~" << endl;
            while ( !file.eof() ) {
				file.read((char *) & getS, 10);
				if ( getS[0] != '\0' ) {
		    		cout << "[" << quantity + 1 << "] " << getS << ", ";  
					while ( index < 10 ) {
						temp.sid[index] = getS[index];
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) );
					file.read((char *) & getS, 10);
		    		cout << getS << ", "; 
					while ( index < 10 ) {
						temp.sname[index] = getS[index];
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) );
			    	while ( index < 6 )	{
	        			file.get(getC);
	        			getI = (int) getC;
	        			cout << getI << " ";
						temp.score[index] = getI;
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) );
					file.get(getC);
					file.get(getC);
					file.read((char *) &getF, sizeof(float));
					cout << getF << endl;
		    		temp.average = getF;
		    		quantity++;
		    		temp.number = quantity;
			    	aDataList.push_back(temp);
				}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
    
    void LineProbing( string n ) {									 // �ϥ�hash���� 
		int t = 0, i = 0, done = 0, steps = 1;
		char num[8];
		strcpy( num, n.c_str() );									 // �N�Ѽƪ��Ǹ��ର�}�C 
		t = Sumofsid ( num ) % hashSize;
		while ( done == 0 && steps < hashSize ) {					 // �Y�٥��N��������ˬd�@�M 
			if ( strcmp( num, hashList[t].sid ) == 0 ) {			 // ���ӾǸ� 
				cout << endl << "[" << hashList[t].number << "] " << hashList[t].sid << ", ";
				cout << hashList[t].sname << ", ";
				while ( i < 6 ) {
					cout << (int) hashList[t].score[i] << " ";
					i++;
				}
				cout << hashList[t].average << endl;
				done = 1;
			}
			else {
				t++;
				steps++;
				if ( t == hashSize )
					t = 0;
			}
		}
		if ( done == 0 )
			cout << endl << n << " does not exist!!!" << endl;
		else
			cout << endl << "Using " << steps << " steps to find it !!!" << endl;
	}
    
    void InitializeList() {                                          // ��l�Ƹ�Ʈw
	    aDataList.clear();
	    delete hashList;
	    hashList = NULL;
	    quantity = 0;
	    hashSize = 0;
    }

    int GetQuantity() {                                              // ���o����`�� 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	List aList;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		aList.InitializeList();                                      // �N���e����ƲM��M�� 
		cout << "########################################################" << endl;
		cout << "Mission 1: Transform a text file into a binary file" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 401, 402): [0]Quit" << endl;
        cin >> num;
        fileName = "input" + num + ".txt";
	    if ( !aList.Readtxt( fileName ) )                            // �YŪ�ɥ��� 
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	//aList.Check();										 // �ˬdŪ�J��� 
        	aList.WriteBinary( num );								 // ����1 
        	/*
        	fileName = "input" + num + ".bin";						 // ��binŪ�^���ˬd 
	    	if ( !aList.Readbin( fileName ) )                        // �YŪ�ɥ��� 
		    	cout << endl << fileName << " does not exist!!!" << endl << endl;
		    aList.Check();
		    */
		    cout << endl;
			cout << "========================================================" << endl;
			cout << "Mission 2: Hashing with Linear probing" << endl;
			cout << "========================================================" << endl;
		    aList.BuildHash();										 // ����2 
		    cout << endl << "Input the student number : " << endl;
		    cin >> num;
            aList.LineProbing( num );
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
