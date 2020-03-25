#include<stdio.h>
typedef long long int num;

int main()
{
	num p,q;
	printf("Enter p and q \n");
	scanf("%lld %lld",&p,&q);
	num k = p/q;
	printf("Value: %lld\n",k);
	return 0;
}
