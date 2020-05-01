#include<stdio.h>
#include<math.h>
int primefactor(int num){

	int x1=0; // Only for 2
	while(num%2==0)
	{
		num = num/2;
		x1++;
	}

	int x2 = 0;
	for(int i=3;i<=sqrt(num);i+=2)
	{
		int x = 0; // loop
		while(num%i==0)
		{
			x++;
			num = num/i;
		}
		x2+=x;
	}

	int x3=0;
	if(num>2)
		x3 = 1;

	return (x1+x2+x3);
}

int main(){

	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);


	int test;
	scanf("%d",&test);
	while(test--)
	{
		int L,R;
		scanf("%d %d",&L,&R);
		int result=0;
		for(int i=L;i<=R;i++)
		{
			result += primefactor(A[i]);
		}
		printf("%d\n",result);
	}
}