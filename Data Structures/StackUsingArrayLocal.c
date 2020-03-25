// stack implementation by array
#include<stdio.h>
#include<stdlib.h>

void push(int stack[],int size,int *top,int key);
void pop(int stack[],int *top);
void peek(int stack[],int *top);
void display(int stack[],int *top);

int main()
{
	printf("Enter size of Stack \n");
	int size;
	scanf("%d",&size);
	int *stack = (int*)malloc(size * sizeof(int));
	int top = -1;
	while(1)
	{
		printf("Enter choice \n");
		printf("1-Push 2-Pop 3-Peek 4-Display 5-Exit \n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				printf("Enter Element to be pushed \n");
				int key;
				scanf("%d",&key);
				push(stack,size,&top,key);
				break;
			}
			case 2:{
				pop(stack,&top);
				break;
			}
			case 3:{
				peek(stack,&top);
				break;
			}
			case 4:{
				display(stack,&top);
				break;
			}
			case 5:{
				exit(0);				
				break;
			}
		}
	}
	return 0;
}

void push(int stack[],int size,int *top,int key)
{
	if(*top<size-1)
	{
		*top = *top+1;
		stack[*top] = key;
		printf("%d pushed at index %d\n",key,*top);
	}
	else
		printf("Stack Overflow \n");
}

void peek(int stack[],int *top)
{
	if(*top>=0)
		printf("%d is present at index %d \n",stack[*top],*top);
	else
		printf("Stack is empty \n");
}

void pop(int stack[],int *top)
{
	if(*top>=0)
	{
		printf("%d popped from index %d \n",stack[*top],*top);
		*top = *top-1;	
	}
	else
		printf("Stack is empty \n");
}


void display(int stack[],int *top)
{
	if(*top>=0)
	{
		printf("Stack : ");
		int i;
		for(i=*top;i>=0;i--)
			printf("%d ",stack[i]);
		printf("\n");
	}
	else
		printf("Stack is empty \n");
}



