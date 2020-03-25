#include<stdio.h>

// Rotate by d elements

// Store d element in temp array
// Shift A by d elements (left shift)
// Store back d elements to A

// Time Complexity O(n)
// n for shifting by d elements
// Space Complexity O(d)
// Using of temp array of size d

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

void rotate(int A[],int n,int d)
{
	if(n>=d)
	{
		// Storing d elements in temp
		int temp[d];
		int i;
		for(i=0;i<d;i++)
			temp[i] = A[i];

		// Shifting A by d elements (left shift)
		for(i=0;i<n-d;i++)
			A[i] = A[i+d];

		// Storing back d elements to A
		for(i=n-d;i<n;i++)
			A[i] = temp[i-n+d];
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


