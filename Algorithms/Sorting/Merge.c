#include<stdio.h>
#include<stdlib.h>

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

int* Merge(int A[],int B[],int p,int q)
{
	int *C = (int*)malloc((p+q)*sizeof(int));
	// int C[p+q];
	int i=0,j=0,k=0;
	while(i<p && j<q)
	{
		if(A[i]<B[j])
			C[k++] = A[i++];
			else
			C[k++] = B[j++];
	}
	
	while(i<p)
		C[k++] = A[i++]; 
	while(j<q)
		C[k++] = B[j++];
		Array(C,p+q,'w');
	return C;
}

int main()
{
	printf("Enter size \n");
	int p;
	scanf("%d",&p);
	int A[p];
	printf("Enter Elements \n");
	Array(A,p,'r');
	
	
	printf("Enter size \n");
	int q;
	scanf("%d",&q);
	int B[q];
	printf("Enter Elements \n");
	Array(B,q,'r');
	
	int *C = Merge(A,B,p,q);
	Array(C,p+q,'w');
	return 0;
}


