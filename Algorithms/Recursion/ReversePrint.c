#include<stdio.h>

void recursion(int i,int n)
{
	if(i<=n)
	{
		recursion(i+1,n);
		printf("%d \n",i);
	}
}

int main()
{
	printf("Enter lower and upper bound \n");
	int l,u;
	
	scanf("%d %d",&l,&u);
	printf("Reverse Printing \n");
	recursion(l,u);
	return 0;
}
