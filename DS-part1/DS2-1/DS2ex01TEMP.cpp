//*********************** ********************************************************************/
//TEMPLATE of DS2 Exercise 1: File Access/Heap Construction  Wu, Yi-Hung@ICE.CYCU    2018/02
//********************************************************************************************/
#include <iostream>                                                         // cout, endl
#include <fstream>                                                          // open, is_open
#include <string>                                                           // string
#include <vector>                                                           // vector
#include <cstdlib>                                                          // atoi, system
#include <iomanip>                                                          // setw

using namespace std;

typedef struct cT                                                           // declare a type for a selected record
{   string	cname;                                                          // college name
    string  dname;                                                          // department name
   	string  type;                                                           // either day or night
    string  level;                                                          // graduate or undergraduate
    int     total;                                                          // number of students
}	collegeType;
//*********************** ********************************************************************/

typedef struct hT											                // declare a type for a heap node
{	int	    rid;                                                            // a serial number as record identifier
	int     value;                                                          // the key for comparisons
}	heapType;

void heapInsert(heapType [], const int, const int, const int);              // insert one record into heap
//*********************** ********************************************************************/

int main(void)
{   fstream     inFile;                                                     // input file handler
    string      fileName;                                                   // name of input file

    do
    {   cout << endl << "Input the file name: [default]102_sdata [0]Quit" << endl;  // press 0 to stop execution
        cin >> fileName;
        if (!fileName.compare("0"))                                         // No file to open, so quit
            return 0;
        fileName = "input" + fileName + ".txt";                             // append a file extension
        inFile.open(fileName.c_str(), fstream::in);                         // open a file
        if (!inFile.is_open())
            cout << endl << "### " << fileName << " does not exist! ###" << endl;   // failed to open a file, so try again
        else
            break;                                                          // successfully open a file, so leave the loop
    } while(1);   //end while
    do
    {   string                  coName, depName, stLevel, coType;           // user-specified keywords for each field
        string                  quitOrNot;                                  // do it again or not
        char                    rBuf[255];                                  // buffer to keep one whole record
        vector <collegeType>    cSet;                                       // a collection of selected records
        int                     ansNo = 0;                                  // a serial number

        cout << endl << "************************************************************" << endl;
        cout << "*** Mission One: Select Matched Records from a Text File ***" << endl;
        cout << "************************************************************" << endl;
        cout << endl << "Enter a keyword of 學校名稱: [*]for all" << endl;
        cin >> coName;
        cout << endl << "Enter a keyword of 科系名稱: [*]for all" << endl;
        cin >> depName;
        cout << endl << "Enter a keyword of 日夜別: [*]for all" << endl;
        cin >> coType;
        cout << endl << "Enter a keyword of 等級別: [*]for all" << endl;
        cin >> stLevel;

        inFile.ignore(255,'\n');                                            // skip the first three line in file
        inFile.ignore(255,'\n');                                            // because they are file header
        inFile.ignore(255,'\n');                                            // indicates meta-data such as field names
        while (inFile.getline(rBuf, 255, '\n'))                             // retrieve one entire record from file
        {   string      temp;                                               // duplicate a string in another format
            collegeType oneC;                                               // keep one record with only the required fields
            int         cNo = 0, pre = 0, pos = 0;                          // indicators to extract each field in a record from left to right

            temp.assign(rBuf);                                              // make a duplicate of the entire record
            pos = temp.find_first_of('\t', pre);                            // move to the end of the first field
            while (pos != string::npos)
            {   switch (++cNo)
               	{   case 2: oneC.cname = temp.substr(pre, pos - pre);       // copy a college name
                            if ((coName != "*") && ((oneC.cname.find(coName)) == string::npos))
                                cNo = 0;
                            break;
//
// Mission One part I.
// Get the content of the other fields
//
                    default:    break;
               	}   //end switch
               	if (cNo == 0)                                               // ignore a record if any field is not matched or unknown
                    break;
                 pre = ++pos;
                 pos = temp.find_first_of('\t', pre);                       // move to the end of the next field
            }   //end for
            if (cNo != 0)
                cSet.push_back(oneC);                                       // put a record into the collection if it is not ignored
        }   //end while
        inFile.close();                                                     // close the input file
//
// Mission One part II.
// Display the content of each field in a selected record
//
        system("pause");
        if (!cSet.size())
            cout << endl << "### " << " There is nothing matched! ###" << endl;
        else
        {   try
            {   heapType	*heapArray = new heapType [cSet.size()];        // dynamic array to keep heap nodes, total size is known
                int         idx = 0;                                        // serial number of a selected record in the data collection

                for (vector<collegeType>::iterator it = cSet.begin(); it < cSet.end(); ++idx, ++it)
                    heapInsert(heapArray, idx, it->total, idx);             // serial number is also the current bottom in the heap
//
// Mission Two part I.
// Display the content of the root, the bottom and the node at the leftmost bottom in the heap
//
                delete [] heapArray;				                        // release the dynamic array of heap structure
            }	// end try
            catch (std::bad_alloc& ba)								        // failed to allocate dynamic space
            {
                std::cerr << endl << "bad_alloc caught: " << ba.what() << endl;
            }   // end catch
        }   // end else
        cSet.clear();                                                   // release the space of vector for the selected records
        cout << endl << "[0]Quit or [Any other]continue?" << endl;
        cin >> quitOrNot;
        if (!quitOrNot.compare("0"))                                        // press 0 to stop execution
            return 0;
        else
            inFile.open(fileName.c_str(), fstream::in);                     // open a file
    } while (1);
}	// end main
//*********************** ********************************************************************/

void heapInsert(heapType H[], const int newRid, const int newValue, const int bottom)
{   // a heap, serial number of a new record, key for comparisons on a heap, the bottom node
	int place = bottom;                                                     // start at the bottom node
    int parent = (place - 1)/2;										        // locate its parent node

	H[place].rid = newRid;                                                  // save a new record to the bottom node
	H[place].value = newValue;
//
// Mission Two part II.
// Make a loop to trickle up the new record if it violates the ordering rule of a heap
//
}	// end heapInsert
//*********************** ********************************************************************/
