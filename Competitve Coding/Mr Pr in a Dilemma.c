#include<stdio.h>
#include<math.h>
typedef long long int num;
int main()
{
	num t;
	scanf("%lld",&t);
	num a,b;
	num c,d;
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		scanf("%lld %lld",&c,&d);
		num diff1 = abs(b-a);
		num diff2 = abs(d-c);
		if(diff2!=0 && diff1%diff2==0)
			printf("YES\n");
		else
			printf("NO\n");

	}
}