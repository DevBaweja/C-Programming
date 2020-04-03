#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef long long int num;

num input()
{
	num temp;
	scanf("%lld",&temp);
	return temp;
}

num OPT(bool A[],num n)
{
    num inverse = 0;
    for(num i=0;i<n;i++)
    {
        if(A[i]) // Founded Right
        {
            // Count Left from Next onward
            for(num j = i+1;j<n;j++)
            {
                if(!A[j])
                    inverse++;
            }
        }
    }
    return inverse;
}

int main()
{
	// your code goes here
	num n;
	n = input();
	bool* A = (bool*)malloc(n*sizeof(bool));
	for(num i=0;i<n;i++)
	{
		char temp;
		scanf(" %c",&temp);
		A[i] = (temp == 'R') ? true : false;
	}
	printf("%lld",OPT(A,n));
}