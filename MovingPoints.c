#include<stdio.h>
#include<stdlib.h>
typedef long long int num;

num input()
{
    num temp;
    scanf("%lld",&temp);
    return temp;
}

struct Point{
    num coordinate;
    num velocity;
};


void swap(struct Point * point[], num i,num j)
{
    struct Point* temp = point[i];
    point[i] = point[j];
    point[j] = temp;
}

void bubbleSort(struct Point* point[], num n)
{
   num i, j;
   for (i = 0; i < n-1; i++)
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (point[j]->coordinate > point[j+1]->coordinate)
              swap(point,j,j+1);
}

void create(struct Point * point[],num n)
{
    num i;
    for(i=0;i<n;i++)
        {
            num temp;
            temp = input();
            point[i]->coordinate = temp;
        }
    for(i=0;i<n;i++)
        {
            num temp;
            temp = input();
            point[i]->velocity = temp;
        }
}

void display(struct Point * point[],num n)
{
    num i;
    for(i=0;i<n;i++)
        printf("%lld ",point[i]->coordinate);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%lld ",point[i]->velocity);
    printf("\n");
}

int  main()
{
    num n;
    n = input();
    struct Point * point[n];
    num k;
     for(k=0;k<n;k++)
        point[k] = (struct Point*)malloc(sizeof(struct Point));

    create(point,n);

    num i,j;
    num distance = 0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
                num rv = point[i]->velocity-point[j]->velocity;
                if(rv<=0) // Initial
                    {
                        num d = point[i]->coordinate - point[j]->coordinate;
                        printf("%lld\n",d);
                        if(d>0)
                            distance += d;
                        else
                            distance -= d;
                    }
        }
        printf("%lld \n",distance);

}
