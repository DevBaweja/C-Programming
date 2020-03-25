#include<stdio.h>

void swap(int A[],int i,int j)  
{  
    int temp = A[i];  
    A[i] = A[j];  
    A[j] = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int A[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (A[j] > A[j+1])  
            swap(A[j],j,j+1);  
} 

void display()
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void way(int A[],int n,int k,int s,int d)
{
	
}


int main()
{
	int n;
	scanf("%d",&n);
	int k;
	scanf("%d",&k);

	int A[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	int s = A[0];
	int d = A[n-1];
	bubbleSort(A,n);
	display();

	way(A,n,k,s,d);
}