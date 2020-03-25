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

int Freq(int A[],int n,int key)
{
	if(n>=0)
	{
		if(A[n]==key)
			{
				printf("At %d \n",n+1);
				return 1+Freq(A,n-1,key);
			}
			else
			return Freq(A,n-1,key);
	}
	else 
	return 0;
		
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
	int count = Freq(A,n-1,key);
	printf("Count is %d \n",count);
	return 0;
}


