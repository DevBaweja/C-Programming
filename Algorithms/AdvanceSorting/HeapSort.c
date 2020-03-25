#include<stdio.h>

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

void adjust(int A[],int n,int i)
{
		int item = A[i];
		int j = 2*i+1; // Child node
		while(j<n)
		{

			if(A[j+1]>A[j] && j<n-1)
					j++;
			if(item<A[j])
				A[(j-1)/2] = A[j];
			else
				break;
			j = 2*j+1;
		}
		A[(j-1)/2] = item;

}

void heapify(int A[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		adjust(A,n,i);
	}
}

void swap(int A[],int j)
{
	int temp = A[0];
	A[0] = A[j];
	A[j] = temp;
}

void neutral(int B[],int n)
{
	int i;
	for(i=0;i<n;i++)
		B[i]=0;
}

void heap(int A[],int n)
{
	heapify(A,n);

	int B[n];
	neutral(B,n);

	int i;
		int j=0;
		for(i=n-1;i>0;i--)
		{
			swap(A,i);
			B[j++] = A[i];
			adjust(A,i,0);
		}
	B[j] = A[0];
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	heap(A,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}
