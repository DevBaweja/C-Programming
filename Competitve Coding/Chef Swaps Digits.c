#include <stdio.h>
int maxSum;
void makeDigit(int a,int b,int c,int d)
{
    int temp = a*10+b+c*10+d;
    if(temp > maxSum)
        maxSum = temp;
}

int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int a1,a2,b1,b2;
        maxSum = a+b;
        a1 = a/10;
        a2 = a%10;
        b1 = b/10;
        b2 = b%10;
        // a1 a2 b1 b2
        /* printf("%d %d %d %d \n",a1,a2,b1,b2); */
        
        // makeDigit(b1,a2,a1,b2); No difference
        if(a1 != 0)
        makeDigit(b2,a2,b1,a1);
        if(b1 != 0)
        makeDigit(a1,b1,a2,b2); 
        // makeDigit(a1,b2,b1,a2); No difference

        printf("%d\n",maxSum);
    }
    
    return 0;
}
