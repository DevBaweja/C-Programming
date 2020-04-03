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

num minimum(num a,num b,num c)
{
    if( a < b && a < c)
        return a;
    else
     {
        if( b < c)
         return b;
        else
         return c;    
     }

}

num OPT(num A[],num n)
{
	num p,q,r,s;
	p=-2000000001;q=-2000000001;r=2000000001;s=2000000001;
	bool extra = false;
	for(num i=0;i<n;i++)
	{
        if(A[i]>0) // Positive Number
        {
            if(A[i]==r)
            {
                s = r;
            }
            else
            if(A[i]<r)
                {
                    s = r;
                    r = A[i]; 
                }
            else
            if(A[i]<s)
            {
                s = A[i];
            }
        }
        if(A[i]<0) // Negative Number
        {
            if(A[i]==q)
            {
                p = q;
            }
            else
            if(A[i]>q)
            {
                p = q;
                q = A[i];
            }
            else
            if(A[i]>p)
            {
                p = A[i];
            }
        }
        if(A[i]==0)
        {
            extra = true;
        }
    }
// 	printf("%lld %lld %lld %lld \n",p,q,r,s);

	num minSum,minSum1,minSum2;
	if(s+q>0)
	    minSum1 = s+q;
	else
	if(s+p>0)
	    minSum1 = s+p;
	else
	    minSum1 = 4000000001;
	    
	 
	if(r+q>0)
	    minSum2 = r+q;
	else
	if(r+p>0)
	    minSum2 = r+p;
	else
	    minSum2 = 4000000001;    
	
	minSum = r + s;
	
	if(extra)
	{
	    minSum = r;    
	}
	
// 	printf("%lld %lld %lld \n",minSum,minSum1,minSum2);
	num min = minimum(minSum,minSum1,minSum2);
	return min;
}

int main()
{
	// your code goes here
	num n;
	n = input();
	num* A = (num*)malloc(n*sizeof(num));
	for(num i=0;i<n;i++)
		A[i] = input();
	printf("%lld\n",OPT(A,n));
}