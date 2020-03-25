#include<stdio.h>
#include<string.h>
#define SIZE 5

void swap(char A[],int i,int j)
{
	char temp = A[i];
	A[i] = A[j];
	A[j] = temp; 
}

void perm(char A[],int l,int r)
{
	int k;
	if(l==r)
		printf("%s \n",A);
		else
	{
		for(k=l;k<=r;k++)
		{
			swap(A,l,k);
			perm(A,l+1,r);
			swap(A,l,k); // Backtracking
		}
	}
}

int main()
{
	char str[SIZE];
	printf("Enter String \n");
	scanf("%s",str);
	int l = 0;
	int r = strlen(str)-1;
	perm(str,l,r);
	return 0;
}


