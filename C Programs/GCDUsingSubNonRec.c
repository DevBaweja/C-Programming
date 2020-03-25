#include<stdio.h>

int gcd(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main()
{
    while(1)
    {
        printf("Enter n1 and n2 \n");
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        int GCD = gcd(n1,n2);
        printf("Gcd is %d\n",GCD);
    }
        return 0;
}
/*
12 4
8 4
4 4

4

7 21
7 14
7 7
7


3 4
3 1
2 1
1 1
1

10 6
4 6
4 2
2 2
2

*/