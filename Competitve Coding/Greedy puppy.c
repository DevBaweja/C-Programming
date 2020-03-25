#include<stdio.h>
typedef long long int num;

long long int input()
{
	long long temp;
	scanf("%lld",&temp);
	return temp;
}

int main()
{
	num k;
	k = input();
	while(k--)
	{
		num n,k;
		n = input();
		k = input();
		num max=0;
		num i,temp;

		// Call everyone
		if(k>n)
		{
			printf("%lld\n",n);
			continue;
		}
		// 0 and 1 will give nothing
		for(i=2;i<=k;i++)
		{
			temp=n%i;
			if(temp>max)
				max = temp;
		}
		printf("%lld\n",max);
	}
}
