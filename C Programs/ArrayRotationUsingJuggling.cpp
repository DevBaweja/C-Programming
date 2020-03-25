#include<stdio.h>
// Juggling Algorithm
// Instead of moving one by one divide array into subsets
// where number of element in subsets is equal to gcd of d and n
// move element within subsets

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

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

void rotate(int A[],int n,int d)
{
	int i,j,k,temp;
	if(n>=d)
	{
		int g_c_d = gcd(d,n);
		for(i=0;i<g_c_d;i++) // Number of element in block is g_c_d
		{
			// Move i-th value of each block
			temp = A[i];
			j=i;
			// j is tail
			// k is head
			while(1)
			{
				k=j+d; // Head -> next

				if()
				A[j] = A[k]; // Tail = Head
				j=k; // Tail -> next
			}
			A[j] = temp;
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


/*
				if (k >= n)
                k = k - n;
		        if (k == i)
		            break;
		        arr[j] = arr[k];
           		j = k;
*/

