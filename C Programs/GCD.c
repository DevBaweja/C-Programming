#include<stdio.h>

int main()
{
        printf("Enter n1 and n2 \n");
        int n1,n2;
        int gcd = 1;
        scanf("%d %d",&n1,&n2);
        int i;
        for(i=2;i<=n1 && i<=n2;i++)
        	{
        		if(n1%i==0  && n2%i==0)
        			gcd = i;
        	}
        printf("Gcd is %d\n",gcd);
        return 0;
}
