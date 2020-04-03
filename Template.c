#include<stdio.h>
#include<stdlib.h>
// Undirected Graph using Adjacency Matrix
typedef long long int num;

void Display(num *mat[],num n)
{
	num i,j;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d  ",mat[i][j]);
			printf("\n");
		}
}

void Graph(num *mat[],num n)
{
	num i,j;
	for(i=0;i<n;i++)
		mat[i][i] = 0; 
	// Diagonal is zero due to absence of self-loop
	
	for(i=0;i<n-1;i++)
	{
		printf("\n For %d vertex \n",i+1);
		for(j=i+1;j<n;j++)
			{	
					printf("Are %d and %d connected \n",i+1,j+1);
					num ch;
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
					num ch;
					scanf("%d",&ch);
						mat[i][j] = mat[j][i] = ch;
				}
			}
	}
*/
	
num main()
{
	printf("Enter vertex \n");
	num n;
	scanf("%d",&n);	
    num *mat[n];
    num i;
    for (i=0; i<n; i++) 
         mat[i] = (num *)malloc(n*sizeof(num));
	Graph(mat,n);
	return 0;
}