#include<stdio.h>

// Rotate by d elements

// Store 0th element in temp
// Shift all elements of A (left shift)
// Store back last element with 0th element

// Time Complexity O(n*d)
// d times and n for one by one rotation
// Space Complexity O(1)
// Using of temp

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

void leftRotateOneByOne(int A[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
			A[i] = A[i+1];
}

void rotate(int A[],int n,int d)
{
	if(n>=d)
	{
		int i,temp;
		for(i=0;i<d;i++)
		{
			// Store 0th element in temp
			temp = A[0];
			// Shift all elements of A (left shift)
			leftRotateOneByOne(A,n);
			// Store back last element with 0th element
			A[n-1] = temp;
		}
	}
	else
	{
		printf("Enter valid argument\n");
	}
}

int main()
{
    int n,d;
	printf("Enter size \n");
	scanf("%d",&n);
    int A[n];
	printf("Enter Elements \n");
    Array(A,n,'r');
    printf("Rotate By \n");
    scanf("%d",&d);
    rotate(A,n,d);
    printf("After Rotation \n");
    Array(A,n,'w');

	return 0;
}


