#include<stdio.h>
#include<stdlib.h>
#define SIZE 10	//Stack���j�p 

struct Stack
{
	int data[SIZE];	//�s�� 
	int top;	//���V�̤W�������� 
		Stack()
		{
			top=-1;		//��l�ȬO-1 
		}
	bool isEmpty();		//�O�_���� 
	bool isFull();		//�O�_���� 
	bool Push(int number);	//��J���| (�ǤJ��J����) 
	int  Pop();				//�q���|���X  (�^�Ǩ��X����) 
	bool Show();			//���stack�����e 
	void list();
};
	
	void Stack::list()
	{
		printf("1.Push   2.Pop   3.show   ");
		printf("��ܧA�n������:");
		int choose;
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				if(!isFull())
				{
					int number;
					printf("<Push>��J�A�nPush����:");
					scanf("%d",&number);
					Push(number);
				}
				else
				{
					printf("Stack����,�L�k�[�J����\n"); 
				}
				
			    break;
			case 2:
				if(!isEmpty())
				{
					printf("<Pop>���X���Ȭ�:%d\n",Pop()); 
				}
				else
				{
					printf("Stack����,�L�k�R������\n"); 
				}
				break;
			case 3:
				Show();
				break;
			default:
				printf("�S���o�ӿﶵ��!\n");
				break; 
				 
		}
		 
	}
	
	bool Stack::isEmpty()
	{
		if(top==-1)		//top��-1�ɬ��� 
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
		if(top==SIZE-1)	//top���̫�@��ɬ��� 
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
		if(!isFull())//�p�G���O�����~��[�J���� 
		{
			top+=1;
			data[top]=number;
			return true;
		}
		else
		{
			printf("stack�����L�k�[�J����\n"); 
			return false;	
		}
	}
	
	int Stack::Pop()
	{
		if(!isEmpty())//�p�G���O�Ū��~��R������ 
		{
			top-=1;
			return (data[top+1]);
		}
		else
		{
			printf("stack���ŵL�k�R������\n"); 
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
					printf(" ��top"); 
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
			printf("stack����\n"); 
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
