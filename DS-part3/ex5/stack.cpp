#include<stdio.h>
#include<stdlib.h>
#define SIZE 10	//Stack的大小 

struct Stack
{
	int data[SIZE];	//存值 
	int top;	//指向最上面的那格 
		Stack()
		{
			top=-1;		//初始值是-1 
		}
	bool isEmpty();		//是否為空 
	bool isFull();		//是否為滿 
	bool Push(int number);	//放入堆疊 (傳入放入的值) 
	int  Pop();				//從堆疊取出  (回傳取出的值) 
	bool Show();			//顯示stack的內容 
	void list();
};
	
	void Stack::list()
	{
		printf("1.Push   2.Pop   3.show   ");
		printf("選擇你要做的事:");
		int choose;
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				if(!isFull())
				{
					int number;
					printf("<Push>輸入你要Push的值:");
					scanf("%d",&number);
					Push(number);
				}
				else
				{
					printf("Stack為滿,無法加入元素\n"); 
				}
				
			    break;
			case 2:
				if(!isEmpty())
				{
					printf("<Pop>取出的值為:%d\n",Pop()); 
				}
				else
				{
					printf("Stack為空,無法刪除元素\n"); 
				}
				break;
			case 3:
				Show();
				break;
			default:
				printf("沒有這個選項喔!\n");
				break; 
				 
		}
		 
	}
	
	bool Stack::isEmpty()
	{
		if(top==-1)		//top為-1時為空 
		{
			return true;	
		}	
		else
		{
			return false;
		}
	}
	
	bool Stack::isFull()
	{
		if(top==SIZE-1)	//top為最後一格時為滿 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Stack::Push(int number)
	{
		if(!isFull())//如果不是滿的才能加入元素 
		{
			top+=1;
			data[top]=number;
			return true;
		}
		else
		{
			printf("stack為滿無法加入元素\n"); 
			return false;	
		}
	}
	
	int Stack::Pop()
	{
		if(!isEmpty())//如果不是空的才能刪除元素 
		{
			top-=1;
			return (data[top+1]);
		}
		else
		{
			printf("stack為空無法刪除元素\n"); 
			return false;
		}
		
	}

	bool Stack::Show()
	{
		if(!isEmpty())
		{
			int counter;
			for(counter=0;counter<=top;counter++)
			{
				printf(" [%2d]",counter);
			}
			printf("\n");
			for(counter=0;counter<=top;counter++)
			{
				printf("%5d",data[counter]);
			}
			printf("\n");
			for(counter=0;counter<=top;counter++)
			{
				if(counter==top)
				{
					printf(" ↑top"); 
				}
				else
				{
					printf("     ");
				}
			}
			printf("\n");
		}
		else
		{
			printf("stack為空\n"); 
		}
		
	}

int main()
{
	Stack testStack;
	
	while(true)
	{
		testStack.list();
	}
	
	system("pause");
	return 0;
 } 
