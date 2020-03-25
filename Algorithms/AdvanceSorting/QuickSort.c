#include<stdio.h>

void Array(int a[],int n,char mode)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(mode=='r')
			scanf("%d",&a[i]);
		if(mode=='w')
			printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int A[],int i,int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	printf("Swapping %d %d \n",A[i],A[j]);
}

int Partition (int A[],int low,int high,int n)
{
	printf("\n Partition %d %d \n",low,high);
	int v = A[low];
	printf("Pivot %d \n",v);
	int i=low+1,j=high;
	
	while(i<j)
	{
		while(A[i]<=v && i<high)
			i++;
		while(A[j]>=v && j>low)
			j--;
			
		if(i<j)
			{
				swap(A,i,j);
				Array(A,n,'w');
			}
	}
	printf(" i = %d j = %d \n",i,j);
	swap(A,low,j);
	printf("After Breaking \n");
	Array(A,n,'w');
	return j;
}

int QuickSort(int A[],int low,int high,int n)
{
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
	int a[n];
	printf("Enter Elements \n");
	Array(a,n,'r');
	QuickSort(a,0,n-1,n);
	printf("After Sorting \n");
	Array(a,n,'w');
	return 0;
}
// 44 15 77 88 55 17 47 19 99

