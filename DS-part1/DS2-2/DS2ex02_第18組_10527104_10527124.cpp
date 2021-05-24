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
#include <time.h>

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
	int serialNumber = 0;
} ;

typedef Content content;

void Hi() {
   	cout << "************************************************************" << endl;
   	cout << "On-machine Exercise                                        *" << endl;
   	cout << "Mission 1: Construct a min-max heap                        *" << endl;
   	cout << "Mission 2: Find top-K maximums by min-max heap             *" << endl;
  	cout << "************************************************************" << endl << endl;
}

class List {
	vector<content> aSchoolList, aTopList;
	int quantity = 0;                                                // 資料總數 
public:
	bool Readtxt( string num ) {                                     // 讀取文字檔 
		int x = 0;
		file.open( num.c_str(), ios::in );
	    char getS[255];
	    content temp;
	    if ( !file ) {                                               // 若找不到指定檔案 
	    	file.close();
	    	return false;
		}
		else {
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
				else temp.graduate = getS; 
				file.ignore(255,'\n');                               // 跳過剩餘資料直到下一行 
				if ( x == 0 ) {                                      // 若此筆資料無誤 
					ss << temp.graduate;
					ss >> temp.graduates;
        	        ss.str("");
                    ss.clear();
    				quantity++;                                      // 資料總數 +1 
	    			aSchoolList.push_back(temp);                     // 新增筆資料於資料清單 
	    		}
			}
		}
		file.close();
	    return true;
    }
    
    void Print() {                                                   // 印出資料清單 
        int index = 0;
        cout << "*** There are " << quantity << " matched records, listed as below:" << endl << endl;
    	while ( index < quantity ) {
    		cout << "[" << index + 1 << "] " << aSchoolList[index].school << " " << aSchoolList[index].department;
			cout << "," << aSchoolList[index].training << "," << aSchoolList[index].level << ",";
			cout << aSchoolList[index].graduates << endl;
        	index++;
        }
        cout << "********************************************************" << endl;
	}
 
    void Check() {                                                   // 篩選關鍵字
    	int index = 0, x = -1, j = 0;
    	string num;
    	while ( j < 4 ) {
    	    if ( j == 0 )
			    cout << "Enter a keyword of 學校名稱: [*]for all" << endl;
    	    if ( j == 1 )
			    cout << "Enter a keyword of 科系名稱: [*]for all" << endl;
    	    if ( j == 2 )
			    cout << "Enter a keyword of 日夜別: [*]for all" << endl;
    	    if ( j == 3 )
			    cout << "Enter a keyword of 等級別: [*]for all" << endl;
    		cin >> num;
        	if ( num.compare( "*" ) != 0 ) {                         // 若有關鍵字要篩選 
            	while ( index < quantity ) {
            		if ( j == 0 )
					    x = aSchoolList[index].school.find( num, 0 ); // 將x設為字串中關鍵字所在的位置, 不存在則 < 0
            		if ( j == 1 )
					    x = aSchoolList[index].department.find( num, 0 );
            		if ( j == 2 )
					    x = aSchoolList[index].training.find( num, 0 );
            		if ( j == 3 )
					    x = aSchoolList[index].level.find( num, 0 );
    	        	if ( x < 0 ) {                                   // 若找不到關鍵字 
    	    	    	aSchoolList.erase( aSchoolList.begin() + index ); // 刪除此筆資料 
    	    		    quantity--;                                  // 資料總數 -1 
		        	}
		        	else
					    index++;                                     // 換下筆資料 
		        }
		    }
		    index = 0, x = -1, j++;                                  // 換下個欄位 
	    }
	}
	 
    void PrintHeap( content Heap[] ) {
        int index = 0;
        cout << "*** There are " << quantity << " matched records, listed as below:" << endl << endl;
    	while ( index < quantity ) {
            cout << "[" << index + 1 << "] " << "{" << Heap[index].serialNumber << "} " << Heap[index].graduates << endl;
        	index++;
        }
        cout << endl;
	}
	
	void PrintResult( content Heap[] ) {                             // 印出最右.最左節點 
		int index = 0;
		cout << "bottom:[" << Heap[quantity - 1].serialNumber << "] " << Heap[quantity - 1].graduates << endl; // 最右節點 
		while ( index < quantity )
		    index = index * 2 + 1;
		index = (index-1)/2;
		cout << "leftmost bottom:[" << Heap[index].serialNumber << "] " << Heap[index].graduates << endl << endl; // 最左節點  
	}
	
	void UpMax( content Heap[], int index ) {                        // 向上平衡MaxHeap
		int local = index, grandparents = ((local-1)/2 - 1)/2;
		while ( local > 2 && Heap[local].graduates > Heap[grandparents].graduates ) { // 若此資料的祖父節點存在 && 此資料畢業人數 > 祖父節點畢業人數 
			swap( Heap[local], Heap[grandparents] );                 // 兩筆資料交換 
			local = grandparents; 
		    grandparents = ((local-1)/2 - 1)/2;
		}
	}
	
	void UpMin( content Heap[], int index ) {                        // 向上平衡MinHeap
		int local = index, grandparents = ((local-1)/2 - 1)/2;
		while ( local > 2 && Heap[local].graduates < Heap[grandparents].graduates ) { // 若此資料的祖父節點存在 && 此資料畢業人數 < 祖父節點畢業人數 
			swap( Heap[local], Heap[grandparents] );                 // 兩筆資料交換 
			local = grandparents;
		    grandparents = ((local-1)/2 - 1)/2;
		}
	}
		
	void DownMax( content Heap[], int index, int tail ) {            // 向下平衡MaxHeap
		int local = index, children = local*2 + 1, grandchildren = (local*2 + 1)*2 + 1, n = 1, t = 1;
		if ( children + 1 <= tail && Heap[children].graduates < Heap[children+1].graduates ) // 找出子節點中最大者 
		    children++;
		if ( children <= tail && Heap[local].graduates < Heap[children].graduates ) { // 若此資料的子節點存在 && 此資料畢業人數 < 子節點畢業人數 
			swap( Heap[local], Heap[children] );                     // 兩筆資料交換
			DownMax( Heap, local, tail );                            // 交換後以遞迴繼續檢查
	    }
		else {
			while ( t < 4 && grandchildren + n <= tail ) {           // 找出孫節點中最大者 
		        if ( Heap[grandchildren].graduates < Heap[grandchildren+n].graduates ) // 此孫比後者小 
	    		    grandchildren = grandchildren + n, n = 1;        // 替換為較大者 
	    		else
				    n++;
		   	 	t++;                                                 // 換下一位 
			}
			if ( grandchildren <= tail  && Heap[local].graduates < Heap[grandchildren].graduates ) { // 若此資料的孫節點存在 && 此資料畢業人數 < 孫節點畢業人數 
				swap( Heap[local], Heap[grandchildren] );            // 兩筆資料交換 
				DownMax( Heap, grandchildren, tail );                // 交換後以遞迴繼續檢查 
			}
			if ( grandchildren > tail && children <= tail ) { //若此資料位於倒數第二層(有子節點無孫節點) 
				if ( Heap[local].graduates < Heap[children].graduates ) // 若此資料畢業人數 < 子節點畢業人數 
				    swap( Heap[local], Heap[children] );             // 兩筆資料交換 
			}
		}
	}
	
	void BuildMinMax( content Heap[] ) {                             // 建立MinMaxHeap
		int index = 0, parents = 0, local = 1;
		while ( index < quantity ) {                                 // 若清單中還有剩於工作未放進Heap陣列 
			Heap[index].serialNumber = index + 1;                    // 填入序號與畢業人數等內容 
			Heap[index].graduates = aSchoolList[index].graduates;
			Heap[index].school = aSchoolList[index].school;
			Heap[index].department = aSchoolList[index].department;
			Heap[index].training = aSchoolList[index].training;
			Heap[index].level = aSchoolList[index].level;
			local = index, parents = (local-1)/2;
			if ( local > 0 ) {                                       // 若非第一筆資料 
		        if ( IsOdd( index ) ) {                              // 若位於奇數層 
		            if ( Heap[local].graduates > Heap[parents].graduates ) { // 若此資料畢業人數 > 父節點畢業人數 
				        swap( Heap[local], Heap[parents] );          // 兩筆資料交換
		                UpMax( Heap, parents );                      // 向上平衡Max
		        	}
		        	else
					    UpMin( Heap, local );                        // 向上平衡Min 
			    }
		        else {
		            if ( Heap[local].graduates < Heap[parents].graduates ) { // 若此資料畢業人數 < 父節點畢業人數 
				        swap( Heap[local], Heap[parents] );          // 兩筆資料交換 
		                UpMin( Heap, parents );                      // 向上平衡Min 
		        	}
		        	else
					    UpMax( Heap, local );                        // 向上平衡Max 
		    	}
			}
			index++;                                                 // 換下筆資料 
		}
	}
	
	bool IsOdd( int index ) {                                        // 是否位於奇數層 
		int level = 1, leftNode = 0, rightNode = 0;                  // 層數,level層最左節點的位置,level層最右節點的位置 
		while ("今天天氣真好") {
			if ( leftNode <= index && index <= rightNode ) {         // 若index位於level這層範圍內 
				if ( level % 2 == 1 )
				    return true;                                     // level是奇數 
    			else
				    return false;                                    // level是偶數 
			}
			level++;                                                 // 換下一層 
			leftNode = leftNode*2 + 1;
			rightNode = leftNode * 2;
		}
	}
	
	void ReBuildHeap( content Heap[], int n, int &tail ) {           // 重新平衡Heap 
		int local = n, children = n*2 + 1;
		swap( Heap[n], Heap[tail] );                                 // 刪除已被擷取的節點,以末端節點取代 
		tail--;                                                      // 最後一筆資料的位置 -1 
		if ( children <= tail ) {                                    // 若子節點存在 
		    if ( children + 1 <= tail && Heap[children].graduates < Heap[children+1].graduates ) // 找出子節點中最大者 
			    children++;
		    if ( Heap[local].graduates < Heap[children].graduates )  // 若此資料畢業人數 < 子節點畢業人數  
			    swap( Heap[local], Heap[children] );                 // 兩筆資料交換  
    		DownMax( Heap, local, tail );                            // 往下平衡Max 
		}
	}
	
	void AddtoList( content node ) {                                 // 新增資料進擷取清單 
		content temp;
		temp.serialNumber = node.serialNumber;
		temp.graduates = node.graduates;
		temp.school = node.school;
		temp.department = node.department;
		temp.training = node.training;
		temp.level = node.level;
		aTopList.push_back( temp );
	}
	
	void FindTopK( content Heap[], int &k ) {                        // 尋找前K筆最大的資料 
		int tail = quantity - 1, index = -1;                         // 最後一筆資料的位置,待擷取資料的位置 
		if ( k > quantity )
		    k = quantity;
		while ( tail >= 0 && aTopList.size() < k ) {
			if ( tail > 1 ) {                                        // 若資料總數>2 
				if ( Heap[1].graduates >= Heap[2].graduates )        // 比較兩Max節點較大者 
				    index = 1;                                       // 擷取左邊Max節點 
				else
				    index = 2;                                       // 擷取右邊Max節點
			}
			else if ( tail == 1 )
			    index = 1;                                           // 擷取唯一的Max節點 
			else
			    index = 0;                                           // 擷取根節點 
			AddtoList( Heap[index] );                                // 新增資料進擷取清單 
			// if ( tail > 2 ) cout << "***" << Heap[1].graduates << ":" << Heap[2].graduates << endl; // 檢查用 
			if ( index > 0 )                                         // 若剩餘資料總數>1 
			    ReBuildHeap( Heap, index, tail );                    // 重新整理Heap 
		}
	}
	
    void PrintTop() {                                                // 印出擷取清單 
        int n, index = 0;
    	while ( index < aTopList.size() ) {
        	n = index + 1;
            cout << "Top" << setw(4) << n << ": [" << aTopList[index].serialNumber << "] " << aTopList[index].school << ",";
			cout << aTopList[index].department << "," << aTopList[index].training << "," << aTopList[index].level << ",";
			cout << aTopList[index].graduates << endl;
        	index++;
        }
        cout << endl;
	}
	
    void InitializeList() {                                          // 清空資料清單 
	    aSchoolList.clear();
	    aTopList.clear();
	    quantity = 0;
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

void Check( List &aList ) {                                          // 前置篩選作業 
	cout << endl;
	aList.Check();                                                   // 依序篩選學校,科系,日/進,等級共4個欄位 
	aList.Print();                                                   // 印出篩選後剩餘的資料 
}

void Mission( List &aList ) {
    clock_t start_time, end_time;
    int k = 0, insertion_time = 0, deletion_time = 0;
	content *Heap = new content[aList.GetQuantity()];           // 以資料總數大小建立Heao陣列 
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "Mission 1: Min-max Heap Construction" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
    if ( aList.GetQuantity() > 0 ) {                                 // 若清單中有資料 
        start_time = clock();
    	aList.BuildMinMax( Heap );                                   // 任務1 
	    end_time = clock();
	    insertion_time = end_time - start_time;
    	//aList.PrintHeap( Heap );                                   // deBug檢查用 
    	aList.PrintResult( Heap );                                   // 印出最右.最左節點
		cout << "Enter the value of K:" << endl << "[0..." << aList.GetQuantity() << "] " << endl;
		cin >> k;
	    cout << "========================================================" << endl;
	    cout << "Mission 2: Find top-K maximums by min-max heap  (K=" << k <<")" << endl;
	    cout << "========================================================" << endl << endl;
    	start_time = clock();
	    aList.FindTopK( Heap, k );                                   // 任務2 
	    end_time = clock();
	    aList.PrintTop();                                            // 印出擷取清單 
	    deletion_time = end_time - start_time;
	    cout << "[Insertion Time] min-max heap: " << insertion_time << " ms" << endl; // 任務1執行時間 
	    cout << "[Deletion Time] min-max heap: " << deletion_time << " ms" << endl << endl; // 任務2執行時間  
	}
	else
	    cout << "###  There is nothing matched! ###" << endl << endl;
}

int main(int argc, char** argv) {
    Hi();
	List aList;
    int num = 1;
	while ( num != 0 ) {
		aList.InitializeList();                                      // 將先前的資料清單清空 
        cout << "Input the file number: 201, 202, ... [0]Quit" << endl << endl;
        cin >> num;
	    if ( !ReadFile( aList, num ) )
		    cout << endl << "### input" << num << ".txt does not exist! ###" << endl << endl;
        else {
        	Check( aList );                                          // 前置篩選作業 
            Mission( aList );
            cout << "[0]Quit or [Any other]continue?" << endl;
			cin >> num;
			Hi();
		}
    }
	aList.InitializeList();
	return 0;
}
