#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define BASE 10

struct node {
	int data;
	struct node* next;
};

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

void Matrix(struct node* radix[])
{
	int i;
	struct node* temp;
	printf("\n");
			for(i=0;i<BASE;i++)
			{
				temp = radix[i];
				printf("%d : ",i);
				if(temp)
				{
					do{
						printf("%d ",temp->data);
						temp = temp->next;		
					}
					while(temp);
				}
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

void fill(int A[],struct node* radix[])
{
	int i,j;
	int k=0;
	
	struct node* temp;
		for(i=0;i<BASE;i++)
		{
			temp = radix[i];
			if(temp)
			{
				do{
					A[k++] = temp->data;
					temp = temp->next;		
				}
				while(temp);
			}
		}
}

struct node* createNode(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void initialRadix(struct node* radix[])
{
	int i;
	for(i=0;i<BASE;i++)
			radix[i] = NULL;		
}

void RadixSort(int A[],int n)
{
	int max = maximum(A,n);
	int pass = digitCount(max);
	int i,j;
	struct node* radix[BASE];
	
	for(i=0;i<pass;i++)
	{
		initialRadix(radix);;
		printf("\n In %d pass \n",i+1);
		for(j=0;j<n;j++)
		{
			int mod = (A[j]/(int)pow(10,i))%10;
			struct node* temp = radix[mod];
			if(!temp)
					radix[mod] = createNode(A[j]);
			else
			{
				while(temp->next)
					temp = temp->next;
				temp->next = createNode(A[j]);
			}
		}
		Matrix(radix);
		fill(A,radix);
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
