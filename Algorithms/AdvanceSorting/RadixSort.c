#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define BASE 10

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

void Matrix(int *mat[],int n)
{
	int i,j;
	printf("\n");
	for(i=n-1;i>=0;i--)
		{
			for(j=0;j<BASE;j++)
				printf("%d \t",mat[j][i]);
			printf("\n");
		}
	printf("\n");
}

int maximum(int A[],int n)
{
	int maxi = 0;
	int i;
	for(i=1;i<n;i++)
	{
		if(A[i]>A[maxi])
			maxi=i;
	}
	return A[maxi];
}

int digitCount(int num)
{
	int temp,count;
	for(temp=num,count=0;temp>0;temp /= 10)
		count++;
	return count;
}

void initialArray(int index[])
{
	int i;
	for(i=0;i<BASE;i++)
		index[i] = 0;
}

void initialMatrix(int *mat[],int n)
{
	int i,j;
	for(i=0;i<BASE;i++)
		for(j=0;j<n;j++)
			mat[i][j] = 0;
}

void fill(int A[],int *radix[],int index[])
{
	int i,j;
	int k=0;
	
	for(i=0;i<BASE;i++)
	{
		for(j=0;j<index[i];j++)
			A[k++] = radix[i][j];
	}
}

void RadixSort(int A[],int n)
{
	int max = maximum(A,n);
	int pass = digitCount(max);
	int i,j;
	int *radix[BASE];
	for(i=0;i<BASE;i++)
		radix[i] = (int *)malloc(n*sizeof(int));
	int index[BASE];
	
	for(i=0;i<pass;i++)
	{
		initialMatrix(radix,n);
		initialArray(index);
		printf("\n In %d pass \n",i+1);
		for(j=0;j<n;j++)
		{
			int mod = (A[j]/(int)pow(10,i))%10;
			radix[mod][index[mod]++] = A[j];
		}
		Matrix(radix,n);
		fill(A,radix,index);
		Array(A,n,'w');
	}
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Element \n");
	Array(A,n,'r');
	RadixSort(A,n);
	printf("\n After Sorting \n");
	Array(A,n,'w');
	return 0;
}


