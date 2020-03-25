#include<stdio.h>
#include<stdlib.h>
// Undirected Graph using Adjacency Matrix

void Display(int *mat[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d  ",mat[i][j]);
			printf("\n");
		}
}

void Graph(int *mat[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		mat[i][i] = 0; 
	// Diagonal is zero due to absence of self-loop
	
	for(i=0;i<n-1;i++)
	{
		printf("\n For %d vertex \n",i+1);
		for(j=i+1;j<n;j++)
			{	
					printf("Are %d and %d connected \n",i+1,j+1);
					int ch;
					scanf("%d",&ch);
						mat[i][j] = mat[j][i] = ch;
			}
	}

	printf("Graph \n");
	Display(mat,n);
}
// Without initial diagonal being zero
/*
for(i=0;i<n;i++)
	{
		if(i!=n-1)
			printf("\n For %d vertex \n",i+1);
		for(j=i;j<n;j++)
			{	
			if(i==j)
				mat[i][j] = 0;
			else
				{
					printf("Are %d and %d connected \n",i+1,j+1);
					int ch;
					scanf("%d",&ch);
						mat[i][j] = mat[j][i] = ch;
				}
			}
	}
*/
	
int main()
{
	printf("Enter vertex \n");
	int n;
	scanf("%d",&n);	
    int *mat[n];
    int i;
    for (i=0; i<n; i++) 
         mat[i] = (int *)malloc(n*sizeof(int));
	Graph(mat,n);
	return 0;
}
