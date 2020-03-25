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

int Prod(int A[],int n)
{
	if(n>=0)
		return A[n]*Prod(A,n-1);
	else
		return 1;
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	int product = Prod(A,n-1);
	printf("Product is %d \n",product);
	return 0;
}


