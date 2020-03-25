#include<stdio.h>

void isUgly(int A[],int n,int s)
{
	int temp = n;
	int i=0;
	while(i<s)
	{			
		int mod = temp%A[i];
		if(mod==0)
		temp = temp/A[i];
		else
		i++;	
	}
	if(i==s)
		printf("Not Ugly \n");
		else
		printf("Ugly \n");
}

int main()
{
	printf("Enter Size \n");
	int s;
	scanf("%d",&s);
	int A[s];
	printf("Enter Elements \n");
	int i;
	for(i=0;i<s;i++)
		scanf("%d",&A[i]);
	while(1)
	{
	printf("Enter Number \n");
		int n;
		scanf("%d",&n);
		isUgly(A,n,s);
	}
	return 0;
}

// 4 2 7 13 19
