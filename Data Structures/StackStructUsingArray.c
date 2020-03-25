// stack implementation by array
#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int top;
	int capacity;
	int *array;
};


struct Stack* createStack(int capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(capacity*sizeof(int));		
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack,int key)
{
	if(isFull(stack))
		{
			printf("Stack Overflow \n");
			return;	
		}
	
	stack->array[++stack->top]= key;
	printf("%d pushed at index %d\n",key,stack->top);
}

void peek(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is empty \n");
		return;
	}
	
		printf("%d is present at index %d \n",stack->array[stack->top],stack->top);
}

void pop(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is empty \n");
		return;
	}
	
		printf("%d popped from index %d \n",stack->array[stack->top],stack->top);
		stack->top--;
}


void display(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is empty \n");
		return;
	}

		printf("Stack : ");
		int i;
		for(i=stack->top;i>=0;i--)
			printf("%d ",stack->array[i]);
		printf("\n");
}

int main()
{
	printf("Enter size of Stack \n");
	int capacity;
	scanf("%d",&capacity);
	struct Stack *stack = createStack(capacity);
	
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
				push(stack,key);
				break;
			}
			case 2:{
				pop(stack);
				break;
			}
			case 3:{
				peek(stack);
				break;
			}
			case 4:{
				display(stack);
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



