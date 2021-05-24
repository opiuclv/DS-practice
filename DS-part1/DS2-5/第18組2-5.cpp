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
	int sid = -1;
	int sid2 = -1 ;
	float weight = 0.0;
	int vertex = 0 ;
	int edge = 0 ;
} ;

typedef Content content;

void Hi() {
   	cout << "*****************************************" << endl;
   	cout << " On-machine Exercise                    *" << endl;
   	cout << " Mission 1: Build adjacency lists       *" << endl;
   	cout << " Mission 2: Find connected components   *" << endl;
  	cout << "*****************************************" << endl << endl;
}

class List {
	vector<content> aDataList; // 資料清單 
	vector<content> temp2;
	int quantity = 0 ; // 資料總數
public:
	
	bool Readbin( string num ) { // 讀取bin檔 
		InitializeList();
		int index = 0;
		float getF = 0.0;
		file.open( num.c_str(), ios::in|ios::binary );
	    char getS[12], getC;
	    content temp;
	    if ( file ) {
            while ( !file.eof() ) {
				file.read((char *) & getS, 10); // 讀學號 
				temp.sid = atoi(getS);

				file.read((char *) & getS, 10); // 讀學號 
				temp.sid2 = atoi(getS);

				file.get(getC); // 讀掉空白 
				file.get(getC);
				file.read((char *) &getF, sizeof(float)); // 讀權重
		    	temp.weight = getF;
		    	strcpy(getS,"");
			    aDataList.push_back(temp);
			}
		}
		file.close();
		Count() ;
		if ( quantity > 0 )
	    	return true;
	    else
	    	return false;
    }


   	void WriteAdj( string num ) { // 輸出Adjacency檔
   		int index = 0 ;
   		int index2 = 0 ;
   		int count = 0 ; // 計數有幾筆相關資料

		string filename = "input" + num + ".adj";
		file.open( filename.c_str(), ios::out );
		file << " ---Adjacency Lists --- " << endl;
		while( index < quantity ) {
			file << "[" << setw(3) << index << "]"; // 寫編號
			file << setw(11) << temp2[index].sid << " : "; // 寫學號 

			while( index2 < aDataList.size() ) { // 尋找所有有關連的資料 並寫入權重
				if( aDataList[index2].sid2 == temp2[index].sid ) {
					file << "(" << setw(3) << count << ")"; // 寫編號
					file << setw(11) << aDataList[index].sid << ", "; 
					file << setw(11) << aDataList[index].weight << ", "; 
					count ++ ;
				} // end if
				index2 ++ ;				
			} // end while

			count = 0 ;
			file << endl;
			index++;

		} // end while

		file.close();

		cout << endl << "~~ The Adjacency lists has been successfully created! ~~" << endl << endl;
		// cout << vertex << "pairs => " << edge << " nodes " << endl << endl;
	}
	
    void InitializeList() { // 初始化資料庫
	    aDataList.clear();
	    quantity = 0;
    }

    void Count() { // 計算總共有幾種不同學號
    	int num = 0, num2 = 0 ;
    	bool judge = true ;
    	int count = aDataList.size() ;

    	while ( count > 0 ) {
    		while ( num < temp2.size() ) {
    			if( aDataList[num].sid == temp2[num2].sid || aDataList[num].sid2 == temp2[num2].sid  ) {
    				judge = false ;
    			} // end if
    			num ++ ;
    		} // end while

    		if( judge ) quantity ++ ;
    		count -- ;

    	} // end while

    }

    int GetQuantity() { // 取得資料總數 
	    return quantity ;
	}
};

int main(int argc, char** argv) {
    Hi();
	List aList;
    string num = "1", fileName;
	while ( num.compare("0") != 0 ) {
		aList.InitializeList(); // 將先前的資料清單清空 
		cout << "########################################################" << endl;
		cout << "Mission 1: Build adjacency lists" << endl;
		cout << "########################################################" << endl << endl;
	    cout << "Input the file number (e.g., 501, 502): [0]Quit" << endl;
        cin >> num;
        fileName = "input" + num + ".txt";
	    if ( !aList.Readbin( fileName ) )
		    cout << endl << fileName << " does not exist!!!" << endl << endl;
        else {
		    cout << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Mission 2: Find connected components" << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		    aList.WriteAdj( num ); // 任務2 
            cout << endl << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
