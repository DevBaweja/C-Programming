//  In insertion sort, values is inserted at correct positio by shifting 
#include<stdio.h>

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
// Best - Direction sorted O(n) outer loop-n inner loop-1
// Worst - Reverse sorted O(n2)
void InsertionSort(int A[],int n)
{
	int i,j,key;
	int s=0,c=0;
	// i = [1 to n-1] as it for passes
	// j = i-1 to 0 as to get correct position 
	for(i=1;i<=n-1;i++)
	{
		int stemp = 0;
		key = A[i];
		j = i-1;
		// Condition is checked from left to right
		while(j>=0 && ++c && key<A[j])
		{
			stemp++;
			A[j+1] = A[j];
			j--;
			
		}
//		for(j=i-1;j>=0;j--)
//		{
//			c++;
//			if(key<A[j])
//				{
//					A[j+1]  = A[j];
//					stemp++;
//					continue;
//				}
//					break;
//		}
		A[j+1] = key; // to fill the gap created
		printf("%d is inserted at %d position \n",key,j+1);
		printf("Shifts done is %d \n",stemp);
		s+= stemp;
		
		Array(A,n,'w');
		printf("\n");
	}
	printf("Total Comparsion : %d \n",c);
	printf("Total Shifting : %d \n",s);
}

int main()
{
	printf("Enter size \n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements \n");
	Array(A,n,'r');
	InsertionSort(A,n);
	printf("After Sorting \n");
	Array(A,n,'w');
	return 0;
}


