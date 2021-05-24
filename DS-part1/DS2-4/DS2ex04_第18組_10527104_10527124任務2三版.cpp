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

struct Content {                                                     // 資料結構 
	int number = 0;
	char sid[10] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }; // 初始化陣列 
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
	int quantity = 0, hashSize = 0;                                  // 資料總數, hash陣列大小 
public:
	bool Readtxt( string num ) {                                     // 讀取文字檔 
		int getI = 0, index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in );
	    char getS[12] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }, getC;
	    content temp;
	    if ( file ) {                                                // 若找不到指定檔案 
	    	cout << endl << "~~ A binary file has been successfully created! ~~" << endl;
            while ( !file.eof() ) {                                  // 若檔案尚未到結尾 
				file.getline( getS, 12, '\t');                       // 將到tab為止的字元存進getS陣列 
				if ( getS[0] != '\0' ) {
		    		cout << "[" << quantity + 1 << "] " << getS << ", ";  
					while ( index < 10 ) {
						temp.sid[index] = getS[index];
						index++;
					}
					index = 0;
					memset( getS, '\0', strlen(getS) ); 			 // 陣列初始化 
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
		    		quantity++;                                      // 資料總數 +1 
		    		temp.number = quantity;
		    		memset( getS, '\0', strlen(getS) );
			    	aDataList.push_back(temp);                       // 新增筆資料於資料清單
				}
			}
		}
		file.close();
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }
	
    void SetHashRange() {											 // 設定hash陣列大小 
    	int i = 2, j = quantity, x = 0;
    	while ( x == 0 ) {											 // 取最接近資料總數的質數 
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

	int Sumofsid ( char num[] ) {									 // 加總學號 
		int i = 0, sum = 0;
		while ( i < 8 ) {
			sum = sum + num[i] - 48;
			i++;
		}
		//cout << endl << "sum:" << sum << endl;
		return sum;
	}

    void BuildHash() {												 // 建立hash陣列 
    	if ( hashList == NULL )										 // 設定陣列大小 
			SetHashRange();
		int index = 0, i = 0, t = 0, done = 0;
		while ( index < quantity ) {
			t = Sumofsid ( aDataList[index].sid ) % hashSize;		 // 取得目標index 
			while ( done == 0 ) {
				if ( hashList[t].sid[0] == '\0' ) {				 //  若欄位為空 
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
				else {												 // 已滿則換下一個欄位 
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
	    
    void Check() {                                                   // 檢查資料清單 
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

	void WriteBinary( string num ) {								 // 輸出bin檔
		int index = 0, i = 0;
		char temp[6];
		string filename = "input" + num + ".bin";
		file.open( filename.c_str(), ios::out|ios::binary );
		while ( index < quantity ) {
			file.write( aDataList[index].sid, 10 );					 // 寫學號 
			file.write( aDataList[index].sname, 10 );				 // 寫姓名 
			for( i = 0; i < 6; i++ )
				temp[i] = aDataList[index].score[i];
			file.write( temp, 6 );								 	 // 寫6個分數 
			file.put('\0'); 
			file.put('\0'); 
			file.write( (char *) &aDataList[index].average, sizeof(float) ); // 寫平均 
			index++;
		}
		file.close();
	}
	
	bool Readbin( string num ) {                                     // 讀取bin檔(驗算) 
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
    
    void LineProbing( string n ) {									 // 使用hash找資料 
		int t = 0, i = 0, done = 0, steps = 1;
		char num[8];
		strcpy( num, n.c_str() );									 // 將參數的學號轉為陣列 
		t = Sumofsid ( num ) % hashSize;
		while ( done == 0 && steps < hashSize ) {					 // 若還未將全部欄位檢查一遍 
			if ( strcmp( num, hashList[t].sid ) == 0 ) {			 // 找到該學號 
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
    
    void InitializeList() {                                          // 初始化資料庫
	    aDataList.clear();
	    delete hashList;
	    hashList = NULL;
	    quantity = 0;
	    hashSize = 0;
    }

    int GetQuantity() {                                              // 取得資料總數 
	    return quantity;
	}
};

int main(int argc, char** argv) {
    Hi();
	List aList;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		aList.InitializeList();                                      // 將先前的資料清單清空 
		cout << "########################################################" << endl;
		cout << "Mission 1: Transform a text file into a binary file" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 401, 402): [0]Quit" << endl;
        cin >> num;
        fileName = "input" + num + ".txt";
	    if ( !aList.Readtxt( fileName ) )                            // 若讀檔失敗 
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
        	//aList.Check();										 // 檢查讀入資料 
        	aList.WriteBinary( num );								 // 任務1 
        	/*
        	fileName = "input" + num + ".bin";						 // 把bin讀回來檢查 
	    	if ( !aList.Readbin( fileName ) )                        // 若讀檔失敗 
		    	cout << endl << fileName << " does not exist!!!" << endl << endl;
		    aList.Check();
		    */
		    cout << endl;
			cout << "========================================================" << endl;
			cout << "Mission 2: Hashing with Linear probing" << endl;
			cout << "========================================================" << endl;
		    aList.BuildHash();										 // 任務2 
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
