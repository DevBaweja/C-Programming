#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int x[n];
	int y[m];

	int c[m][n];
	int i,j;
	for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			c[0][i] = 0;
		}
	for(i=0;i<m;i++)
		{
			scanf("%d",&y[i]);
			c[i][0] = 0;
		}

	for(i=1;i<m;i++)
		for(j=1;j<n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j] = c[i-1][j-1]+1;
			}
			else
				if(c[i-1][j] > c[i][j-1])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i][j-1];
		}

	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
}
