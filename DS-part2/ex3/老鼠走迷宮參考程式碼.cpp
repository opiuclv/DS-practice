//*******************************************************/
//Header file for class CoXY & StackR by Wu, Yi-Hung 2017/10
//*******************************************************/
#include <iostream> //cin, cout
#include <new> //new
using namespace std;
typedef enum {Copy = -1,
 Right, Down, Left, Up} Moves; // denote the direction of each move
//*** CoXY object: 2D coordinate (Y, X) *****************/
class CoXY {
 int y; // Y coordinate
 int x; // X coordinate
public:
 CoXY(): y(0), x(0)
 { }; //end CoXY default constructor
 CoXY(int py, int px) // a coordinate (py, px)
 { y = py;
 x = px;
 } //end CoXY constructor
 CoXY(const CoXY& pt): y(pt.y), x(pt.x) // copy a coordinate
 { } //end CoXY copy constructor
//*******************************************************/
// setXY(py, px): set up the coordinate (py, px)
// getX(pt): get the X coordinate of pt
// getY(pt): get the Y coordinate of pt
// nextXY(dir): get the coordinate after the move toward dir
// match(pt): check if the coordinate is the same as pt
// inRange(maxLimit): check if the coordinate is in the range
//*******************************************************/
 void setXY(const int py, const int px) // set up the coordinate (py, px)
 { y = py;
 x = px;
 } //end CoXY::setXY
 int getX() const // get the X coordinate of pt
 { return x; } //end CoXY::getX
 int getY() const // get the Y coordinate of pt
 { return y; } //end CoXY::getY
 CoXY nextXY(Moves dir) const
 { CoXY pt(y,x); // create a copy of the coordinate (y, x)
 switch (dir) // get the coordinate after the move toward dir
 { case Right: pt.x++;
 break;
 case Down: pt.y++;
 break;
 case Left: pt.x--;
 break;
 case Up: pt.y--;
 break;
 default: ; //just a copy at the same coordinate
 } //end switch
 return pt;
 } //end CoXY::nextXY
 bool match(const CoXY& pt) const // check if it is the same as pt
 { if ((y == pt.y) && (x == pt.x))
 return true;
 return false;
 } //end CoXY::match
 bool inRange(const CoXY& maxLimit) const
 { if ((y >= 0) && (y < maxLimit.y)
 && (x >= 0) && (x < maxLimit.x))
 return true; // if it is in the range of (0,0) and maxLimit
 return false; // out of range
 } //end CoXY::inRange
}; //end CoXY class
//*** StackR object: a route ***************************/
class stackR
{ 
  typedef struct sN // node type used in stackR
  { 
    CoXY p; // the coordinate of a cell
    Moves first, prev; // directions of the first move and the previous move
    struct sN *next; // link to the next node
  } stackNode;
  
  stackNode *topPtr; // implemented stackR as a linked list
  
public:
 stackR(): topPtr(NULL)
 {} 
//end stackR initializer
//*******************************************************/
// isEmpty(): check if it is empty or not
// getTop(pt, first, prev): get the top of stackR
// pop(): remove the top of stackR
// pop(pt, first, prev): get the top of stackR and then remove it
// push(pt, first, prev): set pt as a new top of stackR
// replaceStack(aStack): deep copy of a stackR object
//*******************************************************/
 bool isEmpty() const
 { return topPtr == NULL; } //end stackR::isEmpty
 
 void getTop(CoXY& pt, Moves& first, Moves& prev) // get the top of stackR
 {
   if (isEmpty())
     cout << endl << "Try to retrieve from an empty stack!" << endl;
   else
   { 
     pt = topPtr->p.nextXY(Copy); // nextXY(Copy): a copy of the coordinate
     first = topPtr->first; // get the direction of the first move
     prev = topPtr->prev; // get the direction of the previous move
   } // end else
 }// end stackR::getTop
 
 void pop() // remove the top of stackR
 {
   if (isEmpty())
     cout << endl << "Try to remove the top of an empty stack!" << endl;
   else
   { 
     stackNode *tempPtr = topPtr;
     topPtr = topPtr->next; // set a new top of stackR
     tempPtr->next = NULL;
     delete tempPtr;
   } // end else
 }// end stackR::pop
 
 void pop(CoXY& pt, Moves& first, Moves& prev)
 { 
   getTop(pt, first, prev); // get the top of stackR
   pop(); // remove the top of stackR
 }// end stackR::pop
 
 void push(const CoXY& pt, const Moves& first, const Moves& prev) // a new top
 { 
   try
   { 
     stackNode *newPtr = new stackNode; // create a new node
     newPtr->p = pt.nextXY(Copy); // nextXY(Copy): a copy of the coordinate
     newPtr->first = first; // set the direction of the first move
     newPtr->prev = prev; // set the direction of the previous move
     newPtr->next = topPtr;
     topPtr = newPtr; // set a new top of stackR
   } // end try
   catch (std::bad_alloc& ba) // unable to allocate space
   { 
     std::cerr << endl << "bad_alloc on stack caught: " << ba.what() << endl;
   } // end catch
 }// end stackR::push
 
 ~stackR()
 { 
   while (!isEmpty()) // clear up the entire stackR
     pop();
 } // end destructor
 
 void replaceStack(const stackR& obj) // deep copy of a stackR object
 { 
   while (!isEmpty()) // clear up the entire stackR
     pop();
   if (!obj.isEmpty())
   { 
     stackNode *newPtr = new stackNode; // create a new node
     topPtr = newPtr; // set up the top of stackR
     newPtr->p = obj.topPtr->p.nextXY(Copy); // a copy of the coordinate
     newPtr->first = obj.topPtr->first; // copy the direction of the first move
     newPtr->prev = obj.topPtr->prev; // copy the direction of the previous move
     for (stackNode *oldPtr = obj.topPtr->next; oldPtr != NULL; oldPtr = oldPtr->next)
     { 
	   newPtr->next = new stackNode; // append a new node
       newPtr = newPtr->next;
       newPtr->p = oldPtr->p.nextXY(Copy); // a copy of the coordinate
       newPtr->first = oldPtr->first; // copy the direction of the first move
       newPtr->prev = oldPtr->prev; // copy the direction of the previous move
     } // end for
     
     newPtr->next = NULL; // the end of linked list
   } //end else
 } //end stackR:replaceStack
}; //end stackR class
//*******************************************************/
