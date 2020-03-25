#include<stdio.h>
#include<math.h>
#define SIZE 50

void print(int U[])
{
	int i;
	for(i=0;i<SIZE;i++)
		printf("%d \n",U[i]);
}

void Ugly(int A[],int n)
{
	int U[SIZE];
	int P[n];
	int power = 1;
	int i;
	
	for(i=0;i<n;i++)
		power *= pow(A[i],P[i]);
	
	U[i] = power;
	print(Ugly);
}

int main()
{
	printf("Enter Size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	Ugly(A,n);
	return 0;
}

