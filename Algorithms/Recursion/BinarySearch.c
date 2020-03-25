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

int Search(int A[],int n,int key)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(A[mid]==key)
			return mid;
		
		if(key<A[mid])
			high = mid-1;
		if(key>A[mid])
			low=mid+1;
	}
	
	return -1;;
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	int key;
	printf("Enter Key \n");
	scanf("%d",&key);
	int index = Search(A,n,key);
	if(index>=0)
	printf("Element is found at is %d \n",index+1);
	else
	printf("Element not found \n");
	return 0;
}


