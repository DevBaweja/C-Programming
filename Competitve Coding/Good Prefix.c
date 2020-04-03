#include <stdio.h>
#include<stdlib.h>
#define ALPHA 26
int alpha[ALPHA];
void initial()
{
   for(int i=0;i<ALPHA;i++)
    alpha[i] = 0;
}
int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        initial();
        
        char str[10000];
        scanf("%s",str);
        
        int k,x;
        scanf("%d %d",&k,&x);
        int loop = 0;
        for(int i=0;str[i]!='\0';i++)
        {
            char c = str[i];
            int index = (int)c - 97;
            
            if(alpha[index] < x) // Simply inserted
            {
                
                alpha[index]++;
                loop++;
            }
            else
            if(k>0) // Deleting Element
                k--;
            else
                break;
        }
        printf("%d\n",loop);
    }
    
    return 0;
}