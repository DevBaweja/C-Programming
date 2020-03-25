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

void swap(int A[],int i,int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Partition(int A[],int low,int high,int n)
{
	int i = low;
	int j;
	for(j=low;j<high;j++)
	{
		if(A[j]<A[high])
		{
			swap(A,i,j);
			i++;
		}
	}
	swap(A,i,high);
		return i;
	
}
	
void QuickSort(int A[],int low,int high,int n)
{
	// Atleast two elemenets
	if(low<high)
	{
		int p = Partition(A,low,high,n);
		QuickSort(A,low,p-1,n);
		QuickSort(A,p+1,high,n);
	}
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	QuickSort(A,0,n-1,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}


