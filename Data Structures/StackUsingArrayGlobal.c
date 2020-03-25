// stacks implementation by arrays
#include<stdio.h>
#include<stdlib.h>
#define MAX 2

void push(int data);
void peek();
void pop();
int isempty();
int isfull();
void display();

int stack[MAX];
int top=-1;  // globally

int main()
{

	while(1)
	{

		printf("enter choice \n");
		printf("1-push 2-pop 3-peek 4-display 5-exit \n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("enter data \n");
					int data;
					scanf("%d",&data);
					push(data);
								}break;

			case 2:
			{
				pop();
								}break;
			case 3:
				{
					peek();
								}break;
			case 4:
			{
				display();
								}break;
			case 5:
			{
				return 0;
								}break;
			default:
			{
				printf("Invalid Input \n");
							}break;

		}
	}
}

void push(int data)
{
	if(isfull())
		printf("Stack is Full \n");
	else
	{
		top++;
		stack[top]=data;
		printf("%d is pushed at %d \n",data,top);
	}

}

void peek()
{
	if(isempty())
		printf("Stack is Empty \n");
	else
	printf("%d is top element \n",stack[top]);
}

void pop()
{
	if(isempty())
		printf("Stack is Empty \n");
	else
	{
		printf("%d is removed  \n",stack[top]);
		top--;
	}
}

int isempty()
{
	return top == -1;
}

int isfull()
{
	return top == MAX-1;
}

void display()
{
	if(isempty())
		printf("Stack is Empty \n");
	else
	{
		int temp;
		temp=top;
		printf("Stack : ");
		while(temp!=-1)
		{
			printf("%d ",stack[temp]);
			temp--;
		}
		printf("\n");
	}

}









