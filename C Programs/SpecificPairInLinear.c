#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef long long int num;

void Merge(num A[],num bi[],num l,num m,num h)  // Will sorted merge the two sub-array into array
{
    num n1 = m-l+1;
    num n2 = h-m;
    num L[n1];
    num R[n2];
    num loop;
    for(loop=0;loop<n1;loop++)
        L[loop] = A[l+loop];
    for(loop=0;loop<n2;loop++)
        R[loop] = A[m+1+loop];

    num i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
            {
                A[k] = L[i++];
            }
            else
            {
                A[k] = R[j++];
            }
            bi[k] = A[k]>0 ? 1 : -1;
            if(!A[k])
               bi[k]=0; 
            k++;
    }

    while(i<n1)
        {
            A[k] = L[i++];
            bi[k] = A[k]>0 ? 1 : -1;
            if(!A[k])
               bi[k]=0; 
            k++;
        }
    while(j<n2)
        {
            A[k] = R[j++];
            bi[k] = A[k]>0 ? 1 : -1;
            if(!A[k])
               bi[k]=0; 
            k++;
        }
}

void MergeSort(num A[],num bi[],num low,num high)
{
    if(low<high)
    {
        num mid = (low+high)/2;
        MergeSort(A,bi,0,mid);
        MergeSort(A,bi,mid+1,high);
        Merge(A,bi,low,mid,high);
    }

    // break into low,mid  mid+1,high
}


void scan(num *a,num n)
{
    num i;
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
}
/*
num pairRec(num *c,num n)
{
   num count=0;
    num i,j;
    if(n==2)
    {
        if(c[0]+c[1]>0)
            return 1;
        else
            return 0;
    }
    else
        if(n=3)
        {
            for(i=0;i<3;i++)
                for(j=i+1;j<3;j++)
                    if(c[i]+c[j]>0)
                        count++;
            return count;
        }
else
    {
        num l[n/2],r[n/2+n%2];
        for(i=0;i<n/2;i++)
            l[i] = c[i];
        for(i=n/2;i<n;i++)
            r[i-n/2] = c[i];

        return pairRec(l,n/2)+pairRec(r,n/2+n%2);
        }
}
*/
void print(num a[],num n)
{
    num i;
    for(i=0;i<n;i++)
        printf("%lld ",a[i]);
    printf("\n");
}
// Finding two index where sum is +ve
num positive(num *c,num n)
{
// Sorted
    num bi[n];
    print(c,n);
    MergeSort(c,bi,0,n-1); // n*log(n)
    print(c,n);
    print(bi,n);
}

num pair(num *a,num *b,num n)
{
    num i,j,count=0;
    num c[n];
    for(i=0;i<n;i++)
        c[i] = a[i]-b[i];

    count = positive(c,n);
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
    num count  = pair(a,b,n);
    printf("%lld\n",count);
}
