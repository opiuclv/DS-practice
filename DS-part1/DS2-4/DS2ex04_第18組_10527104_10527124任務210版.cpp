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

struct Content { // 資料結構 
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
	vector<content> aDataList; // 資料清單 
	content * hashList = NULL; // hash陣列 
	int quantity = 0, hashSize = 0; // 資料總數, hash陣列大小 
public:
	bool Readtxt( string num ) { // 讀取文字檔 
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in );
	    char getS[12], getC;
	    content temp;
	    if ( file ) { // 若找不到指定檔案 
	    	cout << endl << "~~ A binary file has been successfully created! ~~" << endl;
            while ( !file.eof() ) { // 若檔案尚未到結尾 
				file.getline( getS, 12, '\t'); // 將到tab為止的字元讀進getS陣列 
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
		    		quantity++; // 資料總數 +1 
		    		strcpy( getS,"" );
			    	aDataList.push_back(temp); // 新增筆資料於資料清單
				}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
	
    void SetHashRange() { // 設定hash陣列大小 
    	int i = 2, j = quantity * 1.2 , x = 0;
    	while ( x == 0 ) { // 取最接近資料總數1.2倍的質數 
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
 
	int GetKey( int num ) { // 取得餘數作Key 
		int i = 1, key = 0;
		char temp[10];
		sprintf ( temp, "%d", num ); // 將學號轉為字元陣列 
		key = (int)temp[0];
		while ( i < strlen(temp) ) {
			key = (key * (int)temp[i]) % hashSize;
			i++;
		}
		return key;
	}
	
    void BuildHash() { // 建立hash陣列 
    	if ( hashSize == 0 ) // 設定陣列大小 
			SetHashRange();
		int index = 0, t = 0, done = 0, start = 0, steps = 1;
		while ( index < quantity ) {
			t = GetKey( aDataList[index].sid ); // 取得目標index 
			start = t; // 紀錄起點 
			while ( done == 0 ) {
				if ( hashList[t].sid == -1 ) { //  若欄位為空 
					hashList[t].key = start;
					hashList[t].compares = steps; // 儲存比較次數(步數) 
					hashList[t].sid = aDataList[index].sid;
					strcpy( hashList[t].sname, aDataList[index].sname );
					hashList[t].average = aDataList[index].average;
					done = 1;
				}
				else { // 已滿則檢查下個欄位
					// t = start + steps * steps; // 平方法 
					t = start + steps; // 線性法 
					steps++;
					if ( t >= hashSize ) // 過頭了
						t = t - hashSize; // 從頭開始(非起點) 
				}
			}
			done = 0;
			steps = 1;
			index++;
		}
		aDataList.clear();
	}
	
	
	void WriteBinary( string num ) { // 輸出bin檔
		int index = 0, i = 0;
		char temp[12];
		string filename = "input" + num + ".bin";
		file.open( filename.c_str(), ios::out|ios::binary );
		while ( index < quantity ) {
			sprintf ( temp, "%d", aDataList[index].sid );
			file.write( temp, 10 ); // 寫學號 
			file.write( aDataList[index].sname, 10 ); // 寫姓名 
			for( i = 0; i < 6; i++ )
				temp[i] = (unsigned char) aDataList[index].score[i];
			file.write( temp, 6 ); // 寫6個分數 
			file.put('\0'); // 補空白 
			file.put('\0'); 
			file.write( (char *) &aDataList[index].average, sizeof(float) ); // 寫平均 
			index++;
		}
		file.close();
	}
	
	
	bool Readbin( string num ) { // 讀回bin檔 
		InitializeList();
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12], getC;
	    content temp;
	    if ( file ) {
            while ( !file.eof() ) {
				file.read((char *) & getS, 10); // 讀學號 
				if ( getS[0] != '\0' ) { 
					temp.sid = atoi(getS);
					file.read((char *) & getS, 10); // 讀姓名 
					while ( index < 6 ) {
						temp.sname[index] = getS[index];
						index++;
					}
					index = 0;
			    	while ( index < 6 )	{ // 讀6個分數 
	        			file.get(getC);
						temp.score[index] = (int)getC;
						index++;
					}
					index = 0;
					file.get(getC); // 讀掉空白 
					file.get(getC);
					file.read((char *) &getF, sizeof(float)); // 讀平均 
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

	void WriteTab( string num ) { // 輸出tab檔
		int index = 0, steps = 0, fw = -1;
		float usf = 0.0, scf = 0.0; // 不存在值與現存值的比較次數 
		string filename = "input" + num + ".tab";
		file.open( filename.c_str(), ios::out );
		file << " --- Hash Table --- by Linear probing" << endl;
		while ( index < hashSize ) {
			file << "[" << setw(3) << index << "]";
			if ( hashList[index].sid != -1 ) { // 有資料
				file << setw(11) << hashList[index].key << ","; // 寫起點 
				file << setw(11) << hashList[index].sid << ","; // 寫學號 
				file << setw(11) << hashList[index].sname << ","; // 寫姓名 
				file << setw(11) << hashList[index].average; // 寫平均 
				scf = scf + hashList[index].compares; // 現存值比較次數累加
				steps++; // 連續資料數累加 
			}
			else {
				if ( fw == -1 ) // 紀錄第一個空位的位置 
					fw = index;
				while ( steps > 0 ) { // 不存在值比較次數累加 
					usf = usf + steps;
					steps--;
				}
			}
			file << endl;
			index++;
		}
		file.close();
		while ( steps > 0 ) { // 消化剩餘steps
			usf = usf + steps + fw;
			steps--;
		}
		cout << endl << "~~ The hash table has been successfully created! ~~" << endl << endl;
		usf = usf / hashSize; // 取得平均 
		cout << "unsuccessful search: " << usf << " comparisons on average" << endl << endl;
 		scf = scf / quantity;
		cout << "successful search: " << scf << " comparisons on average" << endl << endl;
	}
	
    void InitializeList() { // 初始化資料庫
	    aDataList.clear();
	    delete hashList;
	    hashList = NULL;
	    quantity = 0;
	    hashSize = 0;
    }

    int GetQuantity() { // 取得資料總數 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	List aList;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		aList.InitializeList(); // 將先前的資料清單清空 
		cout << "########################################################" << endl;
		cout << "Mission 1: Transform a text file into a binary file" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 401, 402): [0]Quit" << endl;
        cin >> num;
        fileName = "input" + num + ".txt";
	    if ( !aList.Readtxt( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	aList.WriteBinary( num ); // 任務1
        	fileName = "input" + num + ".bin";
	    	aList.Readbin( fileName );
		    cout << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Build a hash table by linear probing" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		    aList.BuildHash(); // 任務2 
			aList.WriteTab( num );
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
