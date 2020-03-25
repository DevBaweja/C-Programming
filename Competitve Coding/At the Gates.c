#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define flipCoin(coin,flipped)

int main()
{
	int tests;
	scanf("%d",&tests);
	int n,k;
	bool flipped;
	while(tests--)
    {
        flipped = false;
        scanf("%d",&n);
        scanf("%d",&k);
        int coins[n];
        int i;
        char temp;
        for(i=0;i<n;i++)
        {
            scanf(" %c",&temp);
            if(temp=='H')
                coins[i]=1;
            if(temp=='T')
                coins[i]=0;
        }
        int count = 0;
        for(i=1;i<=k;i++)
        {
            if(!flipped)
            {
                if(coins[n-i]==1) // Head occur
                    flipped = true;
            }
            else
            {
                if(coins[n-i]==0) // Head occur
                    flipped = false;
            }
        }
        for(i=k+1;i<=n;i++)
        {
              if(!flipped)
            {
                if(coins[n-i]==1) // Head occur
                    count++;
            }
            else
            {
                if(coins[n-i]==0) // Head occur
                    count++;
            }
        }
        printf("%d\n",count);
    }

	return 0;
}
