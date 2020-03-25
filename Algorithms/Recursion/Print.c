#include<stdio.h>

void recursion(int i,int n)
{
	if(i<=n)
	{
		printf("%d \n",i);
		recursion(i+1,n);
	}
}

int main()
{
	printf("Enter lower and upper bound \n");
	int l,u;
	
	scanf("%d %d",&l,&u);
	printf("Printing \n");
	recursion(l,u);
	return 0;
}
