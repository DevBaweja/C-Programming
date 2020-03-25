#include<stdio.h>
#include<stdlib.h>
// Undirected Graph using Adjacency List

struct node {
	int data;
	struct node* next;
};

void Display(struct node* mat[],int n)
{
	int i,j;
	printf("Graph: \n");
	for(i=0;i<n;i++)
		{
			struct node* temp = mat[i];
			do{
				printf("%d  ",temp->data);
				temp=temp->next;
			}
			while(temp);
			printf("\n");
		}
}

struct node* createNode(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void connect(struct node* mat[],int i,int j)
{
	struct node* temp = mat[i];
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next = createNode(j+1);
}

void Graph(struct node* mat[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		printf("\n For %d vertex \n",i+1);
		for(j=i+1;j<n;j++)
			{	
					printf("Are %d and %d connected \n",i+1,j+1);
					int ch;
					scanf("%d",&ch);
					if(ch)
					{
						connect(mat,i,j);
						connect(mat,j,i);
						Display(mat,n);							
					}
			}
	}

	printf("Graph \n");
	Display(mat,n);
}

	
int main()
{
	printf("Enter vertex \n");
	int n;
	scanf("%d",&n);	
    struct node* mat[n];
    int i;
    for (i=0; i<n; i++) 
        {
        	mat[i] = (struct node*)malloc(sizeof(struct node));
        	mat[i]->data = i+1;
        	mat[i]->next = NULL;
		}
    Display(mat,n);
	Graph(mat,n);
	return 0;
}
