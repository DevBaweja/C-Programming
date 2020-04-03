#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long int num;
num n,k,q;
num *p;
num sum;

num input()
{
	num temp;
	scanf("%lld",&temp);
	return temp;
}	

void initial()
{
    num mod = pow(10,9)+7;
    sum = 0;
    num exp = 0;
	for(num i=0;i<n;i++)
		{
			num in = n-(i+1);
			if(p[in]!=-1)
			{
				sum += p[in]*pow(k,exp++);
				sum %= mod;
			}
		}
	printf("%lld\n",sum);
}

int main()
{
	n = input();
	k = input();
	q = input();

	p = (num*)malloc(n*sizeof(num));
	for(num i=0;i<n;i++)
		p[i] = input();
	initial();

	int ch;
	while(q--)
	{
		int ch;
		scanf("%d",&ch);
		
		num index = input();
		index--;
		switch(ch)
		{

			case 1:
			{
				num x = input();

				p[index] = x;
				initial();
			}
			break;
			case 2:
			{
				p[index] = -1;
				initial();
			}
			break;
		}
	}
}