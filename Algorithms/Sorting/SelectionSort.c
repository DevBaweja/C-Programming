// In selection sort element is searched for correct index by finding min or max
#include<stdio.h>


void swap(int A[],int p,int q)
{
	printf("Swapping Elements %d and %d \n",A[p],A[q]);
	int temp = A[p];
	A[p] = A[q];
	A[q] = temp;
}

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
// Best - Direction sorted O(n2)
// Worst - Reverse sorted O(n2)
void SelectionSort(int A[],int n)
{
	int i,j,min;
	int c=0,s=0;
	// i = [0 to n-2] as it is for passes
	// j = [i+1 to n-1] is used to get element from unsorted to sorted part
	for(i=0;i<=n-2;i++)
	{
		printf("\n In %d pass \n",(i+1));
		// searching correct element for this place from unsorted part
		min = i;
		for(j=i+1;j<=n-1;j++)
			{
				c++;
				if(A[j]<A[min])
					min=j;
			}	

		if(min==i)
			printf("No Swapping occurs \n");
		else
			{
				swap(A,i,min);
				s++;	
			}
		Array(A,n,'w');
	}
	printf("Total Comparsion : %d \n",c);
	printf("Total Swapping : %d \n",s);
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	SelectionSort(A,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}
