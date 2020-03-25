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

void Merge(int A[],int l,int m,int h)  // Will sorted merge the two sub-array into array
{
	int n1 = m-l+1;
	int n2 = h-m;
	int L[n1];
	int R[n2];
	int loop;	
	for(loop=0;loop<n1;loop++)
		L[loop] = A[l+loop];
	for(loop=0;loop<n2;loop++)
		R[loop] = A[m+1+loop];
	
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
			A[k++] = L[i++];
			else
			A[k++] = R[j++];
	}
	
	while(i<n1)
		A[k++] = L[i++]; 
	while(j<n2)
		A[k++] = R[j++];
}

void MergeSort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		MergeSort(A,,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
	
	// break into low,mid  mid+1,high
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	
	MergeSort(A,0,n-1);
	Array(A,n,'w');
	return 0;
}


