#include <stdio.h>
#include<stdlib.h>
typedef long long int num;

void scan(num *a,num n)
{
	num i;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
}

num pairRec(num *a,num *b,num n)
{
	num t = n%2;
    num i,j;
	num p[n/2],q[n/2+t],r[n/2],s[n/2+t],count=0;
	if(n==2)
	{
		if(a[0]+a[1]>b[0]+b[1])
        {
            printf("(%lld,%lld):(%lld,%lld) \n",a[0],a[1],b[0],b[1]);
            return 1;
        }
		else
			return 0;
	}
	else
		if(n==3)
		{
			for(i=0;i<3;i++)
            		for(j=i+1;j<3;j++)
                		if(a[i]+a[j]>b[i]+b[j])
                				{
                                    printf("(%lld,%lld):(%lld,%lld) \n",a[i],a[j],b[i],b[j]);
                				    count++;
                				}
            return count;
		}
		else
		{

			// Calculate p,q,r,s
			for(i=0;i<n/2;i++)
			{
					p[i]=a[i];
					r[i]=b[i];
			}
			for(i=n/2,j=0;i<n && j<n/2+t;i++,j++)
			{
					q[j] = a[i];
					s[j] = b[i];
			}

			for(i=0;i<n/2;i++)
				for(j=0;j<n/2+t;j++)
					if(p[i]+q[j]>r[i]+s[j])
						{
                            printf("(%lld,%lld):(%lld,%lld) \n",p[i],q[j],r[i],s[j]);
						    count++;
						    // This will still run n^2/4
						}

			return count + pairRec(p,r,n/2) + pairRec(q,s,n/2+t);
		}
}

num pairIte(num *a,num *b,int n)
{
    num i,j,count=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        		if(a[i]+a[j]>b[i]+b[j])
        			{
        			    printf("%d ",a[i]);
        			    printf("%d ",a[j]);
        			    printf("%d ",b[i]);
        			    printf("%d \n",b[j]);
        			    count++;
        			}
    return count;
}

int main()
{
	num *a,*b;
	num n;
	printf("Enter n \n");
	scanf("%lld",&n);
	a = (num*)malloc(n*sizeof(num));
	b = (num*)malloc(n*sizeof(num));
	scan(a,n);
	scan(b,n);
	num count  = pairRec(a,b,n);
	//num count = pairIte(a,b,n);
	printf("%lld\n",count);
}
