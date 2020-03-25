#include<stdio.h>

int main(void)
{
	
	long long int t;
	scanf("%lld",&t);
	while(t!=0)
	{
	int k;
	long long int d,c,l;
	scanf("%lld %lld %lld",&c,&d,&l);
	if(l%4!=0)
	printf("no\n");
	else
	{
			if((c-2*d)>0)
		k=1;
		else 
		k=0;
			long long int m=l/4;
			if( m>=(d+((c-2*d)*k)) &&  m<=(c+d) )
			printf("yes\n");
			else 
			printf("no\n");
	}
	t--;
	}
}
