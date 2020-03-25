//  In bubble sort, bubbling element to the end of array is done
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
// Best - Direction sorted O(n) outer loop-1 inner loop-n 
// Worst - Reverse sorted O(n2)
void BubbleSort(int A[],int n)
{
	int i,j;
	int s=0,c=0;
	int flag = 0;
	// i = [0 to n-2] as it for passes
	// j = [n-1 to i+1] as to bubble up it upto sorted part
	for(i=0;i<=n-2;i++)
	{
		printf("\n In %d pass \n",(i+1));
		
		for(j=n-1;j>=i+1;j--)
		{
			c++;
			if(A[j]<A[j-1])
				{
					swap(A,j,j-1);
					s++;
					flag = 1;
				}
				else
					printf("No Swapping occur \n");
					
			Array(A,n,'w');
		}
		
		if(flag==0)
			{
				printf("No Swapping occur in this pass \n");
				break;
			}
			// ie no swapping occur
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
	BubbleSort(A,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}


