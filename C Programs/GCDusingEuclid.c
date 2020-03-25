#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
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
4 0

7 21
21 7
7 0 

3 4
4 3
3 1
1 0

10 6
6 4
4 2
2 0
*/