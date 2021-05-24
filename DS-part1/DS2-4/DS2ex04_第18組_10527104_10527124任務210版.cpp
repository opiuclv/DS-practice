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

struct Content { // ��Ƶ��c 
	int key = 0;
	int compares = 0;
	int sid = -1;
	char sname[10];
	int score[6];
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
	vector<content> aDataList; // ��ƲM�� 
	content * hashList = NULL; // hash�}�C 
	int quantity = 0, hashSize = 0; // ����`��, hash�}�C�j�p 
public:
	bool Readtxt( string num ) { // Ū����r�� 
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in );
	    char getS[12], getC;
	    content temp;
	    if ( file ) { // �Y�䤣����w�ɮ� 
	    	cout << endl << "~~ A binary file has been successfully created! ~~" << endl;
            while ( !file.eof() ) { // �Y�ɮש|���쵲�� 
				file.getline( getS, 12, '\t'); // �N��tab����r��Ū�igetS�}�C 
				if ( getS[0] != '\0' ) {
		    		cout << "[" << quantity + 1 << "] " << getS << " ";
					temp.sid = atoi(getS);
					file.getline( getS, 12, '\t');
		    		cout << getS << " "; 
					while ( index < 10 ) {
						temp.sname[index] = getS[index];
						index++;
					}
					index = 0;
			    	while ( index < 6 )	{
	        			file.getline( getS, 12, '\t');
	        			cout << getS << " ";
						temp.score[index] = atoi(getS);
						index++;
					}
					index = 0;
					file.getline( getS, 12, '\n');
					cout << getS << endl;
					getF = atof(getS);
		    		temp.average = getF;
		    		quantity++; // ����`�� +1 
		    		strcpy( getS,"" );
			    	aDataList.push_back(temp); // �s�W����Ʃ��ƲM��
				}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
	
    void SetHashRange() { // �]�whash�}�C�j�p 
    	int i = 2, j = quantity * 1.2 , x = 0;
    	while ( x == 0 ) { // ���̱������`��1.2������� 
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
 
	int GetKey( int num ) { // ���o�l�Ƨ@Key 
		int i = 1, key = 0;
		char temp[10];
		sprintf ( temp, "%d", num ); // �N�Ǹ��ର�r���}�C 
		key = (int)temp[0];
		while ( i < strlen(temp) ) {
			key = (key * (int)temp[i]) % hashSize;
			i++;
		}
		return key;
	}
	
    void BuildHash() { // �إ�hash�}�C 
    	if ( hashSize == 0 ) // �]�w�}�C�j�p 
			SetHashRange();
		int index = 0, t = 0, done = 0, start = 0, steps = 1;
		while ( index < quantity ) {
			t = GetKey( aDataList[index].sid ); // ���o�ؼ�index 
			start = t; // �����_�I 
			while ( done == 0 ) {
				if ( hashList[t].sid == -1 ) { //  �Y��쬰�� 
					hashList[t].key = start;
					hashList[t].compares = steps; // �x�s�������(�B��) 
					hashList[t].sid = aDataList[index].sid;
					strcpy( hashList[t].sname, aDataList[index].sname );
					hashList[t].average = aDataList[index].average;
					done = 1;
				}
				else { // �w���h�ˬd�U�����
					// t = start + steps * steps; // ����k 
					t = start + steps; // �u�ʪk 
					steps++;
					if ( t >= hashSize ) // �L�Y�F
						t = t - hashSize; // �q�Y�}�l(�D�_�I) 
				}
			}
			done = 0;
			steps = 1;
			index++;
		}
		aDataList.clear();
	}
	
	
	void WriteBinary( string num ) { // ��Xbin��
		int index = 0, i = 0;
		char temp[12];
		string filename = "input" + num + ".bin";
		file.open( filename.c_str(), ios::out|ios::binary );
		while ( index < quantity ) {
			sprintf ( temp, "%d", aDataList[index].sid );
			file.write( temp, 10 ); // �g�Ǹ� 
			file.write( aDataList[index].sname, 10 ); // �g�m�W 
			for( i = 0; i < 6; i++ )
				temp[i] = (unsigned char) aDataList[index].score[i];
			file.write( temp, 6 ); // �g6�Ӥ��� 
			file.put('\0'); // �ɪť� 
			file.put('\0'); 
			file.write( (char *) &aDataList[index].average, sizeof(float) ); // �g���� 
			index++;
		}
		file.close();
	}
	
	
	bool Readbin( string num ) { // Ū�^bin�� 
		InitializeList();
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12], getC;
	    content temp;
	    if ( file ) {
            while ( !file.eof() ) {
				file.read((char *) & getS, 10); // Ū�Ǹ� 
				if ( getS[0] != '\0' ) { 
					temp.sid = atoi(getS);
					file.read((char *) & getS, 10); // Ū�m�W 
					while ( index < 6 ) {
						temp.sname[index] = getS[index];
						index++;
					}
					index = 0;
			    	while ( index < 6 )	{ // Ū6�Ӥ��� 
	        			file.get(getC);
						temp.score[index] = (int)getC;
						index++;
					}
					index = 0;
					file.get(getC); // Ū���ť� 
					file.get(getC);
					file.read((char *) &getF, sizeof(float)); // Ū���� 
		    		temp.average = getF;
		    		quantity++;
		    		strcpy(getS,"");
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

	void WriteTab( string num ) { // ��Xtab��
		int index = 0, steps = 0, fw = -1;
		float usf = 0.0, scf = 0.0; // ���s�b�ȻP�{�s�Ȫ�������� 
		string filename = "input" + num + ".tab";
		file.open( filename.c_str(), ios::out );
		file << " --- Hash Table --- by Linear probing" << endl;
		while ( index < hashSize ) {
			file << "[" << setw(3) << index << "]";
			if ( hashList[index].sid != -1 ) { // �����
				file << setw(11) << hashList[index].key << ","; // �g�_�I 
				file << setw(11) << hashList[index].sid << ","; // �g�Ǹ� 
				file << setw(11) << hashList[index].sname << ","; // �g�m�W 
				file << setw(11) << hashList[index].average; // �g���� 
				scf = scf + hashList[index].compares; // �{�s�Ȥ�����Ʋ֥[
				steps++; // �s���ƼƲ֥[ 
			}
			else {
				if ( fw == -1 ) // �����Ĥ@�ӪŦ쪺��m 
					fw = index;
				while ( steps > 0 ) { // ���s�b�Ȥ�����Ʋ֥[ 
					usf = usf + steps;
					steps--;
				}
			}
			file << endl;
			index++;
		}
		file.close();
		while ( steps > 0 ) { // ���ƳѾlsteps
			usf = usf + steps + fw;
			steps--;
		}
		cout << endl << "~~ The hash table has been successfully created! ~~" << endl << endl;
		usf = usf / hashSize; // ���o���� 
		cout << "unsuccessful search: " << usf << " comparisons on average" << endl << endl;
 		scf = scf / quantity;
		cout << "successful search: " << scf << " comparisons on average" << endl << endl;
	}
	
    void InitializeList() { // ��l�Ƹ�Ʈw
	    aDataList.clear();
	    delete hashList;
	    hashList = NULL;
	    quantity = 0;
	    hashSize = 0;
    }

    int GetQuantity() { // ���o����`�� 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	List aList;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		aList.InitializeList(); // �N���e����ƲM��M�� 
		cout << "########################################################" << endl;
		cout << "Mission 1: Transform a text file into a binary file" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 401, 402): [0]Quit" << endl;
        cin >> num;
        fileName = "input" + num + ".txt";
	    if ( !aList.Readtxt( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	aList.WriteBinary( num ); // ����1
        	fileName = "input" + num + ".bin";
	    	aList.Readbin( fileName );
		    cout << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Build a hash table by linear probing" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		    aList.BuildHash(); // ����2 
			aList.WriteTab( num );
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
