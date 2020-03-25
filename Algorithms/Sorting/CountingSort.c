// Counting Sort uses values as index to sort
#include<stdio.h>
#include<stdlib.h>
// Elements must be positive.(as they acts as index also)
// Elements can be duplicated

void Array(int A[],int n,char mode)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(mode=='r')
			scanf("%d",&A[i]);
		if(mode=='w')
			printf("%d ",A[i]);
	}
	printf("\n");
}

int maxArray(int A[],int n)
{
	int max = A[0];
	int i;
	for(i=0;i<n;i++)
	{
		if(max<A[i])
			max = A[i];
	}
	return max+1;
}

int* countFreq(int A[],int n,int max)
{
	int* count = (int*)malloc(max*sizeof(int));
	int i;
	// Initial all zero
	for(i=0;i<max+1;i++)
		count[i] = 0;
	
	for(i=0;i<n;i++)
		count[A[i]]++;
		
	return count;
}

void findIndex(int count[],int max)
{
	int i;
	for(i=0;i<max-1;i++)
	count[i+1] += count[i];
}

void CountingSort(int A[],int n)
{
	int max = maxArray(A,n);
	int* count = countFreq(A,n,max);
	printf("Count Array \n");
	Array(count,max,'w');
	findIndex(count,max);
	printf("Finding Index \n");
	Array(count,max,'w');
	
	int B[n];
	int i=0;
	while(i<n)
		B[--count[A[i]]] = A[i++];
	
	for(i=0;i<n;i++)
		A[i]=B[i];
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Element \n");
	Array(A,n,'r');
	CountingSort(A,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}


